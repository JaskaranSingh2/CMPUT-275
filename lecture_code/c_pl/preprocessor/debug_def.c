#include <stdio.h>



int main() {
  int x = 1, y = 2000;
  while (x < y) {
    #ifdef DEBUG
    printf("%d\n%d\n", x, y); // REMOVE BEFORE SUBMITTING
    #endif
    x = x*2;
    y = y+50;
  }

}
