/*
-------------------------
Author : Li-Wei Yang
Date : 2021/11/2
Institution : National Taiwan University
Department : Biomechatronics Engineering
Status : Senior
-------------------------
Description:
    This is a class that would generate filters and do filter operation.
    Filters:
    Box, Gaussian, Sobel, Laplacian.
*/
#include "filter.h"
#include <math.h>

//constructor
Filter::Filter(int rows, int cols, double** weights, bool normalizeflag)
{
    this->Rows = rows;
    this->Cols = cols;
    this->elements = weights;
    this->total = 0;
    for (int r =0; r<Rows; r++)
    {
        for (int c = 0; c<Cols; c++)
        {
            this->total += weights[r][c];
        }

    }
    this->normalize = normalizeflag;

}

//generate box filter according to given dimensions
Filter* Filter::GenerateBoxFilter(int m, int n)
{
    double** elements;
    elements = new double* [m];
    for (int r =0; r<m; r++)
    {
        elements[r] = new double [n];
        for (int c = 0; c<n; c++)
        {
            elements[r][c] = 1.0;

        }

    }
    return new Filter(m, n, elements, true);
}

//Generate Gaussian filter according to given dimensions, by default the filter would be normalized;
//if not normalized, the scale (K) can be set.
Filter* Filter::GenerateGaussianFilter(int m, int n, double K, double Sigma)
{
    double** elements;
    Filter* gaussian;
    elements = new double* [m];
    for (int r =0; r<m; r++)
    {
        elements[r] = new double [n];
        for (int c = 0; c<n; c++)
        {
            elements[r][c] = K*exp(-(r^2 + c^2)/2.0/Sigma/Sigma);

        }

    }
    if(K!=1)
    {
        gaussian = new Filter(m,n, elements, false);
    }
    else
    {
        gaussian = new Filter(m,n, elements, true);

    }

    return gaussian;
}

//TODO: learn the algo.
Filter* Filter::GenerateLoGFilter(int m, int n, double std)
{
    double** elements;
    elements = new double* [m];
    for (int r =0; r<m; r++)
    {
        elements[r] = new double [n];
        for (int c = 0; c<n; c++)
        {
            double deltaY = r - m / 2;
            double deltaX = c - n / 2;
            double distanceSquare = deltaY * deltaY + deltaX * deltaX;
            elements[r][c] = - ( (distanceSquare /std / std - 2 ) / std / std ) * exp(-0.5 * distanceSquare / std / std);

        }

    }
    return new Filter(m, n, elements, true);
}

//Generate a Sobel 3*3 horizontal filter;
//the filter can detect where the pixel turn from black to white, horizontally.
Filter* Filter::GenerateSobelHoriFilter()
{
    double** elements;
    elements = new double* [3];
    for (int r = 0; r<3; r++)
    {
        elements[r] = new double [3];
    }
    elements[0][0] = -1.0;
    elements[0][1] = -2.0;
    elements[0][2] = -1.0;
    elements[1][0] = 0.0;
    elements[1][1] = 0.0;
    elements[1][2] = 0.0;
    elements[2][0] = 1.0;
    elements[2][1] = 2.0;
    elements[2][2] = 1.0;
    return new Filter(3, 3, elements, false);
}
//Generate a Sobel 3*3 vertical filter;
//the filter can detect where the pixel turn from black to white, vertically.
Filter* Filter::GenerateSobelVertiFilter()
{
    double** elements;
    elements = new double* [3];
    for (int r = 0; r<3; r++)
    {
        elements[r] = new double [3];
    }
    elements[0][0] = -1.0;
    elements[1][0] = -2.0;
    elements[2][0] = -1.0;
    elements[0][1] = 0.0;
    elements[1][1] = 0.0;
    elements[2][1] = 0.0;
    elements[0][2] = 1.0;
    elements[1][2] = 2.0;
    elements[2][2] = 1.0;
    return new Filter(3, 3, elements, false);
}
//Generate a Laplacian 3*3 half filter, without diagonal elements;
//the filter can detect edges in the image, in terms of high pass spatial filter;
//to sharp the image, simply add the result back to the original image;
Filter* Filter::GenerateLaplacianHalfFilter()
{
    double** elements;
    int c = -1;
    elements = new double* [3];
    for (int r = 0; r<3; r++)
    {
        elements[r] = new double [3];
    }
    elements[0][0] = c * 0;
    elements[1][0] = c * 1;
    elements[2][0] = c * 0;
    elements[0][1] = c * 1;
    elements[1][1] = c * -4;
    elements[2][1] = c * 1;
    elements[0][2] = c * 0;
    elements[1][2] = c * 1;
    elements[2][2] = c * 0;
    return new Filter(3, 3, elements, false);
}
//Generate a Laplacian 3*3 half filter, with diagonal elements included;
//the filter can detect edges in the image, in terms of high pass spatial filter;
//the filter can generate edges more solid;
//to sharp the image, simply add the result back to the original image;
Filter* Filter::GenerateLaplacianFullFilter()
{
    double** elements;
    elements = new double* [3];
    int c = -1;
    for (int r = 0; r<3; r++)
    {
        elements[r] = new double [3];
    }
    elements[0][0] = c * 1;
    elements[1][0] = c * 1;
    elements[2][0] = c * 1;
    elements[0][1] = c * 1;
    elements[1][1] = c * -8;
    elements[2][1] = c * 1;
    elements[0][2] = c * 1;
    elements[1][2] = c * 1;
    elements[2][2] = c * 1;
    return new Filter(3, 3, elements, false);
}


//An overloading operator to convolute a filter over an image;
//algorithm: first choose a point in the image (channel, r, c),
//then apply element-wise multiply in filter and image, using
//two variabes for each direction;
//if the index is out of image boundary, into next loop;
//sum the number then assign to the new image in (channel, r, c);
ColorImage* Filter::operator*(ColorImage* img)
{
    ColorImage* newimg;
    int Height = img->rows;
    int Width = img->cols;
    int rows = this->Rows;
    int cols = this->Cols;
    int*** pixels;
    pixels = new int** [3];
    for (int channel = 0; channel<3; channel++)
    {
        pixels[channel] = new int* [Height];
        for (int r = 0; r < Height; r++)
        {
            pixels[channel][r] = new int [Width];
            for (int c = 0; c< Width; c++)
            {
                double sum = 0.0;
                for (int h = 0, y = r - rows/2; h < rows; h++, y++)
                {
                    for (int w = 0, x = c - cols/2; w < cols; w++, x++)
                    {
                        if (x < 0 || x >= Width) continue;
                        if (y < 0 || y >= Height) continue;
                        sum += this->elements[h][w] * img->pixels[channel][y][x];
                    }
                }
                int pxl;
                if (this->normalize)
                {
                   pxl = sum/this->total;
                }
                else
                {
                    pxl = sum;
                }

                if(pxl>255)pxl=255;
                if(pxl<0)pxl=0;
                pixels[channel][r][c]=pxl;
            }
        }
    }
    newimg = new ColorImage(pixels, Height, Width);
    return newimg;
}
