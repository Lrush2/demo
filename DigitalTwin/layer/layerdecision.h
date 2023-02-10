#ifndef LAYERDECISION_H
#define LAYERDECISION_H

#include <QMainWindow>
#include <QPainter>
#include <QStyleOption>
#include "digitaltwin.h"

namespace Ui {
class LayerDecision;
}

class LayerDecision : public QMainWindow
{
    Q_OBJECT

public:
    explicit LayerDecision(QWidget *parent = nullptr);
    ~LayerDecision();
    void paintEvent(QPaintEvent *e);
    void initToolBar();

private:
    Ui::LayerDecision *ui;
};

#endif // LAYERDECISION_H
