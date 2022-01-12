#ifndef STEGANOGRAPHYPROJECT_H
#define STEGANOGRAPHYPROJECT_H

#include <QMainWindow>
#include <cvimage.h>
#include <QGraphicsScene>
#include <Windows.h>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class SteganographyProject; }
QT_END_NAMESPACE

class SteganographyProject : public QMainWindow
{
    Q_OBJECT
    bool resizeflag = false;
    CVImage* MainLSBCVImage;
    CVImage* MainLSBCVImage0;

    CVImage* HiddenLSBCVImage;
    CVImage* HiddenLSBCVImage0;

    CVImage* MainOriDetectCVImage;
    CVImage* MainStegoDetectCVImage;

    CVImage* MainDCTCVImage;
    CVImage* HiddenDCTCVImage;

    CVImage* MainDWTCVImage;
    CVImage* HiddenDWTCVImage;

    Text* LSBMessage;
    Text* DCTMessage;
    Text* DWTMessage;


public:
    SteganographyProject(QWidget *parent = nullptr);
    ~SteganographyProject();

private:
    void resizeEvent(QResizeEvent *event);
    void grvshow(CVImage* img, QGraphicsView* grv);
    void grvresize(QGraphicsView* grv);
    bool openfile(CVImage** img, QGraphicsView* grv);
    void exportfile(CVImage* img);



private slots:
    void on_btnLSBStegoOpen_clicked();

    void on_btnLSBStegoExecute_clicked();


    void on_btnStegoDetectOpen_clicked();

    void on_btnLSBStegoExport_clicked();

    void on_btnStegoDecrypt_clicked();

    void on_btnDCTStegoOpen_clicked();

    void on_btnDCTStegoExport_clicked();

    void on_btnDCTStegoExecute_clicked();

    void on_btnDecryptOriginal_clicked();

    void on_btnDWTStegoOpen_clicked();

    void on_btnDWTStegoExecute_clicked();

    void on_btnDWTStegoExport_clicked();

    void on_btnDetectImageSubtraction_pressed();

    void on_btnDetectImageSubtraction_released();

private:
    Ui::SteganographyProject *ui;
};
#endif // STEGANOGRAPHYPROJECT_H
