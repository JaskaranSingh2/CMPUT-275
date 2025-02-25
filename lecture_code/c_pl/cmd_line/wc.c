#include <stdio.h>
#include <string.h>
int isWhiteSpace(char c) {
    // returns 1 if c is a whitespace character e.g. '\t', ' ', '\n', '\r'
  return c == '\n' || c == ' ' || c == '\t' || c == '\r';
}

int main(int argc, char **argv) {
  int lc = 0; // line count
  int wc = 0; // word count
  int cc = 0; // character count
  char lastChar = ' ';
  // The ternary operator here replaces the need to initialize my
  // variables, then write an if to update their value if some condition
  // were true.
  int printChars = argc > 1 ? 0 : 1;
  int printWords = printChars, printLines = printChars;
  /*
  int printChars = 1, printWords = 1, printLines = 1;
  if (argc > 1) {
    printChars = 0;
    printWords = 0;
    printLines = 0;
  }
  */
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "-l")) {
      printLines = 1;
    }
    if (!strcmp(argv[i], "-c")) {
      printChars = 1;
    }
    if (!strcmp(argv[i], "-w")) {
      printWords = 1;
    }
  }
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
  if (printLines) printf("%d\t", lc);
  if (printWords) printf("%d\t", wc);
  if (printChars) printf("%d", cc);
  printf("\n");
}
