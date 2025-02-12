#include <stdio.h>

int main() {
  const char *s = "453";
  int num = s;
  printf("%p\n", s);
  printf("%p\n", num);
}
