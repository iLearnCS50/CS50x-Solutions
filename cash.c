#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int q = 0, d = 0, p = 0, n = 0, sum, balance;
    do
    {
        balance = get_int("Change owed:");
    }
    while (balance < 0);
    if (balance == 0)
    {
        sum = 0;
    }
    while (balance > 0)
    {
        if (balance >= 25)
        {
            q++;
            balance = balance - 25;
        }

        else if (balance >= 10)
        {
            d++;
            balance = balance - 10;
        }

        else if (balance >= 5)
        {
            n++;
            balance = balance - 5;
        }
        else
        {
            p++;
            balance = balance - 1;
        }
    }

    {
        if (balance >= 1)
        {
            p++;
            balance = balance - 1;
        }
    }

    sum = q + d + p + n;
    printf("%i\n", sum);
}