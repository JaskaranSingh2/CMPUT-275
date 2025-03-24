#include <stdio.h>
#include <stdlib.h>


int *bad_map(int *arr, int n, int (*f)(int)) {
  // Maps function f onto arr, returns a new heap allocated
  // array that is the result [f(e1), f(e2), ..., f(en)]
  // assuming the original array was [e1, e2, ..., en]
  int *result = malloc(sizeof(int)*n);
  for (int i = 0; i < n; ++i) {
    result[i] = f(arr[i]);
  }
  return result;
}

void better_map(int *arr, int n, int *res, int (*f) (int)) {
  for (int i = 0; i < n; ++i) {
    res[i] = f(arr[i]);
  }
}

int doubleNum(int n) {
  return n*2;
}

int printInt(int n) {
  printf("%d ", n);
  return n;
}

int fib_rec(int n, int prev1, int prev2) {
  if (n == 0) return prev1;
  int next = prev1+prev2;
  return fib_rec(n-1, next, prev1);
}

int fib(int n) {
  return fib_rec(n-1, 1, 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  free(bad_map(arr, 5, printInt));
  int *p = bad_map(arr, 5, doubleNum);
  free(bad_map(p, 5, printInt));
  printf("\n");
  int *z = bad_map(arr, 5, fib);
  free(bad_map(z, 5, printInt));
  free(z);
  free(p);
  printf("\n");
  better_map(arr, 5, arr, printInt);
  printf("\n");
  better_map(arr, 5, arr, doubleNum);
  better_map(arr, 5, arr, printInt);
  printf("\n");
}
