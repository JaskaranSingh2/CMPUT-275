#include <stdio.h>

int sum_tail_recursive(int n, int sumSoFar) {
  // This is a TAIL recursive function, the recursive call itself
  // IS the result of the function, no additional computations needed!
  // As such, when the recursive call is made, this function no longer really
  // needs to exist on the stackframe, since its answer is just going to be the
  // answer of the recursive call anyways! This functions work is done.

  // We achieved this by adding to our recursive parameters what we typically
  // call an "accumulator" because it "accumulates" the result within it.
  if (n == 0) return sumSoFar;
  return sum_tail_recursive(n-1, sumSoFar+n);
}

int summation(int n) {
  return sum_tail_recursive(n, 0);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", summation(n));
}
