#include <stdio.h>
#include <stdlib.h>
#include "pin-objs.h"

// initialize INS/BBL/TRACE

INS create_INS(uint64_t pc)
{
    INS ins = (INS)malloc(sizeof(struct qemu_pin_ins));

    ins->pc = pc;
    ins->opcode = 0;
    ins->insn.opnd_count = 0;
    ins->prev = NULL;
    ins->next = NULL;
}

BBL create_BBL(uint64_t pc)
{
    BBL bbl = (BBL)malloc(sizeof(struct qemu_pin_bbl));

    bbl->pc = pc;
    bbl->ins_count = 0;
    bbl->ins_head = NULL;
    bbl->ins_tail = NULL;
    bbl->prev = NULL;
    bbl->next = NULL;
}

TRACE create_TRACE(uint64_t pc)
{
    TRACE trace = (TRACE)malloc(sizeof(struct qemu_pin_trace));

    trace->pc = pc;
    trace->nr_bbl = 0;
    trace->nr_ins = 0;
    trace->bbl_head = NULL;
    trace->bbl_tail = NULL;
}