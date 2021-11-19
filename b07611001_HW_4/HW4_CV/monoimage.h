#ifndef MONOIMAGE_H
#define MONOIMAGE_H
#include <QImage>
#include <opencv2/opencv.hpp>



class MonoImage
{
    QImage theImage;
public:
    int rows, cols;
    double** intensities;
    cv::Mat cvimg;

    MonoImage(double** pixels, int rows, int cols);
    MonoImage(cv::Mat*, int rows, int cols);
    QImage getImage();
    QImage getImagefromcvimg();
    static MonoImage* threshold(MonoImage* img, int val);
    static MonoImage* LeveledGrey(MonoImage* img, int val);
    static MonoImage* GetResolutionChangedImage(MonoImage* img, int val);
    static MonoImage* DFT(MonoImage* srcimg, MonoImage** phaseimg, cv::Mat** data);
    static MonoImage* IDFT(cv::Mat* data);
    static MonoImage* IDFTmodi(cv::Mat* data, cv::Mat** nonomalize);

    static MonoImage* naturallog(MonoImage* img);
    static MonoImage* naturalexp(cv::Mat* img);

};

#endif // MONOIMAGE_H
