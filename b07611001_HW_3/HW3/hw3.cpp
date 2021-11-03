#include "hw3.h"
#include "ui_hw3.h"
#include <iostream>
#include <string>
#include <QFileDialog>
#include <windows.h>
#include <stdio.h>



Hw3::Hw3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hw3)
{
    ui->setupUi(this);
    //initialize widgets
    on_hsdKernelSizem_valueChanged(ui->hsdKernelSizem->value());
    on_hsdKernelSizen_valueChanged(ui->hsdKernelSizen->value());
    on_hsdKernelSizem_3_valueChanged(ui->hsdKernelSizem_3->value());
    on_hsdKernelSizen_3_valueChanged(ui->hsdKernelSizen_3->value());
    on_hsdKernelSizem_2_valueChanged(ui->hsdKernelSizem_2->value());
    on_hsdKernelSizen_2_valueChanged(ui->hsdKernelSizen_2->value());
    ui->tabWidget->setCurrentIndex(0);


}

Hw3::~Hw3()
{
    delete ui;
}


void Hw3::on_btnOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file A"), ".",
        tr("img Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != "")
    {
        QImage qimg = QImage(fileName);
        // Turn into self-designed class Image.
        mainimg = new ColorImage(&qimg);
        // Display on label.
        ui->lblPic1->setPixmap(QPixmap::fromImage(*mainimg->theBitmap).scaled(ui->lblPic1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        // QPixmap::fromImage(*mainimg->theBitmap)
        // Enable tab yet disable some contents.
        ui->tabWidget->setEnabled(true);
        ui->widget_4->setEnabled(true);
        ui->dsbGaussianK->setEnabled(false);
        ui->ckbGaussainNormalize->setChecked(true);
    }
    else
    {
        // Do not enable when open fails.
        ui->tabWidget->setEnabled(false);

    }
}

//execute different filter according to combobox index
void Hw3::on_btnExecute_clicked()
{
    // get and set system ticks
    clock_t startTime = clock();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if (ui->cbbFilter->currentIndex()==0)
    {
        Filter* box = Filter::GenerateBoxFilter(ui->hsdKernelSizem->value(),ui->hsdKernelSizen->value());
        ColorImage* result = *box*mainimg;
        ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    }
    else if (ui->cbbFilter->currentIndex()==1)
    {
        Filter* gaussian;
        if (ui->ckbGaussainNormalize->isChecked())
        {
            gaussian = Filter::GenerateGaussianFilter(ui->hsdKernelSizem->value(),ui->hsdKernelSizen->value(), 1, ui->dsbGaussianSigma->value());
        }
        else
        {
            gaussian = Filter::GenerateGaussianFilter(ui->hsdKernelSizem->value(),ui->hsdKernelSizen->value(), ui->dsbGaussianK->value(), ui->dsbGaussianSigma->value());
        }
        ColorImage* result = *gaussian*mainimg;
        ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    }
    else if (ui->cbbFilter->currentIndex()==2)
    {
        Filter* sobelhori;
        sobelhori = Filter::GenerateSobelHoriFilter();
        ColorImage* result = *sobelhori*mainimg;
        ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblPic2->resize(ui->lblPic2->pixmap().size());

    }
    else if (ui->cbbFilter->currentIndex()==3)
    {
        Filter* sobelverti;
        sobelverti = Filter::GenerateSobelVertiFilter();
        ColorImage* result = *sobelverti*mainimg;
        ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    }
    else if (ui->cbbFilter->currentIndex()==4)
    {
        Filter* laplacianhalf;
        laplacianhalf = Filter::GenerateLaplacianHalfFilter();
        ColorImage* result = *(*laplacianhalf*mainimg) + mainimg;
        ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    }
    else if (ui->cbbFilter->currentIndex()==5)
    {
        Filter* laplaciandiagonal;
        laplaciandiagonal = Filter::GenerateLaplacianFullFilter();
        ColorImage* result = *(*laplaciandiagonal*mainimg) + mainimg;
        ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    }
    // get seconds
    double seconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    QApplication::restoreOverrideCursor();
    ui->lblTime->setText(QString::asprintf("Time elapsed: %.5f sec", seconds));
    Beep(440, 500);
}

//execute Sobel filtering
void Hw3::on_btnSobel_clicked()
{
    // get and set system ticks
    clock_t startTime = clock();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    Filter* SobelHori = Filter::GenerateSobelHoriFilter();
    Filter* SobelVerti = Filter::GenerateSobelVertiFilter();
    ColorImage* result =  *(*SobelHori*mainimg) + *SobelVerti*mainimg;
    ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    // get seconds
    double seconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    QApplication::restoreOverrideCursor();
    ui->lblTime_4->setText(QString::asprintf("Time elapsed: %.5f sec", seconds));
    Beep(440, 500);
}

//execute different order-statistics filtering according to different radiobutton
void Hw3::on_btnOrderStatisticsExecute_clicked()
{
    // get and set system ticks
    clock_t startTime = clock();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    OrderStatisitcsOperationMode mode;
    if(ui->rbnMedian->isChecked())
        mode = OrderStatisitcsOperationMode::MEDIAN;
    else if (ui->rbnMax->isChecked())
        mode = OrderStatisitcsOperationMode::MAX;
    else
        mode = OrderStatisitcsOperationMode::MIN;
    MonoImage* grey = ColorImage::GetGreyAverage(mainimg);
    MonoImage* result = grey->OrderStatisticsOperation(ui->hsdKernelSizem->value(),ui->hsdKernelSizen->value(),mode);
    ui->lblPic2->setPixmap(QPixmap::fromImage(result->getImage()).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    // get seconds
    double seconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    QApplication::restoreOverrideCursor();
    ui->lblTime_2->setText(QString::asprintf("Time elapsed: %.5f sec", seconds));
    Beep(440, 500);
}

//execute zero-crossing finding, then apply LoG onto the result
void Hw3::on_btnLoG_clicked()
{
    // get and set system ticks
    clock_t startTime = clock();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    Filter* LoG = Filter::GenerateLoGFilter(ui->hsdKernelSizem_2->value(), ui->hsdKernelSizen_2->value(), ui->dsbGaussianSigma_2->value());
    ColorImage* convoluted = *LoG*mainimg;
    ColorImage* result = convoluted->FindZeroCrossing(ui->dsbZeroCrossingThreshold->value());
    ui->lblPic2->setPixmap(QPixmap::fromImage(*result->theBitmap).scaled(ui->lblPic2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->lblPic2->resize(ui->lblPic2->pixmap().size());
    // get seconds
    double seconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    QApplication::restoreOverrideCursor();
    ui->lblTime_3->setText(QString::asprintf("Time elapsed: %.5f sec", seconds));
    Beep(440, 500);

}



//TODO: >or<index, get rid of repeated enable
void Hw3::on_cbbFilter_currentIndexChanged(int index)
{
    //gaussian
    if(index <= 1)
    {
        ui->hsdKernelSizem->setEnabled(true);
        ui->hsdKernelSizen->setEnabled(true);
        if (index == 0)
        {
            ui->widget_4->setEnabled(true);
            ui->dsbGaussianK->setEnabled(false);
            ui->ckbGaussainNormalize->setChecked(true);
            ui->lblKernelSizem->setText(QString::asprintf("Kernel Size m = %d", ui->hsdKernelSizem->value()));
            ui->lblKernelSizen->setText(QString::asprintf("Kernel Size n = %d", ui->hsdKernelSizen->value()));

        }
        else
        {
            ui->widget_4->setEnabled(false);
            ui->ckbGaussainNormalize->setChecked(true);
            ui->lblKernelSizem->setText(QString::asprintf("Kernel Size m = %d", ui->hsdKernelSizem->value()));
            ui->lblKernelSizen->setText(QString::asprintf("Kernel Size n = %d", ui->hsdKernelSizen->value()));

        }
    }
    else
    {
        ui->widget_4->setEnabled(false);
        ui->ckbGaussainNormalize->setChecked(true);
        ui->hsdKernelSizem->setEnabled(false);
        ui->hsdKernelSizen->setEnabled(false);
        ui->lblKernelSizem->setText(QString::asprintf("Kernel Size m = 3"));
        ui->lblKernelSizen->setText(QString::asprintf("Kernel Size n = 3"));

    }

}


//enable or disable normalization operation in generating Gaussian filter
void Hw3::on_ckbGaussainNormalize_stateChanged(int arg1)
{
    if(arg1==2)
    {
        ui->dsbGaussianK->setEnabled(false);
        ui->dsbGaussianK->setValue(1.0);
    }
    else
    {
        ui->dsbGaussianK->setEnabled(true);
        ui->dsbGaussianK->setValue(0.5);

    }
}

//change label text according to the value of slider
void Hw3::on_hsdKernelSizem_valueChanged(int value)
{
    ui->lblKernelSizem->setText(QString::asprintf("Kernel Size m = %d", value));
}

//change label according to the value of slider
void Hw3::on_hsdKernelSizen_valueChanged(int value)
{
    ui->lblKernelSizen->setText(QString::asprintf("Kernel Size n = %d", value));

}
//change label text according to the value of slider
void Hw3::on_hsdKernelSizem_3_valueChanged(int value)
{
    ui->lblKernelSizem_3->setText(QString::asprintf("Kernel Size m = %d", value));
}
//change label text according to the value of slider
void Hw3::on_hsdKernelSizen_3_valueChanged(int value)
{
    ui->lblKernelSizen_3->setText(QString::asprintf("Kernel Size n = %d", value));

}
//change label text according to the value of slider
void Hw3::on_hsdKernelSizem_2_valueChanged(int value)
{
    ui->lblKernelSizem_2->setText(QString::asprintf("Kernel Size m = %d", value));

}
//change label text according to the value of slider
void Hw3::on_hsdKernelSizen_2_valueChanged(int value)
{
    ui->lblKernelSizen_2->setText(QString::asprintf("Kernel Size n = %d", value));

}

