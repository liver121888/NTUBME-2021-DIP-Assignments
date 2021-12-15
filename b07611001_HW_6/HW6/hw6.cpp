#include "hw6.h"
#include "ui_hw6.h"

HW6::HW6(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HW6)
{
    ui->setupUi(this);
    on_hsdHoughThreshold_valueChanged(ui->hsdHoughThreshold->value());
    on_hsdTrapezoidalParam_valueChanged(ui->hsdTrapezoidalParam->value());
    on_hsdTrapezoidalParam2_valueChanged(ui->hsdTrapezoidalParam2->value());
    on_spbWavyParam_valueChanged(ui->spbWavyParam->value());
    on_spbWavyParam2_valueChanged(ui->spbWavyParam2->value());
    on_spbWavyParam3_valueChanged(ui->spbWavyParam3->value());
    on_hsdCanny1_valueChanged(ui->hsdCanny1->value());
    on_hsdCanny2_valueChanged(ui->hsdCanny2->value());

}

HW6::~HW6()
{
    delete ui;
}

//catch resize event of mainwindow and resize the graphicsview in the mainwindow
void HW6::resizeEvent(QResizeEvent *event)
{
    if (resizeflag)
    {
        grvresize(ui->grvGeoOriginal);
        grvresize(ui->grvGeoTransformed);
        grvresize(ui->grvHoughOriginal);
        grvresize(ui->grvHoughTransformed);
        grvresize(ui->grvDWTOriginalA);
        grvresize(ui->grvDWTOriginalB);
        grvresize(ui->grvDWTTransformedA);
        grvresize(ui->grvDWTTransformedB);
        grvresize(ui->grvDWTTransformedFused);
        grvresize(ui->grvDWTInversedFused);

    }
    QWidget::resizeEvent(event);
}

//resize the graphicsview
void HW6::grvresize(QGraphicsView* grv)
{
    if (grv->scene()!=NULL)
        grv->fitInView(grv->scene()->sceneRect(), Qt::KeepAspectRatio);
}

//a funtion to show Qimg in graphicsview
//first create a scene, a scene can include a lot of graphicsitem
//add the pixmap into the scene
//set the scene into the graphicsview
//show the graphicsview
void HW6::grvshow(CVImage* img, QGraphicsView* grv)
{
    QGraphicsScene* scene = new QGraphicsScene();
    QPixmap pix = QPixmap::fromImage(*img->getQimg()).scaled(grv->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scene->addPixmap(pix);
    grv->setScene(scene);
    grv->show();
}

void HW6::on_btnGeoOpen_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        //png has four channel, so the alpha channel needs to be discard in our case
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            GeoCVImage = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            GeoCVImage = new CVImage(filename, false);
        }
        grvshow(GeoCVImage, ui->grvGeoOriginal);
        //enable certain widgets
        ui->widget->setEnabled(true);
    }
}


void HW6::on_btnGeoExecute_clicked()
{
    CVImage* result;
    if (ui->rbnTrapezoidal->isChecked())
    {
        result = CVImage::TrapezoidalTransform(GeoCVImage, ui->hsdTrapezoidalParam->value(), ui->hsdTrapezoidalParam2->value());
    }
    else if (ui->rbnWavy->isChecked())
    {
        result = CVImage::WavyTransform(GeoCVImage, ui->spbWavyParam->value(), ui->spbWavyParam2->value(), ui->spbWavyParam3->value());
    }
    else
    {
        result = CVImage::CircularTransform(GeoCVImage);
    }
    grvshow(result, ui->grvGeoTransformed);
}


void HW6::on_btnDWTOpenA_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        //png has four channel, so the alpha channel needs to be discard in our case
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            DWTCVImageA = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            DWTCVImageA = new CVImage(filename, false);
        }
        grvshow(DWTCVImageA, ui->grvDWTOriginalA);
        //enable certain widgets
        ui->btnDWTExecuteA->setEnabled(true);
        ui->spbDWTOrder->setEnabled(true);
        ui->label_11->setEnabled(true);

    }
}


void HW6::on_btnDWTOpenB_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        //png has four channel, so the alpha channel needs to be discard in our case
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            DWTCVImageB = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            DWTCVImageB = new CVImage(filename, false);
        }
        grvshow(DWTCVImageB, ui->grvDWTOriginalB);
        //enable certain widgets
        ui->btnDWTExecuteB->setEnabled(true);
    }
}

//only to order 3, improvement requires
void HW6::on_btnDWTExecuteA_clicked()
{
    int order = ui->spbDWTOrder->value();
    if (order == 1)
    {
        DWTTransformedCVImageA = CVImage::HarrWaveletTransform(DWTCVImageA);
    }
    else if (order == 2)
    {
        CVImage* first = CVImage::HarrWaveletTransform(DWTCVImageA);
        CVImage* firstrect = first->Rect();
        CVImage* second = CVImage::HarrWaveletTransform(firstrect);
        DWTTransformedCVImageA = *first + second;
    }
    else
    {
        CVImage* first = CVImage::HarrWaveletTransform(DWTCVImageA);
        CVImage* second = CVImage::HarrWaveletTransform(first->Rect());
        CVImage* third = CVImage::HarrWaveletTransform(second->Rect());
        CVImage* temp = *second + third;
        DWTTransformedCVImageA = *first + temp;
    }
    grvshow(DWTTransformedCVImageA, ui->grvDWTTransformedA);
    ui->btnDWTOpenB->setEnabled(true);
}

//only to order 3, improvement requires
void HW6::on_btnDWTExecuteB_clicked()
{
    int order = ui->spbDWTOrder->value();
    if (order == 1)
    {
        DWTTransformedCVImageB = CVImage::HarrWaveletTransform(DWTCVImageB);
    }
    else if (order == 2)
    {
        CVImage* first = CVImage::HarrWaveletTransform(DWTCVImageB);
        CVImage* firstrect = first->Rect();
        CVImage* second = CVImage::HarrWaveletTransform(firstrect);
        DWTTransformedCVImageB = *first + second;
    }
    else
    {
        CVImage* first = CVImage::HarrWaveletTransform(DWTCVImageB);
        CVImage* second = CVImage::HarrWaveletTransform(first->Rect());
        CVImage* third = CVImage::HarrWaveletTransform(second->Rect());
        CVImage* temp = *second + third;
        DWTTransformedCVImageB = *first + temp;
    }
    grvshow(DWTTransformedCVImageB, ui->grvDWTTransformedB);
    ui->btnDWTExecuteFuse->setEnabled(true);
}

//only to order 3, improvement requires
void HW6::on_btnDWTExecuteFuse_clicked()
{
    int order = ui->spbDWTOrder->value();
    if (order == 1)
        DWTTransformedCVImageFused = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA, DWTTransformedCVImageB);
    else if (order == 2)
    {
        CVImage* second = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA->Rect(), DWTTransformedCVImageB->Rect());
        CVImage* first = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA, DWTTransformedCVImageB);
        DWTTransformedCVImageFused = *first + second;
    }
    else
    {
        CVImage* third = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA->Rect()->Rect(), DWTTransformedCVImageB->Rect()->Rect());
        CVImage* second = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA->Rect(), DWTTransformedCVImageB->Rect());
        CVImage* tmp = *second + third;
        CVImage* first = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA, DWTTransformedCVImageB);
        DWTTransformedCVImageFused = *first + tmp;
    }
    grvshow(DWTTransformedCVImageFused, ui->grvDWTTransformedFused);
    ui->btnDWTExecuteInverse->setEnabled(true);

}

//only to order 3, improvement requires
void HW6::on_btnDWTExecuteInverse_clicked()
{
    int order = ui->spbDWTOrder->value();
    if (order == 1)
        DWTTransformedCVImageInversed = CVImage::HarrWaveletTransformInversed(DWTTransformedCVImageFused);
    else if (order == 2)
    {
        CVImage* second = CVImage::HarrWaveletTransformInversed(DWTTransformedCVImageFused->Rect());
        CVImage* first = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA, DWTTransformedCVImageB);
        DWTTransformedCVImageInversed = CVImage::HarrWaveletTransformInversed(*first + second);
    }
    else if (order == 3)
    {
        CVImage* third = CVImage::HarrWaveletTransformInversed(DWTTransformedCVImageFused->Rect()->Rect());
        CVImage* second = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA->Rect(), DWTTransformedCVImageB->Rect());
        CVImage* tmp = *second + third;
        CVImage* tmpinv = CVImage::HarrWaveletTransformInversed(tmp);
        CVImage* first = CVImage::WaveletMeanAndMaxSelection(DWTTransformedCVImageA, DWTTransformedCVImageB);
        DWTTransformedCVImageInversed = CVImage::HarrWaveletTransformInversed(*first + tmpinv);
    }

    grvshow(DWTTransformedCVImageInversed, ui->grvDWTInversedFused);
}


void HW6::on_btnHoughOpen_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        //png has four channel, so the alpha channel needs to be discard in our case
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            HTCVImage = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            HTCVImage = new CVImage(filename, false);
        }
        grvshow(HTCVImage, ui->grvHoughOriginal);
        //enable certain widgets
        ui->widget_5->setEnabled(true);
        ui->btnHoughExecute->setEnabled(true);

    }
}

void HW6::on_btnHoughExecute_clicked()
{
    ptis = new std::vector<cv::Point>();
    HTTransformedCVImage = CVImage::HoughTransform(HTCVImage, ui->hsdCanny1->value(), \
        ui->hsdCanny2->value(), ui->hsdHoughThreshold->value(), &ptis);
    grvshow(HTTransformedCVImage, ui->grvHoughTransformed);
    ui->spbP1->setMaximum((int)(ptis->size()-1));
    ui->spbP2->setMaximum((int)(ptis->size()-1));
    ui->widget_4->setEnabled(true);
}


void HW6::on_hsdHoughThreshold_valueChanged(int value)
{
    ui->lblHoughThreshold->setText(QString::asprintf("Hough threshold: %d", value));
}


void HW6::on_btnGetDistance_clicked()
{
    ui->lblDistance->setText(QString::asprintf("Distance: %.2f", CVImage::GetDistance(ptis, ui->spbP1->value(), ui->spbP2->value())));
}


void HW6::on_rbnTrapezoidal_toggled(bool checked)
{
    if (checked)
    {
        ui->hsdTrapezoidalParam->setEnabled(true);
        ui->lblTrapezoidalParam->setEnabled(true);
        ui->hsdTrapezoidalParam2->setEnabled(true);
        ui->lblTrapezoidalParam2->setEnabled(true);
    }
    else
    {
        ui->hsdTrapezoidalParam->setEnabled(false);
        ui->lblTrapezoidalParam->setEnabled(false);
        ui->hsdTrapezoidalParam2->setEnabled(false);
        ui->lblTrapezoidalParam2->setEnabled(false);
    }
    if (!ui->btnGeoExecute->isEnabled())
        ui->btnGeoExecute->setEnabled(true);
}


void HW6::on_rbnWavy_toggled(bool checked)
{
    if (checked)
    {
        ui->spbWavyParam->setEnabled(true);
        ui->lblWavyParam->setEnabled(true);
        ui->spbWavyParam2->setEnabled(true);
        ui->lblWavyParam2->setEnabled(true);
        ui->spbWavyParam3->setEnabled(true);
        ui->lblWavyParam3->setEnabled(true);
    }
    else
    {
        ui->spbWavyParam->setEnabled(false);
        ui->lblWavyParam->setEnabled(false);
        ui->spbWavyParam2->setEnabled(false);
        ui->lblWavyParam2->setEnabled(false);
        ui->spbWavyParam3->setEnabled(false);
        ui->lblWavyParam3->setEnabled(false);
    }
    if (!ui->btnGeoExecute->isEnabled())
        ui->btnGeoExecute->setEnabled(true);
}




void HW6::on_hsdTrapezoidalParam_valueChanged(int value)
{
    ui->lblTrapezoidalParam->setText(QString::asprintf("Trapezoidal Parameter: %d%", value));
}


void HW6::on_spbWavyParam_valueChanged(int arg1)
{
    ui->lblWavyParam->setText(QString::asprintf("Wavy Parameter: %d", arg1));

}


void HW6::on_spbWavyParam2_valueChanged(int arg1)
{
    ui->lblWavyParam2->setText(QString::asprintf("Wavy Parameter2: %d", arg1));
}


void HW6::on_hsdTrapezoidalParam2_valueChanged(int value)
{
    ui->lblTrapezoidalParam2->setText(QString::asprintf("Trapezoidal Parameter2: %d%", value));
}


void HW6::on_spbWavyParam3_valueChanged(int arg1)
{
    ui->lblWavyParam3->setText(QString::asprintf("Wavy Parameter3: %d", arg1));
}


void HW6::on_hsdCanny1_valueChanged(int value)
{
    ui->lblCanny1->setText(QString::asprintf("Canny threshold1: %d", value));
    ui->hsdCanny2->setMinimum(value);

}


void HW6::on_hsdCanny2_valueChanged(int value)
{
    ui->lblCanny2->setText(QString::asprintf("Canny threshold2: %d", value));


}

