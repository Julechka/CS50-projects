#include "helpers.h"
#include <math.h>

void swap(BYTE *a, BYTE *b);
int average_array(int array[], int array_length);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute average of red, green, and blue
            int temp_pixel[] = {image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue};
            int average = average_array(temp_pixel, 3);

            // Update RGB
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Store original values in temp variable
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Update RGB
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Check the value doesn't exceed 255
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels in the row
            swap(&image[i][j].rgbtRed, &image[i][width - j - 1].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][width - j - 1].rgbtGreen);
            swap(&image[i][j].rgbtBlue, &image[i][width - j - 1].rgbtBlue);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];
    }
    // Blur pixels

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            for (int m = (i - 1); m <= (i + 1); m++)
            {
                for (int n = (j - 1); n <= (j + 1); n++)
                {
                    if (m >= 0 && m < height && n >= 0 && n < width)
                    {
                        sumRed += copy[m][n].rgbtRed;
                        sumGreen += copy[m][n].rgbtGreen;
                        sumBlue += copy[m][n].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(sumRed / (float) count);
            image[i][j].rgbtGreen = round(sumGreen / (float) count);
            image[i][j].rgbtBlue = round(sumBlue / (float) count);
        }
    }
    return;
}

void swap(BYTE *a, BYTE *b)
{
    BYTE temp = *a;
    *a = *b;
    *b = temp;
}

int average_array(int array[], int array_length)
{
    int sum = 0;
    for (int i = 0; i < array_length; i++)
    {
        sum += array[i];
    }
    int average = round(sum / (float) array_length);
    return average;
}
