/********************************************************************************
** Form generated from reading UI file 'hw4.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW4_H
#define UI_HW4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HW4
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *lblPic1;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *lblPic1_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *lblPic1_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *lblPic1_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_9;
    QGridLayout *gridLayout_2;
    QPushButton *btnIFFT;
    QPushButton *btnOpen;
    QPushButton *btnFFT;
    QLabel *lblTime;
    QLabel *lblSize;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_6;
    QGridLayout *gridLayout_7;
    QRadioButton *rbnHighpass;
    QRadioButton *rbnLowpass;
    QWidget *widget_7;
    QGridLayout *gridLayout_6;
    QComboBox *cbbFilter;
    QPushButton *btnFiltering;
    QLabel *label_5;
    QSpinBox *spbCutoffFreq;
    QLabel *label_6;
    QSpinBox *spbButterworthOrder;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_8;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QSpinBox *spbCutoffFreqHomomorphic;
    QDoubleSpinBox *dsbGammaL;
    QLabel *label_11;
    QDoubleSpinBox *dsbC;
    QLabel *label_9;
    QDoubleSpinBox *dsbGammaH;
    QLabel *label_7;
    QPushButton *btnHomomorphic;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_4;
    QLabel *label_15;
    QPushButton *btnInverseFiltering;
    QPushButton *btnWeinerFiltering;
    QSpinBox *spbInverseRadius;
    QPushButton *btnDegradation;
    QWidget *widget_10;
    QGridLayout *gridLayout_3;
    QRadioButton *rbnMotionBlurred;
    QRadioButton *rbnGaussianNoise;
    QWidget *widget_11;
    QGridLayout *gridLayout_4;
    QLabel *label_12;
    QDoubleSpinBox *dsba;
    QDoubleSpinBox *dsbb;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *dsbT;
    QWidget *widget_12;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *dsbStd;
    QLabel *label_16;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *HW4)
    {
        if (HW4->objectName().isEmpty())
            HW4->setObjectName(QString::fromUtf8("HW4"));
        HW4->resize(954, 664);
        centralwidget = new QWidget(HW4);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widget_5 = new QWidget(splitter);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label);

        lblPic1 = new QLabel(widget_3);
        lblPic1->setObjectName(QString::fromUtf8("lblPic1"));
        lblPic1->setStyleSheet(QString::fromUtf8("background-color: rgb(111, 111, 111);"));

        verticalLayout_3->addWidget(lblPic1);


        horizontalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_4);

        lblPic1_2 = new QLabel(widget_4);
        lblPic1_2->setObjectName(QString::fromUtf8("lblPic1_2"));
        lblPic1_2->setStyleSheet(QString::fromUtf8("background-color: rgb(111, 111, 111);"));

        verticalLayout->addWidget(lblPic1_2);


        horizontalLayout_2->addWidget(widget_4);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_2);

        lblPic1_3 = new QLabel(widget_2);
        lblPic1_3->setObjectName(QString::fromUtf8("lblPic1_3"));
        lblPic1_3->setStyleSheet(QString::fromUtf8("background-color: rgb(111, 111, 111);"));

        verticalLayout_2->addWidget(lblPic1_3);


        horizontalLayout_2->addWidget(widget_2);

        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_3);

        lblPic1_4 = new QLabel(widget);
        lblPic1_4->setObjectName(QString::fromUtf8("lblPic1_4"));
        lblPic1_4->setStyleSheet(QString::fromUtf8("background-color: rgb(111, 111, 111);"));

        verticalLayout_4->addWidget(lblPic1_4);


        horizontalLayout_2->addWidget(widget);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        splitter->addWidget(widget_5);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_9 = new QWidget(tab);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_2 = new QGridLayout(widget_9);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnIFFT = new QPushButton(widget_9);
        btnIFFT->setObjectName(QString::fromUtf8("btnIFFT"));

        gridLayout_2->addWidget(btnIFFT, 0, 2, 1, 1);

        btnOpen = new QPushButton(widget_9);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));

        gridLayout_2->addWidget(btnOpen, 0, 0, 1, 1);

        btnFFT = new QPushButton(widget_9);
        btnFFT->setObjectName(QString::fromUtf8("btnFFT"));

        gridLayout_2->addWidget(btnFFT, 0, 1, 1, 1);

        lblTime = new QLabel(widget_9);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));

        gridLayout_2->addWidget(lblTime, 1, 0, 1, 1);

        lblSize = new QLabel(widget_9);
        lblSize->setObjectName(QString::fromUtf8("lblSize"));

        gridLayout_2->addWidget(lblSize, 1, 1, 1, 1);


        horizontalLayout_4->addWidget(widget_9);

        horizontalSpacer = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_6 = new QWidget(tab_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_7 = new QGridLayout(widget_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        rbnHighpass = new QRadioButton(widget_6);
        rbnHighpass->setObjectName(QString::fromUtf8("rbnHighpass"));

        gridLayout_7->addWidget(rbnHighpass, 0, 0, 1, 1);

        rbnLowpass = new QRadioButton(widget_6);
        rbnLowpass->setObjectName(QString::fromUtf8("rbnLowpass"));

        gridLayout_7->addWidget(rbnLowpass, 1, 0, 1, 1);


        horizontalLayout_5->addWidget(widget_6);

        widget_7 = new QWidget(tab_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_6 = new QGridLayout(widget_7);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        cbbFilter = new QComboBox(widget_7);
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->setObjectName(QString::fromUtf8("cbbFilter"));

        gridLayout_6->addWidget(cbbFilter, 0, 0, 1, 2);

        btnFiltering = new QPushButton(widget_7);
        btnFiltering->setObjectName(QString::fromUtf8("btnFiltering"));

        gridLayout_6->addWidget(btnFiltering, 0, 2, 1, 1);

        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        spbCutoffFreq = new QSpinBox(widget_7);
        spbCutoffFreq->setObjectName(QString::fromUtf8("spbCutoffFreq"));
        spbCutoffFreq->setValue(30);

        gridLayout_6->addWidget(spbCutoffFreq, 1, 1, 1, 1);

        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 1, 2, 1, 1);

        spbButterworthOrder = new QSpinBox(widget_7);
        spbButterworthOrder->setObjectName(QString::fromUtf8("spbButterworthOrder"));
        spbButterworthOrder->setMinimum(1);
        spbButterworthOrder->setMaximum(15);

        gridLayout_6->addWidget(spbButterworthOrder, 1, 3, 1, 1);


        horizontalLayout_5->addWidget(widget_7);

        horizontalSpacer_2 = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_6 = new QHBoxLayout(tab_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_8 = new QWidget(tab_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout = new QGridLayout(widget_8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_10 = new QLabel(widget_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        spbCutoffFreqHomomorphic = new QSpinBox(widget_8);
        spbCutoffFreqHomomorphic->setObjectName(QString::fromUtf8("spbCutoffFreqHomomorphic"));
        spbCutoffFreqHomomorphic->setValue(20);

        gridLayout->addWidget(spbCutoffFreqHomomorphic, 1, 3, 1, 1);

        dsbGammaL = new QDoubleSpinBox(widget_8);
        dsbGammaL->setObjectName(QString::fromUtf8("dsbGammaL"));
        dsbGammaL->setValue(0.300000000000000);

        gridLayout->addWidget(dsbGammaL, 0, 3, 1, 1);

        label_11 = new QLabel(widget_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        dsbC = new QDoubleSpinBox(widget_8);
        dsbC->setObjectName(QString::fromUtf8("dsbC"));
        dsbC->setValue(5.000000000000000);

        gridLayout->addWidget(dsbC, 1, 1, 1, 1);

        label_9 = new QLabel(widget_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        dsbGammaH = new QDoubleSpinBox(widget_8);
        dsbGammaH->setObjectName(QString::fromUtf8("dsbGammaH"));
        dsbGammaH->setValue(4.000000000000000);

        gridLayout->addWidget(dsbGammaH, 0, 1, 1, 1);

        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        btnHomomorphic = new QPushButton(widget_8);
        btnHomomorphic->setObjectName(QString::fromUtf8("btnHomomorphic"));

        gridLayout->addWidget(btnHomomorphic, 0, 4, 1, 1);


        horizontalLayout_6->addWidget(widget_8);

        horizontalSpacer_3 = new QSpacerItem(513, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(650, 10, 151, 16));
        btnInverseFiltering = new QPushButton(tab_4);
        btnInverseFiltering->setObjectName(QString::fromUtf8("btnInverseFiltering"));
        btnInverseFiltering->setGeometry(QRect(720, 30, 131, 24));
        btnWeinerFiltering = new QPushButton(tab_4);
        btnWeinerFiltering->setObjectName(QString::fromUtf8("btnWeinerFiltering"));
        btnWeinerFiltering->setGeometry(QRect(720, 80, 121, 24));
        spbInverseRadius = new QSpinBox(tab_4);
        spbInverseRadius->setObjectName(QString::fromUtf8("spbInverseRadius"));
        spbInverseRadius->setGeometry(QRect(660, 30, 46, 25));
        btnDegradation = new QPushButton(tab_4);
        btnDegradation->setObjectName(QString::fromUtf8("btnDegradation"));
        btnDegradation->setGeometry(QRect(450, 40, 80, 24));
        widget_10 = new QWidget(tab_4);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setGeometry(QRect(10, 30, 181, 71));
        gridLayout_3 = new QGridLayout(widget_10);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        rbnMotionBlurred = new QRadioButton(widget_10);
        rbnMotionBlurred->setObjectName(QString::fromUtf8("rbnMotionBlurred"));

        gridLayout_3->addWidget(rbnMotionBlurred, 0, 0, 1, 1);

        rbnGaussianNoise = new QRadioButton(widget_10);
        rbnGaussianNoise->setObjectName(QString::fromUtf8("rbnGaussianNoise"));

        gridLayout_3->addWidget(rbnGaussianNoise, 1, 0, 1, 1);

        widget_11 = new QWidget(tab_4);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setGeometry(QRect(210, 10, 111, 101));
        gridLayout_4 = new QGridLayout(widget_11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_12 = new QLabel(widget_11);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 0, 0, 1, 1);

        dsba = new QDoubleSpinBox(widget_11);
        dsba->setObjectName(QString::fromUtf8("dsba"));
        dsba->setValue(0.100000000000000);

        gridLayout_4->addWidget(dsba, 0, 1, 1, 1);

        dsbb = new QDoubleSpinBox(widget_11);
        dsbb->setObjectName(QString::fromUtf8("dsbb"));
        dsbb->setValue(0.100000000000000);

        gridLayout_4->addWidget(dsbb, 1, 1, 1, 1);

        label_13 = new QLabel(widget_11);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 1, 0, 1, 1);

        label_14 = new QLabel(widget_11);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 2, 0, 1, 1);

        dsbT = new QDoubleSpinBox(widget_11);
        dsbT->setObjectName(QString::fromUtf8("dsbT"));
        dsbT->setValue(1.000000000000000);

        gridLayout_4->addWidget(dsbT, 2, 1, 1, 1);

        widget_12 = new QWidget(tab_4);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setGeometry(QRect(330, 30, 86, 69));
        gridLayout_5 = new QGridLayout(widget_12);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        dsbStd = new QDoubleSpinBox(widget_12);
        dsbStd->setObjectName(QString::fromUtf8("dsbStd"));

        gridLayout_5->addWidget(dsbStd, 2, 0, 1, 1);

        label_16 = new QLabel(widget_12);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_5->addWidget(label_16, 1, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        splitter->addWidget(tabWidget);

        horizontalLayout->addWidget(splitter);

        HW4->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HW4);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 954, 25));
        HW4->setMenuBar(menubar);
        statusbar = new QStatusBar(HW4);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HW4->setStatusBar(statusbar);
        toolBar = new QToolBar(HW4);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        HW4->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(HW4);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(HW4);
    } // setupUi

    void retranslateUi(QMainWindow *HW4)
    {
        HW4->setWindowTitle(QCoreApplication::translate("HW4", "HW4", nullptr));
        label->setText(QCoreApplication::translate("HW4", "Image", nullptr));
        lblPic1->setText(QString());
        label_4->setText(QCoreApplication::translate("HW4", "Spectrum", nullptr));
        lblPic1_2->setText(QString());
        label_2->setText(QCoreApplication::translate("HW4", "Phase angle", nullptr));
        lblPic1_3->setText(QString());
        label_3->setText(QCoreApplication::translate("HW4", "Operated Image", nullptr));
        lblPic1_4->setText(QString());
        btnIFFT->setText(QCoreApplication::translate("HW4", "IFFT", nullptr));
        btnOpen->setText(QCoreApplication::translate("HW4", "Open File", nullptr));
        btnFFT->setText(QCoreApplication::translate("HW4", "FFT", nullptr));
        lblTime->setText(QCoreApplication::translate("HW4", "Time elapsed:", nullptr));
        lblSize->setText(QCoreApplication::translate("HW4", "Image size:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("HW4", "FFT and IFFT", nullptr));
        rbnHighpass->setText(QCoreApplication::translate("HW4", "Highpass", nullptr));
        rbnLowpass->setText(QCoreApplication::translate("HW4", "Lowpass", nullptr));
        cbbFilter->setItemText(0, QCoreApplication::translate("HW4", "Ideal Filter", nullptr));
        cbbFilter->setItemText(1, QCoreApplication::translate("HW4", "Butterworth Filter", nullptr));
        cbbFilter->setItemText(2, QCoreApplication::translate("HW4", "Gaussian Filter", nullptr));

        btnFiltering->setText(QCoreApplication::translate("HW4", "Filtering", nullptr));
        label_5->setText(QCoreApplication::translate("HW4", "Cutoff Frequency", nullptr));
        label_6->setText(QCoreApplication::translate("HW4", "Butterworth Order", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("HW4", "Highpass and Lowpass Filtering", nullptr));
        label_10->setText(QCoreApplication::translate("HW4", "Cutoff Frequency", nullptr));
        label_11->setText(QCoreApplication::translate("HW4", "c", nullptr));
        label_9->setText(QCoreApplication::translate("HW4", "\316\263L", nullptr));
        label_7->setText(QCoreApplication::translate("HW4", "\316\263H", nullptr));
        btnHomomorphic->setText(QCoreApplication::translate("HW4", "Filtering", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("HW4", "Homomorphic Filtering", nullptr));
        label_15->setText(QCoreApplication::translate("HW4", "Radius/Cutoff Frequency", nullptr));
        btnInverseFiltering->setText(QCoreApplication::translate("HW4", "Inverse Filtering", nullptr));
        btnWeinerFiltering->setText(QCoreApplication::translate("HW4", "Wiener Filtering", nullptr));
        btnDegradation->setText(QCoreApplication::translate("HW4", "Add Noise", nullptr));
        rbnMotionBlurred->setText(QCoreApplication::translate("HW4", "Motion Blurred", nullptr));
        rbnGaussianNoise->setText(QCoreApplication::translate("HW4", "Gaussian White Noise", nullptr));
        label_12->setText(QCoreApplication::translate("HW4", "a", nullptr));
        label_13->setText(QCoreApplication::translate("HW4", "b", nullptr));
        label_14->setText(QCoreApplication::translate("HW4", "T", nullptr));
        label_16->setText(QCoreApplication::translate("HW4", "Std", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("HW4", "Noise Addition and Image Restoration", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("HW4", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HW4: public Ui_HW4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW4_H
