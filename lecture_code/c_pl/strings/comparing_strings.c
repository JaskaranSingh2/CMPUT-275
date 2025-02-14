#include <stdio.h>
#include <string.h>

int main() {
  const char myS[] = "aab";
  const char *p1 = "alpha";
  const char *p2 = "omega";
  const char *p3 = "aaz";
  if (p1 < p3) {
    printf("%s is less than %s\n", p1, p3);
  }
  if (myS < p3) {
    printf("Why was \"alpha\" less than \"zeta\" in the first condition?");
    printf("\nbut not in the second?\n");
    printf("%s is less than %s\n", myS, p3);
  }

  if (*p1 < *p3) {
    printf("Second try...\n");
  }
  if (*myS < *p3) {
    printf("Second try with myS...\n");
  }
}
