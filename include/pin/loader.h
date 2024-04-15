#ifndef LOADER_H
#define LOADER_H

#include "qapi/error.h"
#include "qemu/typedefs.h"

void qemu_pintool_opt_parse(const char *, Error **);

#endif