#include "configwizard.h"
#include "ui_configwizard.h"

ConfigWizard::ConfigWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigWizard)
{
    ui->setupUi(this);
}

ConfigWizard::~ConfigWizard()
{
    delete ui;
}
