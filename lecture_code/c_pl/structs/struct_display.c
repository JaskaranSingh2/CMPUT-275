#include <stdio.h>

struct WhatAmI {
  char a, b;
  int x;
};

struct TwoChars {
  char a, b;
};

struct __attribute__((packed)) WhoAmI {
  char a, b;
  int x;
};

struct HowAmI {
  int x;
  char a, b;
};

void printCharBytes(char c) {
  unsigned char pow = 1 << 7;
  while (pow) {
    if (pow & c) {
      printf("1");
    } else {
      printf("0");
    }
    pow = pow >> 1;
  }
  printf("\n");
}

void printStruct(void *p, int size) {
  // This function takes a void * as a parameter - what is that?
  // void * literally means a pointer to void... so a pointer to
  // nothing. Which is a pretty meaningless concept.
  // So, a void * essentially has no purpose - and like a
  // null character which has no purpose the FACT that is has no
  // purpose is in fact its purpose.
  // Since a  void * itself is meaningless, that means we can never
  // actually have a "void *" so instead, a void * is meant to represent
  // a pointer that may actually point at ANYTHING!
  // We often use void *s to write functions that are /generic/, meaning
  // they can work over many types. Then the caller of the function
  // passes in a pointer to whatever data type they want and away
  // we go. However, the function needs some way to know what its working
  // with, or how it should do the thing it needs to do.
  // This function is meant to print out the bytes of a piece of data,
  // since the bytes of data are the same no matter what type it is,
  // this function only needs to know the pointer to the start of the data
  // and how many bytes long the data is, and then it can operate!


  // This function is actually quite easy, let's simply
  // treat our void * like it actually points at a character array
  // of length size, and just call printCharBytes on each of those
  // "characters" (characters in quotes, because they're not necessarily
  // characters, we don't know whats there, but we want to print bytes
  // anyways)
  char *t = p;
  for (int i = 0; i < size; ++i) {
    printCharBytes(t[i]);
  }
}

int main() {
  /*
  printCharBytes('\n');
  printCharBytes('A');
  printCharBytes('a');
  printCharBytes('\0');
  printCharBytes('0');
  */
  struct WhatAmI r;
  r.a = 'A';
  r.b = 'a';
  r.x = -2;
  printf("Printing WhatAmI struct\n");
  printStruct(&r, sizeof(r));

  struct TwoChars tc = {.a='0', .b = '1'};
  printf("Printing TwoChars struct\n");
  printStruct(&tc, sizeof(tc));
  struct WhoAmI q = {.a = 'a', .b = 'A', .x = -2};
  printf("Printing packed WhoAmI struct\n");
  printStruct(&q, sizeof(q));
  struct HowAmI h = {.x = -2, .a ='a', .b = 'A'};
  printf("Printing HowAmI struct with int first\n");
  printStruct(&h, sizeof(h));
}
