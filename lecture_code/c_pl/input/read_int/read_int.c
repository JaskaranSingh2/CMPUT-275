#include <stdio.h>

/*
I don't like that this function reads an extra character!

If the input looks like:
453x

I think it should read only 453, and leave the x in the stream
Or similarly if its

458   

it should leave that space in the stream for whoever reads next!

How to do this? The answer is to put it back from where you found it!

We have ungetc as a function to put a character back, but it is a little
more complicated, so if you want to you can read about ungetc and try
updating this function so it doesn't read an extra character!
Practice for you!
*/

int readInt() {
  /*
    This function reads the next base 10 integer from
    the standard input stream using only getchar,
    skipping over LEADING whitespace.
    It consumes from the stream only that integer
    /and/ the first non integer character.
  */
  char c;
  // Loop until char c is NOT a whitespace character.
  for (c = getchar(); c == ' ' || c == '\n' || c == '\t'; c = getchar());
  // After this for loop c is our first non-whitespace character
  // Since we're assuming there will be an int here, we know our
  // next character is the start of our int.
  int neg = 0; // False by default
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  // From here on, we should assume that c is our first digit
  int num = 0;
  while (c >= '0' && c <= '9') {
    num = num*10;
    num = num + (c - '0');
    c = getchar();
  }
  if (neg) {
    num = -num;
  }
  return num;
}

int main() {
  int first = readInt();
  int second = readInt();
  int third = readInt();
  printf("%d %d %d\n", first, second, third);
}
