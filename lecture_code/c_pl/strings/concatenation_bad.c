#include <stdio.h>
#include <string.h>


int main() {
  char myS[] = "ab";
  const char *p = "xy";
  char anotherStr[] = "pot";
  strcat(myS, p); // ERROR! VERY VERY BAD!!!!
  // We didn't ensure that myS had enough space for
  // the concatentation, as such we've invoked undefined
  // behaviour because strcat will simply keep going past
  // the end of myS and writing the characters of the new
  // string.
  printf("myS: %s\n", myS);
  printf("anotherStr: %s\n", anotherStr);
  printf("p: %s\n", p);
}
