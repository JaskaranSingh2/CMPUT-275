#include <stdio.h>
#include <string.h>

int main() {
  char myS[10] = "help";
  strcat(myS, myS+2); // Try to append "lp" to the end of myS
  // to make it "helplp"
  // The arguments to strcat are not allowed to overlap however!
  // This is undefined behaviour! Not guaranteed to work.
  printf("%s\n", myS);
}
