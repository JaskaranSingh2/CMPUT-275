#include <stdio.h>



int main() {
  // The simplest input function we have in C is the function
  // getchar, getchar returns a single character from the standard
  // input stream (and consumes that character from the stream)
  char c1 = getchar();
  char c2 = getchar();
  printf("%c%c\n", c1, c2);
  // How can we read a single digit integer from the input stream?
  // then print out that integer multiplied by 5?
  char charNum = getchar();
  int val = charNum - '0';
  // Consider the difference between the following:
  printf("charNum*5: %d\n", charNum*5);
  printf("val*5: %d\n", val*5);

}
