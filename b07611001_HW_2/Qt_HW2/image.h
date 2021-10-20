#ifndef IMAGE_H
#define IMAGE_H
#include <QImage>
#include <monoimage.h>


class image
{
public:
    image(QImage* imgptr);
    image(int*** pixels, int rows, int cols);
    static MonoImage* GetGreyAverage(image* cimg);
    static MonoImage* GetGrey2(image* cimg);
    static image* GetBrightnessChangedImage(image* cimg, int DeltaBrightness);
    static image* GetContrastChangedImage(image* cimg, int DeltaContrast);
    static image* Subtract2MonoImage(MonoImage* img1, MonoImage* img2);
    static image* HistoEqualize(image* cimg);
    int cols, rows;
    int*** pixels;
    QImage* theBitmap;

};

#endif // IMAGE_H
