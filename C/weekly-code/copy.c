#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char *s = get_string("s: ");
    char *t = s;

    t[0] = toupper( t[0]);
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    // Both strings changed because they are at the same location
    //(address of the first byte is the same)

    // To solve it uses malloc(number of bytes)

    char *s1 = get_string("s1: ");
    char *t1 = malloc(strlen(s) + 1);
    if (t1 == NULL)
        return 1;
/* Copy in a loop
    for (int i = 0, n = strlen(s1); i <= n; i++)
    // <= to copy /0 - end of string
    {
        t1[i] = s1[i];
    }
*/
    // Alternatively use function strcpy
    strcpy(t1, s1);

    if (strlen(t1) > 0)
        t1[0] = toupper( t1[0]);
    printf("s1: %s\n", s1);
    printf("t1: %s\n", t1);

    // Free memory used
    free(t1);
}
