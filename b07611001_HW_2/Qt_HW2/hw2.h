#ifndef HW2_H
#define HW2_H

#include <QMainWindow>
#include <image.h>

QT_BEGIN_NAMESPACE
namespace Ui { class hw2; }
QT_END_NAMESPACE

class hw2 : public QMainWindow
{
    Q_OBJECT
    image* mainimg;
    MonoImage* grey1;
    MonoImage* grey2;

public:
    hw2(QWidget *parent = nullptr);
    ~hw2();

private slots:
    void on_btnOpenA_clicked();

    void on_btnMono1_clicked();

    void on_btnMono2_clicked();

    void on_btnThresh_clicked();

    void on_hsdThresh_valueChanged(int value);

    void on_btnLevel_clicked();

    void on_hsdBrightness_valueChanged(int value);

    void on_btnBrightness_clicked();

    void on_hsdLevel_valueChanged(int value);

    void on_hsdContrast_valueChanged(int value);

    void on_btnContrast_clicked();

    void on_btnSubtract_clicked();

    void on_hsdResolution_valueChanged(int value);

    void on_btnResolution_clicked();

    void on_actionExit_triggered();

    void on_btnHistoEqualize_clicked();

private:
    Ui::hw2 *ui;
};
#endif // HW2_H
