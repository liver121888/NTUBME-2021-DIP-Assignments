#include "monoimage.h"

//constructor
MonoImage::MonoImage(double** pixels, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    intensities = pixels;
    cvimg = cv::Mat::zeros(this->rows, this->cols, CV_32FC1);
    theImage = QImage(cols, rows, QImage::Format::Format_ARGB32);
    for (int r = 0; r<this->rows;r++)
    {
        for(int c =0; c<this->cols;c++)
        {
            QColor a = QColor((int)(intensities[r][c]),(int)(intensities[r][c]),(int)(intensities[r][c]));
            theImage.setPixelColor(c,r,a);
            cvimg.at<float>(r,c)= intensities[r][c];
        }
    }
}

MonoImage::MonoImage(cv::Mat* mat, int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    cvimg = *mat;
    theImage = QImage(cols, rows, QImage::Format::Format_ARGB32);
}

// Get the QImage to show in label.
QImage MonoImage::getImage()
{
    return theImage;
}

MonoImage* MonoImage::DFT(MonoImage* srcimg, MonoImage** phaseimg, cv::Mat** data)
{
    double** pixels;
    double** angles;
    cv::Mat planes[] = {srcimg->cvimg, cv::Mat::zeros(srcimg->cvimg.size(), CV_32FC1)};
    //use 0 to initialize
    cv::Mat planesout[] = {cv::Mat::zeros(srcimg->cvimg.size(), CV_32FC1), cv::Mat::zeros(srcimg->cvimg.size(), CV_32FC1)};
    cv::Mat* ComplexImg = new cv::Mat();
    //planes is a array with 2 single channel Mat, use planes to merge out a single Mat ComplexImg with 2 channels
    cv::merge(planes, 2, *ComplexImg);
    //discrete Fourier transform
    cv::dft(*ComplexImg, *ComplexImg,cv::DFT_COMPLEX_OUTPUT );
    //split out real and imaginary parts then assign back planes

    int cx = ComplexImg->cols / 2;
    int cy = ComplexImg->rows / 2;
    cv::Mat tmp;
    cv::Mat q0(*ComplexImg, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(*ComplexImg, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(*ComplexImg, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(*ComplexImg, cv::Rect(cx, cy, cx, cy));
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    //for testing
    double a;
    double b;
    for (int r = 0; r < ComplexImg->rows; r++)
    {
        for (int c = 0; c < ComplexImg->cols; c++)
        {
            a = ComplexImg->at<cv::Vec2f>(r,c)[0];
            b = ComplexImg->at<cv::Vec2f>(r,c)[1];
        }
    }

    *data = ComplexImg;
    cv::split(*ComplexImg, planes);
    //planes[0]: real, planes[1]: imaginary
    cv::magnitude(planes[0], planes[1], planesout[0]);
    cv::phase(planes[0], planes[1], planesout[1]);
    cv::Mat mag = planesout[0];
    cv::Mat phaseangle = planesout[1];
    //phase
    //phaseangle += cv::Scalar::all(1);
    cv::normalize(phaseangle, phaseangle, 0, 255, CV_MINMAX);
    angles = new double* [phaseangle.rows];
    for(int r = 0; r<phaseangle.rows;r++)
    {
        angles[r] = new double [phaseangle.cols];
        for(int c= 0; c<phaseangle.cols;c++)
        {
            angles[r][c] = (double)(phaseangle.at<float>(r,c));
        }
    }
    *phaseimg = new MonoImage(angles,phaseangle.rows,phaseangle.cols);

    //mag
    mag += cv::Scalar::all(1);
    cv::log(mag, mag);
    cv::normalize(mag, mag, 0, 255, CV_MINMAX);
    pixels = new double* [srcimg->rows];
    for(int r =0; r<srcimg->rows;r++)
    {
        pixels[r] = new double [srcimg->cols];
        for(int c=0; c<srcimg->cols;c++)
        {
            pixels[r][c] = (double)(mag.at<float>(r,c));
        }
    }
    return new MonoImage(pixels,srcimg->rows,srcimg->cols);
}


MonoImage* MonoImage::IDFT(cv::Mat* data)
{
    double** pixels;
    cv::Mat* result = new cv::Mat();
    *result = cv::Mat::zeros(data->size(), CV_32FC1);
    int cx = data->cols / 2;
    int cy = data->rows / 2;
    cv::Mat tmp;
    cv::Mat q0(*data, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(*data, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(*data, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(*data, cv::Rect(cx, cy, cx, cy));
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    cv::dft(*data, *result, cv::DFT_SCALE|cv::DFT_REAL_OUTPUT|cv::DFT_INVERSE);
    double a;
    for (int r = 0; r < result->rows; r++)
    {
        for (int c = 0; c < result->cols; c++)
        {
            a = result->at<float>(r,c);
        }
    }
    normalize(*result,*result,0,255,CV_MINMAX);
    pixels = new double* [data->rows];
    float  b = 0;
    for(int r =0; r<data->rows;r++)
    {
        pixels[r] = new double [data->cols];
        for(int c=0; c<data->cols;c++)
        {
            b = result->at<float>(r,c);
            pixels[r][c] = (double)(result->at<float>(r,c));
        }
    }
    return new MonoImage(pixels, data->rows, data->cols);
}

MonoImage* MonoImage::IDFTmodi(cv::Mat* data, cv::Mat** nonomalize)
{
    double** pixels;
    cv::Mat* result = new cv::Mat();
    cv::Mat* resultout = new cv::Mat();
    *result = cv::Mat::zeros(data->size(), CV_32FC1);
    int cx = data->cols / 2;
    int cy = data->rows / 2;
    cv::Mat tmp;
    cv::Mat q0(*data, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(*data, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(*data, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(*data, cv::Rect(cx, cy, cx, cy));
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    cv::dft(*data, *result, cv::DFT_SCALE | cv::DFT_REAL_OUTPUT | cv::DFT_INVERSE);
    double a;
    for (int r = 0; r < result->rows; r++)
    {
        for (int c = 0; c < result->cols; c++)
        {
            a = result->at<float>(r, c);
        }
    }
    // an example of me confused by pointer
    // I want to pass result out, so I use pointer to pass it out
    // *nonomalize = result;
    // however, the cv::normalize function accept object so I pass the
    // normalized result to itself.
    // normalize(*result, *result, 0, 255, CV_MINMAX);
    // so the result nonomalize pointer pointing to is normalized, not the way I want.
    // use another pointer to solve this problem.
    *nonomalize = result;
    normalize(*result, *resultout, 0, 255, CV_MINMAX);
    pixels = new double* [data->rows];
    float  b = 0;
    for (int r = 0; r < data->rows; r++)
    {
        pixels[r] = new double[data->cols];
        for (int c = 0; c < data->cols; c++)
        {
            b = resultout->at<float>(r, c);
            pixels[r][c] = (double)(resultout->at<float>(r, c));
        }
    }
    return new MonoImage(pixels, data->rows, data->cols);
}

QImage MonoImage::getImagefromcvimg()
{
    for (int r = 0; r<rows;r++)
    {
        for(int c =0; c<cols;c++)
        {
            QColor a = QColor((int)(cvimg.at<float>(r,c)),(int)(cvimg.at<float>(r,c)),(int)(cvimg.at<float>(r,c)));
            theImage.setPixelColor(c,r,a);
            intensities[r][c] = cvimg.at<float>(r,c);
        }
    }
    return theImage;
}

//    naturallog for f
MonoImage* MonoImage::naturallog(MonoImage* img)
{
    double** pixels;
    pixels = new double* [img->rows];
    for (int r = 0; r < img->rows; r++)
    {
        pixels[r] = new double [img->cols];
        for (int c = 0; c < img->cols; c++)
        {
            if (img->intensities[r][c]==0)
            {
                pixels[r][c] = log(img->intensities[r][c]+1);
                //todo subtract 1
                //pixels[r][c] = pixels[r][c]-1;
            }
            else
                pixels[r][c] = log(img->intensities[r][c]);
        }
    }
    return new MonoImage(pixels, img->rows, img->cols);

}

MonoImage* MonoImage::naturalexp(cv::Mat* img)
{
    double** pixels;
    cv::Mat a = cv::Mat::zeros(img->rows, img->cols, CV_32FC1);
    pixels = new double* [img->rows];
    float x = 0;
    float y = 0;
    for (int r = 0; r < img->rows; r++)
    {
        pixels[r] = new double [img->cols];
        for (int c = 0; c < img->cols; c++)
        {
            x = img->at<float>(r,c);
            a.at<float>(r,c) = exp(img->at<float>(r,c));
            y = a.at<float>(r,c);
        }
    }
    cv::normalize(a, a, 0, 255, CV_MINMAX);
    x = 0;
    for (int r = 0; r < img->rows; r++)
    {
        pixels[r] = new double[img->cols];
        for (int c = 0; c < img->cols; c++)
        {
            pixels[r][c] = a.at<float>(r, c);
        }
    }
    return new MonoImage(pixels, img->rows, img->cols);
}



//HW2
// Apply threshold manipulation on a grey image.
MonoImage* MonoImage::threshold(MonoImage* img, int val)
{
    MonoImage* grey;
    double** pixels;
    int rows = img->rows;
    int cols = img->cols;
    pixels = new double*[rows];
    for (int r=0; r<rows;r++)
    {
        pixels[r] = new double [cols];
        for (int c =0; c<cols;c++)
        {
            pixels[r][c] = img->intensities[r][c];
            // Prevent
            if(pixels[r][c]>=val)
            {

                pixels[r][c]=255;
            }
            else
            {
                pixels[r][c]=0;
            }
        }

    }
    grey = new MonoImage(pixels, rows,cols);
    return grey;
}

// Apply level manipulation on a grey image.
MonoImage* MonoImage::LeveledGrey(MonoImage* img, int val)
{
    MonoImage* grey;
    double** pixels;
    int rows = img->rows;
    int cols = img->cols;
    pixels = new double*[rows];
    double step = val/255.0;
    for (int r=0; r<rows;r++)
    {
        pixels[r] = new double [cols];
        for (int c =0; c<cols;c++)
        {
            int i = img->intensities[r][c]*step;
            if(i<0)i=0;
            else if (i>=val)i=val-1;
            pixels[r][c] = i * 255/(val-1);
        }

    }
    grey = new MonoImage(pixels, rows, cols);
    return grey;
}

// Change the spatial resolution of a grey image.
MonoImage* MonoImage::GetResolutionChangedImage(MonoImage* img, int val)
{
    MonoImage* grey;
    double** pixels;
    int rows = img->rows;
    int cols = img->cols;
    int newrows = rows*val/100.0;
    int newcols = cols*val/100.0;
    if(val/100>=1)
    {
        pixels = new double*[newrows];
        for (int r=0; r<newrows;r++)
        {
            pixels[r] = new double [newcols];
            for (int c =0; c<newcols;c++)
            {
               pixels[r][c] = img->intensities[(int)(r/(val/100.0))][(int)(c/(val/100.0))];
            }
        }
    }
    else
    {
        pixels = new double*[newrows];
        for (int r=0; r<newrows;r++)
        {
            pixels[r] = new double [cols];
            for (int c =0; c<newcols;c++)
            {
               pixels[r][c] = img->intensities[(int)(r/(val/100.0))][(int)(c/(val/100.0))];
            }
        }
    }
    grey = new MonoImage(pixels, newrows, newcols);
    return grey;
}




