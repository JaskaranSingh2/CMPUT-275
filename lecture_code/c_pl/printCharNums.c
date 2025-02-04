#include <stdio.h>

int main() {
  for (int c = getchar(); c != EOF; c = getchar()) {
    printf("%c - %d\n", c, c);
  }
}
