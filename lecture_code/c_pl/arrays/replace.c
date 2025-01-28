#include <stdio.h>

void printArray(int arr[], unsigned int size) {
  for (unsigned int i = 0; i < size; ++i) printf("%d ", arr[i]);
  printf("\n");
}

void replace(int arr[], unsigned int size, int targ, int repl) {
  for (unsigned int i = 0; i < size; ++i) {
    if (arr[i] == targ) {
      arr[i] = repl;
    }
  }
}


int main() {
  int lst1[] = {1, 2, 1, 4, 1, 5, 1, 1, 6, 1};
  unsigned int size = sizeof(lst1)/sizeof(lst1[0]);
  printArray(lst1, size);
  replace(lst1, size, 1, 7);
  printArray(lst1, size);
  replace(lst1, size, 2, 7);
  printArray(lst1, size);
  replace(lst1, size, 7, 9);
  printArray(lst1, size);
}
