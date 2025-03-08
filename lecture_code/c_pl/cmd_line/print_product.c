#include <stdio.h>
#include <stdlib.h>

int strToInt(const char *s) {
  // This function takes in a string that represents
  // an integer and returns its integer value.
  int sum = 0;
  for (; *s != '\0'; ++s) {
    int digit = *s - '0';
    sum = sum*10 + digit;
  }
  return sum;
}


int main(int argc, char **argv) {
  printf("%d\n", strToInt(argv[1])*strToInt(argv[2]));
}
