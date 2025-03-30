#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE rgbtBlue = image[i][j].rgbtBlue;
            BYTE rgbtGreen = image[i][j].rgbtGreen;
            BYTE rgbtRed = image[i][j].rgbtRed;
            BYTE rgbtAvg = round((rgbtBlue + rgbtGreen + rgbtRed) / 3.0);
            image[i][j].rgbtBlue = rgbtAvg;
            image[i][j].rgbtGreen = rgbtAvg;
            image[i][j].rgbtRed = rgbtAvg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE originalBlue = image[i][j].rgbtBlue;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalRed = image[i][j].rgbtRed;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = (BYTE) sepiaBlue;
            image[i][j].rgbtGreen = (BYTE) sepiaGreen;
            image[i][j].rgbtRed = (BYTE) sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            BYTE tempBlue = image[i][j].rgbtBlue;
            BYTE tempGreen = image[i][j].rgbtGreen;
            BYTE tempRed = image[i][j].rgbtRed;

            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1].rgbtBlue = tempBlue;
            image[i][width - j - 1].rgbtGreen = tempGreen;
            image[i][width - j - 1].rgbtRed = tempRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int n;

    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)

        {
            n = 9;
            int blueSum = 0;
            int greenSum = 0;
            int redSum = 0;
            int countR = -1;
            for (int l = 0; l < 3; l++)
            {

                int countC = -1;
                for (int m = 0; m < 3; m++)
                {
                    if ((i + countR) > -1 && (j + countC) > -1 && (i + countR) < height &&
                        (j + countC) < width)
                    {
                        blueSum = blueSum + image[i + countR][j + countC].rgbtBlue;
                        greenSum = greenSum + image[i + countR][j + countC].rgbtGreen;
                        redSum = redSum + image[i + countR][j + countC].rgbtRed;
                    }
                    countC++;
                }
                countR++;
            }

            if (i == 0 || i == height - 1)
            {
                n = n - 3;
            }
            if (j == 0 || j == width - 1)
            {
                n = n - 3;
            }
            if (n < 4)
            {
                n = 4;
            }

            temp[i][j].rgbtBlue = (BYTE) round((blueSum / (float) n));
            temp[i][j].rgbtGreen = (BYTE) round((greenSum / (float) n));
            temp[i][j].rgbtRed = (BYTE) round((redSum / (float) n));
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
