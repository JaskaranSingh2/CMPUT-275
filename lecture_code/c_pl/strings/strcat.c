#include <stdio.h>
#include <string.h>

void mystrcat(char *dest, const char *src) {
  // CHALLENGE: Fix this function so that if dest
  //            and src overlap, it doesn't break!
  int len = strlen(dest);
  if (dest + len > src && dest < src) {
    // Then these overlap.... what to do about it?
    // Challenge for you to solve!
  }
  for (; *dest != '\0'; ++dest);
  // After this above for loop, dest now points at
  // its null terminator character, that is where I want
  // to start writing characters!
  for (; *src != '\0'; ++src, ++dest) {
    *dest = *src;
  }
  *dest = '\0';
}

int main() {
  char myS[256] = "help";
  const char *s = "! I need somebody!";
  const char *p = " Not just anybody!";
  mystrcat(myS, s);
  printf("%s\n", myS);
  mystrcat(myS, p);
  printf("%s\n", myS);
  mystrcat(myS, myS+10);
}
