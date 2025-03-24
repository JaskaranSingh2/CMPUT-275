#include <stdio.h>

int summation(int n) {
  // This is a horrible function that returns the sum of 1->n recursively...
  if (n == 0) {
    return 0;
  }
  // Here, we compute our result based on a computation that /uses/ the recursive
  // result. The problem with that, is that in order for this function to be "done"
  // and able to be removed from the stack, we must wait for ALL the recursions to
  // be done. That means for each recursive call we have 1 stackfram on the stack at
  // a time, so for this function to complete we have to push n stack frames, which
  // takes up a lot of space.
  int result = summation(n-1) + n;
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", summation(n));
}
