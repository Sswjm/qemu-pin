#ifndef QEMU_PIN_DS_H
#define QEMU_PIN_DS_H

#include"qemu/qemu-plugin.h"



typedef struct qemu_pin_INS {
    
} INS;

typedef struct qemu_pin_BBL {

} BBL;

typedef struct qemu_pin_TRACE {

} TRACE;

void tr_init(void *);
void tr_fini(void);
#endif PIN_DS_H