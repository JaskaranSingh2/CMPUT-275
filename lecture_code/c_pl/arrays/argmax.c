#include <stdio.h>

// Now that we've learned about const, here is an example where we'd
// pass a pointer but declare the data const. Here, because of array
// decay, we know that arr is actually just the same as int *arr.
// Since this is a pointer to our data we could mutate it. Is there
// any reason that the function argmax should be mutating our data?
// NO! It's purpose is to return the index of our maximal item, it is
// not meant to change our array. So, we should actually declare our
// arr param here as:
// const int arr[]
int argmax(int arr[], unsigned int len) {
  /*
    arr is a non-empty array of integers, len is its size.
    returns the index of the largest item in arr
    in the case of duplicates returns the index of the first
    occurrence of the largest item.
  */
  int largestInd = 0;
  for (unsigned int i = 1; i < len; ++i) {
    if (arr[i] > arr[largestInd]) largestInd = i;
  }
  return largestInd;
}


int main() {
  int arr1[] = {5, 20, 3, 4};
  int arr2[] = {50, 1, 1, 1};
  int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr4[] = {1, 5, 3, 4, 5};
  int arr5[] = {-6, -5, -4, -10};
  printf("Should be 1: %d\n", argmax(arr1, 4));
  printf("Should be 0: %d\n", argmax(arr2, 4));
  printf("Should be 7: %d\n", argmax(arr3, 8));
  printf("Should be 1: %d\n", argmax(arr4, 5));
  printf("Should be 2: %d\n", argmax(arr5, 4));
}
