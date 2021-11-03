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
#ifndef Image_H
#define Image_H
#include <QImage>
#include <orderstatisitcsoperationmode.h>
#include <monoimage.h>


class ColorImage
{
public:
    int cols;
    int rows;
    int*** pixels;
    QImage* theBitmap;
    ColorImage(QImage* imgptr);
    ColorImage(int*** pixels, int rows, int cols);
    ColorImage* FindZeroCrossing(int threshold);
    ColorImage* operator+(ColorImage* img);
    //HW2
    //static ColorImage* GetBrightnessChangedImage(ColorImage* cimg, int DeltaBrightness);
    //static ColorImage* GetContrastChangedImage(ColorImage* cimg, int DeltaContrast);
    //static ColorImage* HistoEqualize(ColorImage* cimg);

    static MonoImage* GetGreyAverage(ColorImage* cimg);
    //static MonoImage* GetGrey2(Image* cimg);
    //static Image* Subtract2MonoImage(MonoImage* img1, MonoImage* img2);

};

#endif // Image_H
