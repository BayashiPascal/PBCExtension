#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pbcextension.h"
#include <time.h>

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
    printf("UnitTestVANbArgs NOK\n");
    exit(1);
  }
  if (TestVANbArgsStr("a", "b") != 2) {
    printf("UnitTestVANbArgs NOK\n");
    exit(1);
  }
  if (TestVANbArgsFloat(1.0, 2.0, 3.0) != 3) {
    printf("UnitTestVANbArgs NOK\n");
    exit(1);
  }
  printf("UnitTestVANbArgs OK\n");
}

void UnitTestSwap() {
  long a, b;
  long n = 10000;
  clock_t start = clock();
  for (long i = 0; i < n; ++i) {
    for (long j = 0; j < n; ++j) {
      a = i;
      b = j;
      swap(a, b);
      if (memcmp(&a, &j, sizeof(a)) != 0 || 
        memcmp(&b, &i, sizeof(b)) != 0) {
        printf("UnitTestSwap NOK\n");
        exit(1);
      }
    }
  }
  clock_t end = clock();
  float delay = (float)(end - start) * 1000.0 / (float)CLOCKS_PER_SEC;
  printf("UnitTestSwap OK, %fms\n", delay);
}

void UnitTestSGRString() {
  
  char* hello = "Hello\nThis is a test that should appear blinking, underline, bold, in red on blue";
  char* sgrHello = 
    SGRString(
      SGR_SlowBlink(
      SGR_Underline(
      SGR_Bold(
      SGR_ColorFG(255, 00, 0, 
      SGR_ColorBG(0, 0, 255, hello))))));
  printf("%s\n", sgrHello);
  free(sgrHello);

  printf("UnitTestSGRString OK\n");
}

void UnitTestAll() {
  UnitTestVANbArgs();
  UnitTestSwap();
  UnitTestSGRString();
}

int main(void) {
  UnitTestAll();
  return 0;
}

