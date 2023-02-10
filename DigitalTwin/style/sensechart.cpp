#include "sensechart.h"

SenseChart::SenseChart(QWidget *parent) : QWidget(parent)
{

    // 创建横纵坐标轴并设置显示范围
    m_axisX = new QValueAxis();
    m_axisY = new QValueAxis();
    m_axisX->setTitleText("sense data");
    m_axisY->setTitleText("time");

    m_axisX->setTitleFont(QFont("Microsoft Yahei",9));
    m_axisY->setTitleFont(QFont("Microsoft Yahei",9));
    m_axisX->setTitleBrush(QBrush(QColor(26, 85, 153)));//字体颜色
    m_axisY->setTitleBrush(QBrush(QColor(26, 85, 153)));
    m_axisX->setLabelsFont(QFont("Microsoft Yahei",9));
    m_axisY->setLabelsFont(QFont("Microsoft Yahei",9));
    //左右边界值
    m_axisX->setMin(0);
    m_axisY->setMax(0);
    m_axisX->setMax(AXIS_MAX_X);
    m_axisY->setMax(AXIS_MAX_Y);

    m_axisY->setGridLineVisible(false);   //隐藏背景网格Y轴框线
    m_axisX->setGridLineVisible(false);   //隐藏背景网格X轴框线

    m_axisX->setLabelsColor(QColor(26, 85, 153));
    m_axisY->setLabelsColor(QColor(26, 85, 153));

    m_lineSeries = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries->setName("传感器曲线");                            // 图例名称
    //m_chart->legend()->markers().at(0)->setVisible(false);

    m_chart = new QChart();                                        // 创建图表对象
    m_chart->addAxis(m_axisX, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart->addAxis(m_axisY, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart->addSeries(m_lineSeries);                              // 将曲线对象添加到图表上
    m_chart->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_chart->setContentsMargins(0, 0, 0, 0);  //设置外边界全部为0
    m_chart->setMargins(QMargins(0, 0, 0, 0));//设置内边界全部为0

    m_lineSeries->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    m_chart->zoom(0.2);
    m_chart->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置图标对象背景，区别于图表视图背景


}

void SenseChart::BtnClear()
{
    m_lineSeries->clear();
    m_chart->axisX()->setMin(0);
    m_chart->axisX()->setMax(AXIS_MAX_X);

}



void SenseChart::Timeout(int& pointCount)
{
    if(pointCount > AXIS_MAX_X)
    {
        m_lineSeries->remove(0);
        m_chart->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart->axisX()->setMax(pointCount);                    // 更新X轴范围
    }
    //(x,y)坐标
    m_lineSeries->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）

}

