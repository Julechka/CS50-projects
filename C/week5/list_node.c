#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// linked list
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL; /* pointer to the begining of the list */
    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // TODO: free any memory already malloc'd
            return 1;
        }

        /* (*n).number = 1;  "old" syntax. simplified syntax: */
        n->number = get_int("Number: ");
        n->next = NULL;

        // If list is empty
        if (list == NULL)
            list = n;

        // If list has numbers already
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    /* First version of printing the list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    } */

    // Time passes

    // Updated version of printing
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%i\n", ptr->number);

    // Time passes

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}
