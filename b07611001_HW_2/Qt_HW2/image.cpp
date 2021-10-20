#include "image.h"

//constructor
image::image(QImage* ptr)
{
    theBitmap = ptr;
    cols = ptr->width();
    rows = ptr->height();
    pixels = new int **[rows];
    for (int r = 0; r<rows; r++)
    {
        pixels[r] = new int *[cols];
        for (int c = 0; c < cols; c++)
        {
            pixels[r][c] = new int [3];
            QColor a = theBitmap->pixelColor(c,r);
            pixels[r][c][0] = a.red();
            pixels[r][c][1] = a.green();
            pixels[r][c][2] = a.blue();
        }
    }
}

//another constructor
image::image(int*** pixels, int rows, int cols)
{
    this->cols = cols;
    this->rows = rows;
    this->pixels = new int **[rows];
    theBitmap = new QImage(cols, rows,QImage::Format_RGB888);
    for (int r = 0; r<rows; r++)
    {
        this->pixels[r] = new int *[cols];
        for (int c = 0; c < cols; c++)
        {
            this->pixels[r][c] = new int [3];
            this->pixels[r][c][0] = pixels[r][c][0];
            this->pixels[r][c][1] = pixels[r][c][1];
            this->pixels[r][c][2] = pixels[r][c][2];
            QColor a = QColor(pixels[r][c][0],pixels[r][c][1],pixels[r][c][2]);
            theBitmap->setPixelColor(c,r,a);
        }
    }
}

// Turn a color image into grey image 1.
MonoImage* image::GetGreyAverage(image *cimg)
{
    MonoImage* grey;
    int cols = cimg->cols;
    int rows = cimg->rows;
    int** pixels;
    pixels = new int*[rows];
    for (int r = 0; r<rows; r++)
    {
        pixels[r] = new int[cols];
        for (int c=0; c<cols; c++)
        {
            pixels[r][c] = (cimg->pixels[r][c][0] + \
                    cimg->pixels[r][c][1]+cimg->pixels[r][c][2])/3;

        }
    }
    grey = new MonoImage(pixels, rows, cols);
    return grey;
}

// Turn a color image into grey image 2.
MonoImage* image::GetGrey2(image *cimg)
{
    MonoImage* grey;
    int cols = cimg->cols;
    int rows = cimg->rows;
    int** pixels;
    pixels = new int*[rows];
    for (int r = 0; r<rows; r++)
    {
        pixels[r] = new int[cols];
        for (int c=0; c<cols; c++)
        {
            pixels[r][c] = 0.299 * cimg->pixels[r][c][0] + \
                    0.587 * cimg->pixels[r][c][1]+ 0.114 * cimg->pixels[r][c][2];

        }
    }
    grey = new MonoImage(pixels, rows, cols);
    return grey;
}

// Change the brightness of a color image.
image* image::GetBrightnessChangedImage(image* cimg,int d)
{

    image* img;
    int cols = cimg->cols;
    int rows = cimg->rows;
    int*** pixels;
    pixels = new int**[rows];
    for (int r = 0; r<rows; r++)
    {
        pixels[r] = new int *[cols];
        for (int c = 0; c < cols; c++)
        {
            pixels[r][c] = new int [3];
            pixels[r][c][0] =  cimg->pixels[r][c][0] + d;
            pixels[r][c][1] =  cimg->pixels[r][c][1] + d;
            pixels[r][c][2] =  cimg->pixels[r][c][2] + d;
            for (int channel = 0;channel<3;channel++)
            {
                if (pixels[r][c][channel]>255)
                {
                    pixels[r][c][channel]=255;
                }
                else if (pixels[r][c][channel]<0)
                {
                    pixels[r][c][channel]=0;
                }

            }
        }
    }
    // Pontential leak of mamory, should be fixed.
    img = new image(pixels, rows, cols);
    return img;
}

// Change the contrast of a color image, algorithm: https://ithelp.ithome.com.tw/articles/10219730
image* image::GetContrastChangedImage(image* cimg, int d)
{
    image* img;
    int cols = cimg->cols;
    int rows = cimg->rows;
    int*** pixels;
    pixels = new int**[rows];
    double factor = 259.0*( d + 255.0 ) / (255.0*( 259.0 - d ));
    for (int r = 0; r<rows; r++)
    {
        pixels[r] = new int *[cols];
        for (int c = 0; c < cols; c++)
        {
            pixels[r][c] = new int [3];
            pixels[r][c][0] =  factor*(cimg->pixels[r][c][0]-128.0)+128.0;
            pixels[r][c][1] =  factor*(cimg->pixels[r][c][1]-128.0)+128.0;
            pixels[r][c][2] =  factor*(cimg->pixels[r][c][2]-128.0)+128.0;
            for (int channel = 0;channel<3;channel++)
            {
                if (pixels[r][c][channel]>255)pixels[r][c][channel]=255;
                else if (pixels[r][c][channel]<0)pixels[r][c][channel]=0;
            }
        }
    }

    // Pontential leak of mamory, should be fixed.
    img = new image(pixels, rows, cols);
    return img;
}

// Subtract two grey images and show their difference in color image.
image* image::Subtract2MonoImage(MonoImage *img1, MonoImage *img2)
{
    image* contour;
    int*** pixels;
    int rows = img1->rows;
    int cols = img1->cols;
    pixels = new int**[rows];
    for (int r=0; r<rows;r++)
    {
        pixels[r] = new int *[cols];
        for (int c =0; c<cols;c++)
        {
            pixels[r][c] = new int[3];
            pixels[r][c][1] = 0;
            // If img1 has greater intensity, set the color to red.
            if (img1->intensities[r][c] - img2->intensities[r][c]>0)
            {
                pixels[r][c][0] = img1->intensities[r][c] - img2->intensities[r][c]+200;
                pixels[r][c][2] = 0;
            }
            // If both imgs has same intensity, set the color to purple.
            else if (img1->intensities[r][c] - img2->intensities[r][c]==0)
            {
                pixels[r][c][0] = 200;
                pixels[r][c][2] = 200;
            }
            // If img2 has greater intensity, set the color to blue.
            else
            {
                pixels[r][c][0] = 0;
                pixels[r][c][2] = img2->intensities[r][c] - img1->intensities[r][c]+200;

            }

        }

    }
    // Pontential leak of mamory, should be fixed.
    contour = new image(pixels, rows, cols);
    return contour;
}


// Equalize the histogram of a image, algorithm: https://en.wikipedia.org/wiki/Histogram_equalization
image* image::HistoEqualize(image* img)
{
    image* result;
    int*** pixels;
    int Chistogram[3][256] = {{0}};
    int cdf[3][256] = {{0}};
    int rows = img->rows;
    int cols = img->cols;
    int cdfmin[3];
    int cdfmax[3];
    pixels = new int**[rows];
    for (int r=0; r<rows;r++)
    {
        pixels[r] = new int*[cols];
        for (int c = 0; c < cols; c++)
        {
            pixels[r][c] = new int[3];
            for (int channel = 0;channel<3;channel++)
            {
                pixels[r][c][channel] = img->pixels[r][c][channel];
                Chistogram[channel][img->pixels[r][c][channel]]++;
            }
        }
    }
    for (int i =0 ; i<256;i++)
    {
        for (int j =0; j<i+1;j++)
        {
            for (int channel = 0;channel<3;channel++)
            {
                cdf[channel][i] += Chistogram[channel][j];
            }
        }
    }
    for (int channel =0; channel<3; channel++)
    {
        cdfmin[channel] = cdf[channel][0];
        cdfmax[channel] = cdf[channel][255];
    }
    for (int i =0; i<256;i++)
    {
        for (int channel =0; channel<3;channel++)
        {

            Chistogram[channel][i] = round((cdf[channel][i] - cdfmin[channel])*(256.0-1.0)/(cdfmax[channel] - cdfmin[channel]));
        }
    }
    for (int r=0; r<rows;r++)
    {
        for (int c = 0; c < cols; c++)
        {
            for (int channel = 0; channel<3;channel++)
            {
                pixels[r][c][channel] = Chistogram[channel][pixels[r][c][channel]];
                if (pixels[r][c][channel]>255)pixels[r][c][channel]=255;
                else if (pixels[r][c][channel]<0)pixels[r][c][channel]=0;
            }
        }
    }
    result = new image(pixels, rows, cols);
    return result;
}


