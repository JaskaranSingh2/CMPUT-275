#include <stdio.h>

int main() {
  int x = 10;
  int *p = &x;
  int y = 5;
  printf("%d\n", x); // prints 10
  *p = -1; // Since ptr currently stores the address of x,
           // dereferencing it means "access the value at
           // that address, so it accesses the memory of x.
  printf("%d\n", x); // prints -1
  p = &y;
  *p = 20;
  printf("%d\n", x);
  printf("%d\n", y);
}
