#include <stdio.h>
#include <string.h>

void str_replace_1(char *s, char targ, char repl) {
  // This implementation achieves the task, but is
  // a poor implementation! It actually is a O(n^2)
  // algorithm, because each iteration we calculate
  // strlen. strlen needs to iterate over the entire
  // string until it finds the null terminator,
  // so each iteration of our loop strlen is iterating
  // through the entire string, n*n
  for (int i = 0; i < strlen(s); ++i) {
    if (s[i] == targ) {
      s[i] = repl;
    }
  }
}

void str_replace_2(char *s, char targ, char repl) {
  // So, this is better, it's now O(n) which is good
  // but... do we need strlen at all?
  const int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    if (s[i] == targ) {
      s[i] = repl;
    }
  }
}

void str_replace_3(char *s, char targ, char repl) {
  // Since we know strlen is just going to iterate
  // until the null terminator character, and we want
  // to iterate the whole string anyways... why
  // have the middleman? Why not just iterate ourselves
  // until the null terminator character?
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == targ) s[i] = repl;
  }
}

void str_replace(char *s, char targ, char repl) {
  for (; *s != '\0'; ++s) {
    if (*s == targ) *s = repl;
  }
}

int main() {
  char myS[] = "zaboomafoo";
  char *p = myS;
  printf("%p\n", p);
  str_replace(s, 'o', '0');
  printf("%p\n", s);
  printf("%s\n", p);
}
