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
from riscv.AssemblyHelperRISCV import AssemblyHelperRISCV
from riscv.EnvRISCV import EnvRISCV
from riscv.GenThreadRISCV import GenThreadRISCV
from riscv.Utils import LoadGPR64


#  This test verifies the instructions generated by AssemblyHelperRISCV
#  yield the expected results.
class MainSequence(Sequence):
    def generate(self, **kargs):
        assembly_helper = AssemblyHelperRISCV(self)

        appRegSize = self.getGlobalState("AppRegisterWidth")

        if appRegSize == 32:
            self.notice("FORCE/RISCV configured for 32-bits...")
        else:
            self.notice("FORCE/RISCV configured for 64-bits...")

        # TODO(Noah): Test branch instruction generation methods

        (dest_reg_index, src_reg_index, src_reg_index_2) = self.getRandomGPRs(
            3, exclude="0"
        )
        load_gpr64_seq = LoadGPR64(self.genThread)

        src_reg_val = (
            RandomUtils.random32()
            if appRegSize == 32
            else RandomUtils.random64()
        )
        load_gpr64_seq.load(src_reg_index, src_reg_val)

        src_reg_val_2 = (
            RandomUtils.random32()
            if appRegSize == 32
            else RandomUtils.random64()
        )
        load_gpr64_seq.load(src_reg_index_2, src_reg_val_2)

        MAX_GPR_VAL = 0xFFFFFFFF if appRegSize == 32 else 0xFFFFFFFFFFFFFFFF

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genMoveImmediate(dest_reg_index, imm_val)
        dest_reg_val = imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        max_shift_val = 31 if appRegSize == 32 else 63

        shift_amount = RandomUtils.random32(0, max_shift_val)
        assembly_helper.genShiftLeftImmediate(dest_reg_index, shift_amount)
        dest_reg_val = (dest_reg_val << shift_amount) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        shift_amount = RandomUtils.random32(0, max_shift_val)
        assembly_helper.genShiftRightImmediate(dest_reg_index, shift_amount)
        dest_reg_val = (dest_reg_val >> shift_amount) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        shift_amount = RandomUtils.random32(0, max_shift_val)
        assembly_helper.genShiftLeftImmediate(
            dest_reg_index, shift_amount, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = (src_reg_val << shift_amount) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        shift_amount = RandomUtils.random32(0, max_shift_val)
        assembly_helper.genShiftRightImmediate(
            dest_reg_index, shift_amount, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = (src_reg_val >> shift_amount) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genAndImmediate(dest_reg_index, imm_val)
        dest_reg_val &= imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genAndImmediate(
            dest_reg_index, imm_val, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = src_reg_val & imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genOrImmediate(dest_reg_index, imm_val)
        dest_reg_val |= imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genOrImmediate(
            dest_reg_index, imm_val, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = src_reg_val | imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genXorImmediate(dest_reg_index, imm_val)
        dest_reg_val ^= imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genXorImmediate(
            dest_reg_index, imm_val, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = src_reg_val ^ imm_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genAddImmediate(dest_reg_index, imm_val)
        dest_reg_val = (dest_reg_val + imm_val) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        imm_val = RandomUtils.random32(0, 2047)
        assembly_helper.genAddImmediate(
            dest_reg_index, imm_val, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = (src_reg_val + imm_val) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genMoveRegister(dest_reg_index, src_reg_index)
        dest_reg_val = src_reg_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        # Reset destination register value after copying directly from source;
        # otherwise, the tests that follow will be less interesting
        dest_reg_val = (
            RandomUtils.random32()
            if appRegSize == 32
            else RandomUtils.random64()
        )
        load_gpr64_seq.load(dest_reg_index, dest_reg_val)

        assembly_helper.genAndRegister(dest_reg_index, src_reg_index)
        dest_reg_val &= src_reg_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genAndRegister(
            dest_reg_index, src_reg_index, aSrcRegIndex2=src_reg_index_2
        )
        dest_reg_val = src_reg_val_2 & src_reg_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genOrRegister(dest_reg_index, src_reg_index)
        dest_reg_val |= src_reg_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genOrRegister(
            dest_reg_index, src_reg_index, aSrcRegIndex2=src_reg_index_2
        )
        dest_reg_val = src_reg_val_2 | src_reg_val
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genNotRegister(dest_reg_index)
        dest_reg_val = ~dest_reg_val & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genNotRegister(
            dest_reg_index, aSrcRegIndex=src_reg_index
        )
        dest_reg_val = ~src_reg_val & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genAddRegister(dest_reg_index, src_reg_index)
        dest_reg_val = (dest_reg_val + src_reg_val) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genAddRegister(
            dest_reg_index, src_reg_index, aSrcRegIndex2=src_reg_index_2
        )
        dest_reg_val = (src_reg_val_2 + src_reg_val) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genSubRegister(dest_reg_index, src_reg_index)
        dest_reg_val = (dest_reg_val - src_reg_val) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genSubRegister(
            dest_reg_index, src_reg_index, aMinuendRegIndex=src_reg_index_2
        )
        dest_reg_val = (src_reg_val_2 - src_reg_val) & MAX_GPR_VAL
        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genReadSystemRegister(dest_reg_index, "mscratch")
        (dest_reg_val, valid) = self.readRegister("mscratch")
        if not valid:
            self.error("Value for register mscratch is invalid")

        exception_handlers_test_utils.assert_gpr_has_value(
            self, dest_reg_index, dest_reg_val
        )

        assembly_helper.genWriteSystemRegister("mscratch", src_reg_index)
        (mscratch_val, valid) = self.readRegister("mscratch")
        if not valid:
            self.error("Value for register mscratch is invalid")

        if mscratch_val != src_reg_val:
            self.error(
                "Value of register mscratch did not match the expected "
                "value. Expected=0x%x, Actual=0x%x"
                % (src_reg_val, mscratch_val)
            )


MainSequenceClass = MainSequence
GenThreadClass = GenThreadRISCV
EnvClass = EnvRISCV
