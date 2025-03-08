#include <stdio.h>


int main() {
  // Conversions....
  // Can I get the integer value of a float?
  float f = 45.8;
  // What happens here???
  int x = f;
  printf("%d\n", x);
  // c is implicitly /casting/ f into an int for me.
  // It is NOT actually the case, that this is a simple
  // copy of the bits of f into x. We can observer this
  // Simply by printing out f as an int.
  printf("%d\n", f);
  // C actually did the work to translate this floating point
  // into an integer, it did that implicitly. It will NOT always
  // do this implicitly for us.
  // Most of the time, C will just straight up copy the bits.
  // for example... as we've already seen:
  char myDigit = '5';
  x = myDigit;
  printf("%d\n", x);
  int num = 0;
  num = "45341"; // Will this be 453?
  printf("%d\n", num);
  // NO! "453" is a string literal, stored somewhere on my text
  // or data section, assigning num to it is assigning num to the
  // pointer to its first item. First of all, the pointer is not
  // the integer I want, second of all a pointer is larger than an int
  // on many machines, so I'm maybe only grabbing half of it anyways
  // (not that grabbing the full pointer would help my problem).
  const char *s = "10";
  // A typename in parentheses is a "cast" expression, it means treat
  // the expression to the right of it as if it were this type.
  int casted = (int) s;

  // Some sensible casts exist, but most often those are already handled
  // by implicit conversions if you're assigning types of those.
  // One example of a sensible cast if you have a reason for it, is if
  // you needed your int to be treated like a float for example:
  int myInt = 10;
  printf("%f\n", myInt);
  printf("%f\n", (float) myInt);

  // Another thing in mind, simply multiplying or applying any
  // arithmetic operation with a float and an int results in a float...
  // So...
  int someNum = 45;
  float floatVer = floatVer*1.0;
}
