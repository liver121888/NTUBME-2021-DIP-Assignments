/********************************************************************************
** Form generated from reading UI file 'hw2.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW2_H
#define UI_HW2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hw2
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *lblPicA;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btnMono1;
    QPushButton *btnMono2;
    QWidget *widget_2;
    QLabel *lblThresh;
    QSlider *hsdThresh;
    QPushButton *btnThresh;
    QWidget *widget_3;
    QSlider *hsdLevel;
    QLabel *lblLevel;
    QPushButton *btnLevel;
    QPushButton *btnSubtract;
    QWidget *widget_6;
    QSlider *hsdResolution;
    QLabel *lblResolution;
    QPushButton *btnResolution;
    QWidget *tab_2;
    QWidget *widget_4;
    QSlider *hsdBrightness;
    QPushButton *btnBrightness;
    QLabel *lblBrightness;
    QWidget *widget_5;
    QPushButton *btnContrast;
    QSlider *hsdContrast;
    QLabel *lblContrast;
    QWidget *widget_7;
    QPushButton *btnHistoEqualize;
    QPushButton *btnOpenA;
    QLabel *lblPicA_3;
    QLabel *lblPicA_2;
    QLabel *lblPicA_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *lyt1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *lyt2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *lyt3;
    QMenuBar *menubar;
    QMenu *menuAction;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *hw2)
    {
        if (hw2->objectName().isEmpty())
            hw2->setObjectName(QString::fromUtf8("hw2"));
        hw2->resize(1920, 888);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hw2->sizePolicy().hasHeightForWidth());
        hw2->setSizePolicy(sizePolicy);
        actionExit = new QAction(hw2);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(hw2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 331, 801));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));
        lblPicA = new QLabel(widget);
        lblPicA->setObjectName(QString::fromUtf8("lblPicA"));
        lblPicA->setGeometry(QRect(40, 10, 256, 256));
        lblPicA->setAutoFillBackground(false);
        lblPicA->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(false);
        tabWidget->setGeometry(QRect(40, 320, 251, 461));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        btnMono1 = new QPushButton(tab);
        btnMono1->setObjectName(QString::fromUtf8("btnMono1"));
        btnMono1->setGeometry(QRect(10, 10, 80, 24));
        btnMono2 = new QPushButton(tab);
        btnMono2->setObjectName(QString::fromUtf8("btnMono2"));
        btnMono2->setGeometry(QRect(10, 50, 80, 24));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 90, 211, 111));
        lblThresh = new QLabel(widget_2);
        lblThresh->setObjectName(QString::fromUtf8("lblThresh"));
        lblThresh->setGeometry(QRect(20, 50, 91, 16));
        hsdThresh = new QSlider(widget_2);
        hsdThresh->setObjectName(QString::fromUtf8("hsdThresh"));
        hsdThresh->setGeometry(QRect(20, 20, 160, 22));
        hsdThresh->setMaximum(255);
        hsdThresh->setValue(125);
        hsdThresh->setSliderPosition(125);
        hsdThresh->setOrientation(Qt::Horizontal);
        btnThresh = new QPushButton(widget_2);
        btnThresh->setObjectName(QString::fromUtf8("btnThresh"));
        btnThresh->setGeometry(QRect(10, 80, 101, 23));
        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 210, 201, 101));
        hsdLevel = new QSlider(widget_3);
        hsdLevel->setObjectName(QString::fromUtf8("hsdLevel"));
        hsdLevel->setGeometry(QRect(20, 20, 160, 22));
        hsdLevel->setMinimum(2);
        hsdLevel->setMaximum(32);
        hsdLevel->setValue(17);
        hsdLevel->setOrientation(Qt::Horizontal);
        lblLevel = new QLabel(widget_3);
        lblLevel->setObjectName(QString::fromUtf8("lblLevel"));
        lblLevel->setGeometry(QRect(20, 50, 101, 16));
        btnLevel = new QPushButton(widget_3);
        btnLevel->setObjectName(QString::fromUtf8("btnLevel"));
        btnLevel->setGeometry(QRect(10, 70, 101, 23));
        btnSubtract = new QPushButton(tab);
        btnSubtract->setObjectName(QString::fromUtf8("btnSubtract"));
        btnSubtract->setGeometry(QRect(140, 30, 80, 24));
        widget_6 = new QWidget(tab);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(10, 320, 201, 101));
        hsdResolution = new QSlider(widget_6);
        hsdResolution->setObjectName(QString::fromUtf8("hsdResolution"));
        hsdResolution->setGeometry(QRect(20, 20, 160, 22));
        hsdResolution->setMinimum(25);
        hsdResolution->setMaximum(400);
        hsdResolution->setValue(100);
        hsdResolution->setOrientation(Qt::Horizontal);
        lblResolution = new QLabel(widget_6);
        lblResolution->setObjectName(QString::fromUtf8("lblResolution"));
        lblResolution->setGeometry(QRect(20, 50, 121, 16));
        btnResolution = new QPushButton(widget_6);
        btnResolution->setObjectName(QString::fromUtf8("btnResolution"));
        btnResolution->setGeometry(QRect(10, 70, 101, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(30, 20, 181, 111));
        hsdBrightness = new QSlider(widget_4);
        hsdBrightness->setObjectName(QString::fromUtf8("hsdBrightness"));
        hsdBrightness->setGeometry(QRect(10, 10, 160, 18));
        hsdBrightness->setMinimum(-255);
        hsdBrightness->setMaximum(255);
        hsdBrightness->setOrientation(Qt::Horizontal);
        btnBrightness = new QPushButton(widget_4);
        btnBrightness->setObjectName(QString::fromUtf8("btnBrightness"));
        btnBrightness->setGeometry(QRect(10, 70, 111, 24));
        lblBrightness = new QLabel(widget_4);
        lblBrightness->setObjectName(QString::fromUtf8("lblBrightness"));
        lblBrightness->setGeometry(QRect(20, 40, 131, 16));
        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(30, 150, 181, 121));
        btnContrast = new QPushButton(widget_5);
        btnContrast->setObjectName(QString::fromUtf8("btnContrast"));
        btnContrast->setGeometry(QRect(20, 80, 101, 24));
        hsdContrast = new QSlider(widget_5);
        hsdContrast->setObjectName(QString::fromUtf8("hsdContrast"));
        hsdContrast->setGeometry(QRect(10, 20, 160, 18));
        hsdContrast->setMinimum(-255);
        hsdContrast->setMaximum(255);
        hsdContrast->setOrientation(Qt::Horizontal);
        lblContrast = new QLabel(widget_5);
        lblContrast->setObjectName(QString::fromUtf8("lblContrast"));
        lblContrast->setGeometry(QRect(20, 50, 131, 16));
        widget_7 = new QWidget(tab_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(30, 280, 181, 61));
        btnHistoEqualize = new QPushButton(widget_7);
        btnHistoEqualize->setObjectName(QString::fromUtf8("btnHistoEqualize"));
        btnHistoEqualize->setGeometry(QRect(10, 20, 161, 24));
        tabWidget->addTab(tab_2, QString());
        btnOpenA = new QPushButton(widget);
        btnOpenA->setObjectName(QString::fromUtf8("btnOpenA"));
        btnOpenA->setGeometry(QRect(40, 280, 80, 24));
        lblPicA_3 = new QLabel(centralwidget);
        lblPicA_3->setObjectName(QString::fromUtf8("lblPicA_3"));
        lblPicA_3->setGeometry(QRect(370, 560, 256, 256));
        sizePolicy.setHeightForWidth(lblPicA_3->sizePolicy().hasHeightForWidth());
        lblPicA_3->setSizePolicy(sizePolicy);
        lblPicA_3->setAutoFillBackground(false);
        lblPicA_3->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        lblPicA_2 = new QLabel(centralwidget);
        lblPicA_2->setObjectName(QString::fromUtf8("lblPicA_2"));
        lblPicA_2->setGeometry(QRect(370, 290, 256, 256));
        lblPicA_2->setAutoFillBackground(false);
        lblPicA_2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        lblPicA_1 = new QLabel(centralwidget);
        lblPicA_1->setObjectName(QString::fromUtf8("lblPicA_1"));
        lblPicA_1->setGeometry(QRect(370, 20, 256, 256));
        lblPicA_1->setAutoFillBackground(false);
        lblPicA_1->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(680, 20, 811, 251));
        lyt1 = new QVBoxLayout(verticalLayoutWidget);
        lyt1->setSpacing(7);
        lyt1->setObjectName(QString::fromUtf8("lyt1"));
        lyt1->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(680, 290, 811, 251));
        lyt2 = new QVBoxLayout(verticalLayoutWidget_2);
        lyt2->setObjectName(QString::fromUtf8("lyt2"));
        lyt2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(680, 560, 811, 241));
        lyt3 = new QVBoxLayout(verticalLayoutWidget_3);
        lyt3->setObjectName(QString::fromUtf8("lyt3"));
        lyt3->setContentsMargins(0, 0, 0, 0);
        hw2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(hw2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 24));
        menuAction = new QMenu(menubar);
        menuAction->setObjectName(QString::fromUtf8("menuAction"));
        hw2->setMenuBar(menubar);
        statusbar = new QStatusBar(hw2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        hw2->setStatusBar(statusbar);

        menubar->addAction(menuAction->menuAction());
        menuAction->addAction(actionExit);

        retranslateUi(hw2);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(hw2);
    } // setupUi

    void retranslateUi(QMainWindow *hw2)
    {
        hw2->setWindowTitle(QCoreApplication::translate("hw2", "hw2", nullptr));
        actionExit->setText(QCoreApplication::translate("hw2", "Exit", nullptr));
        lblPicA->setText(QString());
        btnMono1->setText(QCoreApplication::translate("hw2", "Grey Scale1", nullptr));
        btnMono2->setText(QCoreApplication::translate("hw2", "Grey Scale2", nullptr));
        lblThresh->setText(QCoreApplication::translate("hw2", "Thresh", nullptr));
        btnThresh->setText(QCoreApplication::translate("hw2", "Set Threshold", nullptr));
        lblLevel->setText(QCoreApplication::translate("hw2", "Level", nullptr));
        btnLevel->setText(QCoreApplication::translate("hw2", "Set GreyLevel", nullptr));
        btnSubtract->setText(QCoreApplication::translate("hw2", "Subtraction", nullptr));
        lblResolution->setText(QCoreApplication::translate("hw2", "Resolution", nullptr));
        btnResolution->setText(QCoreApplication::translate("hw2", "Set Resolution", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("hw2", "Mono", nullptr));
        btnBrightness->setText(QCoreApplication::translate("hw2", "Set Brightness", nullptr));
        lblBrightness->setText(QCoreApplication::translate("hw2", "Brightness", nullptr));
        btnContrast->setText(QCoreApplication::translate("hw2", "Set Contrast", nullptr));
        lblContrast->setText(QCoreApplication::translate("hw2", "Contrast", nullptr));
        btnHistoEqualize->setText(QCoreApplication::translate("hw2", "Histogram Equalization", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("hw2", "Image Processing", nullptr));
        btnOpenA->setText(QCoreApplication::translate("hw2", "Open file A", nullptr));
        lblPicA_3->setText(QString());
        lblPicA_2->setText(QString());
        lblPicA_1->setText(QString());
        menuAction->setTitle(QCoreApplication::translate("hw2", "Action", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hw2: public Ui_hw2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW2_H
