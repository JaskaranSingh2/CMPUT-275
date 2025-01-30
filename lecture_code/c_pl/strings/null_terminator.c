#include <stdio.h>

int main() {
  // A string in c is a null-terminated array of characters.
  // An array of characters that does not have a null terminator in it
  // is not a string, it's simply an array of cahracters.
  char myArr[] = {'a', 'b', 'c', 'd', '\0'};
  printf("%s\n", myArr);
  // If I change the third character of my array to be a null terminator,
  // I'm just changing that string so it's only "ab", even though there's a d
  // and a later null terminator, as soon as a null terminator is reached that
  // is the end of the string!
  myArr[2] = '\0';
  // myArray is now {'a', 'b', '\0', 'd', '\0'}
  printf("%s\n", myArr);
}
