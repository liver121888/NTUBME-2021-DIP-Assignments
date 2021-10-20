#include "hw2.h"
#include "ui_hw2.h"
#include <iostream>
#include <string>
#include <QFileDialog>
using namespace std;


hw2::hw2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hw2)
{
    ui->setupUi(this);
    //initialize widget
    on_hsdThresh_valueChanged(ui->hsdThresh->value());
    on_hsdLevel_valueChanged(ui->hsdLevel->value());
    on_hsdBrightness_valueChanged(ui->hsdBrightness->value());
    on_hsdContrast_valueChanged(ui->hsdContrast->value());
    on_hsdResolution_valueChanged(ui->hsdResolution->value());
    hw2::setWindowState(Qt::WindowFullScreen);
    hw2::showFullScreen();

}

hw2::~hw2()
{
    delete ui;
}

void hw2::on_btnOpenA_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file A"), ".",
        tr("img Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != QString::number(NULL))
    {
        QImage qimg = QImage(fileName);
        // Turn into self-designed class image.
        mainimg = new image(&qimg);
        // Display on label.
        ui->lblPicA->setPixmap(QPixmap::fromImage(*mainimg->theBitmap));
        // Resize the label to fit the image.
        ui->lblPicA->resize(ui->lblPicA->pixmap().size());
        // Enable tab yet disable some contents.
        ui->tabWidget->setEnabled(true);
        ui->btnSubtract->setEnabled(false);
        ui->widget_2->setEnabled(false);
        ui->widget_3->setEnabled(false);
        ui->widget_6->setEnabled(false);
    }
    else
    {
        // Do not enable when open fails.
        ui->tabWidget->setEnabled(false);
    }

}


// Show grey image 1.
void hw2::on_btnMono1_clicked()
{
    grey1 = image::GetGreyAverage(mainimg);
    ui->lblPicA_1->setPixmap(QPixmap::fromImage(grey1->getImage()));
    ui->lblPicA_1->resize(ui->lblPicA_1->pixmap().size());
    if(!ui->lyt1->isEmpty())ui->lyt1->removeItem(ui->lyt1->itemAt(0) ) ;
    ui->lyt1->addWidget(grey1->theChart->GetView());
    // Enable certain manipulations.
    ui->widget_2->setEnabled(true);
    ui->widget_3->setEnabled(true);
    ui->widget_6->setEnabled(true);
    if(!ui->lblPicA_1->pixmap().isNull() && !ui->lblPicA_2->pixmap().isNull())
        ui->btnSubtract->setEnabled(true);



}

// Track the value of the slider and show on label.
void hw2::on_hsdThresh_valueChanged(int value)
{
    ui->lblThresh->setText(QString::asprintf("Thresh= %d", value));

}

// Show grey image 2.
void hw2::on_btnMono2_clicked()
{
    grey2 = image::GetGrey2(mainimg);
    ui->lblPicA_2->setPixmap(QPixmap::fromImage(grey2->getImage()));
    ui->lblPicA_2->resize(ui->lblPicA_2->pixmap().size());
    if(!ui->lyt2->isEmpty())ui->lyt2->removeItem(ui->lyt2->itemAt(0));
    ui->lyt2->addWidget(grey2->theChart->GetView());
    // Enable certain manipulations.
    if(!ui->lblPicA_1->pixmap().isNull() && !ui->lblPicA_2->pixmap().isNull())
        ui->btnSubtract->setEnabled(true);

}

//threshold manipulation
void hw2::on_btnThresh_clicked()
{
    int val=0;
    MonoImage* grey = image::GetGreyAverage(mainimg);
    val = ui->hsdThresh->value();
    grey = MonoImage::threshold(grey, val);
    ui->lblPicA_3->setPixmap(QPixmap::fromImage(grey->getImage()));
    ui->lblPicA_3->resize(ui->lblPicA_3->pixmap().size());
    if(!ui->lyt3->isEmpty())ui->lyt3->removeItem(ui->lyt3->itemAt(0));
    ui->lyt3->addWidget(grey->theChart->GetView());
}

//grey level manipulation
void hw2::on_btnLevel_clicked()
{
    int val=0;
    MonoImage* grey = image::GetGreyAverage(mainimg);
    val = ui->hsdLevel->value();
    grey = MonoImage::LeveledGrey(grey, val);
    ui->lblPicA_3->setPixmap(QPixmap::fromImage(grey->getImage()));
    ui->lblPicA_3->resize(ui->lblPicA_3->pixmap().size());
    if(!ui->lyt3->isEmpty())ui->lyt3->removeItem(ui->lyt3->itemAt(0));
    ui->lyt3->addWidget(grey->theChart->GetView());
}

// Track the value of the slider and show on label.
void hw2::on_hsdBrightness_valueChanged(int value)
{
    ui->lblBrightness->setText(QString::asprintf("Brightness= %d", value));
}

//brightness manipulation
void hw2::on_btnBrightness_clicked()
{
    int val;
    val = ui->hsdBrightness->value();
    image* Changedimg = image::GetBrightnessChangedImage(mainimg, val);
    ui->lblPicA_1->setPixmap(QPixmap::fromImage(*Changedimg->theBitmap));
    ui->lblPicA_1->resize(ui->lblPicA_1->pixmap().size());
    if(!ui->lyt1->isEmpty())ui->lyt1->removeItem(ui->lyt1->itemAt(0));
}

// Track the value of the slider and show on label.
void hw2::on_hsdLevel_valueChanged(int value)
{
    ui->lblLevel->setText(QString::asprintf("Grey level= %d", value));
}

// Track the value of the slider and show on label.
void hw2::on_hsdContrast_valueChanged(int value)
{
    ui->lblContrast->setText(QString::asprintf("Contrast= %d", value));

}

//contrast manipulation
void hw2::on_btnContrast_clicked()
{
    int val;
    val = ui->hsdContrast->value();
    image* Changedimg = image::GetContrastChangedImage(mainimg, val);
    ui->lblPicA_2->setPixmap(QPixmap::fromImage(*Changedimg->theBitmap));
    ui->lblPicA_2->resize(ui->lblPicA_2->pixmap().size());
    if(!ui->lyt2->isEmpty())ui->lyt2->removeItem(ui->lyt2->itemAt(0));

}

// Subtract two grey image to compare them.
void hw2::on_btnSubtract_clicked()
{
     image* result = image::Subtract2MonoImage(grey1, grey2);
     ui->lblPicA_3->setPixmap(QPixmap::fromImage(*result->theBitmap));
     ui->lblPicA_3->resize(ui->lblPicA_3->pixmap().size());
     if(!ui->lyt3->isEmpty())ui->lyt3->removeItem(ui->lyt3->itemAt(0));
}

// Track the value of the slider and show on label.
void hw2::on_hsdResolution_valueChanged(int value)
{
    ui->lblResolution->setText(QString::asprintf("Resolution= %d%%", value));
}

//spatial scale manipulation
void hw2::on_btnResolution_clicked()
{
    int val;
    val = ui->hsdResolution->value();
    MonoImage* grey = MonoImage::GetResolutionChangedImage(grey1, val);
    ui->lblPicA_3->setPixmap(QPixmap::fromImage(grey->getImage()));
    ui->lblPicA_3->resize(ui->lblPicA_3->pixmap().size());
    if(!ui->lyt3->isEmpty())ui->lyt3->removeItem(ui->lyt3->itemAt(0));
    ui->lyt3->addWidget(grey->theChart->GetView());


}

//exit the exe
void hw2::on_actionExit_triggered()
{
    close();
}

//equalization manipulation
void hw2::on_btnHistoEqualize_clicked()
{
    image* result = image::HistoEqualize(mainimg);
    ui->lblPicA_3->setPixmap(QPixmap::fromImage(*result->theBitmap));
    ui->lblPicA_3->resize(ui->lblPicA_3->pixmap().size());
    if(!ui->lyt3->isEmpty())ui->lyt3->removeItem(ui->lyt3->itemAt(0));
}

