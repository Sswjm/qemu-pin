#ifndef QEMU_PIN_DS_H
#define QEMU_PIN_DS_H

#include"qemu/qemu-plugin.h"
#include"pin/pin-types.h"

typedef struct la_opnd {
    int val;
} LA_OPND;

typedef struct qemu_pin_la_insn{
    LA_OPCODE op;
    LA_OPND opnd[4];
    int opnd_count;
} LA_INSN;

typedef struct qemu_pin_ins {
    struct qemu_pin_ins *prev;
    struct qemu_pin_ins *next;

    uint64_t pc;
    uint32_t opcode;
    LA_INSN insn;
} *INS;

typedef struct qemu_pin_bbl {
    struct qemu_pin_bbl *prev;
    struct qemu_pin_bbl *next;

    uint64_t pc;
    int nr_ins;
    INS ins_head;
    INS ins_tail;
} *BBL;

typedef struct qemu_pin_trace {
    uint64_t pc;
    int nr_bbl;
    int nr_ins;

    BBL bbl_head;
    BBL bbl_tail;
} *TRACE;

void tr_init(void *);
void tr_fini(void);
#endif PIN_DS_H