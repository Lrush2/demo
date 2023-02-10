#include "layerdecision.h"
#include "ui_layerdecision.h"

LayerDecision::LayerDecision(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LayerDecision)
{
    ui->setupUi(this);
    initToolBar();
}

LayerDecision::~LayerDecision()
{
    delete ui;
}

void LayerDecision::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void LayerDecision::initToolBar()
{
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/10.png"),tr("打开")));
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/11.png"),tr("删除")));
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/12.png"),tr("测试")));

    ui->toolBar->setIconSize(QSize(60,36));//宽 高  5-3

    ui->toolBar->setFixedSize(1000,80);

    //设置了父类背景之后，子类背景不起作用
    ui->toolBar->setStyleSheet(
//                "QToolButton#btn3 { background-color: rgb(16,20,32) }"
//                "QToolButton#btn3:hover{background:#132743;}"
//                "QToolButton#btn3:pressed{ background-color: rgb(16,20,32) }"
                "QToolBar { background-color: rgb(16,20,32) }"
                "QToolButton { background-color: rgb(16,20,32) }"
                "QToolButton:hover{background:#132743;}"
                "QToolButton:pressed{ background-color: rgb(16,20,32) }"
                );
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//设置文字图标下
    ui->toolBar->setMovable(false);
}
