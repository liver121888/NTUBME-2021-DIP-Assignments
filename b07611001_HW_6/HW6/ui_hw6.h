/********************************************************************************
** Form generated from reading UI file 'hw6.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW6_H
#define UI_HW6_H

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

class Ui_HW6
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnGeoOpen;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbnTrapezoidal;
    QRadioButton *rbnWavy;
    QRadioButton *rbnCircular;
    QLabel *lblTrapezoidalParam;
    QSlider *hsdTrapezoidalParam;
    QLabel *lblTrapezoidalParam2;
    QSlider *hsdTrapezoidalParam2;
    QLabel *lblWavyParam;
    QSpinBox *spbWavyParam;
    QLabel *lblWavyParam2;
    QSpinBox *spbWavyParam2;
    QLabel *lblWavyParam3;
    QSpinBox *spbWavyParam3;
    QPushButton *btnGeoExecute;
    QGridLayout *gridLayout;
    QGraphicsView *grvGeoOriginal;
    QGraphicsView *grvGeoTransformed;
    QLabel *label;
    QLabel *label_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnDWTOpenA;
    QPushButton *btnDWTOpenB;
    QLabel *label_11;
    QSpinBox *spbDWTOrder;
    QPushButton *btnDWTExecuteA;
    QPushButton *btnDWTExecuteB;
    QPushButton *btnDWTExecuteFuse;
    QPushButton *btnDWTExecuteInverse;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QGraphicsView *grvDWTOriginalA;
    QGraphicsView *grvDWTTransformedA;
    QLabel *label_5;
    QLabel *label_6;
    QGraphicsView *grvDWTOriginalB;
    QGraphicsView *grvDWTTransformedB;
    QLabel *label_7;
    QLabel *label_8;
    QGraphicsView *grvDWTTransformedFused;
    QGraphicsView *grvDWTInversedFused;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QSlider *hsdHoughThreshold;
    QLabel *lblHoughThreshold;
    QSlider *hsdCanny2;
    QLabel *lblCanny2;
    QLabel *lblCanny1;
    QSlider *hsdCanny1;
    QLabel *label_9;
    QLabel *label_10;
    QGraphicsView *grvHoughOriginal;
    QGraphicsView *grvHoughTransformed;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QLabel *lblDistance;
    QLabel *lblP1;
    QSpinBox *spbP2;
    QPushButton *btnGetDistance;
    QSpinBox *spbP1;
    QLabel *lblP2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnHoughOpen;
    QPushButton *btnHoughExecute;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HW6)
    {
        if (HW6->objectName().isEmpty())
            HW6->setObjectName(QString::fromUtf8("HW6"));
        HW6->resize(984, 631);
        centralwidget = new QWidget(HW6);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnGeoOpen = new QPushButton(widget_2);
        btnGeoOpen->setObjectName(QString::fromUtf8("btnGeoOpen"));

        verticalLayout->addWidget(btnGeoOpen);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rbnTrapezoidal = new QRadioButton(widget);
        rbnTrapezoidal->setObjectName(QString::fromUtf8("rbnTrapezoidal"));

        verticalLayout_2->addWidget(rbnTrapezoidal);

        rbnWavy = new QRadioButton(widget);
        rbnWavy->setObjectName(QString::fromUtf8("rbnWavy"));

        verticalLayout_2->addWidget(rbnWavy);

        rbnCircular = new QRadioButton(widget);
        rbnCircular->setObjectName(QString::fromUtf8("rbnCircular"));

        verticalLayout_2->addWidget(rbnCircular);


        verticalLayout->addWidget(widget);

        lblTrapezoidalParam = new QLabel(widget_2);
        lblTrapezoidalParam->setObjectName(QString::fromUtf8("lblTrapezoidalParam"));
        lblTrapezoidalParam->setEnabled(false);
        lblTrapezoidalParam->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTrapezoidalParam);

        hsdTrapezoidalParam = new QSlider(widget_2);
        hsdTrapezoidalParam->setObjectName(QString::fromUtf8("hsdTrapezoidalParam"));
        hsdTrapezoidalParam->setEnabled(false);
        hsdTrapezoidalParam->setMinimum(10);
        hsdTrapezoidalParam->setMaximum(49);
        hsdTrapezoidalParam->setValue(25);
        hsdTrapezoidalParam->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(hsdTrapezoidalParam);

        lblTrapezoidalParam2 = new QLabel(widget_2);
        lblTrapezoidalParam2->setObjectName(QString::fromUtf8("lblTrapezoidalParam2"));
        lblTrapezoidalParam2->setEnabled(false);
        lblTrapezoidalParam2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTrapezoidalParam2);

        hsdTrapezoidalParam2 = new QSlider(widget_2);
        hsdTrapezoidalParam2->setObjectName(QString::fromUtf8("hsdTrapezoidalParam2"));
        hsdTrapezoidalParam2->setEnabled(false);
        hsdTrapezoidalParam2->setMinimum(10);
        hsdTrapezoidalParam2->setMaximum(100);
        hsdTrapezoidalParam2->setValue(50);
        hsdTrapezoidalParam2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(hsdTrapezoidalParam2);

        lblWavyParam = new QLabel(widget_2);
        lblWavyParam->setObjectName(QString::fromUtf8("lblWavyParam"));
        lblWavyParam->setEnabled(false);
        lblWavyParam->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblWavyParam);

        spbWavyParam = new QSpinBox(widget_2);
        spbWavyParam->setObjectName(QString::fromUtf8("spbWavyParam"));
        spbWavyParam->setEnabled(false);
        spbWavyParam->setMinimum(10);
        spbWavyParam->setMaximum(360);
        spbWavyParam->setSingleStep(10);
        spbWavyParam->setValue(180);

        verticalLayout->addWidget(spbWavyParam);

        lblWavyParam2 = new QLabel(widget_2);
        lblWavyParam2->setObjectName(QString::fromUtf8("lblWavyParam2"));
        lblWavyParam2->setEnabled(false);
        lblWavyParam2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblWavyParam2);

        spbWavyParam2 = new QSpinBox(widget_2);
        spbWavyParam2->setObjectName(QString::fromUtf8("spbWavyParam2"));
        spbWavyParam2->setEnabled(false);
        spbWavyParam2->setMinimum(10);
        spbWavyParam2->setMaximum(90);
        spbWavyParam2->setSingleStep(10);
        spbWavyParam2->setValue(50);

        verticalLayout->addWidget(spbWavyParam2);

        lblWavyParam3 = new QLabel(widget_2);
        lblWavyParam3->setObjectName(QString::fromUtf8("lblWavyParam3"));
        lblWavyParam3->setEnabled(false);
        lblWavyParam3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblWavyParam3);

        spbWavyParam3 = new QSpinBox(widget_2);
        spbWavyParam3->setObjectName(QString::fromUtf8("spbWavyParam3"));
        spbWavyParam3->setEnabled(false);

        verticalLayout->addWidget(spbWavyParam3);

        btnGeoExecute = new QPushButton(widget_2);
        btnGeoExecute->setObjectName(QString::fromUtf8("btnGeoExecute"));
        btnGeoExecute->setEnabled(false);

        verticalLayout->addWidget(btnGeoExecute);


        horizontalLayout_3->addWidget(widget_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        grvGeoOriginal = new QGraphicsView(tab);
        grvGeoOriginal->setObjectName(QString::fromUtf8("grvGeoOriginal"));
        grvGeoOriginal->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvGeoOriginal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvGeoOriginal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvGeoOriginal->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(grvGeoOriginal, 1, 0, 1, 1);

        grvGeoTransformed = new QGraphicsView(tab);
        grvGeoTransformed->setObjectName(QString::fromUtf8("grvGeoTransformed"));
        grvGeoTransformed->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvGeoTransformed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvGeoTransformed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvGeoTransformed->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(grvGeoTransformed, 1, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnDWTOpenA = new QPushButton(widget_3);
        btnDWTOpenA->setObjectName(QString::fromUtf8("btnDWTOpenA"));

        verticalLayout_3->addWidget(btnDWTOpenA);

        btnDWTOpenB = new QPushButton(widget_3);
        btnDWTOpenB->setObjectName(QString::fromUtf8("btnDWTOpenB"));
        btnDWTOpenB->setEnabled(false);

        verticalLayout_3->addWidget(btnDWTOpenB);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_11);

        spbDWTOrder = new QSpinBox(widget_3);
        spbDWTOrder->setObjectName(QString::fromUtf8("spbDWTOrder"));
        spbDWTOrder->setEnabled(false);
        spbDWTOrder->setMinimum(1);
        spbDWTOrder->setMaximum(3);

        verticalLayout_3->addWidget(spbDWTOrder);

        btnDWTExecuteA = new QPushButton(widget_3);
        btnDWTExecuteA->setObjectName(QString::fromUtf8("btnDWTExecuteA"));
        btnDWTExecuteA->setEnabled(false);

        verticalLayout_3->addWidget(btnDWTExecuteA);

        btnDWTExecuteB = new QPushButton(widget_3);
        btnDWTExecuteB->setObjectName(QString::fromUtf8("btnDWTExecuteB"));
        btnDWTExecuteB->setEnabled(false);

        verticalLayout_3->addWidget(btnDWTExecuteB);

        btnDWTExecuteFuse = new QPushButton(widget_3);
        btnDWTExecuteFuse->setObjectName(QString::fromUtf8("btnDWTExecuteFuse"));
        btnDWTExecuteFuse->setEnabled(false);

        verticalLayout_3->addWidget(btnDWTExecuteFuse);

        btnDWTExecuteInverse = new QPushButton(widget_3);
        btnDWTExecuteInverse->setObjectName(QString::fromUtf8("btnDWTExecuteInverse"));
        btnDWTExecuteInverse->setEnabled(false);

        verticalLayout_3->addWidget(btnDWTExecuteInverse);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addWidget(widget_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        grvDWTOriginalA = new QGraphicsView(tab_2);
        grvDWTOriginalA->setObjectName(QString::fromUtf8("grvDWTOriginalA"));
        grvDWTOriginalA->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDWTOriginalA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTOriginalA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTOriginalA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDWTOriginalA, 1, 0, 1, 1);

        grvDWTTransformedA = new QGraphicsView(tab_2);
        grvDWTTransformedA->setObjectName(QString::fromUtf8("grvDWTTransformedA"));
        grvDWTTransformedA->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDWTTransformedA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTTransformedA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTTransformedA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDWTTransformedA, 1, 1, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 2, 1, 1, 1);

        grvDWTOriginalB = new QGraphicsView(tab_2);
        grvDWTOriginalB->setObjectName(QString::fromUtf8("grvDWTOriginalB"));
        grvDWTOriginalB->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDWTOriginalB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTOriginalB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTOriginalB->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDWTOriginalB, 3, 0, 1, 1);

        grvDWTTransformedB = new QGraphicsView(tab_2);
        grvDWTTransformedB->setObjectName(QString::fromUtf8("grvDWTTransformedB"));
        grvDWTTransformedB->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDWTTransformedB->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTTransformedB->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTTransformedB->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDWTTransformedB, 3, 1, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 4, 1, 1, 1);

        grvDWTTransformedFused = new QGraphicsView(tab_2);
        grvDWTTransformedFused->setObjectName(QString::fromUtf8("grvDWTTransformedFused"));
        grvDWTTransformedFused->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDWTTransformedFused->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTTransformedFused->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTTransformedFused->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDWTTransformedFused, 5, 0, 1, 1);

        grvDWTInversedFused = new QGraphicsView(tab_2);
        grvDWTInversedFused->setObjectName(QString::fromUtf8("grvDWTInversedFused"));
        grvDWTInversedFused->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvDWTInversedFused->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTInversedFused->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvDWTInversedFused->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(grvDWTInversedFused, 5, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_7 = new QHBoxLayout(tab_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_5 = new QWidget(tab_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setEnabled(false);
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        hsdHoughThreshold = new QSlider(widget_5);
        hsdHoughThreshold->setObjectName(QString::fromUtf8("hsdHoughThreshold"));
        hsdHoughThreshold->setMinimum(50);
        hsdHoughThreshold->setMaximum(250);
        hsdHoughThreshold->setValue(100);
        hsdHoughThreshold->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(hsdHoughThreshold, 2, 1, 1, 1);

        lblHoughThreshold = new QLabel(widget_5);
        lblHoughThreshold->setObjectName(QString::fromUtf8("lblHoughThreshold"));

        gridLayout_5->addWidget(lblHoughThreshold, 2, 0, 1, 1);

        hsdCanny2 = new QSlider(widget_5);
        hsdCanny2->setObjectName(QString::fromUtf8("hsdCanny2"));
        hsdCanny2->setMinimum(100);
        hsdCanny2->setMaximum(250);
        hsdCanny2->setValue(200);
        hsdCanny2->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(hsdCanny2, 1, 1, 1, 1);

        lblCanny2 = new QLabel(widget_5);
        lblCanny2->setObjectName(QString::fromUtf8("lblCanny2"));

        gridLayout_5->addWidget(lblCanny2, 1, 0, 1, 1);

        lblCanny1 = new QLabel(widget_5);
        lblCanny1->setObjectName(QString::fromUtf8("lblCanny1"));

        gridLayout_5->addWidget(lblCanny1, 0, 0, 1, 1);

        hsdCanny1 = new QSlider(widget_5);
        hsdCanny1->setObjectName(QString::fromUtf8("hsdCanny1"));
        hsdCanny1->setMaximum(250);
        hsdCanny1->setValue(50);
        hsdCanny1->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(hsdCanny1, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_5, 3, 0, 1, 1);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);

        grvHoughOriginal = new QGraphicsView(tab_3);
        grvHoughOriginal->setObjectName(QString::fromUtf8("grvHoughOriginal"));
        grvHoughOriginal->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvHoughOriginal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvHoughOriginal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvHoughOriginal->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(grvHoughOriginal, 1, 0, 1, 1);

        grvHoughTransformed = new QGraphicsView(tab_3);
        grvHoughTransformed->setObjectName(QString::fromUtf8("grvHoughTransformed"));
        grvHoughTransformed->setStyleSheet(QString::fromUtf8("background-color: rgba(83, 125, 125, 50);"));
        grvHoughTransformed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvHoughTransformed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvHoughTransformed->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(grvHoughTransformed, 1, 1, 1, 1);

        widget_4 = new QWidget(tab_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setEnabled(false);
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lblDistance = new QLabel(widget_4);
        lblDistance->setObjectName(QString::fromUtf8("lblDistance"));
        sizePolicy1.setHeightForWidth(lblDistance->sizePolicy().hasHeightForWidth());
        lblDistance->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lblDistance, 3, 2, 1, 1);

        lblP1 = new QLabel(widget_4);
        lblP1->setObjectName(QString::fromUtf8("lblP1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblP1->sizePolicy().hasHeightForWidth());
        lblP1->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(lblP1, 2, 0, 1, 1);

        spbP2 = new QSpinBox(widget_4);
        spbP2->setObjectName(QString::fromUtf8("spbP2"));
        sizePolicy3.setHeightForWidth(spbP2->sizePolicy().hasHeightForWidth());
        spbP2->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(spbP2, 3, 1, 1, 1);

        btnGetDistance = new QPushButton(widget_4);
        btnGetDistance->setObjectName(QString::fromUtf8("btnGetDistance"));

        gridLayout_3->addWidget(btnGetDistance, 2, 2, 1, 1);

        spbP1 = new QSpinBox(widget_4);
        spbP1->setObjectName(QString::fromUtf8("spbP1"));

        gridLayout_3->addWidget(spbP1, 2, 1, 1, 1);

        lblP2 = new QLabel(widget_4);
        lblP2->setObjectName(QString::fromUtf8("lblP2"));
        sizePolicy1.setHeightForWidth(lblP2->sizePolicy().hasHeightForWidth());
        lblP2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lblP2, 3, 0, 1, 1);


        gridLayout_4->addWidget(widget_4, 3, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnHoughOpen = new QPushButton(tab_3);
        btnHoughOpen->setObjectName(QString::fromUtf8("btnHoughOpen"));

        horizontalLayout_6->addWidget(btnHoughOpen);

        btnHoughExecute = new QPushButton(tab_3);
        btnHoughExecute->setObjectName(QString::fromUtf8("btnHoughExecute"));
        btnHoughExecute->setEnabled(false);

        horizontalLayout_6->addWidget(btnHoughExecute);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        HW6->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HW6);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 984, 25));
        HW6->setMenuBar(menubar);
        statusbar = new QStatusBar(HW6);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HW6->setStatusBar(statusbar);

        retranslateUi(HW6);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HW6);
    } // setupUi

    void retranslateUi(QMainWindow *HW6)
    {
        HW6->setWindowTitle(QCoreApplication::translate("HW6", "HW6", nullptr));
        btnGeoOpen->setText(QCoreApplication::translate("HW6", "Open File", nullptr));
        rbnTrapezoidal->setText(QCoreApplication::translate("HW6", "Trapezoidal Transformation", nullptr));
        rbnWavy->setText(QCoreApplication::translate("HW6", "Wavy Transformation", nullptr));
        rbnCircular->setText(QCoreApplication::translate("HW6", "Cirular Transformation", nullptr));
        lblTrapezoidalParam->setText(QCoreApplication::translate("HW6", "Trapezoidal Parameter", nullptr));
        lblTrapezoidalParam2->setText(QCoreApplication::translate("HW6", "Trapezoidal Parameter2", nullptr));
        lblWavyParam->setText(QCoreApplication::translate("HW6", "Wavy Parameter", nullptr));
        lblWavyParam2->setText(QCoreApplication::translate("HW6", "Wavy Parameter2", nullptr));
        lblWavyParam3->setText(QCoreApplication::translate("HW6", "Wavy Parameter3", nullptr));
        btnGeoExecute->setText(QCoreApplication::translate("HW6", "Apply Geometric\n"
"Transformation", nullptr));
        label->setText(QCoreApplication::translate("HW6", "Original Image", nullptr));
        label_2->setText(QCoreApplication::translate("HW6", "Geometric Transformed Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("HW6", "Geometric Transformation ", nullptr));
        btnDWTOpenA->setText(QCoreApplication::translate("HW6", "Open File A", nullptr));
        btnDWTOpenB->setText(QCoreApplication::translate("HW6", "Open File B", nullptr));
        label_11->setText(QCoreApplication::translate("HW6", "DWT order", nullptr));
        btnDWTExecuteA->setText(QCoreApplication::translate("HW6", "Apply DWT On A", nullptr));
        btnDWTExecuteB->setText(QCoreApplication::translate("HW6", "Apply DWT On B", nullptr));
        btnDWTExecuteFuse->setText(QCoreApplication::translate("HW6", "Image Fusioin", nullptr));
        btnDWTExecuteInverse->setText(QCoreApplication::translate("HW6", "Inverse DWT", nullptr));
        label_3->setText(QCoreApplication::translate("HW6", "Image A", nullptr));
        label_4->setText(QCoreApplication::translate("HW6", "DWT Of A", nullptr));
        label_5->setText(QCoreApplication::translate("HW6", "Image B", nullptr));
        label_6->setText(QCoreApplication::translate("HW6", "DWT of B", nullptr));
        label_7->setText(QCoreApplication::translate("HW6", "Fused DWT", nullptr));
        label_8->setText(QCoreApplication::translate("HW6", "Fused Image", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("HW6", "Image Fusion Using Wavelet Transform ", nullptr));
        lblHoughThreshold->setText(QCoreApplication::translate("HW6", "Hough Threshold: ", nullptr));
        lblCanny2->setText(QCoreApplication::translate("HW6", "Canny Threshold2:", nullptr));
        lblCanny1->setText(QCoreApplication::translate("HW6", "Canny Threshold1:", nullptr));
        label_9->setText(QCoreApplication::translate("HW6", "Original Image", nullptr));
        label_10->setText(QCoreApplication::translate("HW6", "Hoguh Transformed Image", nullptr));
        lblDistance->setText(QCoreApplication::translate("HW6", "Distance: ", nullptr));
        lblP1->setText(QCoreApplication::translate("HW6", "P1", nullptr));
        btnGetDistance->setText(QCoreApplication::translate("HW6", "Get Distance", nullptr));
        lblP2->setText(QCoreApplication::translate("HW6", "P2", nullptr));
        btnHoughOpen->setText(QCoreApplication::translate("HW6", "Open File", nullptr));
        btnHoughExecute->setText(QCoreApplication::translate("HW6", "Apply Hough Transformation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("HW6", "Hough Transform ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HW6: public Ui_HW6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW6_H
