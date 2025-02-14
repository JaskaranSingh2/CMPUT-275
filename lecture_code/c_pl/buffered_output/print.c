#include <stdio.h>



int main() {
  int x = 0;
  scanf("%d", &x); // if 1, print to stdout, if 0 print to stderr
  int *nptr = NULL;
  if (x) {
    for (int i = 0; i < 2000; ++i) {
      fprintf(stdout, "boo ");
      if (i == 7) {
        *nptr = 5;
      }
    }
  } else {
    for (int i = 0; i < 2000; ++i) {
      fprintf(stderr, "boo ");
      if (i == 7) {
        *nptr = 5;
      }
    }
  }
}
