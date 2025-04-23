#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// To mimick the behavior of an array by consuming input from stdin by just using getchar() we have to do two passes

int main(int argc, char *argv[])
{
    int c;
    int numDigits = 0;
    int checkDig;
    int checkSum;

    while ((c = getchar()) != EOF && (c >= '0' && c <= '9'))
    {
        numDigits++;
    }

    // Now we have the number of digits

    rewind(stdin); // rewind the standard input to consume characters again

    for (int positionInSum = 0; positionInSum <= numDigits; positionInSum++)
    {
        c = getchar();
        // since c is a character we need to convert the character to an integer which we do by the subtraction of ASCII values so what we do is take c - '0' which is basically the same as c - 48

        int actual_c = c - '0';

        if (positionInSum == numDigits)
        {
            checkDig = actual_c;
        }
        else
        {
            if ((numDigits - 1) % 2 == 0 && positionInSum % 2 == 0)
            {
                checkSum += actual_c;
            }
            else
            {
                ((2 * actual_c) >= 10) ? (checkSum += (actual_c - 9)) : (checkSum += actual_c);
            }
        }

        if ((checkSum % 10) != checkDig)
        {
            printf("Invalid");
        }
        else
        {
            printf("Valid");
        }
    }
}