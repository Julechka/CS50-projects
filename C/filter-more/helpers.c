#include "helpers.h"
#include <math.h>

// Defining channels for Sobel function
typedef enum { RED, GREEN, BLUE } color_channel;

void swap(BYTE *a, BYTE *b);
int average_array(int array[], int array_length);
int sobel(int height, int width, int i, int j, RGBTRIPLE array[height][width],
          color_channel channel);

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a working image with black borders
    RGBTRIPLE copy_padded[height + 2][width + 2];
    // Make new image black
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            copy_padded[i][j].rgbtRed = 0;
            copy_padded[i][j].rgbtGreen = 0;
            copy_padded[i][j].rgbtBlue = 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            copy_padded[i + 1][j + 1] = image[i][j];
    }

    // Computing pixels value with Sobel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = sobel(height + 2, width + 2, i + 1, j + 1, copy_padded, RED);
            image[i][j].rgbtGreen = sobel(height + 2, width + 2, i + 1, j + 1, copy_padded, GREEN);
            image[i][j].rgbtBlue = sobel(height + 2, width + 2, i + 1, j + 1, copy_padded, BLUE);
        }
    }
    return;
}
// Sobel function
int sobel(int height, int width, int i, int j, RGBTRIPLE array[height][width],
          color_channel channel)
{
    // Define kernels
    int Gx_Kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_Kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int Gx = 0;
    int Gy = 0;

    // Compute Gx and Gy
    for (int m = -1; m < 2; m++)
    {
        for (int n = -1; n < 2; n++)
        {
            int mi = m + i;
            int nj = n + j;
            int color = 0;
            // Switch
            switch (channel)
            {
                case RED:
                    color = array[mi][nj].rgbtRed;
                    break;
                case GREEN:
                    color = array[mi][nj].rgbtGreen;
                    break;
                case BLUE:
                    color = array[mi][nj].rgbtBlue;
                    break;
            }
            Gx += color * Gx_Kernel[m + 1][n + 1];
            Gy += color * Gy_Kernel[m + 1][n + 1];
        }
    }
    // Calculate the square root of Gx^2 + Gy^2
    int Gsq = round(sqrt(Gx * Gx + Gy * Gy));
    // Check the value doesn't exceed 255, is yes set to 255
    Gsq = (Gsq > 255) ? 255 : Gsq;
    return Gsq;
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
