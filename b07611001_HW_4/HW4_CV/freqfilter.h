#ifndef FREQFILTER_H
#define FREQFILTER_H
#include <monoimage.h>


class FreqFilter
{
public:
    int rows, cols;
    double** weights;
    cv::Mat twochanneldata;

    FreqFilter(cv::Mat* m, int rows, int cols);

    FreqFilter(double** weights, int rows, int cols);
    static FreqFilter* GenerateIdealFilter(int rows, int cols, int cutoff, bool HighLowpassFlag);
    static FreqFilter* GenerateButterworthFilter(int rows, int cols,int cutoff, int order, bool HighLowpassFlag);
    static FreqFilter* GenerateGaussianFilter(int rows, int cols, int cutoff, bool HighLowpassFlag);
    static FreqFilter* GenerateHomomorphicFilter(int rows, int cols, int cutoff, double gammaH, double gammaL, double c);
    static FreqFilter* GenerateMotionBlurredFilter(int rows, int cols, double a, double b, double T);
    static cv::Mat* jjj(cv::Mat* data);
    cv::Mat* operator*(cv::Mat* mat);
    cv::Mat* operator^(cv::Mat* mat);
};

#endif // FREQFILTER_H
