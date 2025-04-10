#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Colors
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

// func. to set the color to print
void setColour(const char* colour) {
    static const char* currentColour = "";
    
    // only print the color code if it's diff from the current color
    if (strcmp(colour, currentColour) != 0) {
        printf("%s", colour);
        currentColour = colour;
    }
}

int main(int argc, char* argv[]) {
    // check if we have the correct number of arguments
    if (argc != 2) {
        return 1;
    }
    
    // Get the code word from command line arguments
    const char* theWord = argv[1];
    int wordLength = strlen(theWord);
    
    // Validate the code word length (should be <= 12)
    if (wordLength > 12) {
        printf("Code word too long!\n");
        return 1;
    }
    
    char guess[13];  // Max 12 chars + null terminator
    int guessCount = 0;
    int correctGuess = 0;
    
    // Game loop - max 6 guesses
    while (guessCount < 6) {
        // Get user guess
        printf("Enter guess: ");
        scanf("%12s", guess);
        guessCount++;
        
        // If length doesn't match, skip (per spec we can assume they match)
        if (strlen(guess) != wordLength) {
            guessCount--;
            continue;
        }
        
        // Process the guess
        correctGuess = 1;
        
        // Count letters in the code
        int letterCounts[26] = {0};
        for (int i = 0; i < wordLength; i++) {
            letterCounts[theWord[i] - 'a']++;
        }
        
        // First, mark the green letters (correct positions)
        int *green = (int *)malloc(wordLength * sizeof(int));
        memset(green, 0, wordLength * sizeof(int));
        
        for (int i = 0; i < wordLength; i++) {
            if (guess[i] == theWord[i]) {
                green[i] = 1;
                letterCounts[theWord[i] - 'a']--;
            } else {
                correctGuess = 0;  // Not a perfect match
            }
        }
        
        // Now print the guess with appropriate colors
        for (int i = 0; i < wordLength; i++) {
            if (green[i]) {
                // Letter is in the correct position
                setColour(GREEN);
            } else if (letterCounts[guess[i] - 'a'] > 0) {
                // Letter exists in the code but in a different position
                setColour(YELLOW);
                letterCounts[guess[i] - 'a']--;
            } else {
                // Letter is not in the code
                setColour(WHITE);
            }
            
            printf("%c", guess[i]);
        }
        
        // Reset color and print newline
        setColour(RESET);
        printf("\n");
        
        // Check if guess was correct
        if (correctGuess) {
            printf("Finished in %d guesses\n", guessCount);
            return 0;
        }
    }
    
    // If we get here, all 6 guesses were used
    printf("Failed to guess the word: %s\n", theWord);
    
    return 0;
}