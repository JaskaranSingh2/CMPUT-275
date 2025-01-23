#include <stdio.h>

int main() {
  int x;
  while (!feof(stdin)) {
    if (scanf("%d", &x) == 1) {
      printf("%d\n", x);
      //continue;
    }
    char c;
    scanf("%c", &c);
  }
}
