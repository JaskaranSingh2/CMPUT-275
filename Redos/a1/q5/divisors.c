#include <stdio.h>

int main()
{
    int i;

    if (scanf("%d", &i) == 1)
    {
        printf("%d ", 1);
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                printf("%d ", j);
            }
            else if (i == j)
            {
                printf("%d ", i);
            }
        }
    }
}