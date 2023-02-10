#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
//    this->resize();
//    ui->label->setPixmap(QPixmap(":/image/welcome.png"));
//    ui->label->setScaledContents(false);
}

Welcome::~Welcome()
{
    delete ui;
}
