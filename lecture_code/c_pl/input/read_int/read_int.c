#include <stdio.h>

int readInt() {
  /*
    This function reads the next base 10 integer from
    the standard input stream using only getchar,
    skipping over LEADING whitespace.
    It consumes from the stream only that integer
    /and/ the first non integer character.
  */
}

int main() {
  int first = readInt();
  int second = readInt();
  int third = readInt();
  printf("%d %d %d\n", first, second, third);
}
