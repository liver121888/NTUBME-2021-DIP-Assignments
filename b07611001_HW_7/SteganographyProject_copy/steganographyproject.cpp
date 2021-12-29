#include "steganographyproject.h"
#include "ui_steganographyproject.h"
using namespace std;
using namespace CryptoPP;



SteganographyProject::SteganographyProject(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SteganographyProject)
{
    ui->setupUi(this);
}

SteganographyProject::~SteganographyProject()
{
    delete ui;
}

//catch resize event of mainwindow and resize the graphicsview in the mainwindow
void SteganographyProject::resizeEvent(QResizeEvent *event)
{
    if (resizeflag)
    {
        grvresize(ui->grvLSBOri);
        grvresize(ui->grvLSBStego);
        grvresize(ui->grvOriLSB0);
        grvresize(ui->grvStegoLSB0);
        grvresize(ui->grvDCTOri);
        grvresize(ui->grvDCTStego);
        grvresize(ui->grvMainStegoDetect);
        grvresize(ui->grvStegoDetectHist);
    }
    QWidget::resizeEvent(event);
}

//resize the graphicsview
void SteganographyProject::grvresize(QGraphicsView* grv)
{
    if (grv->scene()!=NULL)
        grv->fitInView(grv->scene()->sceneRect(), Qt::KeepAspectRatio);
}

//a funtion to show Qimg in graphicsview
//first create a scene, a scene can include a lot of graphicsitem
//add the pixmap into the scene
//set the scene into the graphicsview
//show the graphicsview
void SteganographyProject::grvshow(CVImage* img, QGraphicsView* grv)
{
    QGraphicsScene* scene = new QGraphicsScene();
    QPixmap pix = QPixmap::fromImage(*img->getQimg()).scaled(grv->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scene->addPixmap(pix);
    grv->setScene(scene);
    grv->show();
}

//open file and show in graphicsView
bool SteganographyProject::openfile(CVImage** img, QGraphicsView* grv)
{
    bool sucess = false;
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), "../imgs",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(filename != "")
    {
        QString  x = filename.right(3);
        const QChar* s = x.constData();
        //png has four channel, so the alpha channel needs to be discard in our case
        if (s[0]=='p' && s[1]=='n' && s[2]=='g')
        {
            resizeflag = true;
            *img = new CVImage(filename, true);
        }
        else
        {
            resizeflag = true;
            *img = new CVImage(filename, false);
        }
        grvshow(*img, grv);
        sucess = true;
    }
    return sucess;
}

void SteganographyProject::exportfile(CVImage* img)
{
    //Open a Qt Dialog to get save file name path.
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save File"), "../imgs",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));

    if(!fileName.isEmpty())
    {
        cv::Mat m;
        cv::cvtColor(*img->getCVimg(), m, cv::COLOR_RGB2BGRA);
        //OpenCV save image.
        cv::imwrite(fileName.toStdString(), m);
    }
}

void SteganographyProject::on_btnLSBStegoOpen_clicked()
{
    if (openfile(&MainLSBCVImage, ui->grvLSBOri) == true)
    {
        //enable certain widgets
        ui->lblLSBMessage->setEnabled(true);
        ui->pteLSB->setEnabled(true);
        ui->lblLSBKey->setEnabled(true);
        ui->ldtLSBKey->setEnabled(true);
        ui->lblLSBIV->setEnabled(true);
        ui->ldtLSBIV->setEnabled(true);
        ui->lblLSBHexLength->setEnabled(true);
        ui->btnLSBStegoExecute->setEnabled(true);
        MainLSBCVImage0 = CVImage::LSBextract(MainLSBCVImage);
        grvshow(MainLSBCVImage0, ui->grvOriLSB0);
    }
}


void SteganographyProject::on_btnLSBStegoExecute_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);

    std::vector<CryptoPP::byte> key;
    std::vector<CryptoPP::byte> iv;
    for (int i = 0; i < ui->ldtLSBKey->text().length(); i++)
    {
        key.push_back(ui->ldtLSBKey->text().toStdString()[i]);
        iv.push_back(ui->ldtLSBIV->text().toStdString()[i]);
    }
    LSBMessage = new Text(ui->pteLSB->toPlainText());
    Text* Encrypted = Text::Encrypt(LSBMessage, key, iv);
    ui->lblLSBHexLength->setText(QString::asprintf("Hex length: %d", Encrypted->Getstdstr().length()));
    HiddenLSBCVImage = CVImage::LSBStego(MainLSBCVImage, Encrypted);
    grvshow(HiddenLSBCVImage, ui->grvLSBStego);
    ui->btnLSBStegoExport->setEnabled(true);

    HiddenLSBCVImage0 = CVImage::LSBextract(HiddenLSBCVImage);
    grvshow(HiddenLSBCVImage0, ui->grvStegoLSB0);

    QApplication::restoreOverrideCursor();
    Beep(440, 500);

}



void SteganographyProject::on_btnLSBStegoExport_clicked()
{
    exportfile(HiddenLSBCVImage);
}

void SteganographyProject::on_btnStegoDetectOpen_clicked()
{

    openfile(&MainStegoDetectCVImage, ui->grvMainStegoDetect);
    //enable certain widgets

    grvshow(CVImage::calhisto(MainStegoDetectCVImage), ui->grvStegoDetectHist);
}



void SteganographyProject::on_btnStegoDecrypt_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);

    Text HiddenMessage;
    if (ui->rbnLSB->isChecked())
    {
        HiddenMessage = CVImage::LSBStegoDecrypt(MainStegoDetectCVImage);
        std::vector<CryptoPP::byte> key;
        std::vector<CryptoPP::byte> iv;
        for (int i = 0; i < ui->ldtKeyDecrypt->text().length(); i++)
        {
            key.push_back(ui->ldtKeyDecrypt->text().toStdString()[i]);
            iv.push_back(ui->ldtIVDecrypt->text().toStdString()[i]);
        }
        QString s = QString::fromStdString(Text::Decrypt(&HiddenMessage, key, iv)->Getstdstr());
        ui->pteDecrypt->setPlainText(s);
    }
    else if (ui->rbnDCT->isChecked())
    {
        HiddenMessage = CVImage::DCTStegoDecrypt(MainStegoDetectCVImage);
        std::vector<CryptoPP::byte> key;
        std::vector<CryptoPP::byte> iv;
        for (int i = 0; i < ui->ldtKeyDecrypt->text().length(); i++)
        {
            key.push_back(ui->ldtKeyDecrypt->text().toStdString()[i]);
            iv.push_back(ui->ldtIVDecrypt->text().toStdString()[i]);
        }
        QString s = QString::fromStdString(Text::Decrypt(&HiddenMessage, key, iv)->Getstdstr());
        ui->pteDecrypt->setPlainText(s);
    }

    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void SteganographyProject::on_btnDCTStegoOpen_clicked()
{
    if (openfile(&MainDCTCVImage, ui->grvDCTOri) == true)
    {
        //enable certain widgets
        ui->lblDCTMessage->setEnabled(true);
        ui->pteDCT->setEnabled(true);
        ui->lblDCTKey->setEnabled(true);
        ui->ldtDCTKey->setEnabled(true);
        ui->lblDCTIV->setEnabled(true);
        ui->ldtDCTIV->setEnabled(true);
        ui->lblDCTHexLength->setEnabled(true);
        ui->btnDCTStegoExecute->setEnabled(true);
    }
}

void SteganographyProject::on_btnDCTStegoExecute_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);


    std::vector<CryptoPP::byte> key;
    std::vector<CryptoPP::byte> iv;
    for (int i = 0; i < ui->ldtDCTKey->text().length(); i++)
    {
        key.push_back(ui->ldtDCTKey->text().toStdString()[i]);
        iv.push_back(ui->ldtDCTIV->text().toStdString()[i]);
    }
    DCTMessage = new Text(ui->pteDCT->toPlainText());
    Text* Encrypted = Text::Encrypt(DCTMessage, key, iv);
    ui->lblDCTHexLength->setText(QString::asprintf("Hex length: %d", Encrypted->Getstdstr().length()));
    HiddenDCTCVImage = CVImage::DCTStego(MainDCTCVImage, Encrypted);
    grvshow(HiddenDCTCVImage, ui->grvDCTStego);
    ui->btnDCTStegoExport->setEnabled(true);


    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}

void SteganographyProject::on_btnDCTStegoExport_clicked()
{
    exportfile(HiddenDCTCVImage);
}

