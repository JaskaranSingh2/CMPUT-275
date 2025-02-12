#include <stdio.h>
#include <math.h>

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
  // sqrt(n) returns a double, but since sq is an int type
  // this will do the sensible cast and cast that double into
  // an integer (if it can fit)
  int sq = sqrt(n);
  sq = sq + 1;
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
