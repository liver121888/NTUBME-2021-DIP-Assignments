/*
-------------------------
Author : Li-Wei Yang
Date : 2022/01/12
Institution : National Taiwan University
Department : Biomechatronics Engineering
Status : Senior
-------------------------
Description:
    This is a calss that would do various steganography.
    A CVImage include a cv::Mat* for data storage, a QImage* for visual presentation.
    The steganography process include LSB, DCT, and DWT (using Haar wavelet).
    The class can also show the histogram of a image for steganography detection.
*/
#ifndef CVIMAGE_H
#define CVIMAGE_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <tuple>
#include <text.h>


class CVImage
{
private:
    cv::Mat* CVimg;
    QImage* Qimg;
public:
    CVImage();
    cv::Mat* getCVimg();
    QImage* getQimg();

    CVImage(QString filename, bool pngflag);
    CVImage(cv::Mat mat);
    static CVImage* calhisto(CVImage* Img);

    static CVImage* LSBStego(CVImage* Img, Text* HiddenMessage);
    static Text LSBStegoDecrypt(CVImage* Img);
    static CVImage* LSBextract(CVImage* Img);

    static CVImage* DCTStego(CVImage* Img, Text* HiddenMessage);
    static Text DCTStegoDecrypt(CVImage* Img);
    static CVImage* DCTextract(CVImage* Img);

    static CVImage* DWTStego(CVImage* Img, Text* HiddenMessage);
    static Text DWTStegoDecrypt(CVImage* StegoImg);
    static CVImage* DWTextract(CVImage* Img);

    CVImage* operator-(CVImage* oriimg);
};

std::vector<cv::Mat> Haar(cv::Mat mat);
cv::Mat inverseHaar(std::vector<cv::Mat> v);

#endif // CVIMAGE_H
