#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main (void)
{
    int height = get_int("Height: ");
    draw (height);
}

void draw(int n)
{
    // considering base case
    if (n <= 0)
    {
        return;
    }
    // recursive call
    draw(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
     }
     printf("\n");
}
