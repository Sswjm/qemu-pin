#ifndef QEMU_PIN_OBJS_H
#define QEMU_PIN_OBJS_H

#include "types.h"

typedef struct la_opnd {
    int val;
} LA_OPND;

typedef struct qemu_pin_la_insn{
    LA_OPCODE op;
    LA_OPND opnd[4];
    int opnd_count;
} LA_INSN;

typedef struct qemu_pin_ins {
    uint64_t pc;
    uint32_t opcode;
    LA_INSN insn;

    struct qemu_pin_ins *prev;
    struct qemu_pin_ins *next;
} *INS;

typedef struct qemu_pin_bbl {
    uint64_t pc;
    int ins_count;
    INS ins_head;
    INS ins_tail;

    struct qemu_pin_bbl *prev;
    struct qemu_pin_bbl *next;
} *BBL;

typedef struct qemu_pin_trace {
    uint64_t pc;
    int nr_bbl;
    int nr_ins;

    BBL bbl_head;
    BBL bbl_tail;
} *TRACE;

INS create_INS(uint64_t pc);
BBL create_BBL(uint64_t pc);
TRACE create_TRACE(uint64_t pc);

#endif