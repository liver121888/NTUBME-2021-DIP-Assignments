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
    //    theChart = new HistogramChart(histogram,256, "histogram");
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

//perform order-statistics operation
MonoImage* MonoImage::OrderStatisticsOperation(int m, int n, OrderStatisitcsOperationMode mode)
{

    int cnt = 0;
    int* orders = new int[m * n];
    int** pixels = new int *[rows];
    for (int r = 0; r < this->rows; r++)
    {
        pixels[r] = new int [this->cols];
        for (int c = 0; c < this->cols; c++)
        {
            cnt = 0;
            // Construct an ordered sequence
            for (int vv = 0, y = r - m / 2; vv < m; vv++, y++)
            {
                for (int hh = 0, x = c - n / 2; hh < n; hh++, x++)
                {
                    if (x < 0 || x >= this->cols) continue;
                    if (y < 0 || y >= this->rows) continue;

                    orders[cnt] = this->intensities[y][x];
                    for (int i = 0; i < cnt; i++)
                    {
                        if (orders[i] >= this->intensities[y][x])
                        {
                            for (int j = cnt - 1; j >= i; j--)
                                orders[j + 1] = orders[j];
                            orders[i] = this->intensities[y][x];
                            break;
                        }
                    }
                    cnt++;
                }
            }
            if (mode==MEDIAN)
            {
                pixels[r][c] = orders[cnt/2];
            }
            else if(mode==MAX)
            {
                pixels[r][c] = orders[cnt-1];;

            }
            else
            {
                pixels[r][c] = orders[0];
            }
        }
    }


    return new MonoImage(pixels, this->rows, this->cols);

//    int** pixels;
//    int* sequence = new int[m*n];
//    int counter;
//    int pxl;
//    pixels = new int *[rows];
//    for (int r = 0; r < this->rows; r++)
//    {
//        pixels[r] = new int [this->cols];
//        for (int c = 0; c<this->cols; c++)
//        {
//            counter = 0;
//            for (int h = 0, y = r - m/2; h < m; h++, y++)
//            {
//                for (int w = 0, x = c - n/2; w < n; w++, x++)
//                {
//                    if (x < 0 || x >= this->cols)
//                        continue;
//                    if (y < 0 || y >= this->rows)
//                        continue;
//                    sequence[counter] = this->intensities[y][x];
//                    for (int index = 0; index < counter; index++)
//                    {
//                        if (sequence[index] >= this->intensities[y][x])
//                        {
//                            for(int i = counter-1;i>=index;i--)
//                            {
//                                //move all element to the right except last one
//                                sequence[i+1] = sequence[i];
//                            }
//                            sequence[index] = this->intensities[y][x];
//                            break;
//                        }
//                    }
//                    counter++;
//                }
//            }

//            if (mode==MEDIAN)
//            {
//                if((counter-1)%2)
//                    pxl = sequence[(counter-1+1)/2];
//                else
//                    pxl = sequence[((counter-1)/2+((counter-1)/2+1))/2];
//            }
//            else if(mode==MAX)
//            {
//                pxl = sequence[counter-1];

//            }
//            else
    //            {
    //                pxl = sequence[0];
    //            }
    //            pixels[r][c] = pxl;
    //        }
    //    }
    //    return new MonoImage(pixels, this->rows, this->cols);
}



