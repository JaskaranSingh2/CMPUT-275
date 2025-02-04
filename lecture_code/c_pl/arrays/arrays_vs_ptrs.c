#include <stdio.h>
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int *p = arr;
  printf("sizeof(arr): %lu\n", sizeof(arr));
  printf("sizeof(p): %lu\n", sizeof(p));
  printf("p: %p\n", p);
  printf("&p: %p\n", &p);
  printf("arr: %p\n", arr);
  printf("&arr: %p\n", &arr); // !!!
}
