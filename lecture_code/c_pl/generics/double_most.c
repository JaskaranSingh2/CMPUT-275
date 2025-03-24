#include <stdio.h>
#include <stdlib.h>


void doubleMost(void *p, int typeFlag, void *res) {
  // double most works to double most numeric types
  // i.e. doubleMost can be called on an int to double it
  // a float to double, a char to double it, and returns
  // double of that value
  // typeflag is 0 for an int, 1 for a float, 2 for a char
  switch (typeFlag) {
    case 0:
      // Curly braces not required, though if you want to defin new
      // variables you'll get at least a warning without them.
      *(int *)res = (*(int *)p)*2;
      // By default, the case which is true is just the point
      // we *start* executing code, we continue through the rest
      // until we see a break. So if each case is truly meant to be
      // distinct, place a break at the end of each case
      break;
    case 1:
      *(float *)res = (*(float *)p)*2;
      break;
    case 2:
      *(char *)res = (*(char *)p)*2;
      break;
  }
}



int main() {
  int x = 5;
  int y = 0;
  doubleMost(&x, 0, &y);
  printf("%d\n", y);
  doubleMost(&x, 0, &x);
  printf("%d\n", x);
}
