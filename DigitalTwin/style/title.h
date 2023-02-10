#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include "style/iconhelper.h"
#include "style/quiconfig.h"

namespace Ui {
class title;
}

class title : public QWidget
{
    Q_OBJECT

public:
    explicit title(QWidget *parent = nullptr, QString text = "");
    ~title();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //void mouseDoubleClickEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *e);

private slots:
    void onClicked();

private:
    Ui::title *ui;
    QPoint m_start;  //起始点
    QPoint m_end;    //结束点
    bool m_leftButtonPressed;   //鼠标左键按下标记
};

#endif // TITLE_H
