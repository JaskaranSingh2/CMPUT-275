#include <stdio.h>

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


int isPrime(int n) {
  // Returns 1 if n is prime, 0 if otherwise.
  for (int i = 2; i < n; ++i) {
    if (n%i == 0) {
      return 0;
    }
  }
  return 1;
}

void primes(int n) {
  // Prints out all primes (in order) less than n.
  for (int i = 2; i < n; ++i) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }
}

int main(int argc, char **argv) {
  primes(strToInt(argv[1]));
  printf("\n");
}
