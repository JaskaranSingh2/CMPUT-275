#include <stdio.h>
#include <string.h>


int main() {
  // myS is an array of 15 characters,
  // Currently, only the first 6 characters are used!
  // I can still append 9 more characters.
  char myS[15] = "hello";
  const char *p = " friend";
  char otherS[] = "Don't change me pls";
  strcat(myS, p);
  printf("myS: %s\n", myS);
  printf("otherS: %s\n", otherS);

}
