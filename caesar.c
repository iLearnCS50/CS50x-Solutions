#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void endprog(void);
//command-line argument format(argc stores the number of command line inputs and argv[]stores the inputs)
//IMP:argc also counts ./{prog name} as an input and it is stored in argv[0]
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        endprog();
    }
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(argv[1][i]))
        {
            endprog();
        }
    }
    int key_val = atoi(argv[1]);
    string text = get_string("plaintext: \n");
    int text_len = strlen(text);
    printf("ciphertext: ");
    char cipher[text_len + 1];
    for (int j = 0; j < text_len; j++)
    {
        if (isupper(text[j]))
        {
            int charec = text[j] - 'A';
            charec = (charec + key_val) % 26;
            cipher[j] = charec + 'A';
        }
        else if (islower(text[j]))
        {
            int charec = text[j] - 'a';
            charec = (charec + key_val) % 26;
            cipher[j] = charec + 'a';
        }
        else
        {
            cipher[j] = text[j];
        }
    }
    printf("%s\n", cipher);
}

//function definition(this can also be placed above main,and that would require the empty function call for initialisation)
void endprog(void)
{
    printf("Usage: ./caesar key\n");
    exit(1);
}