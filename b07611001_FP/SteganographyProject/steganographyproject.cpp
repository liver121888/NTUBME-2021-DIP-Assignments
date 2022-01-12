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
//future improvement: the grv in inactivate tab would not resize
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
        grvresize(ui->grvDetectOri);
        grvresize(ui->grvDetectHistSub);
        grvresize(ui->grvDCTOriSpect);
        grvresize(ui->grvDCTStegoSpect);
        grvresize(ui->grvDWTOri);
        grvresize(ui->grvDWTStego);
        grvresize(ui->grvDWTOriSpect);
        grvresize(ui->grvDWTStegoSpect);

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

//a function to export the image in png format
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
        ui->ldtLSBHex->setEnabled(true);
        ui->lblLSBHexLength->setEnabled(true);
        ui->btnLSBStegoExecute->setEnabled(true);
        //extract the LSB plane of the image
        MainLSBCVImage0 = CVImage::LSBextract(MainLSBCVImage);
        grvshow(MainLSBCVImage0, ui->grvOriLSB0);
        ui->lblLSBMax->setEnabled(true);
        //allowed hex length in LSB method
        ui->lblLSBMax->setText(QString::asprintf("Allowed Length: %d", 3*MainLSBCVImage->getCVimg()->rows*MainLSBCVImage->getCVimg()->cols));

    }
}


void SteganographyProject::on_btnLSBStegoExecute_clicked()
{
    //let the cursor changed to busy
    QApplication::setOverrideCursor(Qt::WaitCursor);

    //reads in the key and the initial vector
    std::vector<CryptoPP::byte> key;
    std::vector<CryptoPP::byte> iv;
    for (int i = 0; i < ui->ldtLSBKey->text().length(); i++)
    {
        key.push_back(ui->ldtLSBKey->text().toStdString()[i]);
        iv.push_back(ui->ldtLSBIV->text().toStdString()[i]);
    }
    LSBMessage = new Text(ui->pteLSB->toPlainText());
    //encrypt the plain text in to hex
    Text* Encrypted = Text::Encrypt(LSBMessage, key, iv);
    //show hex and get hex length
    ui->ldtLSBHex->setText(Encrypted->toQString());
    ui->lblLSBHexLength->setText(QString::asprintf("Hex length: %d", Encrypted->Getstdstr().length()));
    //embedded the hex into the image using LSB method
    HiddenLSBCVImage = CVImage::LSBStego(MainLSBCVImage, Encrypted);
    grvshow(HiddenLSBCVImage, ui->grvLSBStego);
    ui->btnLSBStegoExport->setEnabled(true);
    //extract the LSB plane of the image
    HiddenLSBCVImage0 = CVImage::LSBextract(HiddenLSBCVImage);
    grvshow(HiddenLSBCVImage0, ui->grvStegoLSB0);
    //restore the cursor
    QApplication::restoreOverrideCursor();
    Beep(440, 500);

}



void SteganographyProject::on_btnLSBStegoExport_clicked()
{
    exportfile(HiddenLSBCVImage);
}

void SteganographyProject::on_btnStegoDetectOpen_clicked()
{

    if (openfile(&MainStegoDetectCVImage, ui->grvMainStegoDetect) == true)
    {
        //enable certain widgets
        ui->widget->setEnabled(true);
        ui->pteDecrypt->setEnabled(true);
        ui->lblDecryptKey->setEnabled(true);
        ui->ldtKeyDecrypt->setEnabled(true);
        ui->lblDecryptIV->setEnabled(true);
        ui->ldtIVDecrypt->setEnabled(true);
        ui->lblDecryptMessage->setEnabled(true);
        ui->pteDecrypt->setEnabled(true);
        ui->btnStegoDecrypt->setEnabled(true);
        //calculate the histogram of the image and show
        grvshow(CVImage::calhisto(MainStegoDetectCVImage), ui->grvStegoDetectHist);

        ui->btnDetectImageSubtraction->setEnabled(true);
    }
}



void SteganographyProject::on_btnStegoDecrypt_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);

    Text HiddenMessage;
    //if the radio button is not checked, nothing happened
    if (ui->rbnLSB->isChecked())
    {
        HiddenMessage = CVImage::LSBStegoDecrypt(MainStegoDetectCVImage);
    }
    else if (ui->rbnDCT->isChecked())
    {
        HiddenMessage = CVImage::DCTStegoDecrypt(MainStegoDetectCVImage);
    }
    else if (ui->rbnDWT->isChecked())
    {
        HiddenMessage = CVImage::DWTStegoDecrypt(MainStegoDetectCVImage);
    }
    std::vector<CryptoPP::byte> key;
    std::vector<CryptoPP::byte> iv;
    for (int i = 0; i < ui->ldtKeyDecrypt->text().length(); i++)
    {
        key.push_back(ui->ldtKeyDecrypt->text().toStdString()[i]);
        iv.push_back(ui->ldtIVDecrypt->text().toStdString()[i]);
    }
    QString s = QString::fromStdString(Text::Decrypt(&HiddenMessage, key, iv)->Getstdstr());
    ui->pteDecrypt->setPlainText(s);
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
        ui->ldtDCTHex->setEnabled(true);
        ui->lblDCTHexLength->setEnabled(true);
        ui->btnDCTStegoExecute->setEnabled(true);
        //show the DCT result of the image
        grvshow(CVImage::DCTextract(MainDCTCVImage), ui->grvDCTOriSpect);

        ui->lblDCTMax->setEnabled(true);
        ui->lblDCTMax->setText(QString::asprintf("Allowed Length: %d", 3*MainDCTCVImage->getCVimg()->rows/8*MainDCTCVImage->getCVimg()->cols/8/8));

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
    ui->ldtDCTHex->setText(Encrypted->toQString());
    ui->lblDCTHexLength->setText(QString::asprintf("Hex length: %d", Encrypted->Getstdstr().length()));
    HiddenDCTCVImage = CVImage::DCTStego(MainDCTCVImage, Encrypted);
    grvshow(HiddenDCTCVImage, ui->grvDCTStego);
    grvshow(CVImage::DCTextract(HiddenDCTCVImage), ui->grvDCTStegoSpect);

    ui->btnDCTStegoExport->setEnabled(true);


    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}

void SteganographyProject::on_btnDCTStegoExport_clicked()
{
    exportfile(HiddenDCTCVImage);
}


void SteganographyProject::on_btnDecryptOriginal_clicked()
{
    if (openfile(&MainOriDetectCVImage, ui->grvDetectOri) == true)
    {
        grvshow(CVImage::calhisto(MainOriDetectCVImage), ui->grvDetectHistSub);
        ui->lblDetectHistSub->setText(QString::asprintf("Original Image Histogram"));
        if(ui->lblDecryptMessage->isEnabled())
            ui->btnDetectImageSubtraction->setEnabled(true);
    }
}




void SteganographyProject::on_btnDWTStegoOpen_clicked()
{
    if (openfile(&MainDWTCVImage, ui->grvDWTOri) == true)
    {
        ui->lblDWTMessage->setEnabled(true);
        ui->pteDWT->setEnabled(true);
        ui->lblDWTKey->setEnabled(true);
        ui->ldtDWTKey->setEnabled(true);
        ui->lblDWTIV->setEnabled(true);
        ui->ldtDWTIV->setEnabled(true);
        ui->ldtDWTHex->setEnabled(true);
        ui->lblDWTHexLength->setEnabled(true);
        ui->btnDWTStegoExecute->setEnabled(true);
        grvshow(CVImage::DWTextract(MainDWTCVImage), ui->grvDWTOriSpect);

        ui->lblDWTMax->setEnabled(true);
        ui->lblDWTMax->setText(QString::asprintf("Allowed Length: %d", 3*MainDWTCVImage->getCVimg()->rows/2*MainDWTCVImage->getCVimg()->cols/2/8));

    }

}


void SteganographyProject::on_btnDWTStegoExecute_clicked()
{

    QApplication::setOverrideCursor(Qt::WaitCursor);


    std::vector<CryptoPP::byte> key;
    std::vector<CryptoPP::byte> iv;
    for (int i = 0; i < ui->ldtDWTKey->text().length(); i++)
    {
        key.push_back(ui->ldtDWTKey->text().toStdString()[i]);
        iv.push_back(ui->ldtDWTIV->text().toStdString()[i]);
    }
    DWTMessage = new Text(ui->pteDWT->toPlainText());
    Text* Encrypted = Text::Encrypt(DWTMessage, key, iv);
    ui->ldtDWTHex->setText(Encrypted->toQString());
    ui->lblDWTHexLength->setText(QString::asprintf("Hex length: %d", Encrypted->Getstdstr().length()));
    HiddenDWTCVImage = CVImage::DWTStego(MainDWTCVImage, Encrypted);
    grvshow(HiddenDWTCVImage, ui->grvDWTStego);
    grvshow(CVImage::DWTextract(HiddenDWTCVImage), ui->grvDWTStegoSpect);

    ui->btnDWTStegoExport->setEnabled(true);


    QApplication::restoreOverrideCursor();
    Beep(440, 500);
}


void SteganographyProject::on_btnDWTStegoExport_clicked()
{
    exportfile(HiddenDWTCVImage);
}

void SteganographyProject::on_btnDetectImageSubtraction_pressed()
{
    ui->lblDetectHistSub->setText(QString::asprintf("Image Subtraction"));
    grvshow(*MainStegoDetectCVImage-MainOriDetectCVImage, ui->grvDetectHistSub);
}


void SteganographyProject::on_btnDetectImageSubtraction_released()
{
    grvshow(CVImage::calhisto(MainOriDetectCVImage), ui->grvDetectHistSub);
    ui->lblDetectHistSub->setText(QString::asprintf("Original Image Histogram"));
}
