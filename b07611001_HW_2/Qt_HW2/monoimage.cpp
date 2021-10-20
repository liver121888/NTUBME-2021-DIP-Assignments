#include "monoimage.h"

//constructor
MonoImage::MonoImage(int** pixels, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    intensities = pixels;
    theImage = QImage(cols, rows, QImage::Format::Format_ARGB32);

    for (int i = 0; i <256; i++)
    {
        histogram[i] = 0;
    }


    for (int r = 0 ; r<rows;r++)
    {
        for (int c =0; c<cols; c++)
        {
            int i = intensities[r][c];
            theImage.setPixelColor(c,r, QColor(i,i,i));
            histogram[intensities[r][c]] += 1;

        }

    }
    theChart = new HistogramChart(histogram,256, "histogram");
}

// Get the QImage to show in label.
QImage MonoImage::getImage()
{
    return theImage;
}

// Apply threshold manipulation on a grey image.
MonoImage* MonoImage::threshold(MonoImage* img, int val)
{
    MonoImage* grey;
    int** pixels;
    int rows = img->rows;
    int cols = img->cols;
    pixels = new int*[rows];
    for (int r=0; r<rows;r++)
    {
        pixels[r] = new int [cols];
        for (int c =0; c<cols;c++)
        {
            pixels[r][c] = img->intensities[r][c];
            // Prevent
            if(pixels[r][c]>=val)
            {

                pixels[r][c]=255;
            }
            else
            {
                pixels[r][c]=0;
            }
        }

    }
    grey = new MonoImage(pixels, rows,cols);
    return grey;
}

// Apply level manipulation on a grey image.
MonoImage* MonoImage::LeveledGrey(MonoImage* img, int val)
{
    MonoImage* grey;
    int** pixels;
    int rows = img->rows;
    int cols = img->cols;
    pixels = new int*[rows];
    double step = val/255.0;
    for (int r=0; r<rows;r++)
    {
        pixels[r] = new int [cols];
        for (int c =0; c<cols;c++)
        {
            int i = img->intensities[r][c]*step;
            if(i<0)i=0;
            else if (i>=val)i=val-1;
            pixels[r][c] = i * 255/(val-1);
        }

    }
    grey = new MonoImage(pixels, rows, cols);
    return grey;
}

// Change the spatial resolution of a grey image.
MonoImage* MonoImage::GetResolutionChangedImage(MonoImage* img, int val)
{
    MonoImage* grey;
    int** pixels;
    int rows = img->rows;
    int cols = img->cols;
    int newrows = rows*val/100.0;
    int newcols = cols*val/100.0;
    if(val/100>=1)
    {
        pixels = new int*[newrows];
        for (int r=0; r<newrows;r++)
        {
            pixels[r] = new int [newcols];
            for (int c =0; c<newcols;c++)
            {
               pixels[r][c] = img->intensities[(int)(r/(val/100.0))][(int)(c/(val/100.0))];
            }
        }

    }
    else
    {
        pixels = new int*[newrows];
        for (int r=0; r<newrows;r++)
        {
            pixels[r] = new int [cols];
            for (int c =0; c<newcols;c++)
            {
               pixels[r][c] = img->intensities[(int)(r/(val/100.0))][(int)(c/(val/100.0))];
            }
        }
    }
    grey = new MonoImage(pixels, newrows, newcols);
    return grey;

}
