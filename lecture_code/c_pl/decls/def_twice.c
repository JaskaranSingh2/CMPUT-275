#include <stdio.h>

// This is a declaration /AND/ definition of the function
// foo.
void foo() {
  printf("Hello\n");
}

// This is a declaration /AND/ definition of the function
// foo. We cannot have two definitions of any entity!
void foo() {
  printf("Goodbye\n");
}

int main() {
  foo();
}
