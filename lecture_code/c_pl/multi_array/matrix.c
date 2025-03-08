#include <stdio.h>
#include <stdlib.h>

int strToInt(const char *s) {
  // This function takes in a string that represents
  // an integer and returns its integer value.
  int sum = 0;
  for (; *s != '\0'; ++s) {
    int digit = *s - '0';
    sum = sum*10 + digit;
  }
  return sum;
}

void print2DArray(int **mat, int r, int c) {
  // Prints a 2d array of ints with r number of rows
  // and c number of columns
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}


int main(int argc, char **argv) {
  int n = strToInt(argv[1]); // number of rows
  int m = strToInt(argv[2]); // number of columns
  // We are going make "sort of" an identity matrix,
  // sort of, because it doesn't have to be square like an
  // identity matrix does.
  // Each item in each row will be 0 unless that element is
  // stored in that row at the same column number as the row,
  // then it will be a 1.
  // e.g. if n == 3 and m == 3 then the matrix we create
  // should be of the form
  // [1, 0, 0]
  // [0, 1, 0]
  // [0, 0, 1]
  // First, allocate our "outer" array, in this case our array
  // of rows.
  int **matrix = malloc(n*sizeof(int*));
  // Now, matrix points at an array that has space for n pointers to ints.
  // Let's now make our rows (our array of ints) and store the pointers to
  // those arrays in matrix!
  for (int i = 0; i < n; ++i) {
    // now create each row
    int *row = malloc(m*sizeof(int));
    for (int j = 0; j < m; ++j) {
      row[j] = i == j ? 1 : 0;
      matrix[i] = row;
    }
  }
  print2DArray(matrix, n, m);
  for (int i = 0; i < n; ++i) {
    free(matrix[i]);
  }
  free(matrix);
  // Impossible to free the inner arrays after freeing the outer array,
  // because I no longer have any pointers to those arrays! My pointers to
  // those arrays were stored in my outer array, but that's freed now!
  // So I can't access its contents.
}
