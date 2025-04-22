#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);

int main(void)
{
    // Manual input of the string to sort
    int numbers[] = {20, 500, 30, 55, 10, 0, 3};
    // Calling the sorting function and printing result
    int len = sizeof(numbers) / sizeof(numbers[0]);
    sort(numbers, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    return 0;
}

// sorting
void merge(int array[], int start, int mid, int end)
{
    int size = sizeof(int);
    // finding numbers of elements in left and right parts
    int num_left = mid - start + 1;
    int num_right = end - mid;
    // memory allocation for two temporary arrays for both parts
    int *tmp_left = (int *) malloc(num_left * size);
    int *tmp_right = (int *) malloc(num_right * size);
    // copying elements of array into both parts
    for (int i = 0; i < num_left; i++)
        tmp_left[i] = array[start + i];
    for (int j = 0; j < num_right; j++)
        tmp_right[j] = array[mid + 1 + j];
    // merging temp parts into sorted array
    for (int i = 0, j = 0, k = start; k <= end; k++)
    {
        if ((i < num_left) && (j >= num_right || tmp_left[i] <= tmp_right[j]))
        {
            array[k] = tmp_left[i];
            i++;
        }
        else
        {
            array[k] = tmp_right[j];
            j++;
        }
    }
    free(tmp_left);
    free(tmp_right);
}
/*  Merge Sort algorithm:
    Sort left half of numbers
    Sort right half of numbers
    Merge sorted halves
    Base case:  if only one number
                Quit */
void sort(int array[], int start, int end)
{
    // Base case:    if only one number
    //               Quit
    if (start >= end)
        return;
    {
        // finding middle
        int mid = (end - start) / 2 + start;
        // dividing left part
        sort(array, start, mid);
        // dividing right part
        sort(array, mid + 1, end);
        // sorting halves and merging
        merge(array, start, mid, end);
    }
}
