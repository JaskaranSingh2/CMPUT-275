#include <stdio.h>

/*
This program reads exactly one integer from the stream,
it does not stop until the user enters an integer. When the user
doesn't enter an integer it continually asks the user to enter one
until they do
*/

void readUntilNum() {
  // This function removes characters from the stream
  // until we reach the start of a integer
  for (char c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar());
  // Now, c is a hyphen or a digit, so we've read until the next
  // int starts

  /*
    NOTE! This function currently does not help us read the first
    integer from stream, since it actually will consume the first
    character that is a part of that integer! If the integer was
    432 then it consumes the 4, so the subsequent scanf will
    read only 32 for example.
  */
}

int main() {
  int x;
  int loop = 1;
  //printf("Enter an integer: ");
  while (loop) {
    int rc = scanf("%d", &x);
    if (rc != 1) {
      // Note: Try uncommenting this print, and try different inputs
      // make sure you understand why it's printing as many times as it
      // is!
      //printf("Please enter an integer: ");
      //readUntilNum(); // Doesn't work!
      getchar();
    } else {
      printf("%d\n", x);
      loop = 0;
    }
  }
}
