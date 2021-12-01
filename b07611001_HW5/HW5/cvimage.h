/*
-------------------------
Author : Li-Wei Yang
Date : 2021/11/30
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
