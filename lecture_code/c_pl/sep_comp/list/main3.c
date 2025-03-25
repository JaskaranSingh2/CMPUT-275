#include <stdio.h>
#include "list.h"

int main() {
  struct List *l = createList();
  addToFront(addToFront(addToFront(l, 1), 2), 3);
  for (int i = 0; i < length(l); ++i) {
    printf("%d\n", ith(l, i));
  }
  // Note, in order to dereference a pointer to a type
  // we would need to know the SIZE of that type (and the details of it).
  // list.h does not provide these details it only provided the declaration
  // of that type. Since main1 and main2 never needed to know the size of list
  // (they only worked through pointers to it, and functions that operated on it)
  // this was never a problem. If, however, your interface provides functions
  // like the following where the client would need to pass your type by value
  // then your header would need to define the implementation of the structure.
  printListByVal(*l);
  destroy(l);
}
