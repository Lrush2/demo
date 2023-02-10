#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QMainWindow>
#include "gaugepanel.h"

namespace Ui {
class WorkWidget;
}

class WorkWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWidget(QWidget *parent = nullptr);
    ~WorkWidget();

private:
    Ui::WorkWidget *ui;
};

#endif // WORKWIDGET_H
