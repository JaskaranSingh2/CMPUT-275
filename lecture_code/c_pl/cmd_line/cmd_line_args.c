#include <stdio.h>

int main(int argc, char **argv) {
  printf("%d number of args given\n", argc);
  for (size_t i = 0; i < argc; ++i) {
    printf("argv[%lu]: %s\n", i, argv[i]);
  }
}
