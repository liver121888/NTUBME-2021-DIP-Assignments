/********************************************************************************
** Form generated from reading UI file 'steganographyproject.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEGANOGRAPHYPROJECT_H
#define UI_STEGANOGRAPHYPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SteganographyProject
{
public:
    QAction *actionOpen_FIle;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btnLSBStegoOpen;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblLSBMessage;
    QPlainTextEdit *pteLSB;
    QLabel *lblLSBKey;
    QLineEdit *ldtLSBKey;
    QLabel *lblLSBIV;
    QLineEdit *ldtLSBIV;
    QLabel *lblLSBHexLength;
    QPushButton *btnLSBStegoExecute;
    QPushButton *btnLSBStegoExport;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QGraphicsView *grvStegoLSB0;
    QGraphicsView *grvLSBOri;
    QGraphicsView *grvOriLSB0;
    QLabel *label_3;
    QGraphicsView *grvLSBStego;
    QLabel *label_4;
    QLabel *label_6;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnDCTStegoOpen;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblDCTMessage;
    QPlainTextEdit *pteDCT;
    QLabel *lblDCTKey;
    QLineEdit *ldtDCTKey;
    QLabel *lblDCTIV;
    QLineEdit *ldtDCTIV;
    QLabel *lblDCTHexLength;
    QPushButton *btnDCTStegoExecute;
    QPushButton *btnDCTStegoExport;
    QGridLayout *gridLayout_2;
    QLabel *label_17;
    QLabel *label_15;
    QGraphicsView *grvDCTStego;
    QLabel *label_16;
    QGraphicsView *grvDCTOriSpect;
    QLabel *label_14;
    QGraphicsView *grvDCTStegoSpect;
    QGraphicsView *grvDCTOri;
    QWidget *tab_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnDCTStegoOpen_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblDCTMessage_2;
    QPlainTextEdit *pteDCT_2;
    QLabel *lblDCTKey_2;
    QLineEdit *ldtDCTKey_2;
    QLabel *lblDCTIV_2;
    QLineEdit *ldtDCTIV_2;
    QLabel *lblDCTHexLength_2;
    QPushButton *btnDCTStegoExecute_2;
    QPushButton *btnDCTStegoExport_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QLabel *label_21;
    QGraphicsView *grvDCTStego_2;
    QLabel *label_22;
    QGraphicsView *grvDCTOriSpect_2;
    QLabel *label_23;
    QGraphicsView *grvDCTStegoSpect_2;
    QGraphicsView *grvDCTOri_2;
    QWidget *tab_5;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnStegoDetectOpen;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *rbnLSB;
    QRadioButton *rbnDCT;
    QRadioButton *rbnDFT;
    QLabel *label_19;
    QLineEdit *ldtKeyDecrypt;
    QLabel *label_20;
    QLineEdit *ldtIVDecrypt;
    QPushButton *btnStegoDecrypt;
    QLabel *label_2;
    QPlainTextEdit *pteDecrypt;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_7;
    QGraphicsView *grvMainStegoDetect;
    QGraphicsView *grvStegoDetectHist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SteganographyProject)
    {
        if (SteganographyProject->objectName().isEmpty())
            SteganographyProject->setObjectName(QString::fromUtf8("SteganographyProject"));
        SteganographyProject->resize(908, 647);
        actionOpen_FIle = new QAction(SteganographyProject);
        actionOpen_FIle->setObjectName(QString::fromUtf8("actionOpen_FIle"));
        centralwidget = new QWidget(SteganographyProject);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnLSBStegoOpen = new QPushButton(tab);
        btnLSBStegoOpen->setObjectName(QString::fromUtf8("btnLSBStegoOpen"));

        verticalLayout->addWidget(btnLSBStegoOpen);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblLSBMessage = new QLabel(widget_2);
        lblLSBMessage->setObjectName(QString::fromUtf8("lblLSBMessage"));
        lblLSBMessage->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblLSBMessage->sizePolicy().hasHeightForWidth());
        lblLSBMessage->setSizePolicy(sizePolicy1);
        lblLSBMessage->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblLSBMessage);

        pteLSB = new QPlainTextEdit(widget_2);
        pteLSB->setObjectName(QString::fromUtf8("pteLSB"));
        pteLSB->setEnabled(false);
        sizePolicy.setHeightForWidth(pteLSB->sizePolicy().hasHeightForWidth());
        pteLSB->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pteLSB);


        verticalLayout->addWidget(widget_2);

        lblLSBKey = new QLabel(tab);
        lblLSBKey->setObjectName(QString::fromUtf8("lblLSBKey"));
        lblLSBKey->setEnabled(false);

        verticalLayout->addWidget(lblLSBKey);

        ldtLSBKey = new QLineEdit(tab);
        ldtLSBKey->setObjectName(QString::fromUtf8("ldtLSBKey"));
        ldtLSBKey->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ldtLSBKey->sizePolicy().hasHeightForWidth());
        ldtLSBKey->setSizePolicy(sizePolicy2);
        ldtLSBKey->setMaxLength(16);

        verticalLayout->addWidget(ldtLSBKey);

        lblLSBIV = new QLabel(tab);
        lblLSBIV->setObjectName(QString::fromUtf8("lblLSBIV"));
        lblLSBIV->setEnabled(false);

        verticalLayout->addWidget(lblLSBIV);

        ldtLSBIV = new QLineEdit(tab);
        ldtLSBIV->setObjectName(QString::fromUtf8("ldtLSBIV"));
        ldtLSBIV->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ldtLSBIV->sizePolicy().hasHeightForWidth());
        ldtLSBIV->setSizePolicy(sizePolicy3);
        ldtLSBIV->setMaxLength(16);

        verticalLayout->addWidget(ldtLSBIV);

        lblLSBHexLength = new QLabel(tab);
        lblLSBHexLength->setObjectName(QString::fromUtf8("lblLSBHexLength"));
        lblLSBHexLength->setEnabled(false);

        verticalLayout->addWidget(lblLSBHexLength);

        btnLSBStegoExecute = new QPushButton(tab);
        btnLSBStegoExecute->setObjectName(QString::fromUtf8("btnLSBStegoExecute"));
        btnLSBStegoExecute->setEnabled(false);

        verticalLayout->addWidget(btnLSBStegoExecute);

        btnLSBStegoExport = new QPushButton(tab);
        btnLSBStegoExport->setObjectName(QString::fromUtf8("btnLSBStegoExport"));
        btnLSBStegoExport->setEnabled(false);

        verticalLayout->addWidget(btnLSBStegoExport);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        grvStegoLSB0 = new QGraphicsView(tab);
        grvStegoLSB0->setObjectName(QString::fromUtf8("grvStegoLSB0"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(grvStegoLSB0->sizePolicy().hasHeightForWidth());
        grvStegoLSB0->setSizePolicy(sizePolicy4);
        grvStegoLSB0->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvStegoLSB0->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvStegoLSB0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvStegoLSB0->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(grvStegoLSB0, 6, 1, 1, 1);

        grvLSBOri = new QGraphicsView(tab);
        grvLSBOri->setObjectName(QString::fromUtf8("grvLSBOri"));
        sizePolicy4.setHeightForWidth(grvLSBOri->sizePolicy().hasHeightForWidth());
        grvLSBOri->setSizePolicy(sizePolicy4);
        grvLSBOri->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvLSBOri->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvLSBOri->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvLSBOri->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(grvLSBOri, 2, 0, 1, 1);

        grvOriLSB0 = new QGraphicsView(tab);
        grvOriLSB0->setObjectName(QString::fromUtf8("grvOriLSB0"));
        sizePolicy4.setHeightForWidth(grvOriLSB0->sizePolicy().hasHeightForWidth());
        grvOriLSB0->setSizePolicy(sizePolicy4);
        grvOriLSB0->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvOriLSB0->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvOriLSB0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvOriLSB0->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(grvOriLSB0, 2, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        grvLSBStego = new QGraphicsView(tab);
        grvLSBStego->setObjectName(QString::fromUtf8("grvLSBStego"));
        sizePolicy4.setHeightForWidth(grvLSBStego->sizePolicy().hasHeightForWidth());
        grvLSBStego->setSizePolicy(sizePolicy4);
        grvLSBStego->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvLSBStego->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvLSBStego->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvLSBStego->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(grvLSBStego, 6, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnDCTStegoOpen = new QPushButton(tab_2);
        btnDCTStegoOpen->setObjectName(QString::fromUtf8("btnDCTStegoOpen"));

        verticalLayout_4->addWidget(btnDCTStegoOpen);

        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lblDCTMessage = new QLabel(widget_3);
        lblDCTMessage->setObjectName(QString::fromUtf8("lblDCTMessage"));
        lblDCTMessage->setEnabled(false);
        sizePolicy1.setHeightForWidth(lblDCTMessage->sizePolicy().hasHeightForWidth());
        lblDCTMessage->setSizePolicy(sizePolicy1);
        lblDCTMessage->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblDCTMessage);

        pteDCT = new QPlainTextEdit(widget_3);
        pteDCT->setObjectName(QString::fromUtf8("pteDCT"));
        pteDCT->setEnabled(false);
        sizePolicy.setHeightForWidth(pteDCT->sizePolicy().hasHeightForWidth());
        pteDCT->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pteDCT);


        verticalLayout_4->addWidget(widget_3);

        lblDCTKey = new QLabel(tab_2);
        lblDCTKey->setObjectName(QString::fromUtf8("lblDCTKey"));
        lblDCTKey->setEnabled(false);

        verticalLayout_4->addWidget(lblDCTKey);

        ldtDCTKey = new QLineEdit(tab_2);
        ldtDCTKey->setObjectName(QString::fromUtf8("ldtDCTKey"));
        ldtDCTKey->setEnabled(false);
        sizePolicy2.setHeightForWidth(ldtDCTKey->sizePolicy().hasHeightForWidth());
        ldtDCTKey->setSizePolicy(sizePolicy2);
        ldtDCTKey->setMaxLength(16);

        verticalLayout_4->addWidget(ldtDCTKey);

        lblDCTIV = new QLabel(tab_2);
        lblDCTIV->setObjectName(QString::fromUtf8("lblDCTIV"));
        lblDCTIV->setEnabled(false);

        verticalLayout_4->addWidget(lblDCTIV);

        ldtDCTIV = new QLineEdit(tab_2);
        ldtDCTIV->setObjectName(QString::fromUtf8("ldtDCTIV"));
        ldtDCTIV->setEnabled(false);
        sizePolicy3.setHeightForWidth(ldtDCTIV->sizePolicy().hasHeightForWidth());
        ldtDCTIV->setSizePolicy(sizePolicy3);
        ldtDCTIV->setMaxLength(16);

        verticalLayout_4->addWidget(ldtDCTIV);

        lblDCTHexLength = new QLabel(tab_2);
        lblDCTHexLength->setObjectName(QString::fromUtf8("lblDCTHexLength"));
        lblDCTHexLength->setEnabled(false);

        verticalLayout_4->addWidget(lblDCTHexLength);

        btnDCTStegoExecute = new QPushButton(tab_2);
        btnDCTStegoExecute->setObjectName(QString::fromUtf8("btnDCTStegoExecute"));
        btnDCTStegoExecute->setEnabled(false);

        verticalLayout_4->addWidget(btnDCTStegoExecute);

        btnDCTStegoExport = new QPushButton(tab_2);
        btnDCTStegoExport->setObjectName(QString::fromUtf8("btnDCTStegoExport"));
        btnDCTStegoExport->setEnabled(false);

        verticalLayout_4->addWidget(btnDCTStegoExport);


        horizontalLayout_3->addLayout(verticalLayout_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_17, 0, 1, 1, 1);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        grvDCTStego = new QGraphicsView(tab_2);
        grvDCTStego->setObjectName(QString::fromUtf8("grvDCTStego"));
        sizePolicy4.setHeightForWidth(grvDCTStego->sizePolicy().hasHeightForWidth());
        grvDCTStego->setSizePolicy(sizePolicy4);
        grvDCTStego->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTStego->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStego->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStego->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDCTStego, 3, 0, 1, 1);

        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_16, 2, 1, 1, 1);

        grvDCTOriSpect = new QGraphicsView(tab_2);
        grvDCTOriSpect->setObjectName(QString::fromUtf8("grvDCTOriSpect"));
        sizePolicy4.setHeightForWidth(grvDCTOriSpect->sizePolicy().hasHeightForWidth());
        grvDCTOriSpect->setSizePolicy(sizePolicy4);
        grvDCTOriSpect->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTOriSpect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOriSpect->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOriSpect->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDCTOriSpect, 1, 1, 1, 1);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        grvDCTStegoSpect = new QGraphicsView(tab_2);
        grvDCTStegoSpect->setObjectName(QString::fromUtf8("grvDCTStegoSpect"));
        sizePolicy4.setHeightForWidth(grvDCTStegoSpect->sizePolicy().hasHeightForWidth());
        grvDCTStegoSpect->setSizePolicy(sizePolicy4);
        grvDCTStegoSpect->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTStegoSpect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStegoSpect->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStegoSpect->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDCTStegoSpect, 3, 1, 1, 1);

        grvDCTOri = new QGraphicsView(tab_2);
        grvDCTOri->setObjectName(QString::fromUtf8("grvDCTOri"));
        sizePolicy4.setHeightForWidth(grvDCTOri->sizePolicy().hasHeightForWidth());
        grvDCTOri->setSizePolicy(sizePolicy4);
        grvDCTOri->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTOri->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOri->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOri->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDCTOri, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 280, 459));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnDCTStegoOpen_2 = new QPushButton(layoutWidget);
        btnDCTStegoOpen_2->setObjectName(QString::fromUtf8("btnDCTStegoOpen_2"));

        verticalLayout_5->addWidget(btnDCTStegoOpen_2);

        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lblDCTMessage_2 = new QLabel(widget_4);
        lblDCTMessage_2->setObjectName(QString::fromUtf8("lblDCTMessage_2"));
        lblDCTMessage_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(lblDCTMessage_2->sizePolicy().hasHeightForWidth());
        lblDCTMessage_2->setSizePolicy(sizePolicy1);
        lblDCTMessage_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lblDCTMessage_2);

        pteDCT_2 = new QPlainTextEdit(widget_4);
        pteDCT_2->setObjectName(QString::fromUtf8("pteDCT_2"));
        pteDCT_2->setEnabled(false);
        sizePolicy.setHeightForWidth(pteDCT_2->sizePolicy().hasHeightForWidth());
        pteDCT_2->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(pteDCT_2);


        verticalLayout_5->addWidget(widget_4);

        lblDCTKey_2 = new QLabel(layoutWidget);
        lblDCTKey_2->setObjectName(QString::fromUtf8("lblDCTKey_2"));
        lblDCTKey_2->setEnabled(false);

        verticalLayout_5->addWidget(lblDCTKey_2);

        ldtDCTKey_2 = new QLineEdit(layoutWidget);
        ldtDCTKey_2->setObjectName(QString::fromUtf8("ldtDCTKey_2"));
        ldtDCTKey_2->setEnabled(false);
        sizePolicy2.setHeightForWidth(ldtDCTKey_2->sizePolicy().hasHeightForWidth());
        ldtDCTKey_2->setSizePolicy(sizePolicy2);
        ldtDCTKey_2->setMaxLength(16);

        verticalLayout_5->addWidget(ldtDCTKey_2);

        lblDCTIV_2 = new QLabel(layoutWidget);
        lblDCTIV_2->setObjectName(QString::fromUtf8("lblDCTIV_2"));
        lblDCTIV_2->setEnabled(false);

        verticalLayout_5->addWidget(lblDCTIV_2);

        ldtDCTIV_2 = new QLineEdit(layoutWidget);
        ldtDCTIV_2->setObjectName(QString::fromUtf8("ldtDCTIV_2"));
        ldtDCTIV_2->setEnabled(false);
        sizePolicy3.setHeightForWidth(ldtDCTIV_2->sizePolicy().hasHeightForWidth());
        ldtDCTIV_2->setSizePolicy(sizePolicy3);
        ldtDCTIV_2->setMaxLength(16);

        verticalLayout_5->addWidget(ldtDCTIV_2);

        lblDCTHexLength_2 = new QLabel(layoutWidget);
        lblDCTHexLength_2->setObjectName(QString::fromUtf8("lblDCTHexLength_2"));
        lblDCTHexLength_2->setEnabled(false);

        verticalLayout_5->addWidget(lblDCTHexLength_2);

        btnDCTStegoExecute_2 = new QPushButton(layoutWidget);
        btnDCTStegoExecute_2->setObjectName(QString::fromUtf8("btnDCTStegoExecute_2"));
        btnDCTStegoExecute_2->setEnabled(false);

        verticalLayout_5->addWidget(btnDCTStegoExecute_2);

        btnDCTStegoExport_2 = new QPushButton(layoutWidget);
        btnDCTStegoExport_2->setObjectName(QString::fromUtf8("btnDCTStegoExport_2"));
        btnDCTStegoExport_2->setEnabled(false);

        verticalLayout_5->addWidget(btnDCTStegoExport_2);

        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(342, 52, 521, 451));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 1, 1, 1);

        label_21 = new QLabel(layoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_21, 2, 0, 1, 1);

        grvDCTStego_2 = new QGraphicsView(layoutWidget_2);
        grvDCTStego_2->setObjectName(QString::fromUtf8("grvDCTStego_2"));
        sizePolicy4.setHeightForWidth(grvDCTStego_2->sizePolicy().hasHeightForWidth());
        grvDCTStego_2->setSizePolicy(sizePolicy4);
        grvDCTStego_2->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTStego_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStego_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStego_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvDCTStego_2, 3, 0, 1, 1);

        label_22 = new QLabel(layoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_22, 2, 1, 1, 1);

        grvDCTOriSpect_2 = new QGraphicsView(layoutWidget_2);
        grvDCTOriSpect_2->setObjectName(QString::fromUtf8("grvDCTOriSpect_2"));
        sizePolicy4.setHeightForWidth(grvDCTOriSpect_2->sizePolicy().hasHeightForWidth());
        grvDCTOriSpect_2->setSizePolicy(sizePolicy4);
        grvDCTOriSpect_2->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTOriSpect_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOriSpect_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOriSpect_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvDCTOriSpect_2, 1, 1, 1, 1);

        label_23 = new QLabel(layoutWidget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_23, 0, 0, 1, 1);

        grvDCTStegoSpect_2 = new QGraphicsView(layoutWidget_2);
        grvDCTStegoSpect_2->setObjectName(QString::fromUtf8("grvDCTStegoSpect_2"));
        sizePolicy4.setHeightForWidth(grvDCTStegoSpect_2->sizePolicy().hasHeightForWidth());
        grvDCTStegoSpect_2->setSizePolicy(sizePolicy4);
        grvDCTStegoSpect_2->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTStegoSpect_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStegoSpect_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTStegoSpect_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvDCTStegoSpect_2, 3, 1, 1, 1);

        grvDCTOri_2 = new QGraphicsView(layoutWidget_2);
        grvDCTOri_2->setObjectName(QString::fromUtf8("grvDCTOri_2"));
        sizePolicy4.setHeightForWidth(grvDCTOri_2->sizePolicy().hasHeightForWidth());
        grvDCTOri_2->setSizePolicy(sizePolicy4);
        grvDCTOri_2->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDCTOri_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOri_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDCTOri_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_3->addWidget(grvDCTOri_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_4 = new QHBoxLayout(tab_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        btnStegoDetectOpen = new QPushButton(tab_4);
        btnStegoDetectOpen->setObjectName(QString::fromUtf8("btnStegoDetectOpen"));
        sizePolicy3.setHeightForWidth(btnStegoDetectOpen->sizePolicy().hasHeightForWidth());
        btnStegoDetectOpen->setSizePolicy(sizePolicy3);

        verticalLayout_8->addWidget(btnStegoDetectOpen);

        widget = new QWidget(tab_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        rbnLSB = new QRadioButton(widget);
        rbnLSB->setObjectName(QString::fromUtf8("rbnLSB"));

        verticalLayout_7->addWidget(rbnLSB);

        rbnDCT = new QRadioButton(widget);
        rbnDCT->setObjectName(QString::fromUtf8("rbnDCT"));

        verticalLayout_7->addWidget(rbnDCT);

        rbnDFT = new QRadioButton(widget);
        rbnDFT->setObjectName(QString::fromUtf8("rbnDFT"));

        verticalLayout_7->addWidget(rbnDFT);


        verticalLayout_8->addWidget(widget);

        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy5.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy5);

        verticalLayout_8->addWidget(label_19);

        ldtKeyDecrypt = new QLineEdit(tab_4);
        ldtKeyDecrypt->setObjectName(QString::fromUtf8("ldtKeyDecrypt"));
        sizePolicy3.setHeightForWidth(ldtKeyDecrypt->sizePolicy().hasHeightForWidth());
        ldtKeyDecrypt->setSizePolicy(sizePolicy3);
        ldtKeyDecrypt->setMaxLength(16);

        verticalLayout_8->addWidget(ldtKeyDecrypt);

        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy5.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy5);

        verticalLayout_8->addWidget(label_20);

        ldtIVDecrypt = new QLineEdit(tab_4);
        ldtIVDecrypt->setObjectName(QString::fromUtf8("ldtIVDecrypt"));
        sizePolicy3.setHeightForWidth(ldtIVDecrypt->sizePolicy().hasHeightForWidth());
        ldtIVDecrypt->setSizePolicy(sizePolicy3);
        ldtIVDecrypt->setMaxLength(16);

        verticalLayout_8->addWidget(ldtIVDecrypt);

        btnStegoDecrypt = new QPushButton(tab_4);
        btnStegoDecrypt->setObjectName(QString::fromUtf8("btnStegoDecrypt"));
        sizePolicy3.setHeightForWidth(btnStegoDecrypt->sizePolicy().hasHeightForWidth());
        btnStegoDecrypt->setSizePolicy(sizePolicy3);

        verticalLayout_8->addWidget(btnStegoDecrypt);

        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_2);

        pteDecrypt = new QPlainTextEdit(tab_4);
        pteDecrypt->setObjectName(QString::fromUtf8("pteDecrypt"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pteDecrypt->sizePolicy().hasHeightForWidth());
        pteDecrypt->setSizePolicy(sizePolicy6);

        verticalLayout_8->addWidget(pteDecrypt);


        horizontalLayout_4->addLayout(verticalLayout_8);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_7, 0, 1, 1, 1);

        grvMainStegoDetect = new QGraphicsView(tab_4);
        grvMainStegoDetect->setObjectName(QString::fromUtf8("grvMainStegoDetect"));
        grvMainStegoDetect->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvMainStegoDetect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvMainStegoDetect->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvMainStegoDetect->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(grvMainStegoDetect, 1, 0, 1, 1);

        grvStegoDetectHist = new QGraphicsView(tab_4);
        grvStegoDetectHist->setObjectName(QString::fromUtf8("grvStegoDetectHist"));
        grvStegoDetectHist->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvStegoDetectHist->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvStegoDetectHist->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvStegoDetectHist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(grvStegoDetectHist, 1, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_4);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout_2->addWidget(tabWidget);

        SteganographyProject->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SteganographyProject);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 908, 25));
        SteganographyProject->setMenuBar(menubar);
        statusbar = new QStatusBar(SteganographyProject);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SteganographyProject->setStatusBar(statusbar);

        retranslateUi(SteganographyProject);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(SteganographyProject);
    } // setupUi

    void retranslateUi(QMainWindow *SteganographyProject)
    {
        SteganographyProject->setWindowTitle(QCoreApplication::translate("SteganographyProject", "SteganographyProject", nullptr));
        actionOpen_FIle->setText(QCoreApplication::translate("SteganographyProject", "Open FIle", nullptr));
        btnLSBStegoOpen->setText(QCoreApplication::translate("SteganographyProject", "Open File", nullptr));
        lblLSBMessage->setText(QCoreApplication::translate("SteganographyProject", "Hidden Message", nullptr));
        lblLSBKey->setText(QCoreApplication::translate("SteganographyProject", "AES Key", nullptr));
        lblLSBIV->setText(QCoreApplication::translate("SteganographyProject", "CBC Iv", nullptr));
        lblLSBHexLength->setText(QCoreApplication::translate("SteganographyProject", "HexLength:", nullptr));
        btnLSBStegoExecute->setText(QCoreApplication::translate("SteganographyProject", "LSB Stego", nullptr));
        btnLSBStegoExport->setText(QCoreApplication::translate("SteganographyProject", "Export Stego Image", nullptr));
        label_5->setText(QCoreApplication::translate("SteganographyProject", "LSB of Stego Image", nullptr));
        label_3->setText(QCoreApplication::translate("SteganographyProject", "Original Image", nullptr));
        label_4->setText(QCoreApplication::translate("SteganographyProject", "Stego Image", nullptr));
        label_6->setText(QCoreApplication::translate("SteganographyProject", "LSB of Original Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SteganographyProject", "LSBStego", nullptr));
        btnDCTStegoOpen->setText(QCoreApplication::translate("SteganographyProject", "Open File", nullptr));
        lblDCTMessage->setText(QCoreApplication::translate("SteganographyProject", "Hidden Message", nullptr));
        lblDCTKey->setText(QCoreApplication::translate("SteganographyProject", "AES Key", nullptr));
        lblDCTIV->setText(QCoreApplication::translate("SteganographyProject", "CBC Iv", nullptr));
        lblDCTHexLength->setText(QCoreApplication::translate("SteganographyProject", "HexLength:", nullptr));
        btnDCTStegoExecute->setText(QCoreApplication::translate("SteganographyProject", "DCT Stego", nullptr));
        btnDCTStegoExport->setText(QCoreApplication::translate("SteganographyProject", "Export Stego Image", nullptr));
        label_17->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("SteganographyProject", "Stego Image", nullptr));
        label_16->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("SteganographyProject", "Original Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SteganographyProject", "DCTStego", nullptr));
        btnDCTStegoOpen_2->setText(QCoreApplication::translate("SteganographyProject", "Open File", nullptr));
        lblDCTMessage_2->setText(QCoreApplication::translate("SteganographyProject", "Hidden Message", nullptr));
        lblDCTKey_2->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        lblDCTIV_2->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        lblDCTHexLength_2->setText(QCoreApplication::translate("SteganographyProject", "HexLength:", nullptr));
        btnDCTStegoExecute_2->setText(QCoreApplication::translate("SteganographyProject", "DCT Stego", nullptr));
        btnDCTStegoExport_2->setText(QCoreApplication::translate("SteganographyProject", "Export Stego Image", nullptr));
        label_18->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        label_21->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        label_23->setText(QCoreApplication::translate("SteganographyProject", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("SteganographyProject", "DFTStego", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("SteganographyProject", "DWTStego", nullptr));
        btnStegoDetectOpen->setText(QCoreApplication::translate("SteganographyProject", "Open File", nullptr));
        rbnLSB->setText(QCoreApplication::translate("SteganographyProject", "LSB", nullptr));
        rbnDCT->setText(QCoreApplication::translate("SteganographyProject", "DCT", nullptr));
        rbnDFT->setText(QCoreApplication::translate("SteganographyProject", "DFT", nullptr));
        label_19->setText(QCoreApplication::translate("SteganographyProject", "AES Key", nullptr));
        label_20->setText(QCoreApplication::translate("SteganographyProject", "CBC Iv", nullptr));
        btnStegoDecrypt->setText(QCoreApplication::translate("SteganographyProject", "Decrypt", nullptr));
        label_2->setText(QCoreApplication::translate("SteganographyProject", "Hidden Message", nullptr));
        label->setText(QCoreApplication::translate("SteganographyProject", "Stego Image", nullptr));
        label_7->setText(QCoreApplication::translate("SteganographyProject", "Stego Image Histogram", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("SteganographyProject", "Stego Detection and Decryption", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SteganographyProject: public Ui_SteganographyProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEGANOGRAPHYPROJECT_H
