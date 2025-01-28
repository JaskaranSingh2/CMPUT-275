#include <stdio.h>

int main() {
  int x = 5;
  int *p = &x;
  p[0] = 10; // *(p+0) = 10
  printf("%d\n", x);
  *(p+0) = 12;
  printf("%d\n", x);
}
