#include <stdio.h>

// func. to convert a Roman numeral char to its int value
int romanToValue(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;  // invalid char
    }
}

int main() {
    int total = 0;
    int current_value, next_value;
    char current, next;
    
    // read the first char
    current = getchar();
    if (current == EOF) {
        printf("0\n");  // empty input
        return 0;
    }
    
    current_value = romanToValue(current);
    
    // process each character and look ahead to the next one
    while ((next = getchar()) != EOF && romanToValue(next) != 0) {
        next_value = romanToValue(next);
        
        // If current value is less than next, subtract it
        if (current_value < next_value) {
            total -= current_value;
        } else {
            // Otherwise add it
            total += current_value;
        }
        
        // Move to next character
        current = next;
        current_value = next_value;
    }
    
    // Add the last character's value
    total += current_value;
    
    // Print the result
    printf("%d\n", total);
    
    return 0;
}