#include "layerdata.h"
#include "style/sensechart.h"
#include "ui_layerdata.h"

LayerData::LayerData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LayerData)
{
    ui->setupUi(this);
    initCharts();
    initTableWidget();
    initToolBar();
}

LayerData::~LayerData()
{
    delete ui;
}

void LayerData::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void LayerData::initCharts()
{
    ChartInflux = new SenseChart();

    //influx
    ui->graphicsInflux->setChart(ChartInflux->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsInflux->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphicsInflux->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphicsInflux->setContentsMargins(0,0,0,0);

}

void LayerData::initTableWidget()
{
    //设置列数和列宽
    int width = qApp->desktop()->availableGeometry().width() - 120;
    ui->ChannelWidget->setColumnCount(6);
    ui->ChannelWidget->setColumnWidth(0, width * 0.07);
    ui->ChannelWidget->setColumnWidth(1, width * 0.07);
    ui->ChannelWidget->setColumnWidth(2, width * 0.06);
    ui->ChannelWidget->setColumnWidth(3, width * 0.07);
    ui->ChannelWidget->setColumnWidth(4, width * 0.07);
    ui->ChannelWidget->setColumnWidth(5, width * 0.07);

    ui->ChannelWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "通道ID" << "通道使能" << "通道名称" << "传感器类型"<< "温漂补偿值" << "时漂补偿值";
    ui->ChannelWidget->setHorizontalHeaderLabels(headText);
    ui->ChannelWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ChannelWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ChannelWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ChannelWidget->setAlternatingRowColors(false);
    ui->ChannelWidget->verticalHeader()->setVisible(false);
    ui->ChannelWidget->horizontalHeader()->setStretchLastSection(true);

    //初始化传感器字符串
    //check_str = {"ch01","ch02","ch03","ch04","应变传感器","温度传感器"};


    //设置行高和行数
    ui->ChannelWidget->setRowCount(32);
    int custom_height = qApp->desktop()->availableGeometry().height() - 150;

    for (int i = 0; i < 32; i++) {
        ui->ChannelWidget->setRowHeight(i, custom_height * 0.05);

        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString("ch%1").arg(i + 1));

        QCheckBox *checkSense = new QCheckBox();
        checkSense->setChecked(false);
        checkSense->setText(QString("开启通道"));
        ui->ChannelWidget->setItem(i, 0, itemDeviceID);
        ui->ChannelWidget->setCellWidget(i, 1, checkSense);
        ui->ChannelWidget->item (i,0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //ui->tableWidget->item (i,1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    }


    ui->ChannelWidget->horizontalHeader()->setFont(QFont("song", 12));

    //点击表时不对表头行光亮（获取焦点）
    ui->ChannelWidget->horizontalHeader()->setHighlightSections(false);
    //设置表头字体加粗

    QFont font =  ui->ChannelWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->ChannelWidget->horizontalHeader()->setFont(font);
    //所有单元格的字体  设置成一样
    ui->ChannelWidget->setFont(QFont("song", 12));
}

void LayerData::initToolBar()
{
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/10.png"),tr("打开")));
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/11.png"),tr("删除")));
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/12.png"),tr("测试")));

    ui->toolBar->setIconSize(QSize(60,36));//宽 高

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


