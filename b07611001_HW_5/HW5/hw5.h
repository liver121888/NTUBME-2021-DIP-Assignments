#ifndef HW5_H
#define HW5_H

#include <QMainWindow>
#include <cvimage.h>
#include <QGraphicsScene>
#include <Windows.h>
#include <QFileDialog>
#include <QColorDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class HW5; }
QT_END_NAMESPACE

class HW5 : public QMainWindow
{
    Q_OBJECT
    CVImage* MainCVImage;
    CVImage* MainCVImage2;
    CVImage* MainCVImage2gray;
    CVImage* ColorImage1;
    CVImage* ColorImage2;
    CVImage* ColorImage3;
    CVImage* ColorImage4;
    CVImage* ColorImage5;
    CVImage* ColorBar;
    CVImage* CheckedColorImage = 0;
    CVImage* MainCVImage3;
    bool resizeflag = false;

public:
    HW5(QWidget *parent = nullptr);
    ~HW5();
private:
    void resizeEvent(QResizeEvent *event);
    void grvshow(CVImage* img, QGraphicsView* grv);
    void grvresize(QGraphicsView* grv);



private slots:
    void on_btnOpen_P2_clicked();

    void on_btnOpen_P1_clicked();

    void on_btnRGB_clicked();

    void on_btnCMY_clicked();

    void on_btnHSI_clicked();

    void on_btnXYZ_clicked();

    void on_btnLAB_clicked();

    void on_btnYUV_clicked();

    void on_btnColor1_clicked();

    void on_btnColor2_clicked();

    void on_btnColor3_clicked();

    void on_btnColor4_clicked();

    void on_btnCreateColorBar_clicked();

    void on_btnDoPseudo_clicked();

    void on_btnColor5_clicked();

    void on_hsdCheckColor_sliderReleased();

    void on_btnOpen_P3_clicked();

    void on_btnKmeans_clicked();

private:
    Ui::HW5 *ui;

};
#endif // HW5_H
