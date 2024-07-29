//library functions
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //asks the user for a input string(cs50 specific, not available in standard libraby)
    string name = get_string("What is your name?\n");
    //printf = print formatted. this is a standard lib function.
    printf("hello, %s\n", name);
}
