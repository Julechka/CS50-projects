#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int i = get_int("Input: ");
    printf("Number of steps to 1: %i\n", collatz(i));
}
int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;
    // recursive call for even numbers
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    // recursive call for odd numbers
    else
        return 1 + collatz(n * 3 + 1);
}
