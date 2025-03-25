#include "list.h"
#include <stdio.h>

int main() {
  int x;
  struct List *l = createList();
  while (scanf("%d", &x) == 1) {
    addToFront(l, x);
  }
  while (length(l) > 0) {
    printf("%d\n", pop(l, 0));
  }
  destroy(l);
}
