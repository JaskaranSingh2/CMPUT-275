#include <stdio.h>

void addOne(int arr[]) {
  arr[0] = arr[0] + 1;
  arr[1] = arr[1] + 1;
}


int main() {
  int arr[3] = {1, 2, 3};
  addOne(arr);
  for (int i = 0; i < 3; ++i) printf("%d ", arr[i]);
  printf("\n");
}
