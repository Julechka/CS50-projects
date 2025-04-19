#include <cs50.h>
#include <stdio.h>
int owed(void);
int coins(int x, int y);
int rest(int x, int y, int z);

int main(void)
{
    int n = owed();
    int k = 0;

    // counting quarters
    if (n >= 25)
    {
        k = k + coins(n, 25);
        n = rest(n, 25, coins(n, 25));
    }
    // counting dimes
    if (n >= 10)
    {
        k = k + coins(n, 10);
        n = rest(n, 10, coins(n, 10));
    }
    // counting nickels
    if (n >= 5)
    {
        k = k + coins(n, 5);
        n = rest(n, 5, coins(n, 5));
    }
    // counting pennies and final result
    k = k + n;
    printf("%i\n", k);
}
// prompting change owed
int owed(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);
    return n;
}
// counting coins of value y for amount x
int coins(int x, int y)
{
    int m = x / y;
    return m;
}
// counting rest from x after having z coins of value y
int rest(int x, int y, int z)
{
    int m = x - y * z;
    return m;
}
