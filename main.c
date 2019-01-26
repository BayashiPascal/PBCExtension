#include <stdlib.h>
#include <stdio.h>
#include "pbcextension.h"

int _TestVANbArgsInt(int nbArg, ...) {
  return nbArg;
}
#define TestVANbArgsInt(...) \
  (_TestVANbArgsInt(__VA_NB_ARGS__(int, __VA_ARGS__), __VA_ARGS__))

int _TestVANbArgsStr(int nbArg, ...) {
  return nbArg;
}
#define TestVANbArgsStr(...) \
  (_TestVANbArgsStr(__VA_NB_ARGS__(char*, __VA_ARGS__), __VA_ARGS__))

int _TestVANbArgsFloat(int nbArg, ...) {
  return nbArg;
}
#define TestVANbArgsFloat(...) \
  (_TestVANbArgsFloat(__VA_NB_ARGS__(float, __VA_ARGS__), __VA_ARGS__))

void UnitTestVANbArgs() {
  if (TestVANbArgsInt(1) != 1) {
    printf("UnitTestVANbArgs OK\n");
    exit(1);
  }
  if (TestVANbArgsStr("a", "b") != 2) {
    printf("UnitTestVANbArgs OK\n");
    exit(1);
  }
  if (TestVANbArgsFloat(1.0, 2.0, 3.0) != 3) {
    printf("UnitTestVANbArgs OK\n");
    exit(1);
  }
  printf("UnitTestVANbArgs OK\n");
}

void UnitTestAll() {
  UnitTestVANbArgs();
}

int main(void) {
  UnitTestAll();
  return 0;
}

