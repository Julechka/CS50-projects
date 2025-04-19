#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

// Constant N: number of inputs
const int N = 5;

// Prototypes
float average(int length, int array[]);

int main(void)
{

    // Get number
    int numbers [N];
    for (int i = 0; i < N; i++)
    {
        numbers[i] = get_int("Number %i: ", i+1);
    }
    //print result
    printf("Average: %f\n", average(N,numbers));
}
    //compute average
    float average(int length, int array[])
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += array[i];
        }
        return sum / (float) length;
    }
