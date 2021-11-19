#include "hw4.h"
#include "ui_hw4.h"
#include <QFileDialog>
#include <Windows.h>

HW4::HW4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HW4)
{
    ui->setupUi(this);
}

HW4::~HW4()
{
    delete ui;
}


void HW4::on_btnOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), ".",
        tr("img Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != "")
    {
        QImage qimg = QImage(fileName);
        // Turn into self-designed class Image.
        mainimg = new ColorImage(&qimg);
        maingrey = ColorImage::GetGreyAverage(mainimg);
        // Display on label.
        ui->lblPic1->setPixmap(QPixmap::fromImage(maingrey->getImage()).scaled(ui->lblPic1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        // Resize the label to fit the image.
        ui->lblPic1->resize(ui->lblPic1->pixmap().size());
        // Set the maxium of cutoff freq.
        ui->spbCutoffFreq->setMaximum(maingrey->rows);
        //TODO: change label to graphicsview and leran to resize and crop to prevent label's superimpose issue
        //        QGraphicsScene* scene = new QGraphicsScene();
        //        scene->addPixmap(QPixmap::fromImage(maingrey->getImage()));
        //        ui->grvA->setScene(scene);
        //        ui->grvA->show();

        // Enable tab yet disable some contents.
        //        ui->tabWidget->setEnabled(true);
        //        ui->widget_4->setEnabled(true);
        //        ui->dsbGaussianK->setEnabled(false);
        //        ui->ckbGaussainNormalize->setChecked(true);
    }
    else
    {


    }

}

void HW4::on_btnFFT_clicked()
{
	clock_t startTime = clock();
	QApplication::setOverrideCursor(Qt::WaitCursor);
    magresult = MonoImage::DFT(maingrey, &phaseresult, &data);
    ui->lblPic1_2->setPixmap(QPixmap::fromImage(magresult->getImage()).scaled(ui->lblPic1_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	// Resize the label to fit the image.
	ui->lblPic1_2->resize(ui->lblPic1_2->pixmap().size());
    ui->lblPic1_3->setPixmap(QPixmap::fromImage(phaseresult->getImage()).scaled(ui->lblPic1_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Resize the label to fit the image.
    ui->lblPic1_3->resize(ui->lblPic1_3->pixmap().size());
	// get seconds
	double seconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
	QApplication::restoreOverrideCursor();
    ui->lblTime->setText(QString::asprintf("Time elapsed: %.5f sec", seconds));
    ui->lblSize->setText(QString::asprintf("Image size: %d * %d", maingrey->rows,maingrey->cols));
    Beep(440, 500);
}


void HW4::on_btnIFFT_clicked()
{
    clock_t startTime = clock();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    MonoImage* result;
    result = MonoImage::IDFT(data);
    ui->lblPic1_4->setPixmap(QPixmap::fromImage(result->getImage()).scaled(ui->lblPic1_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Resize the label to fit the image.
    ui->lblPic1_4->resize(ui->lblPic1_4->pixmap().size());
    // get seconds
    double seconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    QApplication::restoreOverrideCursor();
    ui->lblTime->setText(QString::asprintf("Time elapsed: %.5f sec", seconds));
    ui->lblSize->setText(QString::asprintf("Image size: %d * %d", magresult->rows,magresult->cols));
    Beep(440, 500);

}

void HW4::on_btnFiltering_clicked()
{
    int index = ui->cbbFilter->currentIndex();
    bool flag = ui->rbnHighpass->isChecked();
    int cutoff = ui->spbCutoffFreq->value();
    int order;
    MonoImage* finalresult;
    switch (index)
    {
    case 0:
        //Ideal Filter
        if (flag)
        {
            //highpass
            FreqFilter* IHPF = FreqFilter::GenerateIdealFilter(maingrey->rows,maingrey->cols,cutoff,flag);
            cv::Mat* filtered = *IHPF* data;
            finalresult = MonoImage::IDFT(filtered);
        }
        else
        {
            //lowpass
            FreqFilter* ILPF = FreqFilter::GenerateIdealFilter(maingrey->rows, maingrey->cols, cutoff, flag);
            cv::Mat* filtered = *ILPF * data;
            finalresult = MonoImage::IDFT(filtered);
        }
        break;

    case 1:
        //Butterworth Filter
        order = ui->spbButterworthOrder->value();
        if (flag)
        {
            //highpass
            FreqFilter* BHPF = FreqFilter::GenerateButterworthFilter(maingrey->rows,maingrey->cols, cutoff, order, flag);
            cv::Mat* filtered = *BHPF* data;
            finalresult = MonoImage::IDFT(filtered);
        }
        else
        {
            //lowpass
            FreqFilter* BLPF = FreqFilter::GenerateButterworthFilter(maingrey->rows, maingrey->cols, cutoff, order, flag);
            cv::Mat* filtered = *BLPF * data;
            finalresult = MonoImage::IDFT(filtered);
        }
        break;

    case 2:
        //Gaussian Filter
        if (flag)
        {
            //highpass
            FreqFilter* GHPF = FreqFilter::GenerateGaussianFilter(maingrey->rows,maingrey->cols, cutoff, flag);
            cv::Mat* filtered = *GHPF* data;
            finalresult = MonoImage::IDFT(filtered);
        }
        else
        {
            //lowpass
            FreqFilter* GLPF = FreqFilter::GenerateGaussianFilter(maingrey->rows, maingrey->cols, cutoff, flag);
            cv::Mat* filtered = *GLPF * data;
            finalresult = MonoImage::IDFT(filtered);
        }
        break;

    default:
        finalresult = nullptr;
        break;

    }


    ui->lblPic1_4->setPixmap(QPixmap::fromImage(finalresult->getImage()).scaled(ui->lblPic1_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Resize the label to fit the image.
    ui->lblPic1_4->resize(ui->lblPic1_4->pixmap().size());
}


void HW4::on_btnHomomorphic_clicked()
{
    MonoImage* finalresult;
    MonoImage* midresult;
    MonoImage* loggedimg;
    cv::Mat* srcimg = new cv::Mat();
    *srcimg = cv::Mat::zeros(data->size(), CV_32FC2);
    float gammaH = ui->dsbGammaH->value();
    float gammaL = ui->dsbGammaL->value();
    float c = ui->dsbC->value();
    int cutoff = ui->spbCutoffFreqHomomorphic->value();
    FreqFilter* HMF = FreqFilter::GenerateHomomorphicFilter(maingrey->rows,maingrey->cols,cutoff, gammaH, gammaL, c);
    loggedimg = MonoImage::naturallog(maingrey);
    MonoImage* dummymgr;
    MonoImage* dummyphr;
    cv::Mat* result;
    dummymgr = MonoImage::DFT(loggedimg, &dummyphr, &result);
    cv::Mat* filtered = *HMF * result;
    cv::Mat* nonomalize;
    midresult = MonoImage::IDFTmodi(filtered, &nonomalize);
    finalresult = MonoImage::naturalexp(nonomalize);
    ui->lblPic1_4->setPixmap(QPixmap::fromImage(finalresult->getImagefromcvimg()).scaled(ui->lblPic1_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Resize the label to fit the image.
    ui->lblPic1_4->resize(ui->lblPic1_4->pixmap().size());
}


void HW4::on_btnDegradation_clicked()
{
    cv::Mat* filtered;
    MonoImage* finalresult;

    if (ui->rbnMotionBlurred->isChecked())
    {
        float a = ui->dsba->value();
        float b = ui->dsbb->value();
        float T = ui->dsbT->value();
        FreqFilter* MB = FreqFilter::GenerateMotionBlurredFilter(maingrey->rows,maingrey->cols,a, b, T);
//        filtered = FreqFilter::jjj(data);
        filtered = *MB^data;
        finalresult = MonoImage::IDFT(filtered);
    }
    else //gaussian
    {
        float std = ui->dsbStd->value();
    }
    ui->lblPic1_4->setPixmap(QPixmap::fromImage(finalresult->getImagefromcvimg()).scaled(ui->lblPic1_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Resize the label to fit the image.
    ui->lblPic1_4->resize(ui->lblPic1_4->pixmap().size());
}

