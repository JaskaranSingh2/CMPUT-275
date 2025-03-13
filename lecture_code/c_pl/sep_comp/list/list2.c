#include <stddef.h>
#include <stdlib.h>
#include "list.h"
struct List {
  size_t cap;
  size_t len;
  int *arr;
};

struct List *createList() {
  struct List *l = malloc(sizeof(struct List));
  l->cap = 4;
  l->len = 0;
  l->arr = malloc(sizeof(int)*l->cap);
}

struct List *addToFront(struct List *l, int elem) {
  if (l->len == l->cap) {
    int *newArr = malloc(sizeof(int)*2*l->cap);
    for (size_t i = 0; i < l->len; ++i) newArr[i] = l->arr[i];
    free(l->arr);
    l->arr = newArr;
    l->cap = l->cap*2;
  }
  l->arr[l->len++] = elem;
  return l;
}

int ith(struct List *l, size_t i) {
  return l->arr[l->len-1-i];
}

int length(struct List *l) {
  return l->len;
}

int pop(struct List *l, int i) {
  int ret = l->arr[l->len-1-i];
  for (int j = l->len-1-i; j < l->len-1; ++j) {
    l->arr[j] = l->arr[j+1];
  }
  --l->len;
  return ret;
}

void destroy(struct List *l) {
  free(l->arr);
  free(l);
}

