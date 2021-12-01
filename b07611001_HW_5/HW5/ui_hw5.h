/********************************************************************************
** Form generated from reading UI file 'hw5.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW5_H
#define UI_HW5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HW5
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGraphicsView *grvNW_P1;
    QGraphicsView *grvNE_P1;
    QLabel *lblNE;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnOpen_P1;
    QPushButton *btnRGB;
    QPushButton *btnCMY;
    QPushButton *btnHSI;
    QPushButton *btnXYZ;
    QPushButton *btnLAB;
    QPushButton *btnYUV;
    QGraphicsView *grvSW_P1;
    QLabel *lblSE;
    QLabel *lblSW;
    QLabel *lblNW;
    QGraphicsView *grvSE_P1;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnCreateColorBar;
    QGraphicsView *grvColor1;
    QPushButton *btnColor3;
    QPushButton *btnColor4;
    QPushButton *btnColor1;
    QPushButton *btnDoPseudo;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *grvColor5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnColor2;
    QGraphicsView *grvColorBar;
    QLabel *lblGrayLevel;
    QSlider *hsdCheckColor;
    QGraphicsView *grvColor2;
    QPushButton *btnColor5;
    QGraphicsView *grvColor3;
    QGraphicsView *grvColor4;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *grvCheckedColor;
    QPushButton *btnOpen_P2;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QGraphicsView *grvA;
    QGraphicsView *grvB;
    QLabel *label_3;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_8;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *btnOpen_P3;
    QSpinBox *spbK;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rbnRGB;
    QRadioButton *rbnHSI;
    QRadioButton *rbnLAB;
    QPushButton *btnKmeans;
    QSpacerItem *verticalSpacer;
    QWidget *widget_7;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QLabel *label_5;
    QGraphicsView *grvSrcimg;
    QGraphicsView *grvMeanedimg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HW5)
    {
        if (HW5->objectName().isEmpty())
            HW5->setObjectName(QString::fromUtf8("HW5"));
        HW5->resize(1114, 806);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HW5->sizePolicy().hasHeightForWidth());
        HW5->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(HW5);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        grvNW_P1 = new QGraphicsView(tab);
        grvNW_P1->setObjectName(QString::fromUtf8("grvNW_P1"));
        grvNW_P1->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvNW_P1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvNW_P1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvNW_P1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvNW_P1, 1, 1, 1, 1);

        grvNE_P1 = new QGraphicsView(tab);
        grvNE_P1->setObjectName(QString::fromUtf8("grvNE_P1"));
        grvNE_P1->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvNE_P1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvNE_P1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvNE_P1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvNE_P1, 1, 2, 1, 1);

        lblNE = new QLabel(tab);
        lblNE->setObjectName(QString::fromUtf8("lblNE"));
        lblNE->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblNE, 0, 2, 1, 1);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnOpen_P1 = new QPushButton(widget_2);
        btnOpen_P1->setObjectName(QString::fromUtf8("btnOpen_P1"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnOpen_P1->sizePolicy().hasHeightForWidth());
        btnOpen_P1->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnOpen_P1);

        btnRGB = new QPushButton(widget_2);
        btnRGB->setObjectName(QString::fromUtf8("btnRGB"));
        btnRGB->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnRGB->sizePolicy().hasHeightForWidth());
        btnRGB->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnRGB);

        btnCMY = new QPushButton(widget_2);
        btnCMY->setObjectName(QString::fromUtf8("btnCMY"));
        btnCMY->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnCMY->sizePolicy().hasHeightForWidth());
        btnCMY->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnCMY);

        btnHSI = new QPushButton(widget_2);
        btnHSI->setObjectName(QString::fromUtf8("btnHSI"));
        btnHSI->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnHSI->sizePolicy().hasHeightForWidth());
        btnHSI->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnHSI);

        btnXYZ = new QPushButton(widget_2);
        btnXYZ->setObjectName(QString::fromUtf8("btnXYZ"));
        btnXYZ->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnXYZ->sizePolicy().hasHeightForWidth());
        btnXYZ->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnXYZ);

        btnLAB = new QPushButton(widget_2);
        btnLAB->setObjectName(QString::fromUtf8("btnLAB"));
        btnLAB->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnLAB->sizePolicy().hasHeightForWidth());
        btnLAB->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnLAB);

        btnYUV = new QPushButton(widget_2);
        btnYUV->setObjectName(QString::fromUtf8("btnYUV"));
        btnYUV->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnYUV->sizePolicy().hasHeightForWidth());
        btnYUV->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(btnYUV);


        gridLayout_3->addWidget(widget_2, 1, 0, 3, 1);

        grvSW_P1 = new QGraphicsView(tab);
        grvSW_P1->setObjectName(QString::fromUtf8("grvSW_P1"));
        grvSW_P1->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvSW_P1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvSW_P1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvSW_P1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvSW_P1, 3, 1, 1, 1);

        lblSE = new QLabel(tab);
        lblSE->setObjectName(QString::fromUtf8("lblSE"));
        lblSE->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblSE, 2, 2, 1, 1);

        lblSW = new QLabel(tab);
        lblSW->setObjectName(QString::fromUtf8("lblSW"));
        lblSW->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblSW, 2, 1, 1, 1);

        lblNW = new QLabel(tab);
        lblNW->setObjectName(QString::fromUtf8("lblNW"));
        lblNW->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblNW, 0, 1, 1, 1);

        grvSE_P1 = new QGraphicsView(tab);
        grvSE_P1->setObjectName(QString::fromUtf8("grvSE_P1"));
        grvSE_P1->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvSE_P1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvSE_P1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvSE_P1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvSE_P1, 3, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 8, 1, 1, 1);

        btnCreateColorBar = new QPushButton(widget_4);
        btnCreateColorBar->setObjectName(QString::fromUtf8("btnCreateColorBar"));
        btnCreateColorBar->setEnabled(false);
        sizePolicy.setHeightForWidth(btnCreateColorBar->sizePolicy().hasHeightForWidth());
        btnCreateColorBar->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnCreateColorBar, 4, 1, 1, 5);

        grvColor1 = new QGraphicsView(widget_4);
        grvColor1->setObjectName(QString::fromUtf8("grvColor1"));
        sizePolicy2.setHeightForWidth(grvColor1->sizePolicy().hasHeightForWidth());
        grvColor1->setSizePolicy(sizePolicy2);
        grvColor1->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvColor1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(grvColor1, 1, 1, 1, 1);

        btnColor3 = new QPushButton(widget_4);
        btnColor3->setObjectName(QString::fromUtf8("btnColor3"));
        btnColor3->setEnabled(false);
        sizePolicy.setHeightForWidth(btnColor3->sizePolicy().hasHeightForWidth());
        btnColor3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnColor3, 2, 3, 1, 1);

        btnColor4 = new QPushButton(widget_4);
        btnColor4->setObjectName(QString::fromUtf8("btnColor4"));
        btnColor4->setEnabled(false);
        sizePolicy.setHeightForWidth(btnColor4->sizePolicy().hasHeightForWidth());
        btnColor4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnColor4, 2, 4, 1, 1);

        btnColor1 = new QPushButton(widget_4);
        btnColor1->setObjectName(QString::fromUtf8("btnColor1"));
        btnColor1->setEnabled(false);
        sizePolicy.setHeightForWidth(btnColor1->sizePolicy().hasHeightForWidth());
        btnColor1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnColor1, 2, 1, 1, 1);

        btnDoPseudo = new QPushButton(widget_4);
        btnDoPseudo->setObjectName(QString::fromUtf8("btnDoPseudo"));
        btnDoPseudo->setEnabled(false);
        sizePolicy.setHeightForWidth(btnDoPseudo->sizePolicy().hasHeightForWidth());
        btnDoPseudo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnDoPseudo, 9, 1, 1, 4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 9, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 5, 1, 1);

        grvColor5 = new QGraphicsView(widget_4);
        grvColor5->setObjectName(QString::fromUtf8("grvColor5"));
        sizePolicy2.setHeightForWidth(grvColor5->sizePolicy().hasHeightForWidth());
        grvColor5->setSizePolicy(sizePolicy2);
        grvColor5->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvColor5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(grvColor5, 1, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 8, 4, 1, 2);

        btnColor2 = new QPushButton(widget_4);
        btnColor2->setObjectName(QString::fromUtf8("btnColor2"));
        btnColor2->setEnabled(false);
        sizePolicy.setHeightForWidth(btnColor2->sizePolicy().hasHeightForWidth());
        btnColor2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnColor2, 2, 2, 1, 1);

        grvColorBar = new QGraphicsView(widget_4);
        grvColorBar->setObjectName(QString::fromUtf8("grvColorBar"));
        sizePolicy2.setHeightForWidth(grvColorBar->sizePolicy().hasHeightForWidth());
        grvColorBar->setSizePolicy(sizePolicy2);
        grvColorBar->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvColorBar->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColorBar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColorBar->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(grvColorBar, 5, 1, 1, 4);

        lblGrayLevel = new QLabel(widget_4);
        lblGrayLevel->setObjectName(QString::fromUtf8("lblGrayLevel"));
        sizePolicy.setHeightForWidth(lblGrayLevel->sizePolicy().hasHeightForWidth());
        lblGrayLevel->setSizePolicy(sizePolicy);
        lblGrayLevel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblGrayLevel, 7, 1, 1, 4);

        hsdCheckColor = new QSlider(widget_4);
        hsdCheckColor->setObjectName(QString::fromUtf8("hsdCheckColor"));
        hsdCheckColor->setEnabled(false);
        sizePolicy.setHeightForWidth(hsdCheckColor->sizePolicy().hasHeightForWidth());
        hsdCheckColor->setSizePolicy(sizePolicy);
        hsdCheckColor->setMaximum(255);
        hsdCheckColor->setOrientation(Qt::Horizontal);
        hsdCheckColor->setTickPosition(QSlider::TicksBelow);
        hsdCheckColor->setTickInterval(5);

        gridLayout->addWidget(hsdCheckColor, 6, 1, 1, 4);

        grvColor2 = new QGraphicsView(widget_4);
        grvColor2->setObjectName(QString::fromUtf8("grvColor2"));
        sizePolicy2.setHeightForWidth(grvColor2->sizePolicy().hasHeightForWidth());
        grvColor2->setSizePolicy(sizePolicy2);
        grvColor2->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvColor2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(grvColor2, 1, 2, 1, 1);

        btnColor5 = new QPushButton(widget_4);
        btnColor5->setObjectName(QString::fromUtf8("btnColor5"));
        btnColor5->setEnabled(false);
        sizePolicy.setHeightForWidth(btnColor5->sizePolicy().hasHeightForWidth());
        btnColor5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnColor5, 2, 5, 1, 1);

        grvColor3 = new QGraphicsView(widget_4);
        grvColor3->setObjectName(QString::fromUtf8("grvColor3"));
        sizePolicy2.setHeightForWidth(grvColor3->sizePolicy().hasHeightForWidth());
        grvColor3->setSizePolicy(sizePolicy2);
        grvColor3->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvColor3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(grvColor3, 1, 3, 1, 1);

        grvColor4 = new QGraphicsView(widget_4);
        grvColor4->setObjectName(QString::fromUtf8("grvColor4"));
        sizePolicy2.setHeightForWidth(grvColor4->sizePolicy().hasHeightForWidth());
        grvColor4->setSizePolicy(sizePolicy2);
        grvColor4->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvColor4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvColor4->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(grvColor4, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 5, 1, 1);

        grvCheckedColor = new QGraphicsView(widget_4);
        grvCheckedColor->setObjectName(QString::fromUtf8("grvCheckedColor"));
        sizePolicy.setHeightForWidth(grvCheckedColor->sizePolicy().hasHeightForWidth());
        grvCheckedColor->setSizePolicy(sizePolicy);
        grvCheckedColor->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvCheckedColor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvCheckedColor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvCheckedColor->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(grvCheckedColor, 8, 2, 1, 2);

        btnOpen_P2 = new QPushButton(widget_4);
        btnOpen_P2->setObjectName(QString::fromUtf8("btnOpen_P2"));
        sizePolicy.setHeightForWidth(btnOpen_P2->sizePolicy().hasHeightForWidth());
        btnOpen_P2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnOpen_P2, 0, 1, 1, 5);


        horizontalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(4);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy4);
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        grvA = new QGraphicsView(widget_5);
        grvA->setObjectName(QString::fromUtf8("grvA"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(grvA->sizePolicy().hasHeightForWidth());
        grvA->setSizePolicy(sizePolicy6);
        grvA->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(grvA, 2, 0, 1, 1);

        grvB = new QGraphicsView(widget_5);
        grvB->setObjectName(QString::fromUtf8("grvB"));
        sizePolicy6.setHeightForWidth(grvB->sizePolicy().hasHeightForWidth());
        grvB->setSizePolicy(sizePolicy6);
        grvB->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvB->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(grvB, 2, 1, 1, 1);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(widget_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_6 = new QHBoxLayout(tab_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_8 = new QWidget(tab_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        sizePolicy3.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy3);
        gridLayout_2 = new QGridLayout(widget_8);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(widget_8);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy7);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        btnOpen_P3 = new QPushButton(widget_8);
        btnOpen_P3->setObjectName(QString::fromUtf8("btnOpen_P3"));

        gridLayout_2->addWidget(btnOpen_P3, 0, 0, 1, 3);

        spbK = new QSpinBox(widget_8);
        spbK->setObjectName(QString::fromUtf8("spbK"));
        spbK->setEnabled(false);
        sizePolicy5.setHeightForWidth(spbK->sizePolicy().hasHeightForWidth());
        spbK->setSizePolicy(sizePolicy5);
        spbK->setMinimum(1);
        spbK->setValue(2);

        gridLayout_2->addWidget(spbK, 1, 1, 1, 1);

        widget_3 = new QWidget(widget_8);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setEnabled(false);
        sizePolicy6.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy6);
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        rbnRGB = new QRadioButton(widget_3);
        rbnRGB->setObjectName(QString::fromUtf8("rbnRGB"));

        verticalLayout_4->addWidget(rbnRGB);

        rbnHSI = new QRadioButton(widget_3);
        rbnHSI->setObjectName(QString::fromUtf8("rbnHSI"));

        verticalLayout_4->addWidget(rbnHSI);

        rbnLAB = new QRadioButton(widget_3);
        rbnLAB->setObjectName(QString::fromUtf8("rbnLAB"));

        verticalLayout_4->addWidget(rbnLAB);


        gridLayout_2->addWidget(widget_3, 2, 0, 1, 2);

        btnKmeans = new QPushButton(widget_8);
        btnKmeans->setObjectName(QString::fromUtf8("btnKmeans"));
        btnKmeans->setEnabled(false);

        gridLayout_2->addWidget(btnKmeans, 3, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 2);


        horizontalLayout_5->addWidget(widget_8);

        widget_7 = new QWidget(tab_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(2);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy8);
        gridLayout_5 = new QGridLayout(widget_7);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_5, 0, 1, 1, 1);

        grvSrcimg = new QGraphicsView(widget_7);
        grvSrcimg->setObjectName(QString::fromUtf8("grvSrcimg"));
        sizePolicy3.setHeightForWidth(grvSrcimg->sizePolicy().hasHeightForWidth());
        grvSrcimg->setSizePolicy(sizePolicy3);
        grvSrcimg->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvSrcimg->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvSrcimg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvSrcimg->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout_5->addWidget(grvSrcimg, 1, 0, 1, 1);

        grvMeanedimg = new QGraphicsView(widget_7);
        grvMeanedimg->setObjectName(QString::fromUtf8("grvMeanedimg"));
        sizePolicy3.setHeightForWidth(grvMeanedimg->sizePolicy().hasHeightForWidth());
        grvMeanedimg->setSizePolicy(sizePolicy3);
        grvMeanedimg->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvMeanedimg->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvMeanedimg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvMeanedimg->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout_5->addWidget(grvMeanedimg, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(widget_7);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        HW5->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HW5);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1114, 25));
        HW5->setMenuBar(menubar);
        statusbar = new QStatusBar(HW5);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HW5->setStatusBar(statusbar);

        retranslateUi(HW5);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HW5);
    } // setupUi

    void retranslateUi(QMainWindow *HW5)
    {
        HW5->setWindowTitle(QCoreApplication::translate("HW5", "HW5", nullptr));
        lblNE->setText(QString());
        btnOpen_P1->setText(QCoreApplication::translate("HW5", "Open", nullptr));
        btnRGB->setText(QCoreApplication::translate("HW5", "RGB", nullptr));
        btnCMY->setText(QCoreApplication::translate("HW5", "CMY", nullptr));
        btnHSI->setText(QCoreApplication::translate("HW5", "HSI", nullptr));
        btnXYZ->setText(QCoreApplication::translate("HW5", "XYZ", nullptr));
        btnLAB->setText(QCoreApplication::translate("HW5", "L*a*b*", nullptr));
        btnYUV->setText(QCoreApplication::translate("HW5", "YUV", nullptr));
        lblSE->setText(QString());
        lblSW->setText(QString());
        lblNW->setText(QCoreApplication::translate("HW5", "Original Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("HW5", "Color Model Conversion", nullptr));
        btnCreateColorBar->setText(QCoreApplication::translate("HW5", "Create Color Bar", nullptr));
        btnColor3->setText(QCoreApplication::translate("HW5", "Color3", nullptr));
        btnColor4->setText(QCoreApplication::translate("HW5", "Color4", nullptr));
        btnColor1->setText(QCoreApplication::translate("HW5", "Color1", nullptr));
        btnDoPseudo->setText(QCoreApplication::translate("HW5", "Get Pseudo-color Image", nullptr));
        btnColor2->setText(QCoreApplication::translate("HW5", "Color2", nullptr));
        lblGrayLevel->setText(QCoreApplication::translate("HW5", "Gray Scale: ", nullptr));
        btnColor5->setText(QCoreApplication::translate("HW5", "Color5", nullptr));
        btnOpen_P2->setText(QCoreApplication::translate("HW5", "Open", nullptr));
        label_2->setText(QCoreApplication::translate("HW5", "Original Image", nullptr));
        label_3->setText(QCoreApplication::translate("HW5", "Pseudo-color Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("HW5", "Pseudo-color Image", nullptr));
        label->setText(QCoreApplication::translate("HW5", "K value:", nullptr));
        btnOpen_P3->setText(QCoreApplication::translate("HW5", "Open", nullptr));
        rbnRGB->setText(QCoreApplication::translate("HW5", "RGB", nullptr));
        rbnHSI->setText(QCoreApplication::translate("HW5", "HSI", nullptr));
        rbnLAB->setText(QCoreApplication::translate("HW5", "L*a*b*", nullptr));
        btnKmeans->setText(QCoreApplication::translate("HW5", "Color Segmentation", nullptr));
        label_4->setText(QCoreApplication::translate("HW5", "Original Image", nullptr));
        label_5->setText(QCoreApplication::translate("HW5", "Segemented Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("HW5", "Color Segmentation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HW5: public Ui_HW5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW5_H
