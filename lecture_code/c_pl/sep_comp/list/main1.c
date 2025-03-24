#include <stdio.h>
#include "list.h"

int main() {
  struct List *l = createList();
  addToFront(addToFront(addToFront(l, 1), 2), 3);
  for (int i = 0; i < length(l); ++i) {
    printf("%d\n", ith(l, i));
  }
  destroy(l);
}
