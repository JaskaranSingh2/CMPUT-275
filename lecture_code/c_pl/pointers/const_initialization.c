#include <stdio.h>

int main() {
  // This is a useless identifier now...
  // x is const, so we can't change its data.
  // But it was left uninitialized, so reading its data
  // is undefined behaviour. So, it serves absolutely
  // 0 purpose. So don't do this!
  const int x;

  // Consider the two following variable declarations (and definitions)
  // Are both useless? Is one useless? are neither useless?
  const int *p1;
  int * const p2;
  // p2 is completely useless, it is a const variable that was left
  // unitialized!
  // p1 is a pointer to constant data, the pointer itself is not const!
  // so we can actually still change p1 itself.
  p1 = &x; // Completely valid!
}
