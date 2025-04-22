#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* This is the implementation of bubble sort algorithm:
    Repeat n times
        For i from 0 to n-2
            If numbers[i] and numbers[i+1] out of order
                Swap them

    */
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int len_unsorted = length - 1;

    do
    {
        int swaps = 0;
        for (int i = 0; i < len_unsorted; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                // swaping elements in array
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;

                swaps++;
            }
        }
        // if no swaps go to print
        if (swaps == 0)
        {
            break;
        }
        len_unsorted--;
    }
    while (len_unsorted > 1);
    // printing new version of numbers[]
    for (int i = 0; i < length; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    return 0;
}
