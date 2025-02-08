#include <stdlib.h>
#include <stdio.h>
int doAThing() {
  // This function does something... but leaks memory!
  int *p = malloc(1024*sizeof(int));
  char c = getchar();
  // do something...
}

int main() {
  while (!feof(stdin)) {
    doAThing();
  }
}
