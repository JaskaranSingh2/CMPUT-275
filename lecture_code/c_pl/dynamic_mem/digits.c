#include <stdio.h>
#include <stdlib.h>

int *digits(int n) {
  int count = 0;
  int copy = n;
  int pow10 = 1;
  while (copy > 0) {
    count = count + 1;
    copy = copy/10;
    pow10 = pow10*10;
  }
  pow10 = pow10/10;
  int *arr = malloc(sizeof(int)*count);
  for (int i = 0; i < count; ++i) {
    int tmp = n/pow10;
    arr[i] = tmp%10;
    pow10 = pow10/10;
  }
  return arr;
}

int digCount(int n) {
  if (!n) return 1;
  int count = 0;
  while (n > 0) {
    ++count;
    n = n/10;
  }
  return count;
}

int main() {
  int d;
  scanf("%d", &d);
  int *arr = digits(d);
  int count = digCount(d);
  for (int i = 0; i < count; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
}
