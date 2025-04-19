#include <cs50.h>
#include <stdio.h>
void print_spaces(int m);
void print_hashes(int k);
int size(void);

int main(void)
{
    // ask the size of the pyramid
    int n = size();
    // printing the pyramid

    int p = n - 1;

    for (int f = 1; f <= n; f++)
    {

        print_spaces(p);
        print_hashes(f);
        print_spaces(2);
        print_hashes(f);
        p--;
        printf("\n");
    }
}

// function for printing m spaces
void print_spaces(int m)
{
    for (int i = m; i > 0; i--)
    {
        printf(" ");
    }
}
// function for printing k hashes
void print_hashes(int k)
{
    for (int j = 1; j <= k; j++)
    {
        printf("#");
    }
}
// function for prompting the size of the pyramid
int size(void)
{
    int n;
    do
    {
        n = get_int("How tall is the pyramid? Chose the number between 1 and 8: ");
    }
    while (n < 1 || n > 8);
    return n;
}
