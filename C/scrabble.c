#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int word_score(string word);

// Declare array
const int SCORE[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Compute and compare scores and print result
    int score1 = word_score(word1);
    int score2 = word_score(word2);
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
// compute word scores
int word_score(string word)
{
    int s = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // convert letters of the word to upper case
        word[i] = toupper(word[i]);
        // check on alphabetical characters
        if (isalpha(word[i]))
        //  compute score
        {
            s += SCORE[word[i] - 'A'];
        }
    }
    return s;
}
