#include <stdio.h>

int isWhiteSpace(char c) {
    // returns 1 if c is a whitespace character e.g. '\t', ' ', '\n', '\r'
  return c == '\n' || c == ' ' || c == '\t' || c == '\r';
}

int main() {
  int lc = 0; // line count
  int wc = 0; // word count
  int cc = 0; // character count
  char lastChar = ' ';
  for (int readChar = getchar(); readChar != EOF; readChar = getchar()) {
    ++cc;
    if (readChar == '\n') ++lc;
    if (isWhiteSpace(readChar) && !isWhiteSpace(lastChar)) {
      ++wc;
    }
    lastChar = readChar;
  }
  // We just saw EOF. Handle the case where a word is actually ended by EOF instead
  // of whitespace. If lastChar was not whitespace then we were in the middle of a
  // word when EOF was received.
  if (!isWhiteSpace(lastChar)) ++wc;

  printf("\t%d\t%d\t%d\n", lc, wc, cc);
}
