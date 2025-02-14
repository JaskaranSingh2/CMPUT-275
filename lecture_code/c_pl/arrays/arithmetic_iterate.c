#include <stdio.h>

int main() {
  int arr[] = {2, 4, 6, 8};
  for (unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
    printf("arr + %u - %p\n", i, arr + i);
    printf("*(arr + %u) - %d\n", i, *(arr + i));
  }
}
