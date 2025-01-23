#include <stdio.h>

int main() {
  int x = 10;
  int y = 15;
  int *px = &x; // px is a pointer to x
  int *py = &y; // py is a pointer to y
  printf("x: %d - px: %p\n", x, px);
  printf("y: %d - py: %p\n", y, py);
  printf("*px: %d\n", *px);
  printf("*py: %d\n", *py);
  float *fpx = &x;
  printf("*fpx: %f\n", *fpx);
  int c = 18500;
  char *pc = &c;
  printf("c: %d - pc: %p\n", c, pc);
  printf("*pc: %c\n", *pc);
  printf("pc+1: %p\n", pc+1);
  printf("*(pc+1): %c\n", *(pc+1));
}
