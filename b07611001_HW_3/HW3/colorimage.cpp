/*
-------------------------
Author : Li-Wei Yang
Date : 2021/11/2
Institution : National Taiwan University
Department : Biomechatronics Engineering
Status : Senior
-------------------------
Description:
    This is a calss that would generate colorimage.
    A color image include a bitmap in QIamge data type;
    rows, which is the height of a image;
    cols, which is the width of a image;
    pixels, which is the intensity store in the image.
*/
#include "colorimage.h"

//constructor
ColorImage::ColorImage(QImage* ptr)
{
    theBitmap = ptr;
    cols = ptr->width();
    rows = ptr->height();
    pixels = new int **[3];
    for (int channel = 0; channel<3; channel++)
    {
        pixels[channel] = new int *[rows];
        for (int r = 0; r < rows; r++)
        {
            pixels[channel][r] = new int [cols];
            for (int c = 0; c<cols; c++)
            {
                QColor a = theBitmap->pixelColor(c,r);
                if (channel == 0)
                {
                    pixels[channel][r][c] = a.red();
                }
                if (channel == 1)
                {
                    pixels[channel][r][c] = a.green();
                }
                else
                {
                    pixels[channel][r][c] = a.blue();
                }

            }
        }
    }
}

//another constructor
ColorImage::ColorImage(int*** pixels, int rows, int cols)
{
    this->cols = cols;
    this->rows = rows;
    this->pixels = pixels;
    theBitmap = new QImage(cols, rows,QImage::Format_ARGB32);
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c<cols ; c++)
        {
            QColor a = QColor(this->pixels[0][r][c],this->pixels[1][r][c],this->pixels[2][r][c]);
            theBitmap->setPixelColor(c,r,a);
        }

    }
}
//an overloading operator to plus images
ColorImage* ColorImage::operator+(ColorImage* img)
{

    int***pixels;
    pixels = new int**[3];
    for (int channel = 0; channel<3; channel++)
    {
        pixels[channel] = new int*[rows];
        for (int r = 0; r < rows; r++)
        {
            pixels[channel][r] = new int[cols];
            for (int c = 0; c<cols; c++)
            {
                pixels[channel][r][c] = this->pixels[channel][r][c] + img->pixels[channel][r][c];
                if (pixels[channel][r][c]>255)pixels[channel][r][c]=255;
                else if (pixels[channel][r][c]<0)pixels[channel][r][c]=0;
            }
        }
    }
    return  new ColorImage(pixels, img->rows, img->cols);
}


//Find zero-crossing
ColorImage* ColorImage::FindZeroCrossing(int threshold)
{
    int*** pixels;
    pixels = new int**[3];
    for (int channel = 0; channel<3;channel++)
    {
        pixels[channel] = new int*[this->rows];
        for (int r = 0; r < this->rows; r++)
        {
            pixels[channel][r] = new int[this->cols];
        }
    }
    for (int r = 0; r < this->rows; r++)
    {
        for (int c = 0; c < this->cols; c++)
        {
            if ((this->pixels[0][r][c]+this->pixels[1][r][c]+this->pixels[2][r][c])/3.0 < threshold || r == 0 || c == 0 || r == rows - 1 || c == cols - 1)
            {
                pixels[0][r][c]=0;
                pixels[1][r][c]=0;
                pixels[2][r][c]=0;
                continue;
            }
            // vertical
            if ((this->pixels[0][r-1][c]+this->pixels[1][r-1][c]+this->pixels[2][r-1][c])*(this->pixels[0][r+1][c]+this->pixels[1][r+1][c]+this->pixels[2][r+1][c]<=0))
            {
                pixels[0][r][c]=255;
                pixels[1][r][c]=255;
                pixels[2][r][c]=255;
                continue;
            }
            // horizontal
            if ((this->pixels[0][r][c-1]+this->pixels[1][r][c-1]+this->pixels[2][r][c-1])*(this->pixels[0][r][c+1]+this->pixels[1][r][c+1]+this->pixels[2][r][c+1]<=0))
            {
                pixels[0][r][c]=255;
                pixels[1][r][c]=255;
                pixels[2][r][c]=255;
                continue;
            }
            // Diagonal down
            if ((this->pixels[0][r-1][c-1]+this->pixels[1][r-1][c-1]+this->pixels[2][r-1][c-1])*(this->pixels[0][r+1][c+1]+this->pixels[1][r+1][c+1]+this->pixels[2][r+1][c+1]<=0))
            {
                pixels[0][r][c]=255;
                pixels[1][r][c]=255;
                pixels[2][r][c]=255;
                continue;
            }
            // Diagonal down
            if ((this->pixels[0][r+1][c-1]+this->pixels[1][r+1][c-1]+this->pixels[2][r+1][c-1])*(this->pixels[0][r-1][c+1]+this->pixels[1][r-1][c+1]+this->pixels[2][r-1][c+1]<=0))
            {
                pixels[0][r][c]=255;
                pixels[1][r][c]=255;
                pixels[2][r][c]=255;
                continue;
            }
            pixels[0][r][c]=0;
            pixels[1][r][c]=0;
            pixels[2][r][c]=0;
        }
    }
    return new ColorImage(pixels, this->rows, this->cols);
}




//HW2
//ColorImage* ColorImage::GetBrightnessChangedImage(ColorImage* cimg,int d)
//{

//    ColorImage* img;
//    int cols = cimg->cols;
//    int rows = cimg->rows;
//    int*** pixels;
//    pixels = new int**[rows];
//    for (int r = 0; r<rows; r++)
//    {
//        pixels[r] = new int *[cols];
//        for (int c = 0; c < cols; c++)
//        {
//            pixels[r][c] = new int [3];
//            pixels[r][c][0] =  cimg->pixels[r][c][0] + d;
//            pixels[r][c][1] =  cimg->pixels[r][c][1] + d;
//            pixels[r][c][2] =  cimg->pixels[r][c][2] + d;
//            for (int channel = 0;channel<3;channel++)
//            {
//                if (pixels[r][c][channel]>255)
//                {
//                    pixels[r][c][channel]=255;
//                }
//                else if (pixels[r][c][channel]<0)
//                {
//                    pixels[r][c][channel]=0;
//                }

//            }
//        }
//    }
//    // Pontential leak of mamory, should be fixed.
//    img = new ColorImage(pixels, rows, cols);
//    return img;
//}

//// Change the contrast of a color image, algorithm: https://ithelp.ithome.com.tw/articles/10219730
//ColorImage* ColorImage::GetContrastChangedImage(ColorImage* cimg, int d)
//{
//    ColorImage* img;
//    int cols = cimg->cols;
//    int rows = cimg->rows;
//    int*** pixels;
//    pixels = new int**[rows];
//    double factor = 259.0*( d + 255.0 ) / (255.0*( 259.0 - d ));
//    for (int r = 0; r<rows; r++)
//    {
//        pixels[r] = new int *[cols];
//        for (int c = 0; c < cols; c++)
//        {
//            pixels[r][c] = new int [3];
//            pixels[r][c][0] =  factor*(cimg->pixels[r][c][0]-128.0)+128.0;
//            pixels[r][c][1] =  factor*(cimg->pixels[r][c][1]-128.0)+128.0;
//            pixels[r][c][2] =  factor*(cimg->pixels[r][c][2]-128.0)+128.0;
//            for (int channel = 0;channel<3;channel++)
//            {
//                if (pixels[r][c][channel]>255)pixels[r][c][channel]=255;
//                else if (pixels[r][c][channel]<0)pixels[r][c][channel]=0;
//            }
//        }
//    }

//    // Pontential leak of mamory, should be fixed.
//    img = new ColorImage(pixels, rows, cols);
//    return img;
//}
//// Equalize the histogram of a image, algorithm: https://en.wikipedia.org/wiki/Histogram_equalization

//ColorImage* ColorImage::HistoEqualize(ColorImage* img)
//{
//    ColorImage* result;
//    int*** pixels;
//    int Chistogram[3][256] = {{0}};
//    int cdf[3][256] = {{0}};
//    int rows = img->rows;
//    int cols = img->cols;
//    int cdfmin[3];
//    int cdfmax[3];
//    pixels = new int**[rows];
//    for (int r=0; r<rows;r++)
//    {
//        pixels[r] = new int*[cols];
//        for (int c = 0; c < cols; c++)
//        {
//            pixels[r][c] = new int[3];
//            for (int channel = 0;channel<3;channel++)
//            {
//                pixels[r][c][channel] = img->pixels[r][c][channel];
//                Chistogram[channel][img->pixels[r][c][channel]]++;
//            }
//        }
//    }
//    for (int i =0 ; i<256;i++)
//    {
//        for (int j =0; j<i+1;j++)
//        {
//            for (int channel = 0;channel<3;channel++)
//            {
//                cdf[channel][i] += Chistogram[channel][j];
//            }
//        }
//    }
//    for (int channel =0; channel<3; channel++)
//    {
//        cdfmin[channel] = cdf[channel][0];
//        cdfmax[channel] = cdf[channel][255];
//    }
//    for (int i =0; i<256;i++)
//    {
//        for (int channel =0; channel<3;channel++)
//        {

//            Chistogram[channel][i] = round((cdf[channel][i] - cdfmin[channel])*(256.0-1.0)/(cdfmax[channel] - cdfmin[channel]));
//        }
//    }
//    for (int r=0; r<rows;r++)
//    {
//        for (int c = 0; c < cols; c++)
//        {
//            for (int channel = 0; channel<3;channel++)
//            {
//                pixels[r][c][channel] = Chistogram[channel][pixels[r][c][channel]];
//                if (pixels[r][c][channel]>255)pixels[r][c][channel]=255;
//                else if (pixels[r][c][channel]<0)pixels[r][c][channel]=0;
//            }
//        }
//    }
//    result = new ColorImage(pixels, rows, cols);
//    return result;
//}
// Turn a color image into grey image 1.
MonoImage* ColorImage::GetGreyAverage(ColorImage *cimg)
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
            pixels[r][c] = (cimg->pixels[0][r][c] + \
                    cimg->pixels[1][r][c]+cimg->pixels[2][r][c])/3;

        }
    }
    grey = new MonoImage(pixels, rows, cols);
    return grey;
}

//// Turn a color image into grey image 2.
//MonoImage* Image::GetGrey2(Image *cimg)
//{
//    MonoImage* grey;
//    int cols = cimg->cols;
//    int rows = cimg->rows;
//    int** pixels;
//    pixels = new int*[rows];
//    for (int r = 0; r<rows; r++)
//    {
//        pixels[r] = new int[cols];
//        for (int c=0; c<cols; c++)
//        {
//            pixels[r][c] = 0.299 * cimg->pixels[r][c][0] + \
//                    0.587 * cimg->pixels[r][c][1]+ 0.114 * cimg->pixels[r][c][2];

//        }
//    }
//    grey = new MonoImage(pixels, rows, cols);
//    return grey;
//}

// Change the brightness of a color image.

//// Subtract two grey images and show their difference in color image.
//Image* Image::Subtract2MonoImage(MonoImage *img1, MonoImage *img2)
//{
//    Image* contour;
//    int*** pixels;
//    int rows = img1->rows;
//    int cols = img1->cols;
//    pixels = new int**[rows];
//    for (int r=0; r<rows;r++)
//    {
//        pixels[r] = new int *[cols];
//        for (int c =0; c<cols;c++)
//        {
//            pixels[r][c] = new int[3];
//            pixels[r][c][1] = 0;
//            // If img1 has greater intensity, set the color to red.
//            if (img1->intensities[r][c] - img2->intensities[r][c]>0)
//            {
//                pixels[r][c][0] = img1->intensities[r][c] - img2->intensities[r][c]+200;
//                pixels[r][c][2] = 0;
//            }
//            // If both imgs has same intensity, set the color to purple.
//            else if (img1->intensities[r][c] - img2->intensities[r][c]==0)
//            {
//                pixels[r][c][0] = 200;
//                pixels[r][c][2] = 200;
//            }
//            // If img2 has greater intensity, set the color to blue.
//            else
//            {
//                pixels[r][c][0] = 0;
//                pixels[r][c][2] = img2->intensities[r][c] - img1->intensities[r][c]+200;

//            }

//        }

//    }
//    // Pontential leak of mamory, should be fixed.
//    contour = new Image(pixels, rows, cols);
//    return contour;
//}
