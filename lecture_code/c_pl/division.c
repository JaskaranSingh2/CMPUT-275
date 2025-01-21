#include <stdio.h>

int main() {
  // Notes on division in C.
  // Division between two ints results in an int, it is integer divsion:
  printf("%d\n", 5/2);
  // If either operand is a float, the result is a float
  printf("%f\n", 5.0/2);
}
