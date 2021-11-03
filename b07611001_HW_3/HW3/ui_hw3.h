/********************************************************************************
** Form generated from reading UI file 'hw3.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW3_H
#define UI_HW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hw3
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *lblBanner1;
    QLabel *lblPic1;
    QPushButton *btnOpen;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblBanner2;
    QLabel *lblPic2;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *lblTime;
    QSlider *hsdKernelSizen;
    QLabel *lblKernelSizen;
    QLabel *lblKernelSizem;
    QPushButton *btnExecute;
    QSlider *hsdKernelSizem;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QLabel *lblGaussianSigma;
    QDoubleSpinBox *dsbGaussianSigma;
    QDoubleSpinBox *dsbGaussianK;
    QLabel *lblGaussianK;
    QCheckBox *ckbGaussainNormalize;
    QComboBox *cbbFilter;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QLabel *lblGaussianSigma_2;
    QLabel *lblZeroCrossingThreshold;
    QLabel *lblKernelSizem_2;
    QDoubleSpinBox *dsbGaussianSigma_2;
    QLabel *lblTime_3;
    QDoubleSpinBox *dsbZeroCrossingThreshold;
    QLabel *lblMH;
    QSlider *hsdKernelSizem_2;
    QSlider *hsdKernelSizen_2;
    QLabel *lblKernelSizen_2;
    QPushButton *btnLoG;
    QWidget *widget_8;
    QGridLayout *gridLayout_4;
    QPushButton *btnSobel;
    QLabel *lblSobel;
    QLabel *lblTime_4;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QSlider *hsdKernelSizem_3;
    QLabel *lblKernelSizem_3;
    QSlider *hsdKernelSizen_3;
    QLabel *lblKernelSizen_3;
    QWidget *widget_7;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QRadioButton *rbnMedian;
    QRadioButton *rbnMax;
    QRadioButton *rbnMin;
    QPushButton *btnOrderStatisticsExecute;
    QLabel *lblTime_2;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Hw3)
    {
        if (Hw3->objectName().isEmpty())
            Hw3->setObjectName(QString::fromUtf8("Hw3"));
        Hw3->resize(1062, 671);
        centralwidget = new QWidget(Hw3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(139, 139, 139);\n"
"border-color: rgb(8, 8, 8);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblBanner1 = new QLabel(widget_2);
        lblBanner1->setObjectName(QString::fromUtf8("lblBanner1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblBanner1->sizePolicy().hasHeightForWidth());
        lblBanner1->setSizePolicy(sizePolicy1);
        lblBanner1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);\n"
"color: rgb(255, 255, 255);"));
        lblBanner1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblBanner1);

        lblPic1 = new QLabel(widget_2);
        lblPic1->setObjectName(QString::fromUtf8("lblPic1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblPic1->sizePolicy().hasHeightForWidth());
        lblPic1->setSizePolicy(sizePolicy2);
        lblPic1->setAutoFillBackground(false);
        lblPic1->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));

        verticalLayout->addWidget(lblPic1);

        btnOpen = new QPushButton(widget_2);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        sizePolicy1.setHeightForWidth(btnOpen->sizePolicy().hasHeightForWidth());
        btnOpen->setSizePolicy(sizePolicy1);
        btnOpen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-color: rgb(8, 8, 8);"));

        verticalLayout->addWidget(btnOpen);

        splitter->addWidget(widget_2);
        widget_3 = new QWidget(splitter);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblBanner2 = new QLabel(widget_3);
        lblBanner2->setObjectName(QString::fromUtf8("lblBanner2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblBanner2->sizePolicy().hasHeightForWidth());
        lblBanner2->setSizePolicy(sizePolicy3);
        lblBanner2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);\n"
"color: rgb(255, 255, 255);"));
        lblBanner2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblBanner2);

        lblPic2 = new QLabel(widget_3);
        lblPic2->setObjectName(QString::fromUtf8("lblPic2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lblPic2->sizePolicy().hasHeightForWidth());
        lblPic2->setSizePolicy(sizePolicy4);
        lblPic2->setAutoFillBackground(false);
        lblPic2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));

        verticalLayout_2->addWidget(lblPic2);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        splitter->addWidget(widget_3);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy5);
        tabWidget->setBaseSize(QSize(0, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy3.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy3);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblTime = new QLabel(widget);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));

        gridLayout_2->addWidget(lblTime, 8, 0, 1, 1);

        hsdKernelSizen = new QSlider(widget);
        hsdKernelSizen->setObjectName(QString::fromUtf8("hsdKernelSizen"));
        hsdKernelSizen->setMinimum(3);
        hsdKernelSizen->setMaximum(49);
        hsdKernelSizen->setSingleStep(2);
        hsdKernelSizen->setValue(25);
        hsdKernelSizen->setOrientation(Qt::Horizontal);
        hsdKernelSizen->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(hsdKernelSizen, 3, 0, 1, 1);

        lblKernelSizen = new QLabel(widget);
        lblKernelSizen->setObjectName(QString::fromUtf8("lblKernelSizen"));

        gridLayout_2->addWidget(lblKernelSizen, 4, 0, 1, 1);

        lblKernelSizem = new QLabel(widget);
        lblKernelSizem->setObjectName(QString::fromUtf8("lblKernelSizem"));

        gridLayout_2->addWidget(lblKernelSizem, 2, 0, 1, 1);

        btnExecute = new QPushButton(widget);
        btnExecute->setObjectName(QString::fromUtf8("btnExecute"));

        gridLayout_2->addWidget(btnExecute, 7, 0, 1, 1);

        hsdKernelSizem = new QSlider(widget);
        hsdKernelSizem->setObjectName(QString::fromUtf8("hsdKernelSizem"));
        hsdKernelSizem->setMinimum(3);
        hsdKernelSizem->setMaximum(49);
        hsdKernelSizem->setSingleStep(2);
        hsdKernelSizem->setValue(25);
        hsdKernelSizem->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(hsdKernelSizem, 1, 0, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblGaussianSigma = new QLabel(widget_4);
        lblGaussianSigma->setObjectName(QString::fromUtf8("lblGaussianSigma"));

        gridLayout->addWidget(lblGaussianSigma, 1, 1, 1, 1);

        dsbGaussianSigma = new QDoubleSpinBox(widget_4);
        dsbGaussianSigma->setObjectName(QString::fromUtf8("dsbGaussianSigma"));
        dsbGaussianSigma->setDecimals(1);
        dsbGaussianSigma->setMinimum(1.000000000000000);
        dsbGaussianSigma->setMaximum(10.000000000000000);

        gridLayout->addWidget(dsbGaussianSigma, 2, 1, 1, 1);

        dsbGaussianK = new QDoubleSpinBox(widget_4);
        dsbGaussianK->setObjectName(QString::fromUtf8("dsbGaussianK"));
        dsbGaussianK->setDecimals(1);
        dsbGaussianK->setMinimum(0.500000000000000);
        dsbGaussianK->setMaximum(10.000000000000000);
        dsbGaussianK->setSingleStep(0.500000000000000);

        gridLayout->addWidget(dsbGaussianK, 2, 0, 1, 1);

        lblGaussianK = new QLabel(widget_4);
        lblGaussianK->setObjectName(QString::fromUtf8("lblGaussianK"));

        gridLayout->addWidget(lblGaussianK, 1, 0, 1, 1);

        ckbGaussainNormalize = new QCheckBox(widget_4);
        ckbGaussainNormalize->setObjectName(QString::fromUtf8("ckbGaussainNormalize"));
        ckbGaussainNormalize->setChecked(true);

        gridLayout->addWidget(ckbGaussainNormalize, 0, 0, 1, 2);


        gridLayout_2->addWidget(widget_4, 6, 0, 1, 1);

        cbbFilter = new QComboBox(widget);
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->addItem(QString());
        cbbFilter->setObjectName(QString::fromUtf8("cbbFilter"));

        gridLayout_2->addWidget(cbbFilter, 0, 0, 1, 1);


        verticalLayout_5->addWidget(widget);

        verticalSpacer_4 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lblGaussianSigma_2 = new QLabel(widget_5);
        lblGaussianSigma_2->setObjectName(QString::fromUtf8("lblGaussianSigma_2"));

        gridLayout_3->addWidget(lblGaussianSigma_2, 1, 0, 1, 1);

        lblZeroCrossingThreshold = new QLabel(widget_5);
        lblZeroCrossingThreshold->setObjectName(QString::fromUtf8("lblZeroCrossingThreshold"));

        gridLayout_3->addWidget(lblZeroCrossingThreshold, 1, 1, 1, 1);

        lblKernelSizem_2 = new QLabel(widget_5);
        lblKernelSizem_2->setObjectName(QString::fromUtf8("lblKernelSizem_2"));

        gridLayout_3->addWidget(lblKernelSizem_2, 4, 0, 1, 1);

        dsbGaussianSigma_2 = new QDoubleSpinBox(widget_5);
        dsbGaussianSigma_2->setObjectName(QString::fromUtf8("dsbGaussianSigma_2"));
        dsbGaussianSigma_2->setDecimals(1);
        dsbGaussianSigma_2->setMinimum(1.000000000000000);
        dsbGaussianSigma_2->setMaximum(10.000000000000000);

        gridLayout_3->addWidget(dsbGaussianSigma_2, 2, 0, 1, 1);

        lblTime_3 = new QLabel(widget_5);
        lblTime_3->setObjectName(QString::fromUtf8("lblTime_3"));

        gridLayout_3->addWidget(lblTime_3, 8, 0, 1, 1);

        dsbZeroCrossingThreshold = new QDoubleSpinBox(widget_5);
        dsbZeroCrossingThreshold->setObjectName(QString::fromUtf8("dsbZeroCrossingThreshold"));
        dsbZeroCrossingThreshold->setDecimals(1);
        dsbZeroCrossingThreshold->setMinimum(0.000000000000000);
        dsbZeroCrossingThreshold->setMaximum(255.000000000000000);
        dsbZeroCrossingThreshold->setValue(0.000000000000000);

        gridLayout_3->addWidget(dsbZeroCrossingThreshold, 2, 1, 1, 1);

        lblMH = new QLabel(widget_5);
        lblMH->setObjectName(QString::fromUtf8("lblMH"));

        gridLayout_3->addWidget(lblMH, 0, 0, 1, 2);

        hsdKernelSizem_2 = new QSlider(widget_5);
        hsdKernelSizem_2->setObjectName(QString::fromUtf8("hsdKernelSizem_2"));
        hsdKernelSizem_2->setMinimum(3);
        hsdKernelSizem_2->setMaximum(49);
        hsdKernelSizem_2->setSingleStep(2);
        hsdKernelSizem_2->setPageStep(2);
        hsdKernelSizem_2->setValue(25);
        hsdKernelSizem_2->setTracking(true);
        hsdKernelSizem_2->setOrientation(Qt::Horizontal);
        hsdKernelSizem_2->setInvertedAppearance(false);
        hsdKernelSizem_2->setInvertedControls(false);
        hsdKernelSizem_2->setTickPosition(QSlider::NoTicks);

        gridLayout_3->addWidget(hsdKernelSizem_2, 3, 0, 1, 2);

        hsdKernelSizen_2 = new QSlider(widget_5);
        hsdKernelSizen_2->setObjectName(QString::fromUtf8("hsdKernelSizen_2"));
        hsdKernelSizen_2->setMinimum(3);
        hsdKernelSizen_2->setMaximum(49);
        hsdKernelSizen_2->setSingleStep(2);
        hsdKernelSizen_2->setValue(25);
        hsdKernelSizen_2->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(hsdKernelSizen_2, 5, 0, 1, 2);

        lblKernelSizen_2 = new QLabel(widget_5);
        lblKernelSizen_2->setObjectName(QString::fromUtf8("lblKernelSizen_2"));

        gridLayout_3->addWidget(lblKernelSizen_2, 6, 0, 1, 1);

        btnLoG = new QPushButton(widget_5);
        btnLoG->setObjectName(QString::fromUtf8("btnLoG"));

        gridLayout_3->addWidget(btnLoG, 7, 0, 1, 1);


        verticalLayout_3->addWidget(widget_5);

        widget_8 = new QWidget(tab_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout_4 = new QGridLayout(widget_8);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btnSobel = new QPushButton(widget_8);
        btnSobel->setObjectName(QString::fromUtf8("btnSobel"));

        gridLayout_4->addWidget(btnSobel, 1, 0, 1, 1);

        lblSobel = new QLabel(widget_8);
        lblSobel->setObjectName(QString::fromUtf8("lblSobel"));

        gridLayout_4->addWidget(lblSobel, 0, 0, 1, 1);

        lblTime_4 = new QLabel(widget_8);
        lblTime_4->setObjectName(QString::fromUtf8("lblTime_4"));

        gridLayout_4->addWidget(lblTime_4, 2, 0, 1, 1);


        verticalLayout_3->addWidget(widget_8);

        verticalSpacer_2 = new QSpacerItem(218, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_6 = new QWidget(tab_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        hsdKernelSizem_3 = new QSlider(widget_6);
        hsdKernelSizem_3->setObjectName(QString::fromUtf8("hsdKernelSizem_3"));
        hsdKernelSizem_3->setMinimum(3);
        hsdKernelSizem_3->setMaximum(11);
        hsdKernelSizem_3->setSingleStep(2);
        hsdKernelSizem_3->setValue(7);
        hsdKernelSizem_3->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(hsdKernelSizem_3, 0, 0, 1, 1);

        lblKernelSizem_3 = new QLabel(widget_6);
        lblKernelSizem_3->setObjectName(QString::fromUtf8("lblKernelSizem_3"));

        gridLayout_6->addWidget(lblKernelSizem_3, 1, 0, 1, 1);

        hsdKernelSizen_3 = new QSlider(widget_6);
        hsdKernelSizen_3->setObjectName(QString::fromUtf8("hsdKernelSizen_3"));
        hsdKernelSizen_3->setMinimum(3);
        hsdKernelSizen_3->setMaximum(11);
        hsdKernelSizen_3->setSingleStep(2);
        hsdKernelSizen_3->setValue(7);
        hsdKernelSizen_3->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(hsdKernelSizen_3, 2, 0, 1, 1);

        lblKernelSizen_3 = new QLabel(widget_6);
        lblKernelSizen_3->setObjectName(QString::fromUtf8("lblKernelSizen_3"));

        gridLayout_6->addWidget(lblKernelSizen_3, 3, 0, 1, 1);


        verticalLayout_4->addWidget(widget_6);

        widget_7 = new QWidget(tab_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_5 = new QGridLayout(widget_7);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(widget_7);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        rbnMedian = new QRadioButton(widget_7);
        rbnMedian->setObjectName(QString::fromUtf8("rbnMedian"));

        gridLayout_5->addWidget(rbnMedian, 1, 0, 1, 1);

        rbnMax = new QRadioButton(widget_7);
        rbnMax->setObjectName(QString::fromUtf8("rbnMax"));

        gridLayout_5->addWidget(rbnMax, 2, 0, 1, 1);

        rbnMin = new QRadioButton(widget_7);
        rbnMin->setObjectName(QString::fromUtf8("rbnMin"));

        gridLayout_5->addWidget(rbnMin, 3, 0, 1, 1);

        btnOrderStatisticsExecute = new QPushButton(widget_7);
        btnOrderStatisticsExecute->setObjectName(QString::fromUtf8("btnOrderStatisticsExecute"));

        gridLayout_5->addWidget(btnOrderStatisticsExecute, 4, 0, 1, 1);

        lblTime_2 = new QLabel(widget_7);
        lblTime_2->setObjectName(QString::fromUtf8("lblTime_2"));

        gridLayout_5->addWidget(lblTime_2, 5, 0, 1, 1);


        verticalLayout_4->addWidget(widget_7);

        verticalSpacer_3 = new QSpacerItem(218, 250, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        tabWidget->addTab(tab_3, QString());
        splitter->addWidget(tabWidget);

        horizontalLayout->addWidget(splitter);

        Hw3->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Hw3);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 24));
        Hw3->setMenuBar(menubar);
        statusbar = new QStatusBar(Hw3);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Hw3->setStatusBar(statusbar);

        retranslateUi(Hw3);

        tabWidget->setCurrentIndex(0);
        cbbFilter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Hw3);
    } // setupUi

    void retranslateUi(QMainWindow *Hw3)
    {
        Hw3->setWindowTitle(QCoreApplication::translate("Hw3", "Hw3", nullptr));
        lblBanner1->setText(QCoreApplication::translate("Hw3", "Original Image", nullptr));
        lblPic1->setText(QString());
        btnOpen->setText(QCoreApplication::translate("Hw3", "Open file A", nullptr));
        lblBanner2->setText(QCoreApplication::translate("Hw3", "Filtered Image", nullptr));
        lblPic2->setText(QString());
        lblTime->setText(QCoreApplication::translate("Hw3", "Time elapsed:", nullptr));
        lblKernelSizen->setText(QCoreApplication::translate("Hw3", "Kernel Size n", nullptr));
        lblKernelSizem->setText(QCoreApplication::translate("Hw3", "Kernel Size m", nullptr));
        btnExecute->setText(QCoreApplication::translate("Hw3", "Execute", nullptr));
        lblGaussianSigma->setText(QCoreApplication::translate("Hw3", "Gaussian Std", nullptr));
        lblGaussianK->setText(QCoreApplication::translate("Hw3", "Gaussian Scale", nullptr));
        ckbGaussainNormalize->setText(QCoreApplication::translate("Hw3", "Normalization", nullptr));
        cbbFilter->setItemText(0, QCoreApplication::translate("Hw3", "Gaussian Filter", nullptr));
        cbbFilter->setItemText(1, QCoreApplication::translate("Hw3", "Box Filter", nullptr));
        cbbFilter->setItemText(2, QCoreApplication::translate("Hw3", "Sobel Horizontal FIlter", nullptr));
        cbbFilter->setItemText(3, QCoreApplication::translate("Hw3", "Sobel Vertical Filter", nullptr));
        cbbFilter->setItemText(4, QCoreApplication::translate("Hw3", "Laplacian Half FIlter", nullptr));
        cbbFilter->setItemText(5, QCoreApplication::translate("Hw3", "Laplacian Full FIlter", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Hw3", "Filtering", nullptr));
        lblGaussianSigma_2->setText(QCoreApplication::translate("Hw3", "Gaussian Std", nullptr));
        lblZeroCrossingThreshold->setText(QCoreApplication::translate("Hw3", "Zero-crossing Threshold", nullptr));
        lblKernelSizem_2->setText(QCoreApplication::translate("Hw3", "Kernel Size m", nullptr));
        lblTime_3->setText(QCoreApplication::translate("Hw3", "Time elapsed:", nullptr));
        lblMH->setText(QCoreApplication::translate("Hw3", "The Marr-Hildreth edge detection method", nullptr));
        lblKernelSizen_2->setText(QCoreApplication::translate("Hw3", "Kernel Size n", nullptr));
        btnLoG->setText(QCoreApplication::translate("Hw3", "Execute", nullptr));
        btnSobel->setText(QCoreApplication::translate("Hw3", "Execute", nullptr));
        lblSobel->setText(QCoreApplication::translate("Hw3", "Sobel vertical+horizontal", nullptr));
        lblTime_4->setText(QCoreApplication::translate("Hw3", "Time elapsed:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Hw3", "Edge Detection", nullptr));
        lblKernelSizem_3->setText(QCoreApplication::translate("Hw3", "Kernel Size m", nullptr));
        lblKernelSizen_3->setText(QCoreApplication::translate("Hw3", "Kernel Size n", nullptr));
        label->setText(QCoreApplication::translate("Hw3", "Order-statistic filter", nullptr));
        rbnMedian->setText(QCoreApplication::translate("Hw3", "Median", nullptr));
        rbnMax->setText(QCoreApplication::translate("Hw3", "Max", nullptr));
        rbnMin->setText(QCoreApplication::translate("Hw3", "Min", nullptr));
        btnOrderStatisticsExecute->setText(QCoreApplication::translate("Hw3", "Execute", nullptr));
        lblTime_2->setText(QCoreApplication::translate("Hw3", "Time elapsed:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Hw3", "Order-statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hw3: public Ui_Hw3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW3_H
