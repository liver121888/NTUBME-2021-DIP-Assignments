#ifndef HISTOGRAMCHART_H
#define HISTOGRAMCHART_H
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

class HistogramChart
{
private:
    const char* title;
    int number;
    int* counts;
    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    QChartView *chartView;

public:
    HistogramChart(int counts[], int length, const char* name);
    QChartView *GetView(){return chartView;}

private:
    void updateSeries();
    void updateChart();
    void updateView();
};

#endif // HISTOGRAMCHART_H
