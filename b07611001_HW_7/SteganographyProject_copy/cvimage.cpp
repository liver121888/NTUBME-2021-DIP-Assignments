#include "cvimage.h"

using namespace std;

//empty constructor
CVImage::CVImage()
{

}


//constructor
CVImage::CVImage(QString filename, bool pngflag)
{
    Qimg = new QImage();
    GrayQimg = new QImage();
    CVimg = new cv::Mat();
    if (pngflag)
    {
        *CVimg = cv::imread(filename.toStdString().data(), cv::IMREAD_UNCHANGED);
        cvtColor(*CVimg, *CVimg, CV_BGRA2RGB);
        (*Qimg).load(filename);
        *GrayQimg = QImage(CVimg->cols, CVimg->rows, QImage::Format_RGB888);
        for (int r = 0; r < CVimg->rows; r++)
        {
            for (int c = 0; c < CVimg->cols; c++)
            {
                int a = (CVimg->at<cv::Vec3b>(r,c)[0]+ CVimg->at<cv::Vec3b>(r,c)[1]+ CVimg->at<cv::Vec3b>(r,c)[2])/3;
                GrayQimg->setPixelColor(c, r, QColor(a, a, a));
            }
        }
    }
    else
    {
        *CVimg = cv::imread(filename.toStdString().data(), cv::IMREAD_COLOR);
        cvtColor(*CVimg, *CVimg, CV_BGR2RGB);
        *GrayQimg = QImage(CVimg->cols, CVimg->rows, QImage::Format_RGB888);
        *Qimg = QImage((unsigned char*)(CVimg->data), CVimg->cols, CVimg->rows, QImage::Format_RGB888);
        for (int r = 0; r < CVimg->rows; r++)
        {
            for (int c = 0; c < CVimg->cols; c++)
            {
                int a = (CVimg->at<cv::Vec3b>(r,c)[0]+ CVimg->at<cv::Vec3b>(r,c)[1]+ CVimg->at<cv::Vec3b>(r,c)[2])/3;
                GrayQimg->setPixelColor(c, r, QColor(a, a, a));
            }
        }
    }
}

//constructor for cv::Mat
CVImage::CVImage(cv::Mat mat)
{
    CVimg = new cv::Mat();
    Qimg = new QImage(mat.cols, mat.rows, QImage::Format_RGB888);
    GrayQimg = new QImage();
    for (int r = 0; r < CVimg->rows; r++)
    {
        for (int c = 0; c < CVimg->cols; c++)
        {
            int a = (CVimg->at<cv::Vec3b>(r,c)[0]+ CVimg->at<cv::Vec3b>(r,c)[1]+ CVimg->at<cv::Vec3b>(r,c)[2])/3;
            GrayQimg->setPixelColor(c, r, QColor(a, a, a));
        }
    }
    *CVimg = mat;
    *Qimg = QImage((unsigned char*)(CVimg->data), CVimg->cols, CVimg->rows, QImage::Format_RGB888);
}

//get private data CVimg
cv::Mat* CVImage::getCVimg()
{
    return CVimg;
}

//get private data Qimg
QImage* CVImage::getQimg()
{
    return Qimg;
}

QImage* CVImage::getGrayQimg()
{
    return GrayQimg;
}

CVImage* CVImage::LSBStego(CVImage* Img, Text* HiddenMessage)
{
    cv::Mat m = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);
    cv::Mat SrcImg;
    //At first plan to use HSV for stego, but the cv color conversion may round the infomation,
    //causing the infomation be distorted by 1 or 2, so I stick to RGB in the final version
    //    cv::cvtColor(*(Img->CVimg), HSIsrc, cv::COLOR_RGB2HSV);
    Img->CVimg->copyTo(SrcImg);
    int valchannel;
    bitset<8> binchannel;
    for (int r = 0; r < SrcImg.rows; r++)
    {
        for (int c = 0; c < SrcImg.cols; c++)
        {
            if ( (r * SrcImg.cols + c) < HiddenMessage->Getstdstr().size())
            {
                for (int channel = 0; channel < 3; channel++)
                {
                    valchannel = SrcImg.at<cv::Vec3b>(r, c)[channel];
                    binchannel = bitset<8>(valchannel);
                    if (channel == 2)
                    {
                        binchannel[0] = HiddenMessage->GetbitsetV()[r * SrcImg.cols + c][channel*2];
                        binchannel[1] = HiddenMessage->GetbitsetV()[r * SrcImg.cols + c][channel*2+1];
                        binchannel[2] = HiddenMessage->GetbitsetV()[r * SrcImg.cols + c][channel*2+2];
                    }
                    else
                    {
                        binchannel[0] = HiddenMessage->GetbitsetV()[r * SrcImg.cols + c][channel*2];
                        binchannel[1] = HiddenMessage->GetbitsetV()[r * SrcImg.cols + c][channel*2+1];
                    }
                    m.at<cv::Vec3b>(r, c)[channel] =  (int)(binchannel.to_ulong());
                }
            }
            else if ( (r * SrcImg.cols + c) == HiddenMessage->Getstdstr().size())
            {
                //add ETX to tell the reader here is the end of the hidden message
                for (int channel = 0; channel < 3; channel++)
                {
                    valchannel = SrcImg.at<cv::Vec3b>(r, c)[channel];
                    binchannel = bitset<8>(valchannel);
                    if (channel == 2)
                    {
                        binchannel[0] = 0;
                        binchannel[1] = 0;
                        binchannel[2] = 0;
                    }
                    else if (channel == 0)
                    {
                        binchannel[0] = 1;
                        binchannel[1] = 1;
                    }
                    else
                    {
                        binchannel[0] = 0;
                        binchannel[1] = 0;
                    }
                    m.at<cv::Vec3b>(r, c)[channel] =  (int)(binchannel.to_ulong());
                }
            }
            else
            {
                for (int channel = 0; channel < 3; channel++)
                {
                    m.at<cv::Vec3b>(r, c)[channel] = SrcImg.at<cv::Vec3b>(r, c)[channel];
                }

            }

        }
    }
    return new CVImage(m);
}

CVImage* CVImage::LSBextract(CVImage* Img)
{
    cv::Mat out = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);;
    bitset<8> binchannel;
    bitset<1> bin2 = 0;
    for (int channel = 0; channel < 3; channel++)
    {
        for (int r = 0; r < Img->CVimg->rows; r++)
        {
            for (int c = 0; c < Img->CVimg->cols; c++)
            {
                binchannel = Img->CVimg->at<cv::Vec3b>(r, c)[channel];
                bin2[0] = binchannel[0];
                out.at<cv::Vec3b>(r, c)[channel] = bin2.to_ulong();
            }
        }
    }
    cv::normalize(out, out, 0, 255, cv::NORM_MINMAX);
    return new CVImage(out);
}

//ref: https://docs.opencv.org/3.4/d8/dbc/tutorial_histogram_calculation.html
CVImage* CVImage::calhisto(CVImage* Img)
{
    std::vector<cv::Mat> rgb_planes;
    cv::split(*(Img->CVimg), rgb_planes);
    int histSize = 256;
    float range[] = { 0, 255 }; //the upper boundary is exclusive
    const float* histRange[] = { range };
    bool uniform = true, accumulate = false;
    cv::Mat r_hist, g_hist, b_hist;
    calcHist( &rgb_planes[0], 1, 0, cv::Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate );
    calcHist( &rgb_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate );
    calcHist( &rgb_planes[2], 1, 0, cv::Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate );

    int hist_w = 400, hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 0,0,0) );
    cv::normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    cv::normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

    for( int i = 1; i < histSize; i++ )
    {
        cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ),
              cv::Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
              cv::Scalar( 0, 0, 255), 2, 8, 0  );
        cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ),
              cv::Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
              cv::Scalar( 0, 255, 0), 2, 8, 0  );
        cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ),
              cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
              cv::Scalar( 255, 0, 0), 2, 8, 0  );
    }
    return new CVImage(histImage);
}




Text CVImage::LSBStegoDecrypt(CVImage* Img)
{
    cv::Mat SrcImg;
    Img->CVimg->copyTo(SrcImg);
    int valchannel;
    bitset<8> binchannel;
    bitset<7> binh;
    Text HiddenMessage = Text();
    for (int r = 0; r < SrcImg.rows; r++)
    {
        for (int c = 0; c < SrcImg.cols; c++)
        {
            binh = 0;
            for (int channel = 0; channel < 3; channel++)
            {
                valchannel = SrcImg.at<cv::Vec3b>(r, c)[channel];
                binchannel = bitset<8> (valchannel);
                if (channel == 2)
                {
                    binh[channel*2] = binchannel[0];
                    binh[channel*2+1] = binchannel[1];
                    binh[channel*2+2] = binchannel[2];
                }
                else
                {
                    binh[channel*2] = binchannel[0];
                    binh[channel*2+1] = binchannel[1];
                }
            }
            //detect ETX, stop decrypting
            if (binh.to_ulong() == 3)
                //first time using goto
                goto out;
            else
                HiddenMessage.Setstdstr()->push_back(static_cast<char>(binh.to_ulong()));
        }
    }
    out:
    return HiddenMessage;
}

CVImage* CVImage::DCTStego(CVImage* Img, Text* HiddenMessage)
{
    cv::Mat m = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);
    cv::Mat mout = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);
    cv::Mat DCTresult = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_32FC1);
    cv::Mat SrcImg = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_32FC3);
    //At first plan to use HSV for stego, but the cv color conversion may round the infomation,
    //causing the infomation be distorted by 1 or 2, so I stick to RGB in the final version
    //    cv::cvtColor(*(Img->CVimg), HSIsrc, cv::COLOR_RGB2HSV);
    Img->CVimg->copyTo(SrcImg);
    cv::cvtColor(SrcImg, SrcImg, cv::COLOR_RGB2HSV);



    std::vector<cv::Mat> planes;
    cv::split(SrcImg, planes);

    cv::FileStorage f("./planes2uchar.xml", cv::FileStorage::WRITE);
    f << "planes2uchar" << planes[2];

    planes[2].convertTo(planes[2], CV_32FC1);

    cv::FileStorage f6("./planes2f.xml", cv::FileStorage::WRITE);
    f6 << "planes2f" << planes[2];

    cv::dct(planes[2], DCTresult);

    cv::FileStorage file("./DCTresult.xml", cv::FileStorage::WRITE);
    file << "DCTresult_mat" << DCTresult;

    float valchannel;
    bitset<32> binchannel;
    ulong tmp;
    float tmpf;

    for (int r = DCTresult.rows-1; r >= 0; r--)
    {
        for (int c = DCTresult.cols-1; c >= 0; c--)
        {
            valchannel = DCTresult.at<float>(r, c);
            //cast my way out
            binchannel = bitset<32>(*(uint32_t*)&valchannel);
            if ( ((DCTresult.rows-1-r)*DCTresult.cols + DCTresult.cols-1-c) < HiddenMessage->Getstdstr().size())
            {
                for (int bitindex = 0; bitindex < 7; bitindex++)
                {
                    binchannel[bitindex] = HiddenMessage->GetbitsetV()[(DCTresult.rows-1-r)*DCTresult.cols + DCTresult.cols-1-c][bitindex];
                }
                tmp = binchannel.to_ulong();
                tmpf =  *reinterpret_cast<float*>(&(tmp));
                DCTresult.at<float>(r, c) =  tmpf;
            }
            else if ( ((DCTresult.rows-1-r)*DCTresult.cols + DCTresult.cols-1-c) == HiddenMessage->Getstdstr().size())
            {
                //add ETX to tell the reader here is the end of the hidden message
                int ETXint = 3;
                bitset<7> ETX = bitset<7>(ETXint);
                for (int bitindex = 0; bitindex < 7; bitindex++)
                {
                    binchannel[bitindex] = ETX[bitindex];
                }
                tmp = binchannel.to_ulong();
                tmpf =  *reinterpret_cast<float*>(&(tmp));
                DCTresult.at<float>(r, c) =  tmpf;
                goto out;
            }

        }
    }
    out:

    cv::FileStorage f2("./DCTresultembedded.xml", cv::FileStorage::WRITE);
    f2 << "DCTresultembedded" << DCTresult;


    cv::idct(DCTresult, DCTresult);

    cv::FileStorage f3("./idctdctresult.xml", cv::FileStorage::WRITE);
    f3 << "idctdctresult" << DCTresult;

    cv::Mat DCTresult2 = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_32FC1);
    cv::dct(DCTresult, DCTresult2);
    cv::FileStorage f4("./DCTresult2.xml", cv::FileStorage::WRITE);
    f4 << "DCTresult2" << DCTresult2;



    DCTresult.convertTo(m, CV_8UC1, 1, 0);
    cv::FileStorage fm("./m.xml", cv::FileStorage::WRITE);
    fm << "m" << m;




    planes[2] = m;
    cv::merge(planes, mout);
    cv::cvtColor(mout, mout, cv::COLOR_HSV2RGB);
    return new CVImage(mout);
}

Text CVImage::DCTStegoDecrypt(CVImage* Img)
{
    cv::Mat RGBsrc;
    cv::Mat HSVsrc;
    std::vector<cv::Mat> planes;
    Img->CVimg->copyTo(RGBsrc);
    cv::cvtColor(RGBsrc, HSVsrc, cv::COLOR_RGB2HSV);
    cv::split(HSVsrc, planes);
    planes[2].convertTo(planes[2], CV_32FC1);
    cv::idct(planes[2], planes[2]);
    float valchannel;
    bitset<32> binchannel;
    bitset<7> binh;
    Text HiddenMessage = Text();
    for (int r = planes[2].rows-1; r >= 0; r--)
    {
        for (int c = planes[2].cols-1; c >= 0; c--)
        {
            binh = 0;
            valchannel = planes[2].at<float>(r, c);
            binchannel = bitset<32>(*(uint32_t*)&valchannel);
            for (int bitindex = 0; bitindex < 7; bitindex++)
            {
                binh[bitindex] = binchannel[bitindex];
            }
            //detect ETX, stop decrypting
            if (binh.to_ulong() == 3)
                //first time using goto
                goto out;
            else
                HiddenMessage.Setstdstr()->push_back(static_cast<char>(binh.to_ulong()));
        }
    }
    out:
    return HiddenMessage;
}

