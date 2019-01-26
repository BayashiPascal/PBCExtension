// ============ PBCEXTENSION.H ================

#ifndef PBCEXTENSION_H
#define PBCEXTENSION_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// ================= Define ==================

// Return the number argument of a variadic function
#define __VA_NB_ARGS__(...) (sizeof((int[]){__VA_ARGS__})/sizeof(int))

#endif
