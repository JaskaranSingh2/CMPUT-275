#include <stdio.h>

/* It is ALWAYS undefined behaviour for a function to return
 * a pointer to its own stackframe. That does NOT mean it is
 * always undefined behaviour to return a pointer to the /stack/
*/

int *max(int *a, int *b) {
  // This function takes in pointers to two integers
  // and returns the address of the larger one.
  // if they are equal it returns its first param
  if (*a >= *b) {
    return a;
  } else {
    return b;
  }
}


int main() {
  int x;
  int y;
  // x and y are local variables to main, where do they reside?
  // On the stack! As all local variables do.
  scanf("%d", &x);
  scanf("%d", &y);
  // I want to do a couple operations on my larger number,
  // so I needa way to choose my larger number.
  int *larger = max(&x, &y);
  *larger = *larger*2;
  printf("%d - %d\n", x, y);
}
