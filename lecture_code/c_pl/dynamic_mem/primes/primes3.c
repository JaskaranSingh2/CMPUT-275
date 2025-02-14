#include <stdio.h>
#include <stdlib.h>

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


void primes(int n) {
  int size = n-2;
  int *arr = malloc(sizeof(int)*size);
  for (int j = 0; j < size; ++j) {
    arr[j] = j+2;
  }
  int *cur = arr;
  while (cur < arr+size) {
    // At the start of my loop, cur should always be
    // the pointer to my current prime! So print it
    printf("%d ", *cur);
    // Now, "scratch out" all the non-primes.
    int *iter = cur + *cur;
    while (iter < arr+size) {
      *iter = 0; // Scratch out this number it is not prime
      iter = iter + *cur; // Increment by our prime.
    }
    ++cur; // Now cur points at the next number.
    // Need to iterate, until it doesn't point at 0.
    while (cur < arr + size && !*cur) {
      // While dereferenced cur IS 0, keep going
      ++cur;
    }
  }
  free(arr);
}

int main(int argc, char **argv) {
  primes(strToInt(argv[1]));
  printf("\n");
}
