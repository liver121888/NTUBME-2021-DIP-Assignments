#ifndef MONOIMAGE_H
#define MONOIMAGE_H
#include <QImage>
#include <orderstatisitcsoperationmode.h>
//#include "histogramchart.h"




class MonoImage
{
    QImage theImage;
    int histogram[256];
public:
    MonoImage(int** pixels, int rows, int cols);
    QImage getImage();
    //    HistogramChart* theChart;
    static MonoImage* threshold(MonoImage* img, int val);
    static MonoImage* LeveledGrey(MonoImage* img, int val);
    static MonoImage* GetResolutionChangedImage(MonoImage* img, int val);
    MonoImage* OrderStatisticsOperation(int m, int n, OrderStatisitcsOperationMode mode = MEDIAN);
    int rows, cols;
    int** intensities;



};

#endif // MONOIMAGE_H
