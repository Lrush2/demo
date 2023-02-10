#ifndef LAYERDATA_H
#define LAYERDATA_H

#include <QMainWindow>
#include <QPainter>
#include <QStyleOption>
#include "digitaltwin.h"

namespace Ui {
class LayerData;
}

class SenseChart;

class LayerData : public QMainWindow
{
    Q_OBJECT

public:
    explicit LayerData(QWidget *parent = nullptr);
    ~LayerData();
    void paintEvent(QPaintEvent *e);
    void initCharts();
    void initTableWidget();
    void initToolBar();

private:
    Ui::LayerData *ui;
    SenseChart *ChartInflux;
};

#endif // LAYERDATA_H
