#include <stdio.h>

int main() {
  /*
    The difference between the prefix increment operator (++var)
    and the postfix increment operator (var++)

    Note: The increment operators are just that, they are OPERATORS!
          Operators produce a value. The increment operators not only
          produce a value, but also mutate a variable. The difference
          between prefix and postfix incrementation is their produced
          value.
   Prefix increment operator (++var) increments the value, and produces
     the NEW value.
   Postfix increment operator (var++) increments the value, and produces
     the OLD value.
  */

  int a = 0;
  int b = 0;
  // Prefix increment returns the /new/ value, so what is prefixResult?
  int prefixResult = ++a;
  printf("prefixResult: %d, a: %d\n", prefixResult, a);

  int postfixResult = b++;
  printf("postfixResult: %d, b: %d\n", postfixResult, b);
}
