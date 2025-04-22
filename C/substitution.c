#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int KEYLEN = 26;

int main(int argc, string argv[])
{
    // Validating the key, provided in command-line input
    // Checking the input is one argument:
    if (argc != 2)
    {
        printf("Usage: ./substitution Key\n");
        exit(1);
    }
    // Checking the key is 26 alphabetic characters:
    else if (strlen(argv[1]) != KEYLEN)
    {
        printf("Key must contain %i characters\n", KEYLEN);
        exit(1);
    }
    // Checking the key is alphabetic characters:
    for (int i = 0; i < KEYLEN; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters\n");
            exit(1);
        }
    }
    // Checking the key is KEYLEN (26) non-repetitive alphabetic characters:
    bool repetitive[KEYLEN] = {false};
    for (int i = 0; i < KEYLEN; i++)
    {
        char key = toupper(argv[1][i]);
        key = key - 'A';
        if (repetitive[(int) key] == true)
        {
            printf("Key must contain %i non-repetitive alphabetic characters\n", KEYLEN);
            exit(1);
        }
        else
        {
            repetitive[(int) key] = true;
        }
    }
    // Converting key to uppercase
    char upper_key[KEYLEN];
    for (int i = 0; i < KEYLEN; i++)
    {
        upper_key[i] = toupper(argv[1][i]);
    }
    // Mapping key to alphabetic characters by building key_position array

    int map[KEYLEN];
    for (int i = 0; i < KEYLEN; i++)
    {
        map[i] = (int) (upper_key[i] - 'A');
    }

    // Prompting text to encrypt
    string plaintext = get_string("plaintext:  ");

    // Encrypting string using the map array
    int len = strlen(plaintext);
    char ciphertext[len];

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = (map[plaintext[i] - 'A']) % KEYLEN + 'A';
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = (map[plaintext[i] - 'a']) % KEYLEN + 'a';
        }
    }
    ciphertext[len] = '\0';
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
