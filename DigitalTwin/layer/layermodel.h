#ifndef LAYERMODEL_H
#define LAYERMODEL_H

#include <QMainWindow>
#include <QPainter>
#include <QStyleOption>
#include "digitaltwin.h"

namespace Ui {
class LayerModel;
}

class LayerModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit LayerModel(QWidget *parent = nullptr);
    ~LayerModel();
    void paintEvent(QPaintEvent *e);
    void initLab();
    void InitMenu();//注意是大写
    void initToolBar();

private:
    Ui::LayerModel *ui;
    QMenu *senseMenu;//右键菜单

private slots:
    void slotContextMenu();
    void slotTest();
};

#endif // LAYERMODEL_H
