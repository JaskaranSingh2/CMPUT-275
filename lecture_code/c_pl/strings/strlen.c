#include <stdio.h>
#include <string.h>
int main() {
  const char *s = "Hello there!";
  char myS[] = "Another string";
  printf("strLen(s): %lu\n", strlen(s));
  printf("strlen(myS): %lu\n", strlen(myS));
  // How can strlen possibly figure out the length of these arrays
  // if it's not receiving a parameter for size? We know the sizeof
  // trick doesn't work when we pass arrays, since array decay means
  // we just pass a pointer! How!?

  // Well... consider this:
  printf("sizeof(myS)/sizeof(myS[0]): %lu\n", sizeof(myS)/sizeof(myS[0]));
}
