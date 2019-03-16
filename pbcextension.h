// ============ PBCEXTENSION.H ================

#ifndef PBCEXTENSION_H
#define PBCEXTENSION_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// ================= Define ==================

// Return the number of arguments of a variadic function given
// the type 'Type' of these arguments
#define __VA_NB_ARGS__(Type, ...) \
  (sizeof((Type[]){__VA_ARGS__})/sizeof(Type))

// Macro to swap two variables
#define swap(a, b) do {char c[sizeof(a)]; memcpy(c, &a, sizeof(a)); \
    a = b; memcpy(&b, c, sizeof(a));} while(0)

#endif
