#include <stdio.h>

int main() {
  int iArr[] = {1, 2, 3, 4};
  char cArr[] = {'a', 'b', 'c', 'd'};
  short int siArr[] = {1, 2, 3, 4};
  for (int i = 0; i < 4; ++i) {
    printf("iArr + %d: %p - *(iArr + %d) - %d\n", i, iArr + i, i, *(iArr + i));
    printf("cArr + %d: %p - *(cArr + %d) - %c\n", i, cArr + i, i, *(cArr + i));
    printf("siArr + %d: %p - *(siArr + %d) - %d\n", i, siArr + i, i, *(siArr + i));
  }
}
