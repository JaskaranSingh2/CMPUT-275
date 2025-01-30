#include <stdio.h>

int main() {
  char myS[] = "On stack"; // This string is stored on the stack,
  // because I explicitly asked for a stack-allocated array variable.
  // All our variables we define (inside functions) are allocated on
  // the stack.
  char *p = "Text/data"; // We should really declare this const, as shown below,
  // because this data /IS/ const, we're not allowed to change it.
  //const char *p = "Text/data"; // THIS string is stored on the text or data section
  // The pointer p itself is still stored on the stack, because once again all
  // variables declared inside functions are allocated on the stack. But again
  // Pointers are not arrays! So the definition of myS actually asks to allocate
  // an entire array of characters on the stack, this definition of p asks only
  // to allocate  space for a pointer, and have it point at that string literal.
  // Address of array myS itself (which is where the string is stored)
  printf("Address of the string literal \"On stack\": %p\n", myS);
  // Address p stores (the address of the string)
  printf("Address of the string literal \"Text/Data\": %p\n", p);
  // Also, since myS is allocated here on the stack, which is my memory to play with
  // as I please, it's my array of characters, I can mutate my array.
  myS[2] = '-';
  printf("New mutated string: %s\n", myS);

  p[0] = 'B';
  printf("Mutated text/data string: %s\n", p);
}
