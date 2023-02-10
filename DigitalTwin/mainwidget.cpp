#include "mainwidget.h"
#include "ui_mainwidget.h"
//#include "digitaltwin.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->resize(1500,1000);
    this->initForm();
//    InitMenu();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initForm()
{
    //引入图形字体
    int fontId = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
    //左 上 右 下 左栏设置

    //workForm = new WorkForm(ui->widget);
    workWidget = new WorkWidget(ui->widget);

    //ui->tabWidget->setFont(QFont("Microsoft Yahei", 10));
    ui->tab->setFont(QFont("Microsoft Yahei", 10));
    ui->tab_2->setFont(QFont("Microsoft Yahei", 10));
    ui->tab_3->setFont(QFont("Microsoft Yahei", 10));
    ui->tab_4->setFont(QFont("Microsoft Yahei", 10));
    ui->tab_5->setFont(QFont("Microsoft Yahei", 10));
    connect(ui->NewConfig, SIGNAL(clicked()), this, SLOT(on_NewConfig_clicked()));

//    title_window = new title();
//    title_window->show();
    configForm = new ConfigForm();
    //configForm->show();
    configWizard = new ConfigWizard();

}

void MainWidget::on_NewConfig_clicked()
{
    //DigitalTwin::showMessageBoxInfo("传感器添加成功!");
    //title_window->show();
    //configForm->show();
    configWizard->show();
}



