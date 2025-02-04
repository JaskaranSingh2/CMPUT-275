#include <stdio.h>


int main() {
  int x = 5;
  x = "Hello"; // This shouldn't be allowed, but it is...
  // It will generate a warning, and we should definitely
  // heed that warning.
  printf("%d\n", x);
}
