#include <stdio.h>

int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a%b;
    a = b;
    b = tmp;
  }
  return a;
}


int main() {
  printf("gcd(16, 8)=%d\n", gcd(16, 8));
  printf("gcd(153,96)=%d\n", gcd(153,96));
}
