#ifndef QEMU_PIN_TYPES_H
#define QEMU_PIN_TYPES_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "opc.h"

typedef unsigned char BOOL;
typedef void VOID;
typedef char CHAR;
typedef unsigned int UINT;
typedef int INT;
typedef double FLT64;
typedef float FLT32;
typedef unsigned int USIZE;

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;

typedef UINT64 ADDRINT;
typedef INT64 ADDRDELTA;

typedef UINT16 OPCODE;

typedef VOID (*AFUNPTR)(void);

typedef uint32_t SYSCALL_STANDARD;

typedef enum LA_OPCODE LA_OPCODE;  // loongarch64 opcode
typedef enum IR2_OPND_TYPE LA_OPND_TYPE;

#endif