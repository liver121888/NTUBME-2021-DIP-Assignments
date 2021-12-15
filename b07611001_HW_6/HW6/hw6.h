#ifndef HW6_H
#define HW6_H

#include <QMainWindow>
#include <cvimage.h>
#include <QGraphicsScene>
#include <Windows.h>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class HW6; }
QT_END_NAMESPACE

class HW6 : public QMainWindow
{
    Q_OBJECT
    CVImage* GeoCVImage;
    CVImage* DWTCVImageA;
    CVImage* DWTCVImageB;
    CVImage* DWTTransformedCVImageA;
    CVImage* DWTTransformedCVImageB;
    CVImage* DWTTransformedCVImageFused;
    CVImage* DWTTransformedCVImageInversed;
    cv::Mat DWTRawData;
    CVImage* HTCVImage;
    CVImage* HTTransformedCVImage;
    std::vector<cv::Point>* ptis;

    bool resizeflag = false;

private:
    void resizeEvent(QResizeEvent *event);
    void grvshow(CVImage* img, QGraphicsView* grv);
    void grvresize(QGraphicsView* grv);

public:
    HW6(QWidget *parent = nullptr);
    ~HW6();

private slots:
    void on_btnGeoOpen_clicked();

    void on_btnGeoExecute_clicked();

    void on_btnDWTOpenA_clicked();

    void on_btnDWTOpenB_clicked();

    void on_btnDWTExecuteA_clicked();

    void on_btnDWTExecuteB_clicked();

    void on_btnDWTExecuteFuse_clicked();

    void on_btnDWTExecuteInverse_clicked();

    void on_btnHoughOpen_clicked();

    void on_btnHoughExecute_clicked();

    void on_hsdHoughThreshold_valueChanged(int value);

    void on_btnGetDistance_clicked();

    void on_rbnTrapezoidal_toggled(bool checked);

    void on_rbnWavy_toggled(bool checked);

    void on_hsdTrapezoidalParam_valueChanged(int value);

    void on_spbWavyParam_valueChanged(int arg1);

    void on_spbWavyParam2_valueChanged(int arg1);

    void on_hsdTrapezoidalParam2_valueChanged(int value);

    void on_spbWavyParam3_valueChanged(int arg1);

    void on_hsdCanny1_valueChanged(int value);

    void on_hsdCanny2_valueChanged(int value);

private:
    Ui::HW6 *ui;

};
#endif // HW6_H
