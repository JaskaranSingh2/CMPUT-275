#include <stdio.h>
#include <stdlib.h>


void str_to_int(void *in, void *out) {
  // in is a pointer to a string, out is a pointer to an int
  // in must be a string that represents a base 10 number.
  int *outLoc = out;
  char *s = *(char **)in;
  int res = 0;
  while (*s) {
    res = res*10 + *s - '0';
    ++s;
  }
  *outLoc = res;
}

void int_to_str(void *in, void *out) {
  int n = *(int*)in;
  if (!n) {
    char *res = malloc(sizeof(char)*2);
    res[0] = '0'; res[1] = '\0';
    *(char **)out = res;
    return;
  }
  int digCount = 0;
  int copy = n;
  int pow10 = 1;
  while (copy > 0) {
    pow10 = pow10*10;
    ++digCount;
    copy = copy/10;
  }
  pow10 = pow10/10;
  char *res = malloc(sizeof(char)*(digCount+1));
  for (int i = 0; i < digCount; ++i) {
    int dig = n/pow10;
    res[i] = dig + '0';
    n = n - dig*pow10;
    pow10 = pow10/10;
  }
  res[digCount] = '\0';
  *(char **)out = res;
}

void map(void *in, size_t inSize, int n, void *res, size_t outSize, void (*f)(void *, void *)) {
  // map, which maps a function onto an array of any type
  // Stores the result in the client programmers given result
  // array
  // Function f takes two void pointers, the first is its input
  // the second is the location to store the result, in place of
  // returning a value.
  for (int i = 0; i < n; ++i) {
    f(in + i*inSize, res + i*outSize);
  }
}

void printStr(void *in, void *res) {
  // Function to print strings for giving to map
  // Does not actually write a result.
  printf("%s\n", *(char **)in);
}

void freeStr(void *in, void *res) {
  // Function frees the the string given by in,
  // and also writes null back to that location.
  // ignores res.
  free(*(char **)in);
  *(char **)in = NULL;
}

int main() {
  const char *strings[] = {"1234", "5678", "90001"};
  int arr[3];
  /*
  int *z;
  const char **p;
  for (p=strings, z = arr; p < strings + 3 && z < arr +3; ++p, ++z) {
    str_to_int(p, z);
  }
  // Has same result as
  */
  /*
  for (int i = 0; i < 3; ++i) {
    str_to_int(&strings[i], &arr[i]);
  }
  */
  // Also has same result as
  /*
  for (int i = 0; i < 3; ++i) {
    printf("%p - %p\n", strings+i, arr +i);
    printf("%p\n", strings[i]);
    str_to_int(strings + i, arr + i);
  }
  */

  map(strings, sizeof(strings[0]), 3, arr, sizeof(arr[0]), str_to_int);
  for (int i = 0; i < 3; ++i) printf("%d ", arr[i]);

  int arr2[] = {3281, 5001, 30};
  char *strs[3];
  map(arr2, sizeof(arr2[0]), 3, strs, sizeof(strs[0]), int_to_str);
  printf("\n");
  map(strs, sizeof(strs[0]), 3, strs, sizeof(strs[0]), printStr);
  map(strs, sizeof(strs[0]), 3, strs, sizeof(strs[0]), freeStr);
  for (int i = 0; i < 3; ++i) printf("%p\n", strs[i]);
}
