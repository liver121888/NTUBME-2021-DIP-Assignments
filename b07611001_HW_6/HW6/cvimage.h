/*
-------------------------
Author : Li-Wei Yang
Date : 2021/12/15
Institution : National Taiwan University
Department : Biomechatronics Engineering
Status : Senior
-------------------------
Description:
    This is a calss that would generate a CVImage.
    A CVImage include a cv::Mat and a corresponding QImage for visual presentation.
*/
#ifndef CVIMAGE_H
#define CVIMAGE_H
#include <opencv2/opencv.hpp>
#include <QImage>
#include <iostream>

class CVImage
{
private:
    cv::Mat* cvimg;
    QImage* Qimg;

public:

    CVImage(QString filename, bool pngflag);
    CVImage(int*** pixels,int rows, int cols);
    CVImage(cv::Mat mat, bool greyflag);
    CVImage(QColor color, QSize size);
    CVImage();
    cv::Mat* getcvimg();
    QImage* getQimg();
    static CVImage* TrapezoidalTransform(CVImage* img, int param, int param2);
    static CVImage* WavyTransform(CVImage* img, int param, int param2, int param3);
    static CVImage* CircularTransform(CVImage* img);
    static CVImage* HarrWaveletTransform(CVImage* img);
    static CVImage* WaveletMeanAndMaxSelection(CVImage* imgA, CVImage* imgB);
    static CVImage* HarrWaveletTransformInversed(CVImage* img);
    static CVImage* HoughTransform(CVImage* img, int CannyThreshold1, int CannyThresold2, int HoughThreshold, std::vector<cv::Point>** ptis);
    static double GetDistance(std::vector<cv::Point>* pts, int iP1, int iP2);
    CVImage* Rect();
    CVImage* operator+(CVImage* img2);




    //HW5
    static void GetRGBPlanes(CVImage* img, CVImage** R, CVImage** G, CVImage** B);
    static void GetCMYPlanes(CVImage* img, CVImage** C, CVImage** M, CVImage** Y);
    static void GetHSIPlanes(CVImage* img, CVImage** H, CVImage** S, CVImage** I);
    static void GetXYZPlanes(CVImage* img, CVImage** X, CVImage** Y, CVImage** Z);
    static void GetLABPlanes(CVImage* img, CVImage** L, CVImage** A, CVImage** B);
    static double GetLABhval(double q);
    static CVImage* TurnGrayScaleImage(CVImage* img);
    static CVImage* CreateColorBar(CVImage* img1, CVImage* img2, CVImage* img3, CVImage* img4, CVImage* img5);
    static CVImage* GetPseudoColorImage(CVImage* srcimg, CVImage* img1, CVImage* img2, CVImage* img3, CVImage* img4, CVImage* img5);
    static CVImage* GetClusteredImage(CVImage* srcimg, int K, int Colortype);
    static void GetYUVPlanes(CVImage* img, CVImage** Y, CVImage** U, CVImage** V);
    static int ForcePixelIntegrityandturnto255(double pxl);
    static int ForcePixelIntegrity255(int pxl);
    static double ForcePixelIntegrity(double pxl);
};

#endif // CVIMAGE_H
