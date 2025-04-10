#include <stdio.h>

int main() {
    int c;
    int sum = 0;
    int digit_count = 0;
    int check_digit;
    
    // first pass we count the digits
    while ((c = getchar()) != EOF && c >= '0' && c <= '9') {
        digit_count++;
    }
    
    // no digits read
    if (digit_count == 0) {
        printf("Invalid\n");
        return 0;
    }
    
    // rewind stdin
    rewind(stdin);
    
    // the second pass - process digits according to the Luhn's algorithm
    for (int pos = 1; pos <= digit_count; pos++) {
        c = getchar();
        int digit = c - '0';
        
        // the last digit is the check digit
        if (pos == digit_count) {
            check_digit = digit;
        } else {
            // determine if this digit should be doubled
            // we double every second digit from the right, excluding the check digit
            // (digit_count - pos) gives the position from the right (0-indexed)
            // if this position is odd, double the digit
            if ((digit_count - pos) % 2 == 1) {
                digit *= 2;
                if (digit >= 10) {
                    digit -= 9;
                }
            }
            
            // add it to the sum
            sum += digit;
        }
    }
    
    // calc. the expected check digit according to the formula
    int expected_check_digit = (sum * 9) % 10;
    
    // Verify
    if (expected_check_digit == check_digit) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    
    return 0;
}