#include "cvimage.h"

using namespace std;

//constructor
CVImage::CVImage(QString filename, bool pngflag)
{
    Qimg = new QImage();
    cvimg = new cv::Mat();
    if (pngflag)
    {
        *cvimg = cv::imread(filename.toStdString().data(), cv::IMREAD_UNCHANGED);
        cvtColor(*cvimg, *cvimg, CV_BGRA2RGB);
        (*Qimg).load(filename);
    }
    else {
        *cvimg = cv::imread(filename.toStdString().data(), cv::IMREAD_COLOR);
        cvtColor(*cvimg, *cvimg, CV_BGR2RGB);
        *Qimg = QImage((unsigned char*)(cvimg->data), cvimg->cols, cvimg->rows, QImage::Format_RGB888);
    }
}

//constructor
CVImage::CVImage(int*** pixels, int rows, int cols)
{
    cvimg = new cv::Mat();
    Qimg = new QImage();
    *cvimg = cv::Mat::zeros(rows, cols, CV_8UC3);
    for (int channel = 0; channel < 3; channel++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                cvimg->at<cv::Vec3b>(r, c)[channel] = pixels[channel][r][c];
            }
        }
    }
    *Qimg = QImage((unsigned char*)(cvimg->data), cvimg->cols, cvimg->rows, QImage::Format_RGB888);
}

//constructor for pure color pixmap
CVImage::CVImage(QColor color, QSize size)
{
    cvimg = new cv::Mat();
    *cvimg = cv::Mat::zeros(size.height(), size.width(), CV_8UC3);
    Qimg = new QImage(size.width(), size.height(), QImage::Format_RGB888);
    *cvimg = cv::Mat::zeros(size.height(), size.width(), CV_8UC3);
    for (int r = 0; r < size.height(); r++)
    {
        for (int c = 0; c < size.width(); c++)
        {
            Qimg->setPixelColor(c, r, color);
            cvimg->at<cv::Vec3b>(r, c)[0] = Qimg->pixelColor(c, r).red();
            cvimg->at<cv::Vec3b>(r, c)[1] = Qimg->pixelColor(c, r).green();
            cvimg->at<cv::Vec3b>(r, c)[2] = Qimg->pixelColor(c, r).blue();
        }
    }

}


//constructor from cv::Mat and can specify mono image or color image
CVImage::CVImage(cv::Mat mat, bool greyflag)
{
    cvimg = new cv::Mat();
    Qimg = new QImage(mat.cols, mat.rows, QImage::Format_RGB888);
    *cvimg = mat;
    if (greyflag)
    {
        for (int r = 0; r < cvimg->rows; r++)
        {
            for (int c = 0; c < cvimg->cols; c++)
            {
                QColor a = QColor((int)(cvimg->at<uchar>(r, c)), (int)(cvimg->at<uchar>(r, c)), (int)(cvimg->at<uchar>(r, c)));
                Qimg->setPixelColor(c, r, a);
            }
        }

    }
    else
        *Qimg = QImage((unsigned char*)(cvimg->data), cvimg->cols, cvimg->rows, QImage::Format_RGB888);
}

//empty constructor
CVImage::CVImage()
{

}

//get private data cvimg
cv::Mat* CVImage::getcvimg()
{
    return cvimg;
}

//get private data Qimg
QImage* CVImage::getQimg()
{
    return Qimg;
}

//cut the NW of the image and return
CVImage* CVImage::Rect()
{
    cv::Mat m = cv::Mat::zeros(this->cvimg->rows/2, this->cvimg->cols/2, CV_8UC3);
    //intend to use rect, but has problem, so use at instead
    //    mRect = m(cv::Rect(0, 0, m.cols / 2, m.rows/2));
    for (int channel = 0; channel < 3; channel++)
    {
        for (int r = 0; r < this->cvimg->rows/2; r ++)
        {
            for (int c = 0; c < this->cvimg->cols/2; c++)
            {
                m.at<cv::Vec3b>(r, c)[channel] = this->cvimg->at<cv::Vec3b>(r, c)[channel];
            }
        }
    }
    return new CVImage(m, false);
}

//an overloading operator to fuse the NW of the image together
CVImage* CVImage::operator+(CVImage* img2)
{
    cv::Mat m = cv::Mat::zeros(this->cvimg->rows, this->cvimg->cols, CV_8UC3);
    for (int channel = 0; channel < 3; channel++)
    {
        for (int r = 0; r < this->cvimg->rows; r ++)
        {
            for (int c = 0; c < this->cvimg->cols; c++)
            {
                if (r < img2->cvimg->rows && c < img2->cvimg->cols)
                    m.at<cv::Vec3b>(r, c)[channel] = img2->cvimg->at<cv::Vec3b>(r, c)[channel];
                else
                    m.at<cv::Vec3b>(r, c)[channel] = this->cvimg->at<cv::Vec3b>(r, c)[channel];
            }
        }
    }
    return new CVImage(m, false);
}



//trapezoidal transformation, the user can specify the percentage of the shirnkage in both direction;
//the shrinkage in horizontal is symmetry, so use (1.0-c) and c in columns
//the shrinkage in vertical is only applied to the bottom of the image
//use cv::findHomography and cv::warpPerspective to get the job done
CVImage* CVImage::TrapezoidalTransform(CVImage* img, int param, int param2)
{
    double c = param / 100.0;
    double r = param2 / 100.0;
    cv::Mat m = cv::Mat::zeros(img->cvimg->rows, img->cvimg->cols, CV_8UC3);
    cv::Mat srcPoints = cv::Mat::zeros(1, 4, CV_32FC2);
    //(x, y) of 4 corners, in clockwise sequence
    srcPoints.at<cv::Vec2f>(0,0)[0] = 0.0;
    srcPoints.at<cv::Vec2f>(0,0)[1] = 0.0;
    srcPoints.at<cv::Vec2f>(0,1)[0] = (double)(img->cvimg->cols);
    srcPoints.at<cv::Vec2f>(0,1)[1] = 0.0;
    srcPoints.at<cv::Vec2f>(0,2)[0] = (double)(img->cvimg->cols);
    srcPoints.at<cv::Vec2f>(0,2)[1] = (double)(img->cvimg->rows);
    srcPoints.at<cv::Vec2f>(0,3)[0] = 0.0;
    srcPoints.at<cv::Vec2f>(0,3)[1] = (double)(img->cvimg->rows);
    cv::Mat dstPoints = cv::Mat::zeros(1, 4, CV_32FC2);
    dstPoints.at<cv::Vec2f>(0,0)[0] = 0.0;
    dstPoints.at<cv::Vec2f>(0,0)[1] = 0.0;
    dstPoints.at<cv::Vec2f>(0,1)[0] = (double)(m.cols);
    dstPoints.at<cv::Vec2f>(0,1)[1] = 0.0;
    dstPoints.at<cv::Vec2f>(0,2)[0] = (1.0-c)*(double)(m.cols);
    dstPoints.at<cv::Vec2f>(0,2)[1] = r*(double)(m.rows);
    dstPoints.at<cv::Vec2f>(0,3)[0] = c*(double)(m.cols);
    dstPoints.at<cv::Vec2f>(0,3)[1] = r*(double)(m.rows);
    cv::Mat trans;
    trans = cv::findHomography(srcPoints, dstPoints);
    cv::warpPerspective(*img->cvimg, m, trans, m.size());
    return new CVImage(m, false);
}

//wavy transformation, the user can modify the amplitude, frequency and the offset of the sin wave;
//the offset is controlled in resolution of 30 degree
//in the first part we build a lookuptable to do the mapping, then use the table to
//assign value into the new image
//if the lookuptable points a point out of bound, assign black to the point
CVImage* CVImage::WavyTransform(CVImage* img, int param, int param2, int param3)
{
    cv::Mat m = cv::Mat::zeros(img->cvimg->rows, img->cvimg->cols, CV_8UC3);
    cv::Mat LookUpTable = cv::Mat::zeros(img->cvimg->rows, img->cvimg->cols, CV_16UC2);

    for (int r = 0; r < img->cvimg->rows; r++)
    {
        for (int c = 0; c < img->cvimg->cols; c++)
        {
            LookUpTable.at<cv::Vec2w>(r, c)[0] =  round(r + param2*sin(2.0*CV_PI*c/param + param3*CV_PI/6.0));
            LookUpTable.at<cv::Vec2w>(r, c)[1] =  round(c + param2*sin(2.0*CV_PI*r/param + param3*CV_PI/6.0));
        }
    }

    for (int channel = 0; channel < 3; channel++)
    {
        for (int r = 0; r < img->cvimg->rows; r++)
        {
            for (int c = 0; c < img->cvimg->cols; c++)
            {
                if (LookUpTable.at<cv::Vec2w>(r, c)[0] < img->cvimg->rows && LookUpTable.at<cv::Vec2w>(r, c)[1] < img->cvimg->cols)
                {
                    m.at<cv::Vec3b>(r, c)[channel] = \
                            img->cvimg->at<cv::Vec3b>(LookUpTable.at<cv::Vec2w>(r, c)[0], LookUpTable.at<cv::Vec2w>(r, c)[1])[channel];
                }
                else
                {
                    m.at<cv::Vec3b>(r, c)[channel] = 0;
                }
            }
        }
    }
    return new CVImage(m, false);
}

//circular transformation, further improvement requires
//separate the image into four quadrants, loop through every pixel in the image,
//assign them to the new image, using polar coordinates
CVImage* CVImage::CircularTransform(CVImage* img)
{
    cv::Mat m = cv::Mat::zeros(img->cvimg->rows, img->cvimg->cols, CV_8UC3);
    double* scales = new double[img->cvimg->rows];
    double* angles = new double[img->cvimg->rows];
    int center[2];
    center[0] = img->cvimg->rows/2;
    center[1] = img->cvimg->cols/2;
    double ab = center[0] * center[1];
    double asq = center[0] * center[0];
    double bsq = center[1] * center[1];
    int cnt = 0;
    int height = img->cvimg->rows, width = img->cvimg->cols;
    int dy;
    int dx = width - center[1];
    double boundDistance;
    double sina;
    double cosa;
    double radius;
    for (int r = height/2; r < height; r++)
    {
        dy = r - center[0];
        boundDistance = sqrt( dx * dx + dy * dy );
        angles[cnt] = atan2(dy, dx);
        sina = sin( angles[ cnt ] );
        cosa = cos( angles[ cnt ] );
        radius = ab / sqrt( asq * sina * sina + bsq * cosa * cosa );
        scales[ cnt ] = radius / boundDistance;
        cnt++;
    }

    dy = height - center[0];
    for( int c = width - 1; c >= width/2 ; c-- )
    {
        dx = c - center[1];
        boundDistance = sqrt( dx * dx + dy * dy );
        angles[ cnt ] = atan2( dy, dx );
        sina = sin( angles[ cnt ] );
        cosa = cos( angles[ cnt ] );
        radius = ab / sqrt( asq * sina * sina + bsq * cosa * cosa );
        scales[ cnt ] = radius / boundDistance;
        cnt++;
    }
    double pangle;
    double pscale;
    int newdx, newdy;
    int newr, newc;
    int mirrowR, mirrowC;
    for( int r = height / 2 ; r < height ; r++ )
    {
        for( int c = width / 2 ; c < width ; c++ )
        {
            dy = r - center[0];
            dx = c - center[1];
            pangle = atan2(dy, dx );
            pscale = 1.0;
            for( int i = 0 ; i < img->cvimg->rows ; i++ )
            {
                if( pangle < angles[i])
                {
                    pscale = scales[i];
                    break;
                }
            }
            newdy = (int) ( dy * pscale );
            newdx = (int) ( dx * pscale );
            // Right-bottom
            newr = center[0] + newdy;
            newc = center[1] + newdx;
            for( int channel = 0 ; channel < 3 ; channel++ )
            {
                if( m.at<cv::Vec3b>(newr,newc)[channel] == 0 )
                    m.at<cv::Vec3b>(newr,newc)[channel] = img->cvimg->at<cv::Vec3b>(r,c)[channel];
                else
                    m.at<cv::Vec3b>(newr,newc)[channel] = (m.at<cv::Vec3b>(newr,newc)[channel] +  img->cvimg->at<cv::Vec3b>(r,c)[channel])/2;
            }
            // Right-Top
            newr = center[0] - newdy;
            newc = center[1] + newdx;
            mirrowR = height - r;
            for( int channel = 0 ; channel < 3 ; channel++ )
            {
                if( m.at<cv::Vec3b>(newr,newc)[channel] == 0 )
                    m.at<cv::Vec3b>(newr,newc)[channel] = img->cvimg->at<cv::Vec3b>(mirrowR,c)[channel];
                else
                    m.at<cv::Vec3b>(newr,newc)[channel] = (m.at<cv::Vec3b>(newr,newc)[channel] +  img->cvimg->at<cv::Vec3b>(mirrowR,c)[channel])/2;
            }
            // Left-Bottom
            newr = center[0] + newdy;
            newc = center[1] - newdx;
            mirrowC = width - c;
            for( int channel = 0 ; channel < 3 ; channel++ )
            {
                if( m.at<cv::Vec3b>(newr,newc)[channel] == 0 )
                    m.at<cv::Vec3b>(newr,newc)[channel] = img->cvimg->at<cv::Vec3b>(r,mirrowC)[channel];
                else
                    m.at<cv::Vec3b>(newr,newc)[channel] = (m.at<cv::Vec3b>(newr,newc)[channel] +  img->cvimg->at<cv::Vec3b>(r,mirrowC)[channel])/2;
            }
            // Left-Top
            newr = center[0] - newdy;
            newc = center[1] - newdx;
            mirrowR = height - r;
            mirrowC = width - c;
            for( int channel = 0 ; channel < 3 ; channel++ )
            {
                if( m.at<cv::Vec3b>(newr,newc)[channel] == 0 )
                    m.at<cv::Vec3b>(newr,newc)[channel] = img->cvimg->at<cv::Vec3b>(mirrowR,mirrowC)[channel];
                else
                    m.at<cv::Vec3b>(newr,newc)[channel] = (m.at<cv::Vec3b>(newr,newc)[channel] +  img->cvimg->at<cv::Vec3b>(mirrowR,mirrowC)[channel])/2;
            }
        }
    }
    return new CVImage(m, false);

}





//ref: https://answers.opencv.org/question/42273/wavelet-transform/
//using Harr wavelet to do the DWT
CVImage* CVImage::HarrWaveletTransform(CVImage* img)
{
    cv::Mat m = cv::Mat::zeros(img->cvimg->rows, img->cvimg->cols, CV_8UC3);
    cv::Mat im1 = cv::Mat::zeros(m.rows/2, m.cols, CV_32FC3);
    cv::Mat im2 = cv::Mat::zeros(m.rows/2, m.cols, CV_32FC3);
    cv::Mat im3 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    cv::Mat im4 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    cv::Mat im5 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    cv::Mat im6 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    img->cvimg->copyTo(m);
    m.convertTo(m, CV_32FC3,1.0,0.0);
    float a, b, c, d;

    //subsample row
    for(int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0; rcnt<m.rows; rcnt+=2)
        {
            for(int ccnt=0; ccnt<m.cols; ccnt++)
            {
                a=m.at<cv::Vec3f>(rcnt,ccnt)[channel];
                b=m.at<cv::Vec3f>(rcnt+1,ccnt)[channel];
                c=(a+b)*0.707;
                d=(a-b)*0.707;
                int _rcnt = rcnt/2;
                //Lowpass
                im1.at<cv::Vec3f>(_rcnt, ccnt)[channel] = c;
                //Highpass
                im2.at<cv::Vec3f>(_rcnt, ccnt)[channel] = d;
            }
        }
    }

    //subsample col w.r.t. im1
    for(int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0; rcnt<m.rows/2; rcnt++)
        {
            for(int ccnt=0; ccnt<m.cols; ccnt+=2)
            {

                a=im1.at<cv::Vec3f>(rcnt,ccnt)[channel];
                b=im1.at<cv::Vec3f>(rcnt,ccnt+1)[channel];
                c=(a+b)*0.707;
                d=(a-b)*0.707;
                int _ccnt=ccnt/2;
                //LL
                im3.at<cv::Vec3f>(rcnt,_ccnt)[channel]=c;
                //LH
                im4.at<cv::Vec3f>(rcnt,_ccnt)[channel]=d;
            }
        }
    }

    //subsample col w.r.t. im2
    for(int channel = 0;channel < 3; channel++)
    {
        for(int rcnt=0;rcnt<m.rows/2;rcnt++)
        {
            for(int ccnt=0;ccnt<m.cols;ccnt+=2)
            {

                a=im2.at<cv::Vec3f>(rcnt,ccnt)[channel];
                b=im2.at<cv::Vec3f>(rcnt,ccnt+1)[channel];
                c=(a+b)*0.707;
                d=(a-b)*0.707;
                int _ccnt = ccnt/2;
                //HL
                im5.at<cv::Vec3f>(rcnt,_ccnt)[channel] = c;
                //HH
                im6.at<cv::Vec3f>(rcnt,_ccnt)[channel] = d;
            }
        }
    }

    cv::Mat imd = cv::Mat::zeros(m.rows,m.cols,CV_32FC3);

    //why this did not work on images when cols != rows?
    //fucked up by the x y notation, rect(x,y,width,height),
    //incorrect->im5.copyTo(imd(cv::Rect(imd.rows / 2, 0, imd.rows/2, imd.cols / 2)));
    //different notation sequence from r, c notation
    cv::normalize(im3, im3, 0, 255, cv::NORM_MINMAX);
    im3.copyTo(imd(cv::Rect(0, 0, imd.cols / 2, imd.rows/2)));
    im4.copyTo(imd(cv::Rect(imd.cols / 2, 0, imd.cols / 2, imd.rows/2)));
    im5.copyTo(imd(cv::Rect(0, imd.rows / 2, imd.cols / 2, imd.rows/2)));
    im6.copyTo(imd(cv::Rect(imd.cols / 2, imd.rows/2, imd.cols / 2, imd.rows/2)));
    imd.convertTo(m, CV_8UC3, 1.0, 0.0);

    return new CVImage(m, false);
}

//apply mean selection in lowpass subband, and apply max selection in highpass subband
CVImage* CVImage::WaveletMeanAndMaxSelection(CVImage* imgA, CVImage* imgB)
{
    cv::Mat A;
    cv::Mat B;
    cv::Mat m = cv::Mat::zeros(imgA->cvimg->rows, imgA->cvimg->cols, CV_8UC3);
    //prepare the four quadrants of the output img
    cv::Mat NW = cv::Mat::zeros(imgA->cvimg->rows/2, imgA->cvimg->cols/2, CV_8UC3);
    cv::Mat NE = cv::Mat::zeros(imgA->cvimg->rows/2, imgA->cvimg->cols/2, CV_8UC3);
    cv::Mat SW = cv::Mat::zeros(imgA->cvimg->rows/2, imgA->cvimg->cols/2, CV_8UC3);
    cv::Mat SE = cv::Mat::zeros(imgA->cvimg->rows/2, imgA->cvimg->cols/2, CV_8UC3);
    A = imgA->cvimg->clone();
    imgB->cvimg->copyTo(B);
    //separate the input img into four quadrants
    cv::Mat NWA = A(cv::Rect(0, 0, imgA->cvimg->cols / 2, imgA->cvimg->rows / 2));
    cv::Mat NEA = A(cv::Rect(imgA->cvimg->cols / 2, 0, imgA->cvimg->cols/2,imgA->cvimg->rows/2));
    cv::Mat SWA = A(cv::Rect(0, imgA->cvimg->rows / 2, imgA->cvimg->cols / 2, imgA->cvimg->rows / 2));
    cv::Mat SEA = A(cv::Rect(imgA->cvimg->cols / 2 , imgA->cvimg->rows / 2, imgA->cvimg->cols / 2, imgA->cvimg->rows / 2));
    cv::Mat NWB = B(cv::Rect(0, 0, imgB->cvimg->cols / 2, imgB->cvimg->rows / 2));
    cv::Mat NEB = B(cv::Rect(imgB->cvimg->cols / 2, 0, imgB->cvimg->cols / 2, imgB->cvimg->rows / 2));
    cv::Mat SWB = B(cv::Rect(0, imgB->cvimg->rows / 2, imgB->cvimg->cols / 2, imgB->cvimg->rows / 2));
    cv::Mat SEB = B(cv::Rect(imgB->cvimg->cols / 2, imgB->cvimg->rows / 2, imgB->cvimg->cols / 2, imgB->cvimg->rows / 2));

    //lowpass subband: averaging operations, highpass subband: maximum selection
    //lowpass subband
    for (int channel = 0; channel < 3; channel++)
    {
        for ( int r = 0; r < NW.rows; r++)
        {
            for (int c = 0; c < NW.cols; c++)
            {
                NW.at<cv::Vec3b>(r, c)[channel] =  (NWA.at<cv::Vec3b>(r, c)[channel] + NWB.at<cv::Vec3b>(r, c)[channel])/2;
            }
        }
    }
    //highpass subband
    for (int channel = 0; channel < 3; channel++)
    {
        for ( int r = 0; r < NE.rows; r++)
        {
            for (int c = 0; c < NE.cols; c++)
            {
                NE.at<cv::Vec3b>(r, c)[channel] =  std::max(NEA.at<cv::Vec3b>(r, c)[channel], NEB.at<cv::Vec3b>(r, c)[channel]);
                SW.at<cv::Vec3b>(r, c)[channel] =  std::max(SWA.at<cv::Vec3b>(r, c)[channel], SWB.at<cv::Vec3b>(r, c)[channel]);
                SE.at<cv::Vec3b>(r, c)[channel] =  std::max(SEA.at<cv::Vec3b>(r, c)[channel], SEB.at<cv::Vec3b>(r, c)[channel]);
            }
        }
    }

    NW.copyTo(m(cv::Rect(0,0, m.cols / 2, m.rows/2)));
    NE.copyTo(m(cv::Rect(m.cols / 2, 0,m.cols/2, m.rows / 2)));
    SW.copyTo(m(cv::Rect(0, m.rows/2, m.cols / 2, m.rows/2)));
    SE.copyTo(m(cv::Rect(m.cols / 2, m.rows/2,m.cols/2, m.rows / 2)));
    return new CVImage(m, false);
}


//ref: https://answers.opencv.org/question/42273/wavelet-transform/
//using Harr wavelet to do the inverse DWT
CVImage* CVImage::HarrWaveletTransformInversed(CVImage* img)
{
    float a, b, c, d;
    cv::Mat m = cv::Mat::zeros(img->cvimg->rows, img->cvimg->cols, CV_32FC3);
    img->cvimg->convertTo(m, CV_32FC3, 1.0, 0.0);
    cv::Mat imr = cv::Mat::zeros(m.rows,m.cols,CV_32FC3);
    cv::Mat imi1 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat imi2 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat imi3 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat imi4 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat im3 = m(cv::Rect(0,0, m.cols / 2, m.rows/2));
    cv::Mat im4 = m(cv::Rect(m.cols / 2, 0, m.cols/2,m.rows/2));
    cv::Mat im5 = m(cv::Rect(0, m.rows / 2, m.cols/2,m.rows/2));
    cv::Mat im6 = m(cv::Rect(m.cols/2,m.rows/2,m.cols/2,m.rows/2));

    //Upsampling of stage I
    for (int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0;rcnt<m.rows/2;rcnt++)
        {
            for(int ccnt=0;ccnt<m.cols/2;ccnt++)
            {
                int _ccnt=ccnt*2;
                imi1.at<cv::Vec3f>(rcnt,_ccnt)[channel] = im3.at<cv::Vec3f>(rcnt,ccnt)[channel];
                imi2.at<cv::Vec3f>(rcnt,_ccnt)[channel] = im4.at<cv::Vec3f>(rcnt,ccnt)[channel];
                imi3.at<cv::Vec3f>(rcnt,_ccnt)[channel] = im5.at<cv::Vec3f>(rcnt,ccnt)[channel];
                imi4.at<cv::Vec3f>(rcnt,_ccnt)[channel] = im6.at<cv::Vec3f>(rcnt,ccnt)[channel];
            }
        }

    }
    //Filtering at Stage I
    for (int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0;rcnt<m.rows/2;rcnt++)
        {
            for(int ccnt=0;ccnt<m.cols;ccnt+=2)
            {

                a = imi1.at<cv::Vec3f>(rcnt,ccnt)[channel];
                b = imi2.at<cv::Vec3f>(rcnt,ccnt)[channel];
                c = (a+b) * 0.707;
                imi1.at<cv::Vec3f>(rcnt,ccnt)[channel] = c;
                d = (a-b)*0.707;
                imi1.at<cv::Vec3f>(rcnt,ccnt+1)[channel] = d;
                a = imi3.at<cv::Vec3f>(rcnt,ccnt)[channel];
                b = imi4.at<cv::Vec3f>(rcnt,ccnt)[channel];
                c = (a+b)*0.707;
                imi3.at<cv::Vec3f>(rcnt,ccnt)[channel] = c;
                d = (a-b)*0.707;
                imi3.at<cv::Vec3f>(rcnt,ccnt+1)[channel] = d;
            }
        }

    }
    cv::Mat temp = cv::Mat::zeros(m.rows,m.cols,CV_32FC3);

    //Upsampling at stage II
    for (int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0;rcnt<m.rows/2;rcnt++)
        {
            for(int ccnt=0;ccnt<m.cols;ccnt++)
            {

                int _rcnt=rcnt*2;
                imr.at<cv::Vec3f>(_rcnt,ccnt)[channel] = imi1.at<cv::Vec3f>(rcnt,ccnt)[channel];
                temp.at<cv::Vec3f>(_rcnt,ccnt)[channel] = imi3.at<cv::Vec3f>(rcnt,ccnt)[channel];
            }
        }
    }

    //Filtering at Stage II
    for (int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0;rcnt<m.rows;rcnt+=2)
        {
            for(int ccnt=0;ccnt<m.cols;ccnt++)
            {

                a = imr.at<cv::Vec3f>(rcnt,ccnt)[channel];
                b = temp.at<cv::Vec3f>(rcnt,ccnt)[channel];
                c = (a+b)*0.707;
                imr.at<cv::Vec3f>(rcnt,ccnt)[channel] = c;
                d = (a-b)*0.707;
                imr.at<cv::Vec3f>(rcnt+1,ccnt)[channel] = d;
            }
        }
    }
    cv::normalize(imr, imr, 0, 255, cv::NORM_MINMAX);
    imr.convertTo(imr,CV_8UC3);

    return new CVImage(imr, false);

}

//ref: https://docs.opencv.org/3.4/d9/db0/tutorial_hough_lines.html
//apply Hough finding line method
//first turn the image into gray, then use Canny to find the edges
//after Canny, use cv::HoughLines to find the rho and theta
//convert rho and theta to y = mx + b, in order to find the (x, y) of intercepting points
//put numbers on the points for specification, then draw long lines for better visual representation
CVImage* CVImage::HoughTransform(CVImage* img, int CannyThreshold1, int CannyThresold2, int HoughThreshold,  vector<cv::Point>** ptis)
{
    // Declare the output variables
    cv::Mat dst, cdst, m;
    (*img->cvimg).convertTo(m, CV_8UC1,1.0, 0.0);
    // Edge detection
    cv::Canny(m, dst, CannyThreshold1, CannyThresold2, 3);
    // Copy edges to the images that will display the results in RGB
    cvtColor(dst, cdst, cv::COLOR_GRAY2RGB);
    // Standard Hough Line Transform
    // will hold the results of the detection
    vector<cv::Vec2f> lines;
    // runs the actual detection, default threshold: 150
    cv::HoughLines(dst, lines, 1, CV_PI/180, HoughThreshold, 0, 0 );
    vector<cv::Vec2f> lineq(lines.size());
    int pcnt = 0;
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        //m
        lineq[i][0] = -cos(theta) / sin(theta);
        //b
        lineq[i][1] = rho / sin(theta);
        cv::Point pti;
        if (i > 0)
        {

            for (size_t j = 1; j <= i; j++)
            {
                pti.x = cvRound((lineq[i - j][1] - lineq[i][1]) / (lineq[i][0] - lineq[i - j][0]));
                pti.y = cvRound(lineq[i][0] * pti.x + lineq[i][1]);
                if (pti.x >= 0 && pti.y >= 0 && pti.x < dst.cols && pti.y < dst.rows)
                {
                    cv::circle(cdst, pti, 2, cv::Scalar(255, 0, 0), -1);
                    cv::putText(cdst, cv::String(std::to_string(pcnt)), cv::Point(pti.x + 2, pti.y + 2), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 255, 255), 1, cv::LINE_AA);
                    pcnt++;
                    (*ptis)->push_back(pti);
                }
            }
        }
        // Draw the lines
        cv::Point pt1, pt2;
        double ct = cos(theta), st = sin(theta);
        double x0 = ct * rho, y0 = st * rho;
        pt1.x = cvRound(x0 + 1000 * (-st));
        pt1.y = cvRound(y0 + 1000 * (ct));
        pt2.x = cvRound(x0 - 1000 * (-st));
        pt2.y = cvRound(y0 - 1000 * (ct));
        cv::line(cdst, pt1, pt2, cv::Scalar(0, 64, 64), 1, cv::LINE_AA);
    }
    return new CVImage(cdst, false);
}

//get the pixel distance of two points
double CVImage::GetDistance(std::vector<cv::Point>* pts, int iP1, int iP2)
{
    return sqrt((pts->at(iP1).x -  pts->at(iP2).x) * (pts->at(iP1).x -  pts->at(iP2).x) + (pts->at(iP1).y -  pts->at(iP2).y) * (pts->at(iP1).y -  pts->at(iP2).y));
}




//HW5
//get the RGB planes of the image
void CVImage::GetRGBPlanes(CVImage* img, CVImage** R, CVImage** G, CVImage** B)
{

    bool greyflag = true;
    std::vector<cv::Mat> V(3);
    //the priority of -> operator is higher than * operator,
    //so *img->cvimg means access cvimg first then dereference cvimg pointer,
    //while (*img).foo means dereference first then use the object to call function
    cv::split(*(img->cvimg), V);
    *R = new CVImage(V[0], greyflag);
    *G = new CVImage(V[1], greyflag);
    *B = new CVImage(V[2], greyflag);
}

//get the CMY planes of the image
void CVImage::GetCMYPlanes(CVImage* img, CVImage** C, CVImage** M, CVImage** Y)
{
    bool greyflag = true;
    std::vector<cv::Mat> V(3);
    cv::split(*(img->cvimg), V);
    for (int channel = 0; channel < 3; channel++)
    {
        for (int r = 0; r < img->cvimg->rows; r++)
        {
            for (int c = 0; c < img->cvimg->cols; c++)
            {
                V[channel].at<uchar>(r, c) =  255 - V[channel].at<uchar>(r, c);
            }
        }
    }
    *C = new CVImage(V[0], greyflag);
    *M = new CVImage(V[1], greyflag);
    *Y = new CVImage(V[2], greyflag);
}

//get the HSI (HSV) planes of the image
void CVImage::GetHSIPlanes(CVImage* img, CVImage** H, CVImage** S, CVImage** I)
{
    bool greyflag = true;
    std::vector<cv::Mat> V(3);
    cv::Mat HSI;
    cv::cvtColor(*img->cvimg, HSI, cv::COLOR_RGB2HSV);
    cv::split(HSI, V);

    //works but somtimes the saturation plane would be a little off
    //    cv::split(*(img->cvimg), V);
    //    double red, green, blue;
    //    double thetarad;
    //    for (int r = 0; r < img->cvimg->rows; r++)
    //    {
    //        for (int c = 0; c < img->cvimg->cols; c++)
    //        {
    //            red = V[0].at<uchar>(r, c);
    //            green = V[1].at<uchar>(r, c);
    //            blue = V[2].at<uchar>(r, c);
    //            //I
    //            V[2].at<uchar>(r, c) = (red + green + blue)/3;
    //            if (red==green && red==blue)
    //            {
    //                //avoid H = nan
    //                thetarad = CV_PI/2.0;
    //                //S = 0
    //                V[1].at<uchar>(r, c) = 0;
    //            }
    //            else
    //            {
    //                V[1].at<uchar>(r, c) = 255 - 1.0/V[2].at<uchar>(r, c) * std::min(red, std::min(green, blue));
    //                thetarad = acos(((red/255.0-green/255.0)+(red/255.0-blue/255.0))/2.0/sqrt((red/255.0-green/255.0)*(red/255.0-green/255.0) + (red/255.0-blue/255.0)*(green/255.0-blue/255.0)));
    //            }
    //            if (thetarad<0)
    //               thetarad = thetarad + 2 * CV_PI;
    //            thetarad = thetarad/(2*CV_PI) * (255.0 - 0.0);
    //            if (blue>green)
    //                V[0].at<uchar>(r, c) = (uchar)(255 - thetarad);
    //            else
    //                V[0].at<uchar>(r, c) = (uchar)(thetarad);
    //        }
    //    }

    *H = new CVImage(V[0], greyflag);
    *S = new CVImage(V[1], greyflag);
    *I = new CVImage(V[2], greyflag);
}

//get the XYZ planes of the image using transform matrix
void CVImage::GetXYZPlanes(CVImage* img, CVImage** X, CVImage** Y, CVImage** Z)
{
    //transform matrix
    //[ X ]   [  0.412453  0.357580  0.180423 ]   [ R ]
    //[ Y ] = [  0.212671  0.715160  0.072169 ] * [ G ]
    //[ Z ]   [  0.019334  0.119193  0.950227 ]   [ B ]
    bool greyflag = true;
    std::vector<cv::Mat> V(3);
    cv::split(*(img->cvimg), V);
    double red, green, blue;
    for (int r = 0; r < img->cvimg->rows; r++)
    {
        for (int c = 0; c < img->cvimg->cols; c++)
        {
            red = V[0].at<uchar>(r, c)/255.0;
            green = V[1].at<uchar>(r, c)/255.0;
            blue = V[2].at<uchar>(r, c)/255.0;
            //kind of stupid to check every block, but is needed because assign >255 to cv::Mat is acceptable,
            //and the pixel would overflow itself. So when I check in CVImage new the pixel is already overflowed,
            //the checking in constructor would fail.
            V[0].at<uchar>(r, c) = ForcePixelIntegrityandturnto255(0.412453 * red + 0.357580 * green + 0.180423 * blue);
            V[1].at<uchar>(r, c) = ForcePixelIntegrityandturnto255(0.212671 * red + 0.715160 * green + 0.072169 * blue);
            V[2].at<uchar>(r, c) = ForcePixelIntegrityandturnto255(0.019334 * red + 0.119193 * green + 0.950227 * blue);
        }
    }
    *X = new CVImage(V[0], greyflag);
    *Y = new CVImage(V[1], greyflag);
    *Z = new CVImage(V[2], greyflag);
}

//get the CIE L*a*b* planes of the image
void CVImage::GetLABPlanes(CVImage* img, CVImage** L, CVImage** A, CVImage** B)
{
    bool greyflag = true;
    std::vector<cv::Mat> V(3);
    cv::Mat m;
    cv::split(*(img->cvimg), V);
    cv::cvtColor(*img->cvimg, m, cv::COLOR_RGB2Lab);
    cv::split(m, V);

    //do not works, but at least I tried gto write the algorithm on my own
    //    double red, green, blue;
    //    double Xw, Yw, Zw;
    //    //CIE standard D65 illumination (defined by x = 0.3127 and y = 0.3290 z = 0.3583)
    //    Xw = 95.0489/255.0;
    //    Yw = 100/255.0;
    //    Zw = 108.884/255.0;
    //    double X, Y, Z;
    //    double j, q, p;
    //    for (int r = 0; r < img->cvimg->rows; r++)
    //    {
    //        for (int c = 0; c < img->cvimg->cols; c++)
    //        {
    //            red = V[0].at<uchar>(r, c)/255.0;
    //            green = V[1].at<uchar>(r, c)/255.0;
    //            blue = V[2].at<uchar>(r, c)/255.0;
    //            //kind of stupid to check every block, because assign >255 to cv::Mat is acceptable,
    //            //the pixel would overflow itself. So when I check in CVImage new the pixel is already overflowed.
    //            X = ForcePixelIntegrity(0.412453 * red + 0.357580 * green + 0.180423 * blue);
    //            Y = ForcePixelIntegrity(0.212671 * red + 0.715160 * green + 0.072169 * blue);
    //            Z = ForcePixelIntegrity(0.019334 * red + 0.119193 * green + 0.950227 * blue);

    //            j = ((116.0 * GetLABhval(Y/Yw) - 16.0)/100.0)*255.0;
    //            q = ((500.0 * (GetLABhval(X/Xw) - GetLABhval(Y/Yw)))-(-500.0))/1000.0*255.0;
    //            p = ((200.0 * (GetLABhval(Y/Yw) - GetLABhval(Z/Zw)))-(-200.0))/400.0*255.0;


    //            V[0].at<uchar>(r, c) = ((116.0 * GetLABhval(Y/Yw) - 16.0)/100.0)*255.0;
    //            V[1].at<uchar>(r, c) = ((500.0 * (GetLABhval(X/Xw) - GetLABhval(Y/Yw)))-(-500.0))/1000.0*255.0;
    //            V[2].at<uchar>(r, c) = ((200.0 * (GetLABhval(Y/Yw) - GetLABhval(Z/Zw)))-(-200.0))/400.0*255.0;
    //        }
    //    }

    *L = new CVImage(V[0], greyflag);
    *A = new CVImage(V[1], greyflag);
    *B = new CVImage(V[2], greyflag);
}

//the h function used in CIE L*a*b*
double CVImage::GetLABhval(double q)
{
    int h;
    if (q>0.008856)
        h = cbrt(q);
    else
        h = 7.787*q + 16.0/116.0;
    return h;
}

//get the YUV planes of the image using RGB,
//the RGB needs to be gamma corrected before substitute into the formula
void CVImage::GetYUVPlanes(CVImage* img, CVImage** Y, CVImage** U, CVImage** V)
{
    bool greyflag = true;
    std::vector<cv::Mat> Vec(3);
    cv::split(*(img->cvimg), Vec);
    int red, green, blue;
    //build gamma correction table to increase efficiency
    //ref: https://www.itread01.com/content/1542586563.html
    //fix gamma to 2.2
    double gamma = 2.2;
    float f;
    int table[256];
    for(int i=0;i<256;i++)
    {
        //normalize
        f=(i+0.5)/256;
        f=(float)pow(f,1.0/gamma);
        //denormalize
        table[i]=(int)(f*256-0.5);
    }
    for (int r = 0; r < img->cvimg->rows; r++)
    {
        for (int c = 0; c < img->cvimg->cols; c++)
        {
            red = Vec[0].at<uchar>(r, c);
            green = Vec[1].at<uchar>(r, c);
            blue = Vec[2].at<uchar>(r, c);
            //kind of stupid to check every block, because assign >255 to cv::Mat is acceptable,
            //the pixel would overflow itself. So when I check in CVImage new the pixel is already overflowed.
            Vec[0].at<uchar>(r, c) = ForcePixelIntegrity255(0.299 * table[red] + 0.587 * table[green] + 0.114 * table[blue] + 0);
            Vec[1].at<uchar>(r, c) = ForcePixelIntegrity255(-0.169 * table[red] + -0.331 * table[green] + 0.5 * table[blue] + 128);
            Vec[2].at<uchar>(r, c) = ForcePixelIntegrity255(0.5 * table[red] + -0.419 * table[green] + -0.081 * table[blue] + 128);
        }
    }
    *Y = new CVImage(Vec[0], greyflag);
    *U = new CVImage(Vec[1], greyflag);
    *V = new CVImage(Vec[2], greyflag);
}


//prevent overflow
int CVImage::ForcePixelIntegrityandturnto255(double pxl)
{
    if (pxl>1)
        pxl=255;
    else if (pxl<0)
        pxl=0;
    else
        pxl = pxl * 255;
    return pxl;
}
//prevent overflow
int CVImage::ForcePixelIntegrity255(int pxl)
{
    if (pxl>255)
        pxl=255;
    else if (pxl<0)
        pxl=0;
    return pxl;
}
//prevent overflow
double CVImage::ForcePixelIntegrity(double pxl)
{
    if (pxl>1)
        pxl=1;
    else if (pxl<0)
        pxl=0;
    return pxl;
}

//turn a color image into gray scale image
CVImage* CVImage::TurnGrayScaleImage(CVImage* img)
{
    cv::Mat mat;
    cvtColor(*(img->cvimg), mat, cv::COLOR_RGB2GRAY);
    return new CVImage(mat, true);
}

//create color bar used in pseudo-color image part
//the color gradient effect is generated by the interpolation of 5 image
//with fixed gray scale range of 64
CVImage* CVImage::CreateColorBar(CVImage* img1, CVImage* img2, CVImage* img3,CVImage* img4, CVImage* img5)
{
    cv::Mat m = cv::Mat::zeros(img1->cvimg->rows,  4 * img1->cvimg->cols, CV_8UC3);
    double rdiff[4];
    double gdiff[4];
    double bdiff[4];
    //calculate the gradient of 4 range
    for (int i = 0; i < 4; i++)
    {
        switch(i)
        {
        case 0:
            rdiff[i] = (img2->Qimg->pixelColor(4, 4).red() - img1->Qimg->pixelColor(4, 4).red())/(double)(img1->cvimg->cols);
            gdiff[i] = (img2->Qimg->pixelColor(4, 4).green() - img1->Qimg->pixelColor(4, 4).green())/(double)(img1->cvimg->cols);
            bdiff[i] = (img2->Qimg->pixelColor(4, 4).blue() - img1->Qimg->pixelColor(4, 4).blue())/(double)(img1->cvimg->cols);
            break;
        case 1:
            rdiff[i] = (img3->Qimg->pixelColor(4, 4).red() - img2->Qimg->pixelColor(4, 4).red())/(double)(img1->cvimg->cols);
            gdiff[i] = (img3->Qimg->pixelColor(4, 4).green() - img2->Qimg->pixelColor(4, 4).green())/(double)(img1->cvimg->cols);
            bdiff[i] = (img3->Qimg->pixelColor(4, 4).blue() - img2->Qimg->pixelColor(4, 4).blue())/(double)(img1->cvimg->cols);
            break;
        case 2:
            rdiff[i] = (img4->Qimg->pixelColor(4, 4).red() - img3->Qimg->pixelColor(4, 4).red())/(double)(img1->cvimg->cols);
            gdiff[i] = (img4->Qimg->pixelColor(4, 4).green() - img3->Qimg->pixelColor(4, 4).green())/(double)(img1->cvimg->cols);
            bdiff[i] = (img4->Qimg->pixelColor(4, 4).blue() - img3->Qimg->pixelColor(4, 4).blue())/(double)(img1->cvimg->cols);
            break;
        case 3:
            rdiff[i] = (img5->Qimg->pixelColor(4, 4).red() - img4->Qimg->pixelColor(4, 4).red())/(double)(img1->cvimg->cols);
            gdiff[i] = (img5->Qimg->pixelColor(4, 4).green() - img4->Qimg->pixelColor(4, 4).green())/(double)(img1->cvimg->cols);
            bdiff[i] = (img5->Qimg->pixelColor(4, 4).blue() - img4->Qimg->pixelColor(4, 4).blue())/(double)(img1->cvimg->cols);
            break;
        default:
            break;
        }
    }
    //assign color into color bar
    int j;
    for (int c = 0; c < 4 * img1->cvimg->cols; c++)
    {
        if (c < img1->cvimg->cols)
        {
            if (c == 0)
                j = 0;
            for (int r = 0; r < img1->cvimg->rows; r++)
            {
                m.at<cv::Vec3b>(r,c)[0] = img1->Qimg->pixelColor(j,r).red() + j*rdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[1] = img1->Qimg->pixelColor(j,r).green() + j*gdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[2] = img1->Qimg->pixelColor(j,r).blue() + j*bdiff[c/img1->cvimg->cols];
            }
            j++;
        }
        else if(c >= img1->cvimg->cols && c < 2 * img1->cvimg->cols)
        {
            if (c == img1->cvimg->cols)
                j = 0;
            for (int r = 0; r < img1->cvimg->rows; r++)
            {
                m.at<cv::Vec3b>(r,c)[0] = img2->Qimg->pixelColor(j,r).red() + j*rdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[1] = img2->Qimg->pixelColor(j,r).green() + j*gdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[2] = img2->Qimg->pixelColor(j,r).blue() + j*bdiff[c/img1->cvimg->cols];
            }
            j++;
        }
        else if(c >= 2 * img1->cvimg->cols && c < 3 * img1->cvimg->cols)
        {
            if (c == 2 * img1->cvimg->cols)
                j = 0;
            for (int r = 0; r < img1->cvimg->rows; r++)
            {
                m.at<cv::Vec3b>(r,c)[0] = img3->Qimg->pixelColor(j,r).red() + j*rdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[1] = img3->Qimg->pixelColor(j,r).green() + j*gdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[2] = img3->Qimg->pixelColor(j,r).blue() + j*bdiff[c/img1->cvimg->cols];
            }
            j++;
        }
        else
        {
            if (c == 3 * img1->cvimg->cols)
                j = 0;
            for (int r = 0; r < img1->cvimg->rows; r++)
            {
                m.at<cv::Vec3b>(r,c)[0] = img4->Qimg->pixelColor(j,r).red() + j*rdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[1] = img4->Qimg->pixelColor(j,r).green() + j*gdiff[c/img1->cvimg->cols];
                m.at<cv::Vec3b>(r,c)[2] = img4->Qimg->pixelColor(j,r).blue() + j*bdiff[c/img1->cvimg->cols];
            }
            j++;
        }
    }
    return new CVImage(m, false);
}

//get pseudo-color image from a gray scale image
CVImage* CVImage::GetPseudoColorImage(CVImage* srcimg, CVImage* img1, CVImage* img2, CVImage* img3, CVImage* img4, CVImage* img5)
{
    cv::Mat m = cv::Mat::zeros(srcimg->cvimg->rows,srcimg->cvimg->cols, CV_8UC3);
    std::vector<QColor> V(256);
    double rdiff[4];
    double gdiff[4];
    double bdiff[4];
    //calculate the gradient of 4 range
    for (int i = 0; i < 4; i++)
    {
        switch(i)
        {
        case 0:
            rdiff[i] = (img2->Qimg->pixelColor(4, 4).red() - img1->Qimg->pixelColor(4, 4).red())/64.0;
            gdiff[i] = (img2->Qimg->pixelColor(4, 4).green() - img1->Qimg->pixelColor(4, 4).green())/64.0;
            bdiff[i] = (img2->Qimg->pixelColor(4, 4).blue() - img1->Qimg->pixelColor(4, 4).blue())/64.0;
            break;
        case 1:
            rdiff[i] = (img3->Qimg->pixelColor(4, 4).red() - img2->Qimg->pixelColor(4, 4).red())/64.0;
            gdiff[i] = (img3->Qimg->pixelColor(4, 4).green() - img2->Qimg->pixelColor(4, 4).green())/64.0;
            bdiff[i] = (img3->Qimg->pixelColor(4, 4).blue() - img2->Qimg->pixelColor(4, 4).blue())/64.0;
            break;
        case 2:
            rdiff[i] = (img4->Qimg->pixelColor(4, 4).red() - img3->Qimg->pixelColor(4, 4).red())/64.0;
            gdiff[i] = (img4->Qimg->pixelColor(4, 4).green() - img3->Qimg->pixelColor(4, 4).green())/64.0;
            bdiff[i] = (img4->Qimg->pixelColor(4, 4).blue() - img3->Qimg->pixelColor(4, 4).blue())/64.0;
            break;
        case 3:
            rdiff[i] = (img5->Qimg->pixelColor(4, 4).red() - img4->Qimg->pixelColor(4, 4).red())/64.0;
            gdiff[i] = (img5->Qimg->pixelColor(4, 4).green() - img4->Qimg->pixelColor(4, 4).green())/64.0;
            bdiff[i] = (img5->Qimg->pixelColor(4, 4).blue() - img4->Qimg->pixelColor(4, 4).blue())/64.0;
            break;
        default:
            break;
        }
    }
    //construct a lookup table for gray scale->color
    for (int i = 0; i < V.size(); i++)
    {
        if (i < 64)
        {
            V[i] =  QColor((img1->Qimg->pixelColor(4, 4).red() + i * rdiff[i/64]), \
                    (img1->Qimg->pixelColor(4, 4).green() + i * gdiff[i/64]), (img1->Qimg->pixelColor(4, 4).blue() + i * bdiff[i/64]));
        }
        else if (i >= 64 && i < 128 )
        {
            V[i] =  QColor((img2->Qimg->pixelColor(4, 4).red() + (i-64) * rdiff[i/64]), \
                    (img2->Qimg->pixelColor(4, 4).green() + (i-64) * gdiff[i/64]), (img2->Qimg->pixelColor(4, 4).blue() + (i-64) * bdiff[i/64]));
        }
        else if (i >= 128 && i < 192 )
        {
            V[i] =  QColor((img3->Qimg->pixelColor(4, 4).red() + (i-128) * rdiff[i/64]), \
                    (img3->Qimg->pixelColor(4, 4).green() + (i-128) * gdiff[i/64]), (img3->Qimg->pixelColor(4, 4).blue() + (i-128) * bdiff[i/64]));
        }
        else
        {
            V[i] =  QColor((img4->Qimg->pixelColor(4, 4).red() + (i-192) * rdiff[i/64]), \
                    (img4->Qimg->pixelColor(4, 4).green() + (i-192) * gdiff[i/64]), (img4->Qimg->pixelColor(4, 4).blue() + (i-192) * bdiff[i/64]));
        }

    }
    //assign color to corresponding gray scale
    for (int r = 0; r < srcimg->cvimg->rows; r++)
    {
        for (int c = 0; c < srcimg->cvimg->cols; c++)
        {
            m.at<cv::Vec3b>(r,c)[0] = V[(int)(srcimg->cvimg->at<uchar>(r,c))].red();
            m.at<cv::Vec3b>(r,c)[1] = V[(int)(srcimg->cvimg->at<uchar>(r,c))].green();
            m.at<cv::Vec3b>(r,c)[2] = V[(int)(srcimg->cvimg->at<uchar>(r,c))].blue();
        }

    }
    return new CVImage(m, false);
}

//using K-means method to get clustered image
CVImage* CVImage::GetClusteredImage(CVImage* srcimg, int K, int Colortype)
{
    //ref: https://www.itread01.com/content/1546892303.html
    cv::Mat ImgRes(srcimg->cvimg->size(), CV_8UC3);
    switch(Colortype)
    {
    case 0:
    {
        cv::Mat ImgRGB;
        ImgRGB = *srcimg->cvimg;
        cv::Mat ImgData(srcimg->cvimg->rows*srcimg->cvimg->cols, 1, CV_32FC3);
        //iterator
        cv::Mat_<cv::Vec3b>::iterator itImg = ImgRGB.begin<cv::Vec3b>();
        cv::Mat_<cv::Vec3f>::iterator itData = ImgData.begin<cv::Vec3f>();
        //put srcdata into new data mat
        for (; itImg != ImgRGB.end<cv::Vec3b>(); ++itImg, ++itData)
            *itData = *itImg;
        cv::Mat ImgLabel, ImgCenter;
        kmeans(ImgData, K, ImgLabel, cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0), 1, cv::KMEANS_PP_CENTERS, ImgCenter);
        cv::Mat_<cv::Vec3b>::iterator itRes = ImgRes.begin<cv::Vec3b>();
        cv::Mat_<int>::iterator itLabel = ImgLabel.begin<int>();
        for (; itLabel != ImgLabel.end<int>(); ++itLabel, ++itRes)
            *itRes = ImgCenter.at<cv::Vec3f>(*itLabel, 0);
        break;
    }

    case 1:
    {
        cv::Mat ImgHSV;
        //turn RGB to HSV
        cv::cvtColor(*srcimg->cvimg, ImgHSV, cv::COLOR_RGB2HSV);
        cv::Mat ImgData(srcimg->cvimg->rows*srcimg->cvimg->cols, 1, CV_32FC3);
        //iterator
        cv::Mat_<cv::Vec3b>::iterator itImg = ImgHSV.begin<cv::Vec3b>();
        cv::Mat_<cv::Vec3f>::iterator itData = ImgData.begin<cv::Vec3f>();
        //put srcdata into new data mat
        for (; itImg != ImgHSV.end<cv::Vec3b>(); ++itImg, ++itData)
            *itData = *itImg;
        cv::Mat ImgLabel, ImgCenter;
        cv::kmeans(ImgData, K, ImgLabel, cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0), 1, cv::KMEANS_PP_CENTERS, ImgCenter);
        cv::Mat_<cv::Vec3b>::iterator itRes = ImgRes.begin<cv::Vec3b>();
        cv::Mat_<int>::iterator itLabel = ImgLabel.begin<int>();
        for (; itLabel != ImgLabel.end<int>(); ++itLabel, ++itRes)
            //itLabel stores the K of each pixel in 1-dim, ImgCenter stores where the K's center at
            //using this kinde of index to get what should be put into the itRes
            *itRes = ImgCenter.at<cv::Vec3f>(*itLabel, 0);
        cvtColor(ImgRes, ImgRes, cv::COLOR_HSV2RGB);
        break;
    }
    case 2:
    {
        cv::Mat ImgLAB;
        //turn RGB to CIELAB
        cv::cvtColor(*srcimg->cvimg, ImgLAB, cv::COLOR_RGB2Lab);
        cv::Mat ImgData(srcimg->cvimg->rows*srcimg->cvimg->cols, 1, CV_32FC3);
        //iterator
        cv::Mat_<cv::Vec3b>::iterator itImg = ImgLAB.begin<cv::Vec3b>();
        cv::Mat_<cv::Vec3f>::iterator itData = ImgData.begin<cv::Vec3f>();
        //put srcdata into new data mat
        for (; itImg != ImgLAB.end<cv::Vec3b>(); ++itImg, ++itData)
            *itData = *itImg;
        cv::Mat ImgLabel, ImgCenter;
        kmeans(ImgData, K, ImgLabel, cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0), 1, cv::KMEANS_PP_CENTERS, ImgCenter);

        cv::Mat_<cv::Vec3b>::iterator itRes = ImgRes.begin<cv::Vec3b>();
        cv::Mat_<int>::iterator itLabel = ImgLabel.begin<int>();
        for (; itLabel != ImgLabel.end<int>(); ++itLabel, ++itRes)
            *itRes = ImgCenter.at<cv::Vec3f>(*itLabel, 0);
        cvtColor(ImgRes, ImgRes, cv::COLOR_Lab2RGB);
        break;
    }
    default:
        break;
    }
    return new CVImage(ImgRes, false);
}




