// Copyright 2024-2024 Nikita Fediuchin. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/***********************************************************************************************************************
 * @file
 * @brief Plan language instruction set.
 */

#pragma once
#include <cstdint>

namespace plan
{

/**
 * @brief Plan assembly instruction set. (Opcodes)
 */
enum class Instruction : uint8_t
{
	Noop, /**< Does nothing, and continues the execution. (No operation) */
	Exit, /**< Exits program. (Stops program execution) */

	// Data Transfer Instructions

	Alloc, /**< Allocate X bytes of memory from the heap. */
	Free,  /**< Frees X bytes of memory from the heap. */

	Mov,    /**< Moves X bytes from the one stack address to the another. (Xbit) */
	Mov8,   /**< Moves 1 byte from the one stack address to the another. (8bit) */
	Mov16,  /**< Moves 2 bytes from the one stack address to the another. (16bit) */
	Mov32,  /**< Moves 4 bytes from the one stack address to the another. (32bit) */
	Mov64,  /**< Moves 8 bytes from the one stack address to the another. (64bit) */
	Mov128, /**< Moves 16 bytes from the one stack address to the another. (128bit) */
	Mov256, /**< Moves 32 bytes from the one stack address to the another. (256bit) */
	Mov512, /**< Moves 64 bytes from the one stack address to the another. (512bit) */

	Load,    /**< Loads X bytes from the heap memory to the stack. (Xbit) */
	Load8,   /**< Loads 1 byte from the heap memory to the stack. (8bit) */
	Load16,  /**< Loads 2 bytes from the heap memory to the stack. (16bit) */
	Load32,  /**< Loads 4 bytes from the heap memory to the stack. (32bit) */
	Load64,  /**< Loads 8 bytes from the heap memory to the stack. (64bit) */
	Load128, /**< Loads 16 bytes from the heap memory to the stack. (128bit) */
	Load256, /**< Loads 32 bytes from the heap memory to the stack. (256bit) */
	Load512, /**< Loads 64 bytes from the heap memory to the stack. (512bit) */

	Store,    /**< Stores X bytes from the stack memory to the heap. (Xbit) */
	Store8,   /**< Stores 1 byte from the stack memory to the heap. (8bit) */
	Store16,  /**< Stores 2 bytes from the stack memory to the heap. (16bit) */
	Store32,  /**< Stores 4 bytes from the stack memory to the heap. (32bit) */
	Store64,  /**< Stores 8 bytes from the stack memory to the heap. (64bit) */
	Store128, /**< Stores 16 bytes from the stack memory to the heap. (128bit) */
	Store256, /**< Stores 32 bytes from the stack memory to the heap. (256bit) */
	Store512, /**< Stores 64 bytes from the stack memory to the heap. (512bit) */

	Push,    /**< Pushes X bytes to the stack. (Xbit) */
	Push0,   /**< Pushes X zeroed bytes to the stack. (Xbit) */
	Push8,   /**< Pushes 1 byte to the stack. (8bit) */
	Push16,  /**< Pushes 2 bytes to the stack. (16bit) */
	Push32,  /**< Pushes 4 bytes to the stack. (32bit) */
	Push64,  /**< Pushes 8 bytes to the stack. (64bit) */
	Push128, /**< Pushes 16 bytes to the stack. (128bit) */
	Push256, /**< Pushes 32 bytes to the stack. (256bit) */
	Push512, /**< Pushes 64 bytes to the stack. (512bit) */

	Pop,    /**< Pops X bytes from the stack. (Xbit) */
	Pop8,   /**< Pops 1 byte from the stack. (8bit) */
	Pop16,  /**< Pops 2 bytes from the stack. (16bit) */
	Pop32,  /**< Pops 4 bytes from the stack. (32bit) */
	Pop64,  /**< Pops 8 bytes from the stack. (64bit) */
	Pop128, /**< Pops 16 bytes from the stack. (128bit) */
	Pop256, /**< Pops 32 bytes from the stack. (256bit) */
	Pop512, /**< Pops 64 bytes from the stack. (512bit) */

	// Arithmetic Instructions

	AddU8,  /**< Adds one 8bit unsigned integer value to the another. (op: +) */
	AddU16, /**< Adds one 16bit unsigned integer value to the another. (op: +) */
	AddU32, /**< Adds one 32bit unsigned integer value to the another. (op: +) */
	AddU64, /**< Adds one 64bit unsigned integer value to the another. (op: +) */
	AddI8,  /**< Adds one 8bit signed integer value to the another. (op: +) */
	AddI16, /**< Adds one 16bit signed integer value to the another. (op: +) */
	AddI32, /**< Adds one 32bit signed integer value to the another. (op: +) */
	AddI64, /**< Adds one 64bit signed integer value to the another. (op: +) */
	AddF32, /**< Adds one 32bit floating point value to the another. (op: +) */
	AddF64, /**< Adds one 64bit floating point value to the another. (op: +) */

	SubU8,  /**< Subtracts one 8bit unsigned integer value from the another. (op: -) */
	SubU16, /**< Subtracts one 16bit unsigned integer value from the another. (op: -) */
	SubU32, /**< Subtracts one 32bit unsigned integer value from the another. (op: -) */
	SubU64, /**< Subtracts one 64bit unsigned integer value from the another. (op: -) */
	SubI8,  /**< Subtracts one 8bit signed integer value from the another. (op: -) */
	SubI16, /**< Subtracts one 16bit signed integer value from the another. (op: -) */
	SubI32, /**< Subtracts one 32bit signed integer value from the another. (op: -) */
	SubI64, /**< Subtracts one 64bit signed integer value from the another. (op: -) */
	SubF32, /**< Subtracts one 32bit floating point value from the another. (op: -) */
	SubF64, /**< Subtracts one 64bit floating point value from the another. (op: -) */

	MulU8,  /**< Multiplies one 8bit unsigned integer value by the another. (op: *) */
	MulU16, /**< Multiplies one 16bit unsigned integer value by the another. (op: *) */
	MulU32, /**< Multiplies one 32bit unsigned integer value by the another. (op: *) */
	MulU64, /**< Multiplies one 64bit unsigned integer value by the another. (op: *) */
	MulI8,  /**< Multiplies one 8bit signed integer value by the another. (op: *) */
	MulI16, /**< Multiplies one 16bit signed integer value by the another. (op: *) */
	MulI32, /**< Multiplies one 32bit signed integer value by the another. (op: *) */
	MulI64, /**< Multiplies one 64bit signed integer value by the another. (op: *) */
	MulF32, /**< Multiplies one 32bit floating point value by the another. (op: *) */
	MulF64, /**< Multiplies one 64bit floating point value by the another. (op: *) */

	DivU8,  /**< Divides one 8bit unsigned integer value by the another. (op: /) */
	DivU16, /**< Divides one 16bit unsigned integer value by the another. (op: /) */
	DivU32, /**< Divides one 32bit unsigned integer value by the another. (op: /) */
	DivU64, /**< Divides one 64bit unsigned integer value by the another. (op: /) */
	DivI8,  /**< Divides one 8bit signed integer value by the another. (op: /) */
	DivI16, /**< Divides one 16bit signed integer value by the another. (op: /) */
	DivI32, /**< Divides one 32bit signed integer value by the another. (op: /) */
	DivI64, /**< Divides one 64bit signed integer value by the another. (op: /) */
	DivF32, /**< Divides one 32bit floating point value by the another. (op: /) */
	DivF64, /**< Divides one 64bit floating point value by the another. (op: /) */

	AddU8V,  /**< Adds one 8bit unsigned integer value to the another. (op: +) */
	AddU16V, /**< Adds one 16bit unsigned integer value to the another. (op: +) */
	AddU32V, /**< Adds one 32bit unsigned integer value to the another. (op: +) */
	AddU64V, /**< Adds one 64bit unsigned integer value to the another. (op: +) */
	AddI8V,  /**< Adds one 8bit signed integer value to the another. (op: +) */
	AddI16V, /**< Adds one 16bit signed integer value to the another. (op: +) */
	AddI32V, /**< Adds one 32bit signed integer value to the another. (op: +) */
	AddI64V, /**< Adds one 64bit signed integer value to the another. (op: +) */
	AddF32V, /**< Adds one 32bit floating point value to the another. (op: +) */
	AddF64V, /**< Adds one 64bit floating point value to the another. (op: +) */

	SubU8V,  /**< Subtracts one 8bit unsigned integer value from the another. (op: -) */
	SubU16V, /**< Subtracts one 16bit unsigned integer value from the another. (op: -) */
	SubU32V, /**< Subtracts one 32bit unsigned integer value from the another. (op: -) */
	SubU64V, /**< Subtracts one 64bit unsigned integer value from the another. (op: -) */
	SubI8V,  /**< Subtracts one 8bit signed integer value from the another. (op: -) */
	SubI16V, /**< Subtracts one 16bit signed integer value from the another. (op: -) */
	SubI32V, /**< Subtracts one 32bit signed integer value from the another. (op: -) */
	SubI64V, /**< Subtracts one 64bit signed integer value from the another. (op: -) */
	SubF32V, /**< Subtracts one 32bit floating point value from the another. (op: -) */
	SubF64V, /**< Subtracts one 64bit floating point value from the another. (op: -) */

	MulU8V,  /**< Multiplies one 8bit unsigned integer value by the another. (op: *) */
	MulU16V, /**< Multiplies one 16bit unsigned integer value by the another. (op: *) */
	MulU32V, /**< Multiplies one 32bit unsigned integer value by the another. (op: *) */
	MulU64V, /**< Multiplies one 64bit unsigned integer value by the another. (op: *) */
	MulI8V,  /**< Multiplies one 8bit signed integer value by the another. (op: *) */
	MulI16V, /**< Multiplies one 16bit signed integer value by the another. (op: *) */
	MulI32V, /**< Multiplies one 32bit signed integer value by the another. (op: *) */
	MulI64V, /**< Multiplies one 64bit signed integer value by the another. (op: *) */
	MulF32V, /**< Multiplies one 32bit floating point value by the another. (op: *) */
	MulF64V, /**< Multiplies one 64bit floating point value by the another. (op: *) */

	DivU8V,  /**< Divides one 8bit unsigned integer value by the another. (op: /) */
	DivU16V, /**< Divides one 16bit unsigned integer value by the another. (op: /) */
	DivU32V, /**< Divides one 32bit unsigned integer value by the another. (op: /) */
	DivU64V, /**< Divides one 64bit unsigned integer value by the another. (op: /) */
	DivI8V,  /**< Divides one 8bit signed integer value by the another. (op: /) */
	DivI16V, /**< Divides one 16bit signed integer value by the another. (op: /) */
	DivI32V, /**< Divides one 32bit signed integer value by the another. (op: /) */
	DivI64V, /**< Divides one 64bit signed integer value by the another. (op: /) */
	DivF32V, /**< Divides one 32bit floating point value by the another. (op: /) */
	DivF64V, /**< Divides one 64bit floating point value by the another. (op: /) */

	IncU8,   /**< Increments 8bit unsigned integer value by one. (op: ++) */
	IncU16,  /**< Increments 16bit unsigned integer value by one. (op: ++) */
	IncU32,  /**< Increments 32bit unsigned integer value by one. (op: ++) */
	IncU64,  /**< Increments 64bit unsigned integer value by one. (op: ++) */
	IncI8,   /**< Increments 8bit signed integer value by one. (op: ++) */
	IncI16,  /**< Increments 16bit signed integer value by one. (op: ++) */
	IncI32,  /**< Increments 32bit signed integer value by one. (op: ++) */
	IncI64,  /**< Increments 64bit signed integer value by one. (op: ++) */

	DecU8,   /**< Decrements 8bit unsigned integer value by one. (op: --) */
	DecU16,  /**< Decrements 16bit unsigned integer value by one. (op: --) */
	DecU32,  /**< Decrements 32bit unsigned integer value by one. (op: --) */
	DecU64,  /**< Decrements 64bit unsigned integer value by one. (op: --) */
	DecI8,   /**< Decrements 8bit signed integer value by one. (op: --) */
	DecI16,  /**< Decrements 16bit signed integer value by one. (op: --) */
	DecI32,  /**< Decrements 32bit signed integer value by one. (op: --) */
	DecI64,  /**< Decrements 64bit signed integer value by one. (op: --) */

	// Logical Instructions

	And8,   /**< ANDs two 8bit binary values. (op: &) */
	And16,  /**< ANDs two 16bit binary values. (op: &) */
	And32,  /**< ANDs two 32bit binary values. (op: &) */
	And64,  /**< ANDs two 64bit binary values. (op: &) */

	Or8,    /**< ORs two 8bit binary values. (op: |) */
	Or16,   /**< ORs two 16bit binary values. (op: |) */
	Or32,   /**< ORs two 32bit binary values. (op: |) */
	Or64,   /**< ORs two 64bit binary values. (op: |) */

	Xor8,   /**< XORs two 8bit binary values. (op: ^) */
	Xor16,  /**< XORs two 16bit binary values. (op: ^) */
	Xor32,  /**< XORs two 32bit binary values. (op: ^) */
	Xor64,  /**< XORs two 64bit binary values. (op: ^) */

	Not8,   /**< NOTs two 8bit binary values. (op: !) */
	Not16,  /**< NOTs two 16bit binary values. (op: !) */
	Not32,  /**< NOTs two 32bit binary values. (op: !) */
	Not64,  /**< NOTs two 64bit binary values. (op: !) */

	And8V,   /**< ANDs two 8bit binary values. (op: &) */
	And16V,  /**< ANDs two 16bit binary values. (op: &) */
	And32V,  /**< ANDs two 32bit binary values. (op: &) */
	AndU64V, /**< ANDs two 64bit binary values. (op: &) */

	Or8V,    /**< ORs two 8bit binary values. (op: |) */
	Or16V,   /**< ORs two 16bit binary values. (op: |) */
	Or32V,   /**< ORs two 32bit binary values. (op: |) */
	Or64V,   /**< ORs two 64bit binary values. (op: |) */

	Xor8V,   /**< XORs two 8bit binary values. (op: ^) */
	Xor16V,  /**< XORs two 16bit binary values. (op: ^) */
	Xor32V,  /**< XORs two 32bit binary values. (op: ^) */
	Xor64V,  /**< XORs two 64bit binary values. (op: ^) */

	Not8V,   /**< NOTs two 8bit binary values. (op: !) */
	Not16V,  /**< NOTs two 16bit binary values. (op: !) */
	Not32V,  /**< NOTs two 32bit binary values. (op: !) */
	Not64V,  /**< NOTs two 64bit binary values. (op: !) */

	// Shift Instructions

	Shl8,  /**< Shifts left 8bit binary value. (op: <<) */
	Shl16, /**< Shifts left 16bit binary value. (op: <<) */
	Shl32, /**< Shifts left 32bit binary value. (op: <<) */
	Shl64, /**< Shifts left 64bit binary value. (op: <<) */

	Shr8,  /**< Shifts right 8bit binary value. (op: >>) */
	Shr16, /**< Shifts right 16bit binary value. (op: >>) */
	Shr32, /**< Shifts right 32bit binary value. (op: >>) */
	Shr64, /**< Shifts right 64bit binary value. (op: >>) */

	Shl8V,  /**< Shifts left 8bit binary value. (op: <<) */
	Shl16V, /**< Shifts left 16bit binary value. (op: <<) */
	Shl32V, /**< Shifts left 32bit binary value. (op: <<) */
	Shl64V, /**< Shifts left 64bit binary value. (op: <<) */

	Shr8V,  /**< Shifts right 8bit binary value. (op: >>) */
	Shr16V, /**< Shifts right 16bit binary value. (op: >>) */
	Shr32V, /**< Shifts right 32bit binary value. (op: >>) */
	Shr64V, /**< Shifts right 64bit binary value. (op: >>) */

	// Control Instructions

	Call, /**< Calls external system function. */
	Jmp,  /**< Unconditionally jumps to the program address. */

	JmpE,     /**< Conditionally jumps if two Xbit binary values are equal. (X bytes) */
	JmpE8,    /**< Conditionally jumps if two 8bit binary values are equal. (1 byte) */
	JmpE16,   /**< Conditionally jumps if two 16bit binary values are equal. (2 bytes) */
	JmpE32,   /**< Conditionally jumps if two 32bit binary values are equal. (4 bytes) */
	JmpE64,   /**< Conditionally jumps if two 64bit binary values are equal. (8 bytes) */
	JmpE128,  /**< Conditionally jumps if two 128bit binary values are equal. (16 bytes) */
	JmpE256,  /**< Conditionally jumps if two 256bit binary values are equal. (32 bytes) */
	JmpE512,  /**< Conditionally jumps if two 612bit binary values are equal. (64 bytes) */

	JmpNE,    /**< Conditionally jumps if two Xbit binary values are not equal. (X bytes) */
	JmpNE8,   /**< Conditionally jumps if two 8bit binary values are not equal. (1 byte) */
	JmpNE16,  /**< Conditionally jumps if two 16bit binary values are not equal. (2 bytes) */
	JmpNE32,  /**< Conditionally jumps if two 32bit binary values are not equal. (4 bytes) */
	JmpNE64,  /**< Conditionally jumps if two 64bit binary values are not equal. (8 bytes) */
	JmpNE128, /**< Conditionally jumps if two 128bit binary values are not equal. (16 bytes) */
	JmpNE256, /**< Conditionally jumps if two 256bit binary values are not equal. (32 bytes) */
	JmpNE512, /**< Conditionally jumps if two 612bit binary values are not equal. (64 bytes) */

	JmpL,     /**< Conditionally jumps if one Xbit binary value is less than the another. (X bytes) */
	JmpL8,    /**< Conditionally jumps if one 8bit binary value is less than the another. (1 byte) */
	JmpL16,   /**< Conditionally jumps if one 16bit binary value is less than the another. (2 bytes) */
	JmpL32,   /**< Conditionally jumps if one 32bit binary value is less than the another. (4 bytes) */
	JmpL64,   /**< Conditionally jumps if one 64bit binary value is less than the another. (8 bytes) */
	JmpL128,  /**< Conditionally jumps if one 128bit binary value is less than the another. (16 bytes) */
	JmpL256,  /**< Conditionally jumps if one 256bit binary value is less than the another. (32 bytes) */
	JmpL512,  /**< Conditionally jumps if one 512bit binary value is less than the another. (64 bytes) */

	JmpLE,    /**< Conditionally jumps if one Xbit binary value is less or equal to the another. (X bytes) */
	JmpLE8,   /**< Conditionally jumps if one 8bit binary value is less or equal to the another. (1 byte) */
	JmpLE16,  /**< Conditionally jumps if one 16bit binary value is less or equal to the another. (2 bytes) */
	JmpLE32,  /**< Conditionally jumps if one 32bit binary value is less or equal to the another. (4 bytes) */
	JmpLE64,  /**< Conditionally jumps if one 64bit binary value is less or equal to the another. (8 bytes) */
	JmpLE128, /**< Conditionally jumps if one 128bit binary value is less or equal to the another. (16 bytes) */
	JmpLE256, /**< Conditionally jumps if one 256bit binary value is less or equal to the another. (32 bytes) */
	JmpLE512, /**< Conditionally jumps if one 512bit binary value is less or equal to the another. (64 bytes) */

	JmpG,     /**< Conditionally jumps if one Xbit binary value is greater than the another. (X bytes) */
	JmpG8,    /**< Conditionally jumps if one 8bit binary value is greater than the another. (1 byte) */
	JmpG16,   /**< Conditionally jumps if one 16bit binary value is greater than the another. (2 bytes) */
	JmpG32,   /**< Conditionally jumps if one 32bit binary value is greater than the another. (4 bytes) */
	JmpG64,   /**< Conditionally jumps if one 64bit binary value is greater than the another. (8 bytes) */
	JmpG128, /**< Conditionally jumps if one 128bit binary value is greater than the another. (16 bytes) */
	JmpG256,  /**< Conditionally jumps if one 256bit binary value is greater than the another. (32 bytes) */
	JmpG512,  /**< Conditionally jumps if one 512bit binary value is greater than the another. (64 bytes) */

	JmpGE,    /**< Conditionally jumps if one Xbit binary value is greater or equal to the another. (X bytes) */
	JmpGE8,   /**< Conditionally jumps if one 8bit binary value is greater or equal to the another. (1 byte) */
	JmpGE16,  /**< Conditionally jumps if one 16bit binary value is greater or equal to the another. (2 bytes) */
	JmpGE32,  /**< Conditionally jumps if one 32bit binary value is greater or equal to the another. (4 bytes) */
	JmpGE64,  /**< Conditionally jumps if one 64bit binary value is greater or equal to the another. (8 bytes) */
	JmpGE128, /**< Conditionally jumps if one 128bit binary value is greater or equal to the another. (16 bytes) */
	JmpGE256, /**< Conditionally jumps if one 256bit binary value is greater or equal to the another. (32 bytes) */
	JmpGE512, /**< Conditionally jumps if one 512bit binary value is greater or equal to the another. (64 bytes) */

	Vec,   /**< Executes vector instrucion. */
	Math,  /**< Executes math instrucion. (Trigonometric, etc.) */
	Ext,   /**< Executes custom instruction. */
	Break, /**< Triggers a break point. (Stops execution when debugging) */
	Count  /**< Total Plan assembly instruction count. */
};

} // namespace plan