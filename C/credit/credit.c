#include <cs50.h>
#include <stdio.h>
long long card(void);
long long cut_number(long long x);
int last_digit(long long x);
int sum_alternated(long long x);
int sum_twins(long long x);
int checksum(long long x);
int first_digit(long long x);
int two_digits(long long x);
int length_number(long long x);

int main(void)
{
    long long number = card();
    int l = length_number(number);

    //  checking that number is valid
    if (last_digit(checksum(number)) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // checking if it's a AMEX card
    int amex_numbers[] = {34, 37};
    for (int i = 0; i < 2; i++)
    {
        if (two_digits(number) == amex_numbers[i] && l == 15)
        {
            printf("AMEX\n");
            return 0;
        }
    }
    // checking if it's a Mastercard
    int master_numbers[] = {51, 52, 53, 54, 55};
    for (int i = 0; i < 5; i++)
    {
        if (two_digits(number) == master_numbers[i] && l == 16)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }
    // checking if it's a VISA card
    if (first_digit(number) == 4 && (l == 13 || l == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// prompt credit card number
long long card(void)
{
    long long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);
    return n;
}
// cutting card number one digit
long long cut_number(long long x)
{
    long long y;
    y = x / 10;
    return y;
}
// getting last digit
int last_digit(long long x)
{
    int y = x % 10;
    return y;
}
// calculating sum of alternated digits starting from last digit
int sum_alternated(long long x)
{
    int s = 0;
    long long y = x;
    while (y > 0)
    {
        s += last_digit(y);
        y = cut_number(cut_number(y));
    }
    return s;
}
// calculating sum of alternated digits multiplied by 2 starting from second-to-last digit
int sum_twins(long long x)
{
    int s = 0;
    long long y = cut_number(x);

    while (y > 0)
    {
        int d = last_digit(y) * 2;
        if (d >= 10)
        {
            d = cut_number(d) + last_digit(d);
        }
        s += d;
        y = cut_number(cut_number(y));
    }
    return s;
}
// calculating checksum
int checksum(long long x)
{
    int s = sum_twins(x) + sum_alternated(x);
    return s;
}
// getting first digit
int first_digit(long long x)
{
    while (x >= 10)
    {
        x = cut_number(x);
    }
    return (int) x;
}
// getting two first digits
int two_digits(long long x)
{
    while (x >= 100)
    {
        x = cut_number(x);
    }
    return (int) x;
}
// calculating the length of a number
int length_number(long long x)
{
    int s = 0;
    long long y = x;
    while (y > 0)
    {
        s++;
        y = cut_number(y);
    }
    return s;
}
