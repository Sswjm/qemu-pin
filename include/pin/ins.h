#ifndef QEMU_PIN_INS_H
#define QEMU_PIN_INS_H

#include"pin/pin-types.h"

/* Ins Inspection API */

bool op_is_branch(LA_OPCODE opc);
bool op_is_direct_branch(LA_OPCODE opc);
bool op_is_indirect_branch(LA_OPCODE opc);
bool op_is_condition_branch(LA_OPCODE opc);
bool op_is_float_branch(LA_OPCODE opc);
bool op_is_syscall(LA_OPCODE opc);
bool op_is_ldst(LA_OPCODE opc);
bool op_is_load(LA_OPCODE opc);
bool op_is_store(LA_OPCODE opc);
bool op_is_float_load(LA_OPCODE opc);
bool op_is_float_store(LA_OPCODE opc);
bool op_is_am(LA_OPCODE opc);
bool op_is_ll(LA_OPCODE opc);
bool op_is_sc(LA_OPCODE opc);



#endif