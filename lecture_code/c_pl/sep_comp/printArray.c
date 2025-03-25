#include <stdio.h>

void printArray(int arr[], size_t size) {
  if (size == 0) return;
  for (size_t i = 0; i < size-1; ++i) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[size-1]);
}
