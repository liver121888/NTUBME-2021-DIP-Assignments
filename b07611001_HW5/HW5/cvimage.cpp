#include "cvimage.h"

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


//constructor for mono image
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




