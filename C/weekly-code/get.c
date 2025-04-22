#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n);

    printf("n: %i\n", n);

    /* for stings there is a danger to overflow the memory:
    char *s;
    printf("string: ");
    scanf("%s", s);
    printf("s: %s\n", n);

    That's why stil use CS50 developed sting.h */
}
