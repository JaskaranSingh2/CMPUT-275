#include <stdio.h>
// Complete next class
int print_binary(unsigned int x) {
  if (x == 0) {
    printf("0");
    return 0;
  }
  int curPow = 1;
  while (curPow <= x) {
    curPow = curPow*2;
  }
  // Once I've reached the end of this loop,
  // curPow is the first power of two larger than x.
  // e.g. if x is the number 1011101
  // then curPow would be   10000000
  // If we then divide curPow by 2 (shift it right once)
  // Then it will be the first power of two that is in our
  // number!
  curPow = curPow / 2;
  while (curPow > 0) {
    if (curPow <= x) {
      printf("1");
      x = x - curPow;
    }
    else {
      printf("0");
    }
    curPow = curPow/2;
  }
  printf("\n");
}

int main() {
  print_binary(5);
  print_binary(10);
  print_binary(16);
  print_binary(43821);
}
