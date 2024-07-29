#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //calling a variable without a initial assigned value gives it a garbage value so be careful not to use it without assigning it anywhere. 
    int n;
    int j = 0;
    do
    {
        n = get_int("Height:");
    }
    //loops till the value entered is not in the range assigned in the probset
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
        printf("\n");
    }
}
