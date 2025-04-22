#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_not_numeric(string s);
int ceasar_key(string c);
char encrypt_char(char t, int key);
//string encrypt_text(string text, int key);
string encrypt_text(string text, int key);

const int MOD = 26;

// prompting input with command-line argument
int main(int argc, string argv[])
{
    // validating input from command line
    if ((argc != 2) || string_not_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    // converting the key to int %26
    int key = ceasar_key(argv[1]);

    // prompting text to encrypt
    string plaintext = get_string("plaintext:  ");

    int len_plain = strlen (plaintext);

    // print encrypting text
    string ciphertext = encrypt_text(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
// functions

// validating input
int string_not_numeric(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return 1;
        }
    }
    return 0;
}
// converting key to int %26
int ceasar_key(string c)
{
    int k = atoi(c) % MOD;
    return (k);
}
// encrypting char
char encrypt_char(char t, int key)
{
    if (isupper(t))
    {
        t = (t + key - 'A') % MOD + 'A';
    }
    else if (islower(t))
    {
        t = (t + key - 'a') % MOD + 'a';
    }
    return (t);
}

// encripting string
string encrypt_text(string text, int key)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            text[i] = encrypt_char(text[i], key);
        }
        else if (!isalpha(text[i]))
        {
            text[i] = text[i];
        }
    }
    return (text);
}
