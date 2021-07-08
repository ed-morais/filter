#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculates the average value
            float avg = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            avg = avg / 3;
            //rounds the value to ne nearest integer
            int roundedavg = round(avg);
            //assign new value
            image[i][j].rgbtBlue = roundedavg;
            image[i][j].rgbtGreen = roundedavg;
            image[i][j].rgbtRed = roundedavg;
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
            
            //applying the formula 
            double sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            double sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            double sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            
            //rounds the result of the formula 
            int blue = round(sepiaBlue);
            int green = round(sepiaGreen);
            int red = round(sepiaRed);
            
            //checks if value is greater than 255
            if (blue > 255)
            {
                blue = 255;
            } 
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }
            
            //assign new value to the pixels
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE reflect[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        { 
            
            //Creates a temporary variable so we can swap values
            RGBTRIPLE tempo;
            
            tempo = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tempo;
            
        }
    }
    return;
}

bool valid_px(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
    
}

RGBTRIPLE blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{   
    int r_value, b_value, g_value; r_value = b_value = g_value = 0;
    int num_valid_px = 0;
    for (int id = -1; id <= 1; id++)
    {
        for (int jd = -1; jd <=1; jd++)
        {
            int new_i = i + id;
            int new_j = j + jd;
            if (valid_px(new_i, new_j, height, width))
            {
                num_valid_px++;
                r_value += image[new_i][new_j].rgbtRed;
                b_value += image[new_i][new_j].rgbtBlue;
                g_value += image[new_i][new_j].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blur_pixel;
    blur_pixel.rgbtRed = round((float)r_value / num_valid_px);
    blur_pixel.rgbtGreen = round((float)g_value / num_valid_px);
    blur_pixel.rgbtBlue = round((float)b_value / num_valid_px);
    return blur_pixel;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = blur_pixel(i, j, height, width, image);
        }
    }
    
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = new_image[i][j];
    
}    
