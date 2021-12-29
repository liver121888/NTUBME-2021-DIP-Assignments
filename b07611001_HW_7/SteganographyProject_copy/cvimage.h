#ifndef CVIMAGE_H
#define CVIMAGE_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <text.h>


class CVImage
{
private:
    cv::Mat* CVimg;
    QImage* Qimg;
    QImage* GrayQimg;


public:
    CVImage();
    cv::Mat* getCVimg();
    QImage* getQimg();
    QImage* getGrayQimg();
    CVImage(QString filename, bool pngflag);
    CVImage(cv::Mat mat);
    static CVImage* calhisto(CVImage* Img);
    static CVImage* LSBStego(CVImage* Img, Text* HiddenMessage);
    static CVImage* LSBextract(CVImage* Img);
    static Text LSBStegoDecrypt(CVImage* Img);
    static CVImage* DCTStego(CVImage* Img, Text* HiddenMessage);
    static Text DCTStegoDecrypt(CVImage* Img);
    static CVImage* DFTStego(CVImage* Img, Text* HiddenMessage);
    static Text DFTStegoDecrypt(CVImage* Img);

};

#endif // CVIMAGE_H
