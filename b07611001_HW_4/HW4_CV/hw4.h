#ifndef HW4_H
#define HW4_H

#include <QMainWindow>
#include <freqfilter.h>
#include <colorimage.h>

QT_BEGIN_NAMESPACE
namespace Ui { class HW4; }
QT_END_NAMESPACE

class HW4 : public QMainWindow
{
    Q_OBJECT
    ColorImage* mainimg;
    MonoImage* maingrey;
    cv::Mat* data;
    MonoImage* magresult;
    MonoImage* phaseresult;

public:
    HW4(QWidget *parent = nullptr);
    ~HW4();

private slots:
    void on_btnOpen_clicked();

    void on_btnFFT_clicked();

    void on_btnIFFT_clicked();

    void on_btnFiltering_clicked();

    void on_btnHomomorphic_clicked();

    void on_btnDegradation_clicked();

private:
    Ui::HW4 *ui;
};
#endif // HW4_H
