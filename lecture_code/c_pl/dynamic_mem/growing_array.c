#include <stdio.h>
#include <stdlib.h>

void push(int **arr, int *cap, int *len, int val) {
  if (*len == *cap) {
    int *newArr = malloc(sizeof(int)**cap*2);
    for (int i = 0; i < *len; ++i) newArr[i] = (*arr)[i];
    free(*arr);
    *arr = newArr;
    *cap = *cap*2;
  }
  (*arr)[(*len)++] = val;
}

int pop(int *arr, int *cap, int *len) {
  // Removes the last item (and returns its value) of
  // a growing array.
  return arr[--(*len)];
}

int main() {
  // Read all ints from standard input, and push them into an array.
  int x = 0;
  int *arr = malloc(sizeof(int)*4);
  int cap = 4;
  int len = 0;
  while (scanf("%d", &x) == 1) {
    push(&arr, &cap, &len, x);
  }

  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  while (len > 0) {
    printf("%d\n", pop(arr, &cap, &len));
  }
  free(arr);
}
