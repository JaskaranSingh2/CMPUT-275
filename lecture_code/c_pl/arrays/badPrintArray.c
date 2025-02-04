#include <stdio.h>

void printArray(int arr[]) {
  printf("sizeof arr: %lu\n", sizeof(arr));
  unsigned int len = sizeof(arr)/sizeof(arr[0]);
  for (unsigned int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// The above function is no different than the following definition:

void printArray2(int *arr) {
  unsigned int len = sizeof(arr)/sizeof(arr[0]);
  for (unsigned int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main() {
  int a1[5] = {1, 2, 3, 4, 5};
  int a2[7] = {2, 4, 6, 8, 10, 12, 14};
  printArray(a1);
  printArray(a2);
}
