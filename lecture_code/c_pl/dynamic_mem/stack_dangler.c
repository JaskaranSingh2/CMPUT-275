#include <stdio.h>

int *genMultiples(int n) {
  // This function returns an array of the first 4 multiples
  // of n.
  int arr[4];
  for (int i = 0; i < 4; ++i) {
    arr[i] = n + n*i;
  }
  return arr;
}

int fib(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return fib(n-1) + fib(n-2);
}

int main() {
  int *arr = genMultiples(5);
  for (int i = 0; i < 4; ++i) {
    printf("%d\n", arr[i]);
  }
  int x = fib(20);
  printf("Fib 20: %d\n", x);
  printf("Printing out fives array again:\n");
  for (int i = 0; i < 4; ++i) {
    printf("%d\n", arr[i]);
  }
  genMultiples(3);
  printf("I have not touched my variable arr, but I did call another fn\n");
  for (int i = 0; i < 4; ++i) {
    printf("%d\n", arr[i]);
  }
}
