#include <stdio.h>

int main(int argc, char **argv) {
  int x = 10;
  float z  = 25.537;
  char c = '^';
  printf("x: %d\nz: %f\nc: %c\n", x, z, c);
  printf("Two sig digs z: %.2f\n", z);
}
