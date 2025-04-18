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
    int curVal, nextVal;
    char curr, next;
    
    // read the first char
    curr = getchar();
    if (curr == EOF) {
        printf("0\n");  // empty input
        return 0;
    }
    
    curVal = romanToValue(curr);
    
    // process each character and look ahead to the next one
    while ((next = getchar()) != EOF && romanToValue(next) != 0) {
        nextVal = romanToValue(next);
        
        // If curr value is less than next, subtract it
        if (curVal < nextVal) {
            total -= curVal;
        } else {
            // Otherwise add it
            total += curVal;
        }
        
        // Move to next character
        curr = next;
        curVal = nextVal;
    }
    
    // Add the last character's value
    total += curVal;
    
    // Print the result
    printf("%d\n", total);
    
    return 0;
}