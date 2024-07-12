#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int text_words(string text_);
int text_sentences(string text_);
int text_letters(string text_);
int words = 0;
int sentences = 0;
int no_letters;
int main(void)
{
    string text = get_string("Text: ");
    words = text_words(text);
    no_letters = text_letters(text);
    sentences = text_sentences(text);

    float L = (no_letters / (float) words) * 100.0;
    float S = (sentences / (float) words) * 100.0;
    int index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int text_words(string text_)
{

    for (int j = 0; j < strlen(text_); j++)
    {
        if (text_[j] == ' ')
        {
            words++;
        }
    }
    words = words + 1;
    return words;
}

int text_sentences(string text_)
{
    for (int i = 0; i < strlen(text_); i++)
    {
        if (text_[i] == '.' || text_[i] == '!' || text_[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int text_letters(string text_)
{
    for (int k = 0; k < strlen(text_); k++)
    {
        if (text_[k] != ' ' && text_[k] != '.' && text_[k] != '?' && text_[k] != '!')
        {
            no_letters++;
        }
    }
    return no_letters;
}