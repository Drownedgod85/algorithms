#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int r = 0; r < width; r++)
        {
    //color value
             int red = image[i][r].rgbtRed;
             int blue = image[i][r].rgbtBlue;
             int green = image[i][r].rgbtGreen;

    //average
             float average = (round(red) + round(blue) + round(green)) / 3;
             average = round(average);

    //implement color
             image[i][r].rgbtRed = average;
             image[i][r].rgbtBlue = average;
             image[i][r].rgbtGreen = average;
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int r = 0; r < width; r++)
        {
            int sepiaRed = round(.393 * image[i][r].rgbtRed + .769 * image[i][r].rgbtGreen + .189 * image[i][r].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][r].rgbtRed + .686 * image[i][r].rgbtGreen + .168 * image[i][r].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][r].rgbtRed + .534 * image[i][r].rgbtGreen + .131 * image[i][r].rgbtBlue);

            image[i][r].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][r].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][r].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
        }
    }
    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int r = 0; r < width / 2; r++)
        {
            swap(&image[i][r], &image[i][width - 1 - r]);
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int r = 0; r < width; r++)
        {
            int sumBlue = 0;
            int sumRed = 0;
            int sumGreen = 0;
            float counter = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int j = -1; j < 2; j++)
                {

                    if (i + m < 0 || i + m > height - 1 || r + j < 0 || r + j > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + m][r + j].rgbtBlue;
                    sumGreen += image[i + m][r + j].rgbtGreen;
                    sumRed += image[i + m][r + j].rgbtRed;

                    counter++;
                }
            }
            temp[i][r].rgbtBlue = round(sumBlue / counter);
            temp[i][r].rgbtGreen = round(sumGreen / counter);
            temp[i][r].rgbtRed = round(sumRed / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int r = 0; r < width; r++)
        {
            image[i][r].rgbtBlue = temp[i][r].rgbtBlue;
            image[i][r].rgbtRed = temp[i][r].rgbtRed;
            image[i][r].rgbtGreen = temp[i][r].rgbtGreen;
        }
    }

    return;
}