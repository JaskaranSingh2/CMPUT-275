#include <stdio.h>

void times2(int *p) {
  *p = 2**p;
}

int main() {
  int x = 5;
  int y = 20;
  printf("%p\n", &x);
  times2(&x);
  printf("%d\n", x);
  int *p = &x;
  // NOTE! This is undefined behaviour!
  // There are times I can add to a pointer, this
  // is not one of them!
  p = p+1;
  *p = -1;
  printf("%d\n", x);
  printf("%d\n", y);
}
