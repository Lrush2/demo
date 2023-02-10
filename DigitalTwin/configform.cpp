#include "configform.h"
#include "ui_configform.h"


ConfigForm::ConfigForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigForm)
{
    //关闭按钮只是隐藏掉，没析构
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);    //隐藏标题栏（无边框）

    QString text = tr("传感器配置");
    mytitle = new title(this, text);
    mytitle->setParent(this);
    //新建一个垂直布局，并将title对象、ui->stackedWidget放置入该垂直布局中去
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(mytitle);
    layout->addWidget(ui->widget);
    //设置垂直布局间隙
    layout->setSpacing(0);
    layout->setMargin(0);

    //要单独设置qss样式，因为弹窗是点击时才创建，只能继承主窗口的qss
    ui->widget->setStyleSheet("#widget{background-color:white;"
                        "border-width:1px;"
                        "border-style:solid;"
                        "border-color:white}");
    IconHelper::Instance()->setIcon(ui->btn_configOK, QChar(0xf00c), 20);
    IconHelper::Instance()->setIcon(ui->btn_configCancel, QChar(0xf00d), 20);

    initTableWidget();
}

ConfigForm::~ConfigForm()
{
    delete ui;
}

//重写事件解除父窗口QSS对子窗口的覆盖
void ConfigForm::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void ConfigForm::initTableWidget()
{
    //设置列数和列宽
    int width = qApp->desktop()->availableGeometry().width() - 120;
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setColumnWidth(0, width * 0.03);
    ui->tableWidget->setColumnWidth(1, width * 0.05);
    ui->tableWidget->setColumnWidth(2, width * 0.05);
    ui->tableWidget->setColumnWidth(3, width * 0.05);
    ui->tableWidget->setColumnWidth(4, width * 0.05);
    ui->tableWidget->setColumnWidth(5, width * 0.05);
    ui->tableWidget->setColumnWidth(6, width * 0.05);
    ui->tableWidget->setColumnWidth(7, width * 0.05);
    ui->tableWidget->setColumnWidth(8, width * 0.05);
    ui->tableWidget->setColumnWidth(9, width * 0.05);

    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "编号" << "传感器类型"  << "采样点数" << "采样频率"<<"分析频率"<< "上截止频率" <<"下截止频率"<<"滤波形式" << "滤波器种类" << "滤波类型" ;
    ui->tableWidget->setHorizontalHeaderLabels(headText);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //初始化传感器字符串
    check_str = {"静压传感器","动压传感器","剪切传感器","风速传感器","应变传感器","温度传感器"};


    //设置行高和行数
    ui->tableWidget->setRowCount(6);
    int custom_height = qApp->desktop()->availableGeometry().height() - 150;

    for (int i = 0; i < 6; i++) {
        ui->tableWidget->setRowHeight(i, custom_height * 0.05);

        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(i + 1));

        QCheckBox *checkSense = new QCheckBox();
        checkSense->setChecked(false);
        checkSense->setText(check_str[i]);
        ui->tableWidget->setItem(i, 0, itemDeviceID);
        ui->tableWidget->setCellWidget(i, 1, checkSense);
        ui->tableWidget->item (i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //ui->tableWidget->item (i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    }


    ui->tableWidget->horizontalHeader()->setFont(QFont("song", 12));

    //点击表时不对表头行光亮（获取焦点）
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);
    //设置表头字体加粗

    QFont font =  ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
    //所有单元格的字体  设置成一样
    ui->tableWidget->setFont(QFont("song", 12));

}
