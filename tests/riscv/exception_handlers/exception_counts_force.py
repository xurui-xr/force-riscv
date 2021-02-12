#
# Copyright (C) [2020] Futurewei Technologies, Inc.
#
# FORCE-RISCV is licensed under the Apache License, Version 2.0
#  (the "License"); you may not use this file except in compliance
#  with the License.  You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES
# OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
# NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
# See the License for the specific language governing permissions and
# limitations under the License.
#
import RandomUtils

import exception_handlers_test_utils
from base.Sequence import Sequence
from riscv.EnvRISCV import EnvRISCV
from riscv.GenThreadRISCV import GenThreadRISCV
from riscv.Utils import LoadGPR64


#  This test verifies that exceptions are triggered as expected and that
#  eneration and simulation can continue after the exceptions are handled. We
# reserve a selection of GPRs to test the exception dispatcher register save
# and restore logic. Reserving the registers prevents the random instructions
# generated by this test from modifying the registers. However, exception
# handlers may modify reserved registers, but must restore them before
# returning.
class MainSequence(Sequence):
    def __init__(self, gen_thread, name=None):
        super().__init__(gen_thread, name)

        self._mExceptCounts = {4: 0, 6: 0, 8: 0, 9: 0, 11: 0}

    def generate(self, **kargs):
        self._configureExceptionDelegation(self._mExceptCounts.keys())
        self._switchToRandomPrivilegeLevel()

        rv32 = self.getGlobalState("AppRegisterWidth") == 32

        orig_gpr_values = exception_handlers_test_utils.reserve_random_gprs(
            self, 20
        )
        ecall_except_codes = {0: 8, 1: 9, 3: 11}
        for _ in range(100):
            priv_level = self.getPEstate("PrivilegeLevel")
            ecall_except_code = ecall_except_codes[priv_level]
            except_code = self.choice((4, 6, ecall_except_code))

            if except_code == 4:
                unaligned_target_addr = (
                    self.genVA(Size=16, Align=8, Type="D") + 1
                )
                if rv32:
                    self.genInstruction(
                        "LW##RISCV", {"LSTarget": unaligned_target_addr}
                    )
                else:
                    self.genInstruction(
                        "LD##RISCV", {"LSTarget": unaligned_target_addr}
                    )
                self._verifyExceptionCount(4)
                exception_handlers_test_utils.assert_gpr_values_unchanged(
                    self, orig_gpr_values
                )
            elif except_code == 6:
                unaligned_target_addr = (
                    self.genVA(Size=16, Align=8, Type="D") + 1
                )
                if rv32:
                    self.genInstruction(
                        "SW##RISCV", {"LSTarget": unaligned_target_addr}
                    )
                else:
                    self.genInstruction(
                        "SD##RISCV", {"LSTarget": unaligned_target_addr}
                    )
                self._verifyExceptionCount(6)
                exception_handlers_test_utils.assert_gpr_values_unchanged(
                    self, orig_gpr_values
                )
            elif except_code == ecall_except_code:
                self.genInstruction("ECALL##RISCV")
                self._verifyExceptionCount(ecall_except_code)
                exception_handlers_test_utils.assert_gpr_values_unchanged(
                    self, orig_gpr_values
                )
            else:
                self.error("Unexpected exception code: %d" % except_code)

    # Randomly configure some of the specified exception codes to be handled
    # at a lower privilege level.
    #
    #  @param aExceptCodes A list of exception codes for configuring
    #       delegation.
    def _configureExceptionDelegation(self, aExceptCodes):
        # Spike appears to only allow exception codes 0, 3, 8, 12, 13 and 15
        # to be delegated. The logic below harmlessly ignores this constraint
        # for simplicity and in case Spike's implementation changes in the
        # future. There does not appear to be any provisions in the RISCV
        # Privileged Architecture Specification that mandate such a
        # restrictive delegation scheme.
        medeleg_val = 0
        for except_code in aExceptCodes:
            medeleg_val |= RandomUtils.random32(0, 1) << except_code

        load_gpr64_seq = LoadGPR64(self.genThread)
        medeleg_val_reg_index = self.getRandomGPR(exclude="0")
        load_gpr64_seq.load(medeleg_val_reg_index, medeleg_val)

        # TODO(Noah): Uncomment the statement below when the medeleg
        #  register is usable; it currently has a specified size of 0.
        # self.genInstruction(
        #   'CSRRW#register#RISCV', {'rd': 0, 'rs1': medeleg_val_reg_index,
        #                            'csr': self.getRegisterIndex('medeleg')})

    # Switch to a random privilege level.
    def _switchToRandomPrivilegeLevel(self):
        self.genInstruction("MRET##RISCV")

    # Verify the exception count for the specified exception code has
    # increased.
    #
    #  @param aExceptCode The code of the exception that should have been
    #       triggered.
    def _verifyExceptionCount(self, aExceptCode):
        new_except_count = self.queryExceptionRecordsCount(aExceptCode)
        if new_except_count > self._mExceptCounts[aExceptCode]:
            self._mExceptCounts[aExceptCode] = new_except_count
        else:
            self.error(
                "An exception with code %d was not triggered" % aExceptCode
            )


MainSequenceClass = MainSequence
GenThreadClass = GenThreadRISCV
EnvClass = EnvRISCV
