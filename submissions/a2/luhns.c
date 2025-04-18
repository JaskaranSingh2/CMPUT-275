#include <stdio.h>

int main()
{
    int c;
    int sum = 0;
    int digCount = 0;
    int checkDig;

    // first pass we count the digits
    while ((c = getchar()) != EOF && c >= '0' && c <= '9')
    {
        digCount++;
    }

    // no digits read
    if (digCount == 0)
    {
        printf("Invalid\n");
        return 0;
    }

    // rewind stdin
    rewind(stdin);

    // the second pass - process digits according to the Luhn's algorithm
    for (int pos = 1; pos <= digCount; pos++)
    {
        c = getchar();
        int digit = c - '0';

        // the last digit is the check digit
        if (pos == digCount)
        {
            checkDig = digit;
        }
        else
        {
            // determine if this digit should be doubled
            // we double every second digit from the right, excluding the check digit
            // (digCount - pos) gives the position from the right (0-indexed)
            // if this position is odd, double the digit
            if ((digCount - pos) % 2 == 1)
            {
                digit *= 2;
                if (digit >= 10)
                {
                    digit -= 9;
                }
            }

            // add it to the sum
            sum += digit;
        }
    }

    // calc. the expected check digit according to the formula
    int expectedCheckDig = (sum * 9) % 10;

    // Verify
    if (expectedCheckDig == checkDig)
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}