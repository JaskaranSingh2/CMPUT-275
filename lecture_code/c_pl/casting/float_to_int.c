#include <stdio.h>

int main() {
  float f = 45.3;
  // Assigning a float to an integer variable will once again
  // Do the sensible cast implicitly.
  int x = f;
  printf("%d\n", x);
  // BUT NOTE! f cannot always be treated as an int:
  printf("%d\n", f);
}
