#include <stdio.h>
#include <cs50.h>
#include <string.h>

// comparing strings without using CS50.h
// still we need it for get_string
int main (void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strcmp(s,t) == 0)
        printf("Same\n");
    else
        printf("Diferent\n");
}
