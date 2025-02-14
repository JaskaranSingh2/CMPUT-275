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


int *primes(int n, int *sizeLoc) {
  // This function returns a pointer to an array
  // of all the primes less than n.
  int size = n-2;
  int *arr = malloc(sizeof(int)*size);
  for (int j = 0; j < size; ++j) {
    arr[j] = j+2;
  }
  int *cur = arr;
  while (cur < arr+size) {
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
  // At this point, arr is an array of integers where each
  // integer is either a prime number (in ascending order) or
  // 0. A 0 means we should ignore it.
  // We can't return this array, because the caller expects
  // an array of primes, not just an array of primes and 0s.
  // So we need to package our primes in a nice array that is
  // all of the primes in order.
  // Let's make our array the right size, which involves
  // iterating our array and counting the primes.
  int primeCount = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i]) {
      ++primeCount;
    }
  }
  *sizeLoc = primeCount;
  int *retArray = malloc(sizeof(int)*primeCount);
  for (int i = 0, placed = 0; i < size; ++i) {
    if (arr[i]) {
      // If this is non-zero, place it in our array
      retArray[placed++] = arr[i];
      // Would the following work the same?
      // retArray[++placed] = arr[i];
      // NO! In this case we are actually /USING/ the evaluation
      // of the increment expression. In this case we definitely do
      // want postfix, because think about when placed is 0, we want
      // to write to index 0 and then increment to 1. Since postfix
      // returns the original value, that's what happens here.
      // If we used prefix we would actually write to index 1 first.
    }
  }
  free(arr);
  return retArray;
}

int main(int argc, char **argv) {
  // If we'd like a function to effectively "return" more than one
  // value, we can define it with extra parameters, those extra
  // parameters are pointers to the type of data we'd like to produce
  // and then the caller simply provides the addresses of their own
  // data where they'd like that function to write that data.

  // For example, if we want primes to be able to tell us the length
  // of the array, we pass another argument which is a pointer to an int
  // and that int is where primes will write the size.
  int size;
  int * p = primes(strToInt(argv[1]), &size);
  // How many primes in our array that p points at?
  // .... don't know... We don't want to calculate that, in order
  // to calculate that we might have to replicate the work of the
  // function itself!!!
  for (int i = 0; i < size; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
