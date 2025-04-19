#include <cs50.h>
#include <stdio.h>
#include <string.h>

int position_min(int start_position, int length, int array[]);

int main(void)
/*  This is implementation of the selection sort algorithm:
    For i from 0 to n-1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]

    for array of int which is coded in line 12.
    Numbers in array numbers[] could be replaced
    The size of array is computed automatically */
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < len; i++)
    {
        // getting position of minimal number is array
        int n = position_min(i, len, numbers);

        // swaping elements in array
        int temp = numbers[n];
        numbers[n] = numbers[i];
        numbers[i] = temp;
    }

    // printing new version of numbers[]
    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    return 0;
}
// finding position of minimal number is array
int position_min(int start_position, int length, int array[])
{
    int min_position = start_position;

    for (int i = start_position; i < length; i++)
    {
        if (array[i] < array[min_position])
        {
            min_position = i;
        }
    }
    return (min_position);
}
