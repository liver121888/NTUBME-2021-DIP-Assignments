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
    CVimg = new cv::Mat();
    if (pngflag)
    {
        *CVimg = cv::imread(filename.toStdString().data(), cv::IMREAD_UNCHANGED);
        cvtColor(*CVimg, *CVimg, CV_BGRA2RGB);
        (*Qimg).load(filename);
    }
    else
    {
        *CVimg = cv::imread(filename.toStdString().data(), cv::IMREAD_COLOR);
        cvtColor(*CVimg, *CVimg, CV_BGR2RGB);
        *Qimg = QImage((unsigned char*)(CVimg->data), CVimg->cols, CVimg->rows, QImage::Format_RGB888);
    }
}

//constructor using cv::Mat
CVImage::CVImage(cv::Mat mat)
{
    CVimg = new cv::Mat();
    Qimg = new QImage(mat.cols, mat.rows, QImage::Format_RGB888);
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

//perform LSB steganography
//The hidden message is transformed to 7 bits (3, 2, 2).
//the last two bits are stored in the last two bits in R channel;
//the two bits in between are stored in the last two bit in G channel;
//the first three bits are stored in the last three bits in B channl;
CVImage* CVImage::LSBStego(CVImage* Img, Text* HiddenMessage)
{
    cv::Mat m = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);
    cv::Mat SrcImg;
    //At first I plan to use HSV for stego, but the cv color conversion may round the infomation,
    //causing the infomation be distorted by 1 or 2, so I stick to RGB in the final version
    //cv::cvtColor(*(Img->CVimg), HSIsrc, cv::COLOR_RGB2HSV);
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
                //add ETX to tell the reader here is the end of the hidden message, stop decrypting
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

//extract the LSB plane of a image
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

//calculate the histogram of a image to detect steganography
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



//decrypt the hidden message using LSB method
//do the reverse of encryption, when detects a ETX, stop decrypting.
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
                //first time using goto, feels cool
                //use wisely to tidy the code and prevent Spaghetti code
                goto out;
            else
                HiddenMessage.Setstdstr()->push_back(static_cast<char>(binh.to_ulong()));
        }
    }
    out:
    return HiddenMessage;
}

//perform DCT steganography
//The hidden message is transformed to 8 bits.
//We first separate the image into 8 by 8 blocks, then we dct the blocks.
//We operate on the coefficients a at (6, 7) and b at (5, 1);
//we first read in a bit in the hidden message, if it is 1, we make a > b, if it is zero, we make b > a;
//we swap the coefficients to meet the message bit if necessary;
//we use a number d generate from a, b, and intensity to larger the difference of a and b to make the message more robust;
//we then IDCT the coefficients to have our stego block, then join these blocks together to have our stego image.
//ref: https://github.com/RoliSoft/Steganography
CVImage* CVImage::DCTStego(CVImage* Img, Text* HiddenMessage)
{
    int intensity = 100;

    auto block_width  = 8;
    auto block_height = 8;
    auto grid_width   = Img->CVimg->cols / block_width+1;
    auto grid_height  = Img->CVimg->rows / block_height+1;

    auto i = 0;
    auto size = HiddenMessage->Getstdstr().length()* 8;
    cv::Mat imgfp;
    Img->CVimg->convertTo(imgfp, CV_32FC3);

    std::vector<cv::Mat> planes;
    cv::split(imgfp, planes);

    for (int ch = 0; ch < 3; ch++)
    {
        for (int x = 1; x < grid_width; x++)
        {
            for (int y = 1; y < grid_height; y++)
            {
                auto px = (x - 1) * block_width;
                auto py = (y - 1) * block_height;

                cv::Mat block(planes[ch], cv::Rect(px, py, block_width, block_height));
                cv::Mat trans(cv::Size(block_width, block_height), block.type());

                dct(block, trans);

                auto a = trans.at<float>(6, 7);
                auto b = trans.at<float>(5, 1);

                if (i == size+8)
                {
                    break;
                }

                auto val = 0;


                if (i < size)
                {
                    //use bitwise operation to get the bit of the message
                    //1 << i % 8: push 1 left for i % 8  bit to make a mask
                    //HiddenMessage->Getstdstr()[i / 8]: get the byte of ith char
                    //& operation: use mask to check whether the i % 8 bit is one
                    //>> i % 8: if it is one, push it back to 1 bit.
                    val = (HiddenMessage->Getstdstr()[i / 8] & 1 << i % 8 )>> i % 8;
                }
                else
                {
                    //add ETX
                    if (i == size || i == size+1)
                    {
                        val = 1;
                    }
                    else
                    {
                        val = 0;
                    }
                }


                if (val == 0)
                {
                    if (a > b)
                    {
                        swap(a, b);
                    }
                }
                else
                {
                    if (a < b)
                    {
                        swap(a, b);
                    }
                }

                if (a > b)
                {
                    //val = 1 & before a < b; val = 1 & before a > b
                    auto d = (intensity - (a - b)) / 2;
                    a = a + d;
                    b = b - d;
                }
                else
                {
                    //val = 0 & before a < b; val = 0 & before a > b
                    auto d = (intensity - (b - a)) / 2;
                    a = a - d;
                    b = b + d;
                }
                trans.at<float>(6, 7) = a;
                trans.at<float>(5, 1) = b;
                cv::Mat stego(cv::Size(block_width, block_height), block.type());
                idct(trans, stego);
                stego.copyTo(planes[ch](cv::Rect(px, py, block_width, block_height)));
                i++;
            }
            if (i >= size)
            {
                break;
            }
        }
        if (i >= size)
        {
            break;
        }
    }

    cv::Mat mergedfp;
    merge(planes, mergedfp);

    cv::Mat merged;
    mergedfp.convertTo(merged, CV_8UC3);
    return new CVImage(merged);
}


//decrypt the hidden message using DCT method
//do the reverse of encryption, when detects a ETX, stop decrypting.
Text CVImage::DCTStegoDecrypt(CVImage* Img)
{
    Text HiddenMessage = Text();
    auto block_width  = 8;
    auto block_height = 8;
    auto grid_width   = Img->CVimg->cols / block_width+1;
    auto grid_height  = Img->CVimg->rows / block_height+1;
    auto i = 0;
    string bits(grid_width * grid_height * 3 / 8, 0);

    cv::Mat imgfp;
    Img->CVimg->convertTo(imgfp, CV_32FC3);
    vector<cv::Mat> planes;
    split(imgfp, planes);
    for (int ch = 0; ch < 3; ch++)
    {
        for (int x = 1; x < grid_width; x++)
        {
            for (int y = 1; y < grid_height; y++)
            {
                auto px = (x - 1) * block_width;
                auto py = (y - 1) * block_height;
                cv::Mat block(planes[ch], cv::Rect(px, py, block_width, block_height));
                cv::Mat trans(cv::Size(block_width, block_height), block.type());

                dct(block, trans);
                auto a = trans.at<float>(6, 7);
                auto b = trans.at<float>(5, 1);

                if (a > b)
                {
                    //use bitwise operation to get the bit of the message
                    //a > b: incoming bit is 1
                    //1 << i % 8: push 1 to i%8 bit
                    //bits[i / 8] |=: do OR operation on the char, to construct the message
                    bits[i / 8] |= 1 << i % 8;
                }
                if ((i+1) % 8 == 0)
                {
                    //detect ETX, stop decrypting
                    if (bits[i / 8] == 3)
                        goto out;
                    else
                        HiddenMessage.Setstdstr()->push_back(bits[i / 8]);
                }
                i++;
            }
        }

    }

    out:
    return HiddenMessage;
}

//do the DCT in 8 by 8 blcoks then join them into a image,
//to let the user compare the original image and the stego image.
CVImage* CVImage::DCTextract(CVImage* Img)
{
    auto block_width  = 8;
    auto block_height = 8;
    auto grid_width   = Img->CVimg->cols / block_width+1;
    auto grid_height  = Img->CVimg->rows / block_height+1;

    cv::Mat imgfp;
    Img->CVimg->convertTo(imgfp, CV_32FC3);
    vector<cv::Mat> planes;
    split(imgfp, planes);
    for (int ch = 0; ch < 3; ch++)
    {
        for (int x = 1; x < grid_width; x++)
        {
            for (int y = 1; y < grid_height; y++)
            {
                auto px = (x - 1) * block_width;
                auto py = (y - 1) * block_height;
                cv::Mat block(planes[ch], cv::Rect(px, py, block_width, block_height));
                cv::Mat trans(cv::Size(block_width, block_height), block.type());
                dct(block, trans);
                //normalize the block for visual presentation
                cv::normalize(trans, trans, 0, 255, cv::NORM_MINMAX);
                trans.copyTo(planes[ch](cv::Rect(px, py, block_width, block_height)));
            }
        }

    }
    cv::Mat mergedfp;
    merge(planes, mergedfp);
    cv::Mat merged;
    mergedfp.convertTo(merged, CV_8UC3);
    return new CVImage(merged);
}





//perform DWT steganography
//The hidden message is transformed to 8 bits.
//We first DWT the image using Haar wavelet, and we operate on the HH subband
//we first read in a bit in the hidden message, if it is 1, we make the coefficient plus alpha,
//if it is zero, we make the coefficient minus alpha;
//we then IDWT the coefficients to have our stego image.
//The result of this steganography method is too obvious, future improvement required.
//ref: https://github.com/RoliSoft/Steganography
CVImage* CVImage::DWTStego(CVImage* Img, Text* HiddenMessage)
{
    auto i = 0;
    auto alpha = 200;

    auto size = HiddenMessage->Getstdstr().length()* 8;
    cv::Mat m = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);
    std::vector<cv::Mat> transv;

    Img->CVimg->copyTo(m);
    m.convertTo(m, CV_32FC3,1.0,0.0);
    transv = Haar(m);

    for (int ch = 0; ch < 3; ch++)
    {                
        for (int y = 0; y < transv[3].rows; y++)
        {
            for (int x = 0; x < transv[3].cols; x++)
            {
                if (i == size+8)
                {
                    break;
                }

                auto val = 0;
                if (i < size)
                {
                    val = (HiddenMessage->Getstdstr()[i / 8] & 1 << i % 8) >> i % 8;
                }
                else
                {
                    //add ETX
                    if (i == size || i == size+1)
                    {
                        val = 1;
                    }
                    else
                        val = 0;
                }


                if (val == 1)
                {
                    transv[3].at<cv::Vec3f>(y, x)[ch] += alpha;

                }
                else
                {
                    transv[3].at<cv::Vec3f>(y, x)[ch] -= alpha;
                }
                i++;
            }
            if (i >= size)
            {
                break;
            }
        }
        if (i >= size)
        {
            break;
        }

    }

    cv::Mat mergedfp;
    mergedfp = inverseHaar(transv);
    cv::Mat merged;
    mergedfp.convertTo(merged, CV_8UC3);
    return new CVImage(merged);
}



//decrypt the hidden message using DWT method
//do the reverse of encryption, when detects a ETX, stop decrypting.
Text CVImage::DWTStegoDecrypt(CVImage* StegoImg)
{
    Text HiddenMessage = Text();
    auto i = 0;
    string bits((StegoImg->CVimg->cols / 2) * (StegoImg->CVimg->rows / 2) * 3/ 8, 0);
    std::vector<cv::Mat> v;
    v = Haar(*StegoImg->CVimg);

    cv::FileStorage f2("v.xml", cv::FileStorage::WRITE);
    f2 << "v" << v[3];

    for (int ch = 0; ch < 3; ch++)
    {
        for (int r = 0; r < v[3].rows; r++)
        {
            for (int c = 0; c < v[3].cols; c++)
            {
                auto val = v[3].at<cv::Vec3f>(r, c)[ch];

                if (val > 0)
                {
                    bits[i / 8] |= 1 << i % 8;
                }
                if ((i+1) % 8 == 0)
                {
                    //detect ETX, stop decrypting
                    if (bits[i / 8] == 3)
                    {
                        goto out;
                    }
                    else
                        HiddenMessage.Setstdstr()->push_back(bits[i / 8]);
                }
                i++;
            }
        }
    }
    out:
    return HiddenMessage;
}

//perform Haar wavelet transform
//ref: https://answers.opencv.org/question/42273/wavelet-transform/
std::vector<cv::Mat> Haar(cv::Mat mat)
{

    std::vector<cv::Mat> v;
    cv::Mat m = cv::Mat::zeros(mat.rows, mat.cols, CV_32FC3);
    cv::Mat im1 = cv::Mat::zeros(m.rows/2, m.cols, CV_32FC3);
    cv::Mat im2 = cv::Mat::zeros(m.rows/2, m.cols, CV_32FC3);
    cv::Mat im3 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    cv::Mat im4 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    cv::Mat im5 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    cv::Mat im6 = cv::Mat::zeros(m.rows/2, m.cols/2, CV_32FC3);
    mat.convertTo(m, CV_32FC3);
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
    v.push_back(im3);
    v.push_back(im4);
    v.push_back(im5);
    v.push_back(im6);

    return v;
}

//perform inverse Haar wavelet transform
//ref: https://answers.opencv.org/question/42273/wavelet-transform/
cv::Mat inverseHaar(std::vector<cv::Mat> v)
{
    float a, b, c, d;
    cv::Mat m = cv::Mat::zeros(v[0].rows*2, v[0].cols*2, CV_32FC3);
    cv::Mat imr = cv::Mat::zeros(m.rows,m.cols,CV_32FC3);
    cv::Mat imi1 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat imi2 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat imi3 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);
    cv::Mat imi4 = cv::Mat::zeros(m.rows/2,m.cols,CV_32FC3);

    //Upsampling of stage I
    for (int channel = 0; channel < 3; channel++)
    {
        for(int rcnt=0;rcnt<m.rows/2;rcnt++)
        {
            for(int ccnt=0;ccnt<m.cols/2;ccnt++)
            {
                int _ccnt=ccnt*2;
                imi1.at<cv::Vec3f>(rcnt,_ccnt)[channel] = v[0].at<cv::Vec3f>(rcnt,ccnt)[channel];
                imi2.at<cv::Vec3f>(rcnt,_ccnt)[channel] = v[1].at<cv::Vec3f>(rcnt,ccnt)[channel];
                imi3.at<cv::Vec3f>(rcnt,_ccnt)[channel] = v[2].at<cv::Vec3f>(rcnt,ccnt)[channel];
                imi4.at<cv::Vec3f>(rcnt,_ccnt)[channel] = v[3].at<cv::Vec3f>(rcnt,ccnt)[channel];
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
    return imr;
}

//using overloading minus to subtract images
CVImage* CVImage::operator-(CVImage* oriimg)
{
    cv::Mat m;
    int val;
    this->CVimg->copyTo(m);

    for (int ch = 0; ch < 3; ch++)
    {
        for (int r = 0; r < this->CVimg->rows; r++)
        {
            for (int c = 0; c < this->CVimg->cols; c++)
            {
                val  = m.at<cv::Vec3b>(r ,c)[ch] - oriimg->CVimg->at<cv::Vec3b>(r ,c)[ch];
                if (val > 0)
                    m.at<cv::Vec3b>(r ,c)[ch] = 255;
                else
                    m.at<cv::Vec3b>(r ,c)[ch]=0;
            }
        }
    }
    return new CVImage(m);

}

//DWT a image to let the user know the steganography works
CVImage* CVImage::DWTextract(CVImage* Img)
{
    cv::Mat m = cv::Mat::zeros(Img->CVimg->rows, Img->CVimg->cols, CV_8UC3);
    std::vector<cv::Mat> transv;
    Img->CVimg->copyTo(m);
    m.convertTo(m, CV_32FC3,1.0,0.0);
    transv = Haar(m);
    transv[0].copyTo(m(cv::Rect(0,0, m.cols / 2, m.rows/2)));
    transv[1].copyTo(m(cv::Rect(m.cols / 2, 0,m.cols/2, m.rows / 2)));
    transv[2].copyTo(m(cv::Rect(0, m.rows/2, m.cols / 2, m.rows/2)));
    transv[3].copyTo(m(cv::Rect(m.cols / 2, m.rows/2,m.cols/2, m.rows / 2)));
    m.convertTo(m, CV_8UC3, 1.0, 0.0);
    return new CVImage(m);
}







