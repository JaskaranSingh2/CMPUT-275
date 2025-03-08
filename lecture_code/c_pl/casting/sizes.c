#include <stdio.h>

int main() {
  char *p = "a";
  int x = 5;
  double f = 45.9;
  printf("%lu, %lu, %lu\n", sizeof(p), sizeof(x), sizeof(f));
}
