// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 71;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Access linked list in a hash table, then traverse it
    node *cursor = table[hash(word)];
    if (cursor == NULL)
        return false;

    while (cursor != NULL)
    {
        // Compare word with the first word in linked list
        if (strcasecmp(word, cursor->word) == 0)
            return true;

        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // 45 first prime numbers
    int prime_list[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
                        53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                        127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197};
    // Hash function that uses a sum of ASCII values multiplied by prime number
    unsigned long key = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        key += toupper(word[i]) * prime_list[i];
    }
    return key % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Clear table
    for (int i = 0; i < N; i++)
        table[i] = NULL;

    // Open dictiorary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Error opening the file \n");
        return false;
    }
    // Create a buffer of size LENGTH for the word
    char word[LENGTH + 1];

    // Read each word from file one at a time
    while (fscanf(source, "%s", word) == 1)
    {
        // Allocate a memory for a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }

        // Create a new node for each word
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Hash word to obtain a hash value
        unsigned long index = hash(word);

        // Set pointer to the head of the linked list
        new_node->next = table[index];
        // Set the head pointer to the new word added
        table[index] = new_node;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int wordcount = 0;
    for (unsigned int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            wordcount++;
            cursor = cursor->next;
        }
    }
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free nodes recursively
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
