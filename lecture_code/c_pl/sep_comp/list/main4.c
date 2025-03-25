#include <stdio.h>
#include "list.h"

int main() {
  struct List l;
  addToFront(&l, 1);
  l.len = 10;
}
