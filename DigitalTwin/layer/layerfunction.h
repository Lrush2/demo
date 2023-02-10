#ifndef LAYERFUNCTION_H
#define LAYERFUNCTION_H

#include <QMainWindow>
#include <QPainter>
#include <QStyleOption>
#include "digitaltwin.h"

namespace Ui {
class LayerFunction;
}

class LayerFunction : public QMainWindow
{
    Q_OBJECT

public:
    explicit LayerFunction(QWidget *parent = nullptr);
    ~LayerFunction();
    void paintEvent(QPaintEvent *e);
    void InitMenu();
    void initToolBar();
    void nameAction(QToolBar * bar, QAction * action, const char * name = nullptr);

private:
    Ui::LayerFunction *ui;

    QMenu *senseMenu;//右键菜单
    QToolBar *functionTool;
    QToolButton *btn1;
    QToolButton *btn2;
    QToolButton *btn3;
    QToolButton *btn4;

private slots:
    void slotContextMenu();
    void slotTest();
};

#endif // LAYERFUNCTION_H
