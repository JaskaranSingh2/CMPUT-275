#include <stdio.h>

struct WhatAmI {
  char a, b;
  int x;
};

struct twoChars {
  char a, b;
};
struct __attribute__((packed)) WhoAmI {
  char a, b;
  int x;
};

int main() {
  struct WhatAmI z;
  printf("%lu\n", sizeof(z));
  struct twoChars p;
  printf("%lu\n", sizeof(p));
  struct WhoAmI t;
  printf("%lu\n", sizeof(t));
}
