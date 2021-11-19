#include "freqfilter.h"

FreqFilter::FreqFilter(double** weights, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int r = 0; r<this->rows;r++)
    {
        for (int c = 0; c<this->cols;c++)
        {
            if (weights[r][c] > 255)
                weights[r][c] = 255;
            else if (weights[r][c] < 0)
                weights[r][c] = 0;
        }
    }
    this->weights  = weights;
}


FreqFilter::FreqFilter(cv::Mat* m, int rows, int cols)
{
    twochanneldata = *m;
    this->rows = rows;
    this->cols = cols;
}



cv::Mat* FreqFilter::operator*(cv::Mat* data)
{
    cv::Mat* result;
    result = new cv::Mat();
    *result = cv::Mat::zeros(data->size(), CV_32FC2);
    double a = 0;
    double b = 0;
    for (int r = 0; r<data->rows;r++)
    {
        for (int c = 0; c<data->cols; c++)
        {
            result->at<cv::Vec2f>(r,c)[0] = this->weights[r][c] * data->at<cv::Vec2f>(r,c)[0];
            result->at<cv::Vec2f>(r,c)[1] = this->weights[r][c] * data->at<cv::Vec2f>(r,c)[1];
            a = result->at<cv::Vec2f>(r,c)[0];
            b = result->at<cv::Vec2f>(r,c)[1];
        }
    }
    return result;
}

FreqFilter* FreqFilter::GenerateIdealFilter(int rows, int cols, int cutoff, bool HighLowpassFlag)
{
    double** weights;
    weights = new double*[rows];
    int d = 0;
    for (int r = 0; r < rows; r++)
    {
        weights[r] = new double [cols];
        for (int c = 0; c< cols; c++)
        {
            d = sqrt((r - rows/2)*(r - rows/2) + (c - cols/2)*(c - cols/2));
            if (HighLowpassFlag)
            {
                //highpass
                if (d>cutoff)
                    weights[r][c] = 1;
                else
                    weights[r][c] = 0;
            }
            else
            {
                //lowpass
                if (d>cutoff)
                    weights[r][c] = 0;
                else
                    weights[r][c] = 1;
            }
        }
    }
    return new FreqFilter(weights, rows, cols);
}

FreqFilter* FreqFilter::GenerateButterworthFilter(int rows, int cols, int cutoff, int order, bool HighLowpassFlag)
{
    double** weights;
    weights = new double*[rows];
    double d = 0.0;
    double cutf = (double)(cutoff);
    double ord = (double)(order);
    for (int r = 0; r < rows; r++)
    {
        weights[r] = new double [cols];
        for (int c = 0; c < cols; c++)
        {
            d = sqrt((r - rows/2)*(r - rows/2) + (c - cols/2)*(c - cols/2));
            if (HighLowpassFlag)//highpass
                weights[r][c] = 1.0/(1.0+pow((cutf/d),(2.0*ord)));
            else//lowpass
                weights[r][c] = 1.0/(1.0+pow((d/cutf),(2.0*ord)));
        }
    }
    return new FreqFilter(weights, rows, cols);
}

FreqFilter* FreqFilter::GenerateGaussianFilter(int rows, int cols, int cutoff, bool HighLowpassFlag)
{
    double** weights;
    weights = new double*[rows];
    double d = 0.0;
    double cutf = (double)(cutoff);
    for (int r = 0; r < rows; r++)
    {
        weights[r] = new double [cols];
        for (int c = 0; c< cols; c++)
        {
            d = sqrt((r - rows/2)*(r - rows/2) + (c - cols/2)*(c - cols/2));
            if (HighLowpassFlag)//highpass
                weights[r][c] = 1.0 - exp(-d*d/(2.0*cutf*cutf));
            else//lowpass
                weights[r][c] = exp(-d*d/(2.0*cutf*cutf));
        }
    }
    return new FreqFilter(weights, rows, cols);
}


FreqFilter* FreqFilter::GenerateHomomorphicFilter(int rows, int cols, int cutoff, double gammaH, double gammaL, double cval)
{
    double** weights;
    weights = new double*[rows];
    double d = 0.0;
    double cutf = (double)(cutoff);
    for (int r = 0; r < rows; r++)
    {
        weights[r] = new double [cols];
        for (int c = 0; c< cols; c++)
        {
            d = sqrt((r - rows/2)*(r - rows/2) + (c - cols/2)*(c - cols/2));
            weights[r][c] = (gammaH - gammaL)*(1.0-exp(-cval*d*d/cutf/cutf))+gammaL;
        }
    }
    return new FreqFilter(weights, rows, cols);
}

FreqFilter* FreqFilter::GenerateMotionBlurredFilter(int rows, int cols, double a, double b, double T)
{
    cv::Mat* cvfilter = new cv::Mat();
    *cvfilter = cv::Mat::zeros(rows, cols, CV_32FC2);
    double x;
    double y;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c< cols; c++)
        {
            double theta = CV_PI * ((r-rows/2) * a + (c-cols/2) * b);
            if (theta == 0)
            {
                cvfilter->at<cv::Vec2f>(r,c)[0] = cos(-theta);
                cvfilter->at<cv::Vec2f>(r,c)[1] = sin(-theta);
                x = cvfilter->at<cv::Vec2f>(r,c)[0];
                y = cvfilter->at<cv::Vec2f>(r,c)[1];
            }
            else
            {
                cvfilter->at<cv::Vec2f>(r,c)[0] = (T/theta) * sin(theta) * cos(-theta);
                cvfilter->at<cv::Vec2f>(r,c)[1] = (T/theta) * sin(theta) * sin(-theta);
                x = cvfilter->at<cv::Vec2f>(r,c)[0];
                y = cvfilter->at<cv::Vec2f>(r,c)[1];
            }


        }
    }
    return new FreqFilter(cvfilter, rows, cols);
}



//legacy
cv::Mat* FreqFilter::jjj(cv::Mat* data)
{
    cv::Mat* result;
    result = new cv::Mat();
    *result = cv::Mat::zeros(data->size(), CV_32FC2);
    double T = 1.0;
    double a = 0.1;
    double b = 0.1;
    double real;
    double imaginary;
    for (int r = 0; r<data->rows;r++)
    {
        for (int c = 0; c<data->cols; c++)
        {

            double theta = CV_PI * ((r-data->rows/2)* a + (c-data->cols/2) * b);
            if (theta == 0)
            {
                result->at<cv::Vec2f>(r,c)[0] = data->at<cv::Vec2f>(r,c)[0];
                result->at<cv::Vec2f>(r,c)[1] = 0;
            }
            else
            {
                real = (T/theta) * sin(theta) * cos(-theta);
                imaginary = (T/theta) * sin(theta) * sin(-theta);
                result->at<cv::Vec2f>(r,c)[0] = real * data->at<cv::Vec2f>(r,c)[0] + (-imaginary * data->at<cv::Vec2f>(r,c)[1]);
                result->at<cv::Vec2f>(r,c)[1] = real * data->at<cv::Vec2f>(r,c)[1] + imaginary * data->at<cv::Vec2f>(r,c)[0];
                a = result->at<cv::Vec2f>(r,c)[0];
                b = result->at<cv::Vec2f>(r,c)[1];
            }

        }
    }
    return result;
}


cv::Mat* FreqFilter::operator^(cv::Mat* data)
{
    cv::Mat* result;
    result = new cv::Mat();
    *result = cv::Mat::zeros(data->size(), CV_32FC2);
    double a;
    double b;
    for (int r = 0; r<data->rows;r++)
    {
        for (int c = 0; c<data->cols; c++)
        {
            a = result->at<cv::Vec2f>(r,c)[0];
            b = result->at<cv::Vec2f>(r,c)[1];
            result->at<cv::Vec2f>(r,c)[0] = this->twochanneldata.at<cv::Vec2f>(r,c)[0] * data->at<cv::Vec2f>(r,c)[0] + (-this->twochanneldata.at<cv::Vec2f>(r,c)[1] * data->at<cv::Vec2f>(r,c)[1]);
            result->at<cv::Vec2f>(r,c)[1] = this->twochanneldata.at<cv::Vec2f>(r,c)[0] * data->at<cv::Vec2f>(r,c)[1] + this->twochanneldata.at<cv::Vec2f>(r,c)[1] * data->at<cv::Vec2f>(r,c)[0];
            a = result->at<cv::Vec2f>(r,c)[0];
            b = result->at<cv::Vec2f>(r,c)[1];
        }
    }
    return result;
}
