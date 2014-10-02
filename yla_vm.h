/*
    Virtual Machine

    This file is part of YLA VM (Yet another Language for Academic purpose: Virtual Machine).

    YLA VM is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef _yla_vm_h
#define _yla_vm_h

#include "yla_stack.h"

#define MAGIC_SIZE 3
#define MAGIC_CODE1 0x796c
#define MAGIC_CODE2 0x615f
#define MAGIC_CODE3 0x766d

#define HEADER_SIZE ((MAGIC_SIZE + 3) * sizeof(yla_stack_type))
#define MAX_CODE_SIZE 65536
#define MAX_STACK_SIZE 65536
#define MAX_VARTABLE_SIZE 65536

#define ERROR_OK 0
#define ERROR_NO_PROGRAM_CODE 1
#define ERROR_CODE_SEG_EXCEED 2
#define ERROR_DIV_BY_ZERO 3
#define ERROR_UNKNOWN_COMMAND 4

/*
Executable program structure:
magic1: yla_stack_type
magic2: yla_stack_type
magic3: yla_stack_type
stack_size: yla_stack_type
vartable_size: yla_stack_type
code_size: yla_stack_type
code: array of char
*/

/**
 * structure contains all internal data of virtual machine
 */
typedef struct {
	yla_stack stack;
	size_t stack_size;

	unsigned char *code;
	size_t code_size;

	yla_stack_type *vartable;
    size_t vartable_size;

	size_t pc;

	int last_error;
} yla_vm;

/*
TODO: move this structure on implementation level
*/

/**
 * Initialize virtual machine with block of program
 **/
int yla_vm_init(yla_vm *vm, unsigned char *program, size_t program_size);

/**
 * Deinitialize virtual machine. 
 * Calling this function after run required
 **/ 
int yla_vm_done(yla_vm *vm);

/**
 * Run program from current place to halt
 **/
int yla_vm_run(yla_vm *vm);

/**
 * Make only one step (perform one command)
 */ 
int yla_vm_do_command(yla_vm *vm);

/*
TODO: Add/Remove breakpoints
*/

#endif
