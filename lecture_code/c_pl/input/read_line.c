/*
This program will read and print every /second/ line from
standard input. So every non-second line will be not printed!
*/
#include <stdio.h>

// in stdio.h there is a constant defined named
// EOF which is the value that will be used to represent
// the EOF signal. getchar will return EOF when
// called and the stream is at EOF.

int readline(int print) {
  // if param is 0 do no print the line we read
  // if param is 1 do print the line we read
  // Returns 1 if read line completed
  // Returns 0 if EOF encountered!

  // getchar /actually/ returns an int. The reason for this is
  // i
  for (int c = getchar(); c != '\n'; c = getchar()) {
    if (c == EOF) {
      return 0;
    }
    if (print) {
      printf("%c", c);
    }
  }
  if (print) {
    printf("\n");
  }
  return 1;
}


int main() {
  // now we have read line that can read and print a line.
  // All we need now is to loop and print every second line
  // So let's keep a number that we'll flip between 0 and 1
  // to pass to readline
  int toPrint = 0;
  for (;;) {
    int retVal = readline(toPrint);
    toPrint = !toPrint;
    if (!retVal) {
      break;
    }
  }
}
