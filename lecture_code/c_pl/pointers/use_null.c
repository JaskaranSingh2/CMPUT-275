#include <stdio.h>

int blah() {
  // Didn't initialize z.
  int *z;
  // accidentally later read z without initializing it first
  printf("%d\n", *z);
}

int main() {
  // p is a pointer I'm going to update to point at an
  // integer.
  // Right now, it's uninitialized...
  // We know leaving data unitialized is a bad idea,
  // because if we accidentally read it before it's initialized
  // it is undefined behaviour, That's extra bad with a pointer,
  // because we don't know what memory address it happens to
  // randomly point at!
  int *p;
  // Better, is to initialize all our variables when we
  // define them, but what value can we initialize a pointer to?
  // since we can't just initialize pointers to random numbers...
  int *q = NULL;
  // NULL is just 0. The address 0 is never a valid memory address
  // for our program to touch. The C standard guarantees that
  // dereferencing a pointer to NULL (often called a NULL ptr)
  // is a guaranteed segmentation fault.
  blah();

  printf("%d\n", *q);
  // Note that in blah, since z was uninitialized, we may actually
  // be able to dereference without crashing, the result is
  // undefined behaviour, and now the result of our program is
  // unknowable - that is a bug!
  // When we try and dereference the null ptr stored in q,
  // we crash. We would much rather have a crash, than a random
  // bug to try and track down later.
  // RECOMMENDATION: Never leave data uninitialized. When
  // initialized pointers you don't have an address to point at
  // yet, intialize them to NULL
}
