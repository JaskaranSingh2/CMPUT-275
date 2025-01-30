#include <stdio.h>

int main() {
  int x = 5;
  int y = 10;
  // px is a pointer to a constant int.
  const int *px = &x;
  /*
  The line below would be a compilation error, because px is a pointer to a constant int
  so we cannot mutate the int it points at using the pointer itself.
  *px = 15;
  */
  // This line is fine
  px = &y; // px itself is not const, just the data it points at, so I can make px point at something else

  // py is a constant pointer to an int
  int * const py = &py;
  *py = 20; // Completely legal, py was not declared as pointing at a constant int
  // so we're allowed to mutate the int through py.

  /*
  The line below would be a compilation error, because px is a constant pointer to an int
  so the pointer itself is const and cannot be changed!
  py = &px
  */
  // cpx is a constant pointer to a constant int.
  const int * const cpx = &x;
  /*
  Both, assigning to the dereferenced pointer or assigning to the pointer itself is
  an error!
  *cpx = 25; // ERROR!
  cpx = &y; // ERROR!
  So this pointer can only ever be read from.
  */
}
