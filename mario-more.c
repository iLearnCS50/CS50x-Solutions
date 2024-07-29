#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int j = 0;
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int k = j; k < n - 1; k++)
        {
            printf(" ");
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //this prints the remaining part from mario-less
        printf("  ");
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}