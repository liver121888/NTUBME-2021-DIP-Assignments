#include "histogramchart.h"

//constructor
HistogramChart::HistogramChart(int counts[], int length, const char* name)
{
    title = name;
    this->counts = counts;
    number = length;
    updateSeries();
    updateChart();
    updateView();
}

//uodate series for plotting
void HistogramChart::updateSeries()
{
    QBarSet* aSet = new QBarSet(title);
    for( int i = 0; i < number; i++)
        aSet->append(counts[i]);
    aSet->setColor(QColor(255,0,0,255));
    series->name() = title;
    series->clear();
    series->append(aSet);
    series->setBarWidth(0.8);
}

//update the chart
void HistogramChart::updateChart()
{
    chart->addSeries(series);
    chart->setTitle( "Histogram");
    chart->setAnimationOptions(QChart::NoAnimation);
    chart->legend()->hide();

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(0,number);
    //hide text label
    //axisX->setTitleText("pixel value");
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);

    //hide Y axis
    //int largestCount = 0;
    //for( int i = 0; i < number; i++ )
    //    if( counts[i] > largestCount) largestCount = counts[i];
    //QValueAxis *axisY = new QValueAxis();
    //axisY->setRange(0,largestCount);
    //axisY->setTitleText("count");
    //chart->addAxis(axisY,Qt::AlignLeft);
    //chart->setTheme(QChart::setTheme(series) )


}

//update view in the layout
void HistogramChart::updateView()
{
    chartView = new QChartView( chart );
}
