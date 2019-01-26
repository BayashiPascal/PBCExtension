#include <stdlib.h>
#include <stdio.h>
#include "pbcextension.h"

int _TestVANbArgs(int nbArg, ...) {
  return nbArg;
}
#define TestVANbArgs(...) \
  (_TestVANbArgs(__VA_NB_ARGS__(__VA_ARGS__), __VA_ARGS__))
void UnitTestVANbArgs() {
  if (TestVANbArgs(1) != 1) {
    printf("UnitTestVANbArgs OK\n");
    exit(1);
  }
  if (TestVANbArgs(1, 2) != 2) {
    printf("UnitTestVANbArgs OK\n");
    exit(1);
  }
  if (TestVANbArgs(1, 2, 3) != 3) {
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

