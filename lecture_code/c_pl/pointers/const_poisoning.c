#include <stdio.h>

int main() {
  const int x = 5;
  // WARNING! Do not assign a pointer to non-constant data
  // to the address of constant data! By doing so, you may
  // accidentally mutate that const data through the pointer
  // and now you've desecrated the constness of that piece of
  // data!
  int *px = &x;
  // If you're going to have a pointer to constant data it
  // ABSOLUTELY should be declared as a pointer to constant
  // data, i.e.
  // const int *px = &x;
  printf("%d\n", x);
  *px = 10;
  printf("%d\n", x);
}
