#include <stdio.h>

int main() {
  int x;
  int rc = scanf("%d", &x);
  if (rc == 1) {
    printf("%d\n", x*3);
  }
}
