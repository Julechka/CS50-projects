#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);

    int *p = &n;
    // &n is the address of n in computer
    // int *p is the pointer to this address. When declaring/initiating, type is mandatory
    // %p uses for printing the pointer
    printf("%p\n", p);

    // it's possible to print the address directly without using variable p
    printf("%p\n",&n);

    // de-referencing the pointer gives us back n:
    printf("%i\n", *p); //not nesessary to use type (int in this case)

    // in CS50.h implemented type "string s".
    // Without CS50.h it's "char *s":
    // typedef char *string;

   char *s = "Hi!";
   printf("%p\n", s); // if it would be &s it would return address of the pointer
   printf("%p\n", &s[0]);

   printf("%s\n", s);
   printf("%s\n", s + 1);
   printf("%c\n", s[0]);
   printf("%c\n", *s);
}
