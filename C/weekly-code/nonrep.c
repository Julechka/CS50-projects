#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

const int KEYLEN = 26;

int main(int argc, string argv[])
{
// Checking the input is 26 non-repetitive alphabetic characters:
bool repetitive[KEYLEN] = {false};

for (int i = 0; i < KEYLEN; i++)
{
    char key = toupper(argv[1][i]);
    key = key - 'A';

    if (repetitive[(int)key] == true)
    {
        printf("Key must contain %i non-repetitive alphabetic characters\n", KEYLEN);
        exit(1);
    }
    else
    {
        repetitive[(int)key] = true;
    }
}
}
