#include <stdio.h>

int main() {
  int x = 5;
  // Quite often, you will see in C code that looks like this:
  int *p = &x;
  // What I mean, is code where the asterisk (which is part of
  // the type) is written right beside the varaible name...
  // Wouldn't it make more sense to write:
  int* q = &x;
  // Since the pointer is part of the type.
  // Both are valid, and arguably the latter does make more sense.
  // The reason that many C programmers prefer the former is
  // because a bit of C syntax...
  // I've been careful not to show this yet, but we can declare
  // (and define) multiple variables on the same line:
  int a=5, b=3;
  // Now a and b are both integers.
  printf("%d - %d\n", a, b);
  // Now consider the following:
  int* t, k;
  printf("%lu - %lu\n", sizeof(t), sizeof(k));
  // t here is an int*, k is just an int...
  // So, in multiplie declarations on the same line,
  // each asterisk applies only to the immediate next declaration
  // if we wanted to declare two pointers to ints hre we'd have to
  // write:
  int* a1, *a2;
  printf("%lu - %lu\n", sizeof(a1), sizeof(a2));
  // So, why do programmers like to put the asterisk beside the identifier
  // whose type is of a pointer type? Because, unfortunately, when we
  // do multiple definitions in the same line it is necssary.
  int *b1, *b2;
}
