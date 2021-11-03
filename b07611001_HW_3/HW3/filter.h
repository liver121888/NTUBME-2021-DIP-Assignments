/*
-------------------------
Author : Li-Wei Yang
Date : 2021/11/2
Institution : National Taiwan University
Department : Biomechatronics Engineering
Status : Senior
-------------------------
Description:
    This is a class that would generate filters and do filter operation.
    Filters:
    Box, Gaussian, Sobel, Laplacian.
*/
#ifndef FILTER_H
#define FILTER_H
#include <colorimage.h>



class Filter
{
public:
    Filter(int rows, int cols, double** weights, bool normalizeflag);
    int Rows;
    int Cols;
    double total;
    double** elements;
    bool normalize;
    static Filter* GenerateBoxFilter(int m, int n);
    static Filter* GenerateGaussianFilter(int m, int n, double scale, double standardDeviation);
    static Filter* GenerateLoGFilter(int m, int n, double standardDeviation);
    static Filter* GenerateSobelHoriFilter();
    static Filter* GenerateSobelVertiFilter();
    static Filter* GenerateLaplacianHalfFilter();
    static Filter* GenerateLaplacianFullFilter();
    ColorImage* operator*(ColorImage* img);
};

#endif // FILTER_H
