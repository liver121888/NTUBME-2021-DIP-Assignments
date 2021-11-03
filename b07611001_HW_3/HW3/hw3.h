#ifndef HW3_H
#define HW3_H

#include <QMainWindow>
#include <colorimage.h>
#include <filter.h>



QT_BEGIN_NAMESPACE
namespace Ui { class Hw3; }
QT_END_NAMESPACE

class Hw3 : public QMainWindow
{
    Q_OBJECT
    ColorImage* mainimg;

public:
    Hw3(QWidget *parent = nullptr);
    ~Hw3();

private slots:
    void on_btnOpen_clicked();

    void on_hsdKernelSizem_valueChanged(int value);

    void on_hsdKernelSizen_valueChanged(int value);

    void on_btnExecute_clicked();

    void on_btnSobel_clicked();

    void on_btnOrderStatisticsExecute_clicked();

    void on_hsdKernelSizem_3_valueChanged(int value);

    void on_hsdKernelSizen_3_valueChanged(int value);

    void on_btnLoG_clicked();

    void on_hsdKernelSizem_2_valueChanged(int value);

    void on_hsdKernelSizen_2_valueChanged(int value);

    void on_cbbFilter_currentIndexChanged(int index);

    void on_ckbGaussainNormalize_stateChanged(int arg1);

private:
    Ui::Hw3 *ui;
};
#endif // HW3_H
