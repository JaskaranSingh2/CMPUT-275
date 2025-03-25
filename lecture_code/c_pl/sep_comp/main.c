#include <stdio.h>

//void printArray(int arr[], size_t);

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  printArray(arr, sizeof(arr)/sizeof(arr[0]));
  printf("\n");
}
