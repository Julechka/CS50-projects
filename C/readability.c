#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int words(string text);
int letters(string text);
int sentences(string text);

// Coleman-Liau constants
const float CLI1 = 5.88;
const float CLI2 = 29.6;
const float CLI3 = 15.8;

int main(void)
{
    string text_input = get_string("Text: ");
    int words_count = words(text_input);
    // compute Coleman-Liau Index
    int index = round(CLI1 * letters(text_input) / words_count -
                      CLI2 * sentences(text_input) / words_count - CLI3);
    // print readability score
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
// count words
int words(string text)
{
    int words_count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i]) == ' ')
        {
            words_count++;
        }
    }
    return (words_count);
}
// count letters
int letters(string text)
{
    int letters_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters_count++;
        }
    }
    return (letters_count);
}

// count sentences
int sentences(string text)
{
    int sentences_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_count++;
        }
    }
    return (sentences_count);
}
