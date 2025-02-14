#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // We're going to read the integer

    for (int i = 1; i <= n; i++) { // i < n because we don't want to include the inputted number basically
        if (n % i == 0) {
            printf("%d ", i); // this prints the divisor with a space
        }
    }

    printf("\n"); // newline as per document
    return 0;
}