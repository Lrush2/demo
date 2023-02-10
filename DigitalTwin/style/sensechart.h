#ifndef SENSECHART_H
#define SENSECHART_H

#include <QWidget>

#include <QTimer>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>

/* 光添加头文件QChartView还不够，还需要引入QChart的命名空间 */
QT_CHARTS_USE_NAMESPACE

class SenseChart : public QWidget
{
    Q_OBJECT
public:
    explicit SenseChart(QWidget *parent = nullptr);

public:

    /* 图表对象 */
    QChart* m_chart;

    /* 横纵坐标轴对象 */
    QValueAxis *m_axisX, *m_axisY;

    /* 曲线图对象 */
    QLineSeries* m_lineSeries;

    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 10, AXIS_MAX_Y = 10;


    void BtnClear();
    void Timeout(int& pointCount);

signals:

};

#endif // SENSECHART_H
