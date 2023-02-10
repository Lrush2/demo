#include "workwidget.h"
#include "ui_workwidget.h"

WorkWidget::WorkWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkWidget)
{
    ui->setupUi(this);
    //可嵌入widget
    this->setWindowFlags(Qt::Widget);
    ui->dockWidget->setFont(QFont("Microsoft Yahei", 9));
    ui->dockWidget_2->setFont(QFont("Microsoft Yahei", 9));
    ui->dockWidgetContents->setFont(QFont("Microsoft Yahei", 9));

    ui->gaugepanel->setValue(60);
    ui->gaugepanel_2->setValue(40);
}

WorkWidget::~WorkWidget()
{
    delete ui;
}
