#ifndef LAYERSENSE_H
#define LAYERSENSE_H

#include <QMainWindow>
#include <QPainter>
#include <QStyleOption>
#include "digitaltwin.h"
#include <QMenu>

namespace Ui {
class LayerSense;
}

class SenseChart;

class LayerSense : public QMainWindow
{
    Q_OBJECT

public:
    explicit LayerSense(QWidget *parent = nullptr);
    ~LayerSense();

    void paintEvent(QPaintEvent *e);
    void initCharts();
    void initLab();
    void initTableWidget();
    void InitMenu();
    void initToolBar();

private:
    Ui::LayerSense *ui;

    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer;
    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 10, AXIS_MAX_Y = 10;
    /* 用来记录数据点数 */
    int pointCount = 0;
    SenseChart * ChartStatic;
    SenseChart * ChartDynamic;
    SenseChart * ChartShear;
    SenseChart * ChartVelocity;
    SenseChart * ChartStrain;
    SenseChart * ChartTemperature;

    //表格项名称
    QVector<QString> check_str;

    QMenu *senseMenu;//右键菜单

private slots:

    void slotBtnClear();
    void slotBtnStartAndStop();
    void slotTimeout();

    void on_addRow_clicked();
    void on_deleteRow_clicked();
    void slotContextMenu();
    void slotTest();
};

#endif // LAYERSENSE_H
