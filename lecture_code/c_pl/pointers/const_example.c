#include <stdio.h>



int main() {
  int x = 5;
  // px is a pointer to a constant integer, I am NOT allowed to change
  // x THROUGH the pointer px, i.e. I can't say *px = ...;
  // HOWEVER, this is no way changes the original declaration of x, x itself
  // is still not const
  const int *px = &x;
  printf("%d\n", x);
  x = 10;
  printf("%d\n", x);
  *px = 15; // Compilation error!
  printf("%d\n", x);
}
