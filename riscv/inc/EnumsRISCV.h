//
// Copyright (C) [2020] Futurewei Technologies, Inc.
//
// FORCE-RISCV is licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR
// FIT FOR A PARTICULAR PURPOSE.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/*  !!! NOTICE !!!
    This file is automatically generated by the script: utils/enum_classes/create_enum_files.py
    Please do not modify this file manually.  Instead, modify the above mentioned script to re-generate this file.
*/

#ifndef Force_EnumsRISCV_H
#define Force_EnumsRISCV_H

#include <string>

namespace Force {


  /*!
    Register reservation group types
  */
  enum class ERegReserveGroup : unsigned char {
    GPR = 0,
    FPRSIMDR = 1,
    VECREG = 2,
    SystemRegister = 3,
  };
  extern unsigned char ERegReserveGroupSize;
  extern const std::string ERegReserveGroup_to_string(ERegReserveGroup in_enum); //!< Get string name for enum.
  extern ERegReserveGroup string_to_ERegReserveGroup(const std::string& in_str); //!< Get enum value for string name.
  extern ERegReserveGroup try_string_to_ERegReserveGroup(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char ERegReserveGroupBaseType; //!< Define a type name for the enum base data type.


  /*!
    Virtual memory translation regime types
  */
  enum class EVmRegimeType : unsigned char {
    M = 0,
    S = 1,
    HS = 2,
    VS = 3,
  };
  extern unsigned char EVmRegimeTypeSize;
  extern const std::string EVmRegimeType_to_string(EVmRegimeType in_enum); //!< Get string name for enum.
  extern EVmRegimeType string_to_EVmRegimeType(const std::string& in_str); //!< Get enum value for string name.
  extern EVmRegimeType try_string_to_EVmRegimeType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EVmRegimeTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Memory bank types
  */
  enum class EMemBankType : unsigned char {
    Default = 0,
  };
  extern unsigned char EMemBankTypeSize;
  extern const std::string EMemBankType_to_string(EMemBankType in_enum); //!< Get string name for enum.
  extern EMemBankType string_to_EMemBankType(const std::string& in_str); //!< Get enum value for string name.
  extern EMemBankType try_string_to_EMemBankType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EMemBankTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Virtual memory request types
  */
  enum class EVmContextParamType : unsigned char {
    MODE = 0,
    MPRV = 1,
    MPP = 2,
    SPP = 3,
    MXR = 4,
    SUM = 5,
    MBE = 6,
    SBE = 7,
    UBE = 8,
    TVM = 9,
  };
  extern unsigned char EVmContextParamTypeSize;
  extern const std::string EVmContextParamType_to_string(EVmContextParamType in_enum); //!< Get string name for enum.
  extern EVmContextParamType string_to_EVmContextParamType(const std::string& in_str); //!< Get enum value for string name.
  extern EVmContextParamType try_string_to_EVmContextParamType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EVmContextParamTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Branch condition types
  */
  enum class EBranchConditionType : unsigned char {
    BEQ = 0,
    BNE = 1,
    BLT = 2,
    BLTU = 3,
    BGE = 4,
    BGEU = 5,
    CBEQZ = 6,
    CBNEZ = 7,
  };
  extern unsigned char EBranchConditionTypeSize;
  extern const std::string EBranchConditionType_to_string(EBranchConditionType in_enum); //!< Get string name for enum.
  extern EBranchConditionType string_to_EBranchConditionType(const std::string& in_str); //!< Get enum value for string name.
  extern EBranchConditionType try_string_to_EBranchConditionType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EBranchConditionTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Page table entry attribute types
  */
  enum class EPteAttributeType : unsigned char {
    Address = 0,
    IGNORED = 1,
    RES0 = 2,
    SystemPage = 3,
    RSW = 4,
    DA = 5,
    G = 6,
    U = 7,
    X = 8,
    WR = 9,
    V = 10,
  };
  extern unsigned char EPteAttributeTypeSize;
  extern const std::string EPteAttributeType_to_string(EPteAttributeType in_enum); //!< Get string name for enum.
  extern EPteAttributeType string_to_EPteAttributeType(const std::string& in_str); //!< Get enum value for string name.
  extern EPteAttributeType try_string_to_EPteAttributeType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EPteAttributeTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Page granule types
  */
  enum class EPageGranuleType : unsigned char {
    G4K = 0,
  };
  extern unsigned char EPageGranuleTypeSize;
  extern const std::string EPageGranuleType_to_string(EPageGranuleType in_enum); //!< Get string name for enum.
  extern EPageGranuleType string_to_EPageGranuleType(const std::string& in_str); //!< Get enum value for string name.
  extern EPageGranuleType try_string_to_EPageGranuleType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EPageGranuleTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Paging mode
  */
  enum class EPagingMode : unsigned char {
    Bare = 0,
    Sv32 = 1,
    Sv39 = 2,
    Sv48 = 3,
    Sv32x4 = 4,
    Sv39x4 = 5,
    Sv48x4 = 6,
  };
  extern unsigned char EPagingModeSize;
  extern const std::string EPagingMode_to_string(EPagingMode in_enum); //!< Get string name for enum.
  extern EPagingMode string_to_EPagingMode(const std::string& in_str); //!< Get enum value for string name.
  extern EPagingMode try_string_to_EPagingMode(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EPagingModeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Boolean type GenPageRequest attributes for configuring page generation
  */
  enum class EPageGenBoolAttrType : unsigned char {
    FlatMap = 0,
    InstrAddr = 1,
    Regulated = 2,
    ViaException = 3,
    Privileged = 4,
    Atomic = 5,
    CanAlias = 6,
    ForceAlias = 7,
    ForceMemAttrs = 8,
    ForceNewAddr = 9,
    NoDataPageFault = 10,
    NoInstrPageFault = 11,
  };
  extern unsigned char EPageGenBoolAttrTypeSize;
  extern const std::string EPageGenBoolAttrType_to_string(EPageGenBoolAttrType in_enum); //!< Get string name for enum.
  extern EPageGenBoolAttrType string_to_EPageGenBoolAttrType(const std::string& in_str); //!< Get enum value for string name.
  extern EPageGenBoolAttrType try_string_to_EPageGenBoolAttrType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EPageGenBoolAttrTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Paging exception types.
  */
  enum class EPagingExceptionType : unsigned char {
    InstructionAccessFault = 0,
    LoadAccessFault = 1,
    StoreAmoAccessFault = 2,
    InstructionPageFault = 3,
    LoadPageFault = 4,
    StoreAmoPageFault = 5,
  };
  extern unsigned char EPagingExceptionTypeSize;
  extern const std::string EPagingExceptionType_to_string(EPagingExceptionType in_enum); //!< Get string name for enum.
  extern EPagingExceptionType string_to_EPagingExceptionType(const std::string& in_str); //!< Get enum value for string name.
  extern EPagingExceptionType try_string_to_EPagingExceptionType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EPagingExceptionTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Virtual memory constraint types.
  */
  enum class EVmConstraintType : unsigned char {
    Existing = 0,
    AddressError = 1,
    ReadOnly = 2,
    NoExecute = 3,
    PrivilegedNoExecute = 4,
    UnprivilegedNoExecute = 5,
    NoUserAccess = 6,
    PageTable = 7,
    UserAccess = 8,
    PageFault = 9,
    FlatMap = 10,
    AccessFault = 11,
    NoDataAccess = 12,
    NotAccessed = 13,
    NotDirty = 14,
  };
  extern unsigned char EVmConstraintTypeSize;
  extern const std::string EVmConstraintType_to_string(EVmConstraintType in_enum); //!< Get string name for enum.
  extern EVmConstraintType string_to_EVmConstraintType(const std::string& in_str); //!< Get enum value for string name.
  extern EVmConstraintType try_string_to_EVmConstraintType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EVmConstraintTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Exception level types
  */
  enum class EPrivilegeLevelType : unsigned char {
    U = 0,
    S = 1,
    H = 2,
    M = 3,
  };
  extern unsigned char EPrivilegeLevelTypeSize;
  extern const std::string EPrivilegeLevelType_to_string(EPrivilegeLevelType in_enum); //!< Get string name for enum.
  extern EPrivilegeLevelType string_to_EPrivilegeLevelType(const std::string& in_str); //!< Get enum value for string name.
  extern EPrivilegeLevelType try_string_to_EPrivilegeLevelType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EPrivilegeLevelTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Memory attribute implementation defined types
  */
  enum class EMemAttributeImplType : unsigned char {
    Unpredictable = 0,
  };
  extern unsigned char EMemAttributeImplTypeSize;
  extern const std::string EMemAttributeImplType_to_string(EMemAttributeImplType in_enum); //!< Get string name for enum.
  extern EMemAttributeImplType string_to_EMemAttributeImplType(const std::string& in_str); //!< Get enum value for string name.
  extern EMemAttributeImplType try_string_to_EMemAttributeImplType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EMemAttributeImplTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    System option types
  */
  enum class ESystemOptionType : unsigned char {
    PrivilegeLevel = 0,
    DisablePaging = 1,
    NoHandler = 2,
    NoSkip = 3,
    FlatMap = 4,
    MatchedHandler = 5,
    SkipBootCode = 6,
  };
  extern unsigned char ESystemOptionTypeSize;
  extern const std::string ESystemOptionType_to_string(ESystemOptionType in_enum); //!< Get string name for enum.
  extern ESystemOptionType string_to_ESystemOptionType(const std::string& in_str); //!< Get enum value for string name.
  extern ESystemOptionType try_string_to_ESystemOptionType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char ESystemOptionTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Types of exception classes.
  */
  enum class EExceptionClassType : unsigned char {
    InstrAddrMisaligned = 0,
    InstrAccessFault = 1,
    IllegalInstr = 2,
    Breakpoint = 3,
    LoadAddrMisaligned = 4,
    LoadAccessFault = 5,
    StoreAmoAddrMisaligned = 6,
    StoreAmoAccessFault = 7,
    EnvCallFromUMode = 8,
    EnvCallFromSMode = 9,
    EnvCallFromMMode = 11,
    InstrPageFault = 12,
    LoadPageFault = 13,
    StoreAmoPageFault = 15,
  };
  extern unsigned char EExceptionClassTypeSize;
  extern const std::string EExceptionClassType_to_string(EExceptionClassType in_enum); //!< Get string name for enum.
  extern EExceptionClassType string_to_EExceptionClassType(const std::string& in_str); //!< Get enum value for string name.
  extern EExceptionClassType try_string_to_EExceptionClassType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EExceptionClassTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Types of instruction groups.
  */
  enum class EInstructionGroupType : unsigned char {
    General = 0,
    Float = 1,
    System = 2,
    Vector = 3,
  };
  extern unsigned char EInstructionGroupTypeSize;
  extern const std::string EInstructionGroupType_to_string(EInstructionGroupType in_enum); //!< Get string name for enum.
  extern EInstructionGroupType string_to_EInstructionGroupType(const std::string& in_str); //!< Get enum value for string name.
  extern EInstructionGroupType try_string_to_EInstructionGroupType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EInstructionGroupTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    RISCV Extensions types for instructions.
  */
  enum class EInstructionExtensionType : unsigned char {
    Default = 0,
    RV32I = 1,
    RV64I = 2,
    RV32A = 3,
    RV64A = 4,
    RV32M = 5,
    RV64M = 6,
    RV32F = 7,
    RV64F = 8,
    RV32D = 9,
    RV64D = 10,
    RV32Q = 11,
    RV64Q = 12,
    Zicsr = 13,
    Zifencei = 14,
    RV32C = 15,
    RV64C = 16,
    RV128C = 17,
    RV64Priv = 18,
    RV32H = 19,
    RV64H = 20,
  };
  extern unsigned char EInstructionExtensionTypeSize;
  extern const std::string EInstructionExtensionType_to_string(EInstructionExtensionType in_enum); //!< Get string name for enum.
  extern EInstructionExtensionType string_to_EInstructionExtensionType(const std::string& in_str); //!< Get enum value for string name.
  extern EInstructionExtensionType try_string_to_EInstructionExtensionType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EInstructionExtensionTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Types of memory access ordering
  */
  enum class EMemOrderingType : unsigned char {
    Init = 0,
    Atomic = 1,
    AtomicRW = 2,
    Ordered = 3,
    LimitedOrdered = 4,
    OrderedRW = 5,
  };
  extern unsigned char EMemOrderingTypeSize;
  extern const std::string EMemOrderingType_to_string(EMemOrderingType in_enum); //!< Get string name for enum.
  extern EMemOrderingType string_to_EMemOrderingType(const std::string& in_str); //!< Get enum value for string name.
  extern EMemOrderingType try_string_to_EMemOrderingType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EMemOrderingTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Types of exception vector
  */
  enum class EExceptionVectorType : unsigned char {
    DefaultMachineModeVector = 0,
    DefaultSupervisorModeVector = 1,
  };
  extern unsigned char EExceptionVectorTypeSize;
  extern const std::string EExceptionVectorType_to_string(EExceptionVectorType in_enum); //!< Get string name for enum.
  extern EExceptionVectorType string_to_EExceptionVectorType(const std::string& in_str); //!< Get enum value for string name.
  extern EExceptionVectorType try_string_to_EExceptionVectorType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EExceptionVectorTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Types of System Operation
  */
  enum class ESystemOpType : unsigned char {
    None = 0,
  };
  extern unsigned char ESystemOpTypeSize;
  extern const std::string ESystemOpType_to_string(ESystemOpType in_enum); //!< Get string name for enum.
  extern ESystemOpType string_to_ESystemOpType(const std::string& in_str); //!< Get enum value for string name.
  extern ESystemOpType try_string_to_ESystemOpType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char ESystemOpTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Types of memory attributes for physical memory segments
  */
  enum class EMemoryAttributeType : unsigned char {
    MainRegion = 0,
    IORegion = 1,
    EmptyRegion = 2,
    LRSC = 3,
    AMONone = 4,
    AMOSwap = 5,
    AMOLogical = 6,
    AMOArithmetic = 7,
    AMOAligned = 8,
    AMOMisaligned = 9,
    RVWMO = 10,
    RVTSO = 11,
    RelaxedOrdering = 12,
    StrongOrderingChannel0 = 13,
    StrongOrderingChannel1 = 14,
    CoherentL1 = 15,
    CoherentL2 = 16,
    CoherentL3 = 17,
    Incoherent = 18,
    CacheableMasterPrivate = 19,
    CacheableShared = 20,
    CacheableSlavePrivate = 21,
    Uncacheable = 22,
    ReadIdempotent = 23,
    ReadNonIdempotent = 24,
    WriteIdempotent = 25,
    WriteNonIdempotent = 26,
  };
  extern unsigned char EMemoryAttributeTypeSize;
  extern const std::string EMemoryAttributeType_to_string(EMemoryAttributeType in_enum); //!< Get string name for enum.
  extern EMemoryAttributeType string_to_EMemoryAttributeType(const std::string& in_str); //!< Get enum value for string name.
  extern EMemoryAttributeType try_string_to_EMemoryAttributeType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EMemoryAttributeTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    VmInfo boolean attribute types (M should be the last one)
  */
  enum class EVmInfoBoolType : unsigned char {
    MODE = 1,
    MPRV = 2,
    TVM = 4,
  };
  extern unsigned char EVmInfoBoolTypeSize;
  extern const std::string EVmInfoBoolType_to_string(EVmInfoBoolType in_enum); //!< Get string name for enum.
  extern EVmInfoBoolType string_to_EVmInfoBoolType(const std::string& in_str); //!< Get enum value for string name.
  extern EVmInfoBoolType try_string_to_EVmInfoBoolType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EVmInfoBoolTypeBaseType; //!< Define a type name for the enum base data type.


  /*!
    Mechanism for determining vector register format
  */
  enum class EVectorLayoutType : unsigned char {
    Vtype = 0,
    FixedElementSize = 1,
    WholeRegister = 2,
  };
  extern unsigned char EVectorLayoutTypeSize;
  extern const std::string EVectorLayoutType_to_string(EVectorLayoutType in_enum); //!< Get string name for enum.
  extern EVectorLayoutType string_to_EVectorLayoutType(const std::string& in_str); //!< Get enum value for string name.
  extern EVectorLayoutType try_string_to_EVectorLayoutType(const std::string& in_str, bool& okay); //!< Try to get enum value for string name, set status to indicate if conversion successful. Return value is indeterminate on failure.
  typedef unsigned char EVectorLayoutTypeBaseType; //!< Define a type name for the enum base data type.

}

#endif
