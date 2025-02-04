#include <stdio.h>
#include <string.h>
void printStrings(const char *arr, const unsigned int len) {
  /*
  * This function takes in an arr that contains characters and
  * at least one null terminator. However, it can contain multiple
  * null terminators, and each one indicates the end of a string.
  * In this way, this array can effectively store multiple
  * strings. This function will print out each of them.

  * That is, this should print out each string in that array
  * one per line.
  * e.g.
  * if the array arr is {'a', 'b', '\0', 'h', 'e', 'l', 'l', 'o', '\0', 'x', 'y', 'z', '\0'}
  * then your function when called printStrings(arr, 13)
  * should print the following three lines:
  * ab
  * hello
  * xyz
  */
  // We know by definition this arr contains at least one string, though it
  // might be the empty string, either way, that's fine. We'll print it
  // right at the start! That will print the first string.
  printf("%s\n", arr);
  // Now, we need to iterate over the array, and each time we see a null terminator
  // before the end of the array, that means there's another string after it we should print
  // So we iterate over the whole array looking for null terminators.
  for (unsigned int i = 0; i < len-1; ++i) {
    if (arr[i] == '\0') {
      printf("%s\n", arr + i + 1);
    }
  }
}

int main() {
  char test1[] = {'a', 'b', '\0', 'h', 'e', 'l', 'l', 'o', '\0', 'x', 'y', 'z', '\0'};
  printStrings(test1, sizeof(test1)/sizeof(test1[0]));
  char test2[] = {'h', 'i', ' ', 'p', 'a', 'l', '\0', 'b', 'y', 'e', '\0'};
  printStrings(test2, sizeof(test2)/sizeof(test2[0]));
  const char *single = "This is only one string!";
  printStrings(single, strlen(single) + 1);
  // A string in c is a null-terminated array of characters.
  // An array of characters that does not have a null terminator in it
  // is not a string, it's simply an array of cahracters.
  char myArr[] = {'a', 'b', 'c', 'd', '\0'};
  printf("%s\n", myArr);
  // If I change the third character of my array to be a null terminator,
  // I'm just changing that string so it's only "ab", even though there's a d
  // and a later null terminator, as soon as a null terminator is reached that
  // is the end of the string!
  myArr[2] = '\0';
  // myArray is now {'a', 'b', '\0', 'd', '\0'}
  printf("%s\n", myArr);

  char newArr[] = "zaboomafoo";
  // Note, that since this is an array declared on my stack it is mutable.
  // So this is effectively the character array:
  // {'z', 'a', 'b', 'o', 'o', 'm', 'a', 'f', 'o', 'o', '\0'}
  // Since we know that passing an array is passing a pointer, each time
  // we've been passing our string to printf (or any string function) we've been
  // passing a pointer to the FIRST character.
  // We now know these functions operate by iterating from that pointer until the
  // null terminator. So what if I wanted a "string" that was zaboomafoo without the
  // first 2 characters?
  char *newString = newArr + 2;
  printf("newArr: %s\nnewString: %s\n", newArr, newString);
  printf("newArr+5: %s\n", newArr+5);

}
