#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Colour codes
const char *YELLOW = "\x1b[33m";
const char *GREEN = "\x1b[32m";
const char *WHITE = "\x1b[0m";

const char *currentColour = NULL;

void setColour(const char *colour)
{
    if (currentColour != colour)
    {
        printf("%s", colour);
        currentColour = colour;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    const char *code = argv[1];
    int codeLen = strlen(code);
    int guessCount = 0;
    char guess[13];

    while (guessCount < 6)
    {
        printf("Enter guess: ");
        if (!fgets(guess, sizeof(guess), stdin))
            break;
        guess[strcspn(guess, "\n")] = 0;

        if (strlen(guess) != codeLen)
            continue;

        int green[12] = {0};
        int codeCounts[128] = {0};

        // Count characters in code
        for (int i = 0; i < codeLen; i++)
            codeCounts[(int)code[i]]++;

        // Mark green characters and deduct counts
        for (int i = 0; i < codeLen; i++)
        {
            if (guess[i] == code[i])
            {
                green[i] = 1;
                codeCounts[(int)guess[i]]--;
            }
        }

        // Process colors
        currentColour = WHITE; // Assume reset state after prompt
        for (int i = 0; i < codeLen; i++)
        {
            char ch = guess[i];
            if (green[i])
            {
                setColour(GREEN);
            }
            else if (codeCounts[(int)ch] > 0)
            {
                setColour(YELLOW);
                codeCounts[(int)ch]--;
            }
            else
            {
                setColour(WHITE);
            }
            putchar(ch);
        }

        // Print newline first, then reset color
        printf("\n");
        setColour(WHITE);

        guessCount++;

        if (strcmp(guess, code) == 0)
        {
            printf("Finished in %d guesses\n", guessCount);
            return 0;
        }
    }

    printf("Failed to guess the word: %s\n", code);
    return 0;
}