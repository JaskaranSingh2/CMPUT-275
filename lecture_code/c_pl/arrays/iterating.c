#include <stdio.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  unsigned int len = sizeof(arr)/sizeof(arr[0]);
  for (unsigned int i = 0; i < len; ++i) {
    printf("arr[%u] - %d\n", i, arr[i]);
  }
}
