#include "digitaltest.h"
#include "ui_digitaltest.h"

DigitalTest::DigitalTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DigitalTest)
{
    ui->setupUi(this);
    this->initControl();
    this->initForm();
}

DigitalTest::~DigitalTest()
{
    delete widgetMain;
    delete ui;
}

