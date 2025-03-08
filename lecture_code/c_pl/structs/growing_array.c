#include <stdio.h>
#include <stdlib.h>
struct Array {
  int *arr;
  int len;
  int cap;
};

struct Array newArray() {
  struct Array a;
  a.arr = malloc(sizeof(int)*4);
  a.cap = 4;
  a.len = 0;
  return a;
}

void push(struct Array *a, int x) {
  if (a->cap == a->len) {
    int *newArr = malloc(sizeof(int)*2*a->cap);
    for (int i = 0; i < a->len; ++i) {
      newArr[i] = a->arr[i];
    }
    free(a->arr);
    a->arr = newArr;
    a->cap = a->cap*2;
  }
  a->arr[a->len++] = x;
}

int pop(struct Array *a) {
  return a->arr[--a->len];
}

int main() {
  int x;
  struct Array a = newArray();
  while (scanf("%d", &x) == 1) {
    push(&a, x);
  }
  for (int i = 0; i < a.len; ++i) {
    printf("%d ", a.arr[i]);
  }
  printf("\n");
  while (a.len >0) {
    printf("%d\n", pop(&a));
  }
  printf("\n");
  free(a.arr);
}
