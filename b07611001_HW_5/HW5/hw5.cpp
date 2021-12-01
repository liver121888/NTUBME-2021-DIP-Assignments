#include "hw5.h"
#include "ui_hw5.h"


HW5::HW5(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HW5)
{
    ui->setupUi(this);
}

HW5::~HW5()
{
    delete ui;
}

//catch resize event of mainwindow and resize the graphicsview in the mainwindow
void HW5::resizeEvent(QResizeEvent *event)
{
    if (resizeflag)
    {
        grvresize(ui->grvNW_P1);
        grvresize(ui->grvNE_P1);
        grvresize(ui->grvSW_P1);
        grvresize(ui->grvSE_P1);
        grvresize(ui->grvA);
        grvresize(ui->grvB);
        grvresize(ui->grvColor1);
        grvresize(ui->grvColor2);
        grvresize(ui->grvColor3);
        grvresize(ui->grvColor4);
        grvresize(ui->grvColor5);
        grvresize(ui->grvCheckedColor);
        grvresize(ui->grvColorBar);
        grvresize(ui->grvMeanedimg);
        grvresize(ui->grvSrcimg);
    }
    QWidget::resizeEvent(event);
}

//resize the graphicsview
void HW5::grvresize(QGraphicsView* grv)
{
    if (grv->scene()!=NULL)
        grv->fitInView(grv->scene()->sceneRect(), Qt::KeepAspectRatio);
}

//a funtion to show Qimg in graphicsview
//first create a scene, a scene can include a lot of graphicsitem
//add the pixmap into the scene
//set the scene into the graphicsview
//show the graphicsview
void HW5::grvshow(CVImage* img, QGraphicsView* grv)
{
    QGraphicsScene* scene = new QGraphicsScene();
    QPixmap pix = QPixmap::fromImage(*img->getQimg()).scaled(grv->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scene->addPixmap(pix);
    grv->setScene(scene);
    grv->show();
}

void HW5::on_btnOpen_P1_clicked()
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
            MainCVImage = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            MainCVImage = new CVImage(filename, false);
        }
        //enable certain widgets
        grvshow(MainCVImage, ui->grvNW_P1);
        ui->btnRGB->setEnabled(true);
        ui->btnCMY->setEnabled(true);
        ui->btnHSI->setEnabled(true);
        ui->btnXYZ->setEnabled(true);
        ui->btnLAB->setEnabled(true);
        ui->btnYUV->setEnabled(true);
    }
}


void HW5::on_btnRGB_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CVImage* R;
    CVImage* G;
    CVImage* B;
    //pass the reference of pointers to return multiple value
    CVImage::GetRGBPlanes(MainCVImage, &R, &G, &B);
    grvshow(R, ui->grvNE_P1);
    grvshow(G, ui->grvSW_P1);
    grvshow(B, ui->grvSE_P1);
    ui->lblNE->setText("R");
    ui->lblSW->setText("G");
    ui->lblSE->setText("B");
    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void HW5::on_btnCMY_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CVImage* C;
    CVImage* M;
    CVImage* Y;
    CVImage::GetCMYPlanes(MainCVImage, &C, &M, &Y);
    grvshow(C, ui->grvNE_P1);
    grvshow(M, ui->grvSW_P1);
    grvshow(Y, ui->grvSE_P1);
    ui->lblNE->setText("C");
    ui->lblSW->setText("M");
    ui->lblSE->setText("Y");
    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void HW5::on_btnHSI_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CVImage* H;
    CVImage* S;
    CVImage* I;
    CVImage::GetHSIPlanes(MainCVImage, &H, &S, &I);
    grvshow(H, ui->grvNE_P1);
    grvshow(S, ui->grvSW_P1);
    grvshow(I, ui->grvSE_P1);
    ui->lblNE->setText("H");
    ui->lblSW->setText("S");
    ui->lblSE->setText("I");
    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void HW5::on_btnXYZ_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CVImage* X;
    CVImage* Y;
    CVImage* Z;
    CVImage::GetXYZPlanes(MainCVImage, &X, &Y, &Z);
    grvshow(X, ui->grvNE_P1);
    grvshow(Y, ui->grvSW_P1);
    grvshow(Z, ui->grvSE_P1);
    ui->lblNE->setText("X");
    ui->lblSW->setText("Y");
    ui->lblSE->setText("Z");
    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void HW5::on_btnLAB_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CVImage* L;
    CVImage* A;
    CVImage* B;
    CVImage::GetLABPlanes(MainCVImage, &L, &A, &B);
    grvshow(L, ui->grvNE_P1);
    grvshow(A, ui->grvSW_P1);
    grvshow(B, ui->grvSE_P1);
    ui->lblNE->setText("L*");
    ui->lblSW->setText("a*");
    ui->lblSE->setText("b*");
    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}

void HW5::on_btnYUV_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CVImage* Y;
    CVImage* U;
    CVImage* V;
    CVImage::GetYUVPlanes(MainCVImage, &Y, &U, &V);
    grvshow(Y, ui->grvNE_P1);
    grvshow(U, ui->grvSW_P1);
    grvshow(V, ui->grvSE_P1);
    ui->lblNE->setText("Y");
    ui->lblSW->setText("U");
    ui->lblSE->setText("V");
    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void HW5::on_btnOpen_P2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            MainCVImage2 = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            MainCVImage2 = new CVImage(filename, false);
        }
        MainCVImage2gray = CVImage::TurnGrayScaleImage(MainCVImage2);
        //enable certain widgets
        grvshow(MainCVImage2gray, ui->grvA);
        ui->btnColor1->setEnabled(true);
        ui->btnColor2->setEnabled(true);
        ui->btnColor3->setEnabled(true);
        ui->btnColor4->setEnabled(true);
        ui->btnColor5->setEnabled(true);
    }
}


//set pseudo-color image gradient points
void HW5::on_btnColor1_clicked()
{
    QColor color1 = QColorDialog::getColor(Qt::red, this);
    ColorImage1 = new CVImage(color1, ui->grvColor1->size());
    grvshow(ColorImage1, ui->grvColor1);
}


void HW5::on_btnColor2_clicked()
{
    QColor color2 = QColorDialog::getColor(Qt::yellow, this);
    ColorImage2 = new CVImage(color2, ui->grvColor2->size());
    grvshow(ColorImage2, ui->grvColor2);

}


void HW5::on_btnColor3_clicked()
{
    QColor color3 = QColorDialog::getColor(Qt::green, this);
    ColorImage3 = new CVImage(color3, ui->grvColor3->size());
    grvshow(ColorImage3, ui->grvColor3);
}


void HW5::on_btnColor4_clicked()
{
    QColor color4 = QColorDialog::getColor(Qt::blue, this);
    ColorImage4 = new CVImage(color4, ui->grvColor4->size());
    grvshow(ColorImage4, ui->grvColor4);
}

void HW5::on_btnColor5_clicked()
{
    QColor color5 = QColorDialog::getColor(Qt::magenta, this);
    ColorImage5 = new CVImage(color5, ui->grvColor5->size());
    grvshow(ColorImage5, ui->grvColor5);
    ui->btnCreateColorBar->setEnabled(true);
}

//create pseudo-color gradient bar
void HW5::on_btnCreateColorBar_clicked()
{
    ColorBar = CVImage::CreateColorBar(ColorImage1, ColorImage2, ColorImage3, ColorImage4, ColorImage5);
    grvshow(ColorBar, ui->grvColorBar);
    on_hsdCheckColor_sliderReleased();
    ui->btnDoPseudo->setEnabled(true);
    ui->hsdCheckColor->setEnabled(true);
}

//create pseudo-color image
void HW5::on_btnDoPseudo_clicked()
{
    CVImage* Pseudo_Color_Image = CVImage::GetPseudoColorImage(MainCVImage2gray, ColorImage1, ColorImage2, ColorImage3, ColorImage4, ColorImage5);
    grvshow(Pseudo_Color_Image, ui->grvB);
}

//check the corresponding color of a certain gray level and show that color in graphicsview
//delete the memory of color when the slider value change to prevent out of memory
void HW5::on_hsdCheckColor_sliderReleased()
{
    int value = ui->hsdCheckColor->value();
    if (CheckedColorImage != 0)
        delete[]CheckedColorImage;
    ui->lblGrayLevel->setText(QString::asprintf("Gray Scale: %d", value));
    QColor a = ColorBar->getQimg()->pixelColor( (ColorBar->getQimg()->width()-1) * value/255,4);
    CheckedColorImage =  new CVImage(a, ui->grvCheckedColor->size());
    grvshow(CheckedColorImage, ui->grvCheckedColor);

}


void HW5::on_btnOpen_P3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            MainCVImage3 = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            MainCVImage3 = new CVImage(filename, false);
        }
        //enalbe certain widgets
        grvshow(MainCVImage3, ui->grvSrcimg);
        ui->btnKmeans->setEnabled(true);
        ui->spbK->setEnabled(true);
        ui->widget_3->setEnabled(true);
    }
}

//perform K-means clustering
//check radio button then choose corresponding K-means method
void HW5::on_btnKmeans_clicked()
{
    int index;
    if(ui->rbnRGB->isChecked())
        index = 0;
    else if (ui->rbnHSI->isChecked())
        index = 1;
    else
        index = 2;
    CVImage* result = CVImage::GetClusteredImage(MainCVImage3, ui->spbK->value(), index);
    grvshow(result, ui->grvMeanedimg);
}

