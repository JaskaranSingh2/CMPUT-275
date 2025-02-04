#include <stdio.h>

int insert(int *arr, int size, int cap, int x) {
  if (size + 1 > cap) {
    // We cannot insert, it's full!
    printf("uh oh....");
    return 0;
  }
  // arr is a pointer to an int array,
  // size is how many items are stored in that array
  // cap is the capacity of that total array
  // x is the integer to insert in increasing sorted order
  // returns 1 if successful, 0 if not.
  int i;
  for (i = 0; i < size; ++i) {
    if (arr[i] > x) break;
  }
  // i is now the location we need to insert x at.
  // But first, we have to shift.
  for (int j = size; j > i; --j) {
    arr[j] = arr[j-1];
  }
  // Now that we have shifted everything to the right,
  // we can insert x.
  arr[i] = x;
  return 1;
}

void printArray(int *p, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");
}

int main() {
  const int size = 100;
  int len = 0;
  int arr[size];
  int x;
  while (!feof(stdin)) {
    int rc = scanf("%d", &x);
    if (1 == rc) {
      // insert returns 0 if failure, 1 if success.
      // so if it succeeded in inserting 1 item,
      // this statement increments our len by 1.
      // if it failed our len remains unchanged
      len += insert(arr, len, size, x);
    }
  }
  printArray(arr, len);
}
