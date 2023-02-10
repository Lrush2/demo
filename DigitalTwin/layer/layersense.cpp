#include "layersense.h"
#include "style/sensechart.h"//头文件要放在UI前面
#include "ui_layersense.h"

LayerSense::LayerSense(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LayerSense)
{
    ui->setupUi(this);
    this->setContentsMargins(0,0,0,0);
    initCharts();
    initLab();
    initTableWidget();

    InitMenu();
    initToolBar();
}

LayerSense::~LayerSense()
{
    delete ui;
}

void LayerSense::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void LayerSense::initCharts()
{
    m_timer = new QTimer(this);
    m_timer->setSingleShot(false);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
    QObject::connect(ui->btn_Clear, SIGNAL(clicked(bool)), this, SLOT(slotBtnClear()));
    QObject::connect(ui->btn_StartAndStop, SIGNAL(clicked(bool)), this, SLOT(slotBtnStartAndStop()));

    ChartStatic = new SenseChart();//添加坐标都在构造函数中实现
    ChartDynamic = new SenseChart();
    ChartShear = new SenseChart();
    ChartVelocity = new SenseChart();
    ChartStrain = new SenseChart();
    ChartTemperature = new SenseChart();
//    //dataWidget图表
//    ChartInflux = new SenseChart();

    ui->graphics_Static->setChart(ChartStatic->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphics_Static->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphics_Static->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphics_Static->setContentsMargins(0,0,0,0);

    ui->graphics_Dynamic->setChart(ChartDynamic->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphics_Dynamic->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphics_Dynamic->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphics_Dynamic->setContentsMargins(0,0,0,0);

    ui->graphics_Shear->setChart(ChartShear->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphics_Shear->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphics_Shear->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphics_Shear->setContentsMargins(0,0,0,0);

    ui->graphics_Velocity->setChart(ChartVelocity->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphics_Velocity->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphics_Velocity->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphics_Velocity->setContentsMargins(0,0,0,0);

    ui->graphics_Strain->setChart(ChartStrain->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphics_Strain->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphics_Strain->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphics_Strain->setContentsMargins(0,0,0,0);

    ui->graphics_Temperature->setChart(ChartTemperature->m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphics_Temperature->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->graphics_Temperature->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
    ui->graphics_Temperature->setContentsMargins(0,0,0,0);


//    //influx
//    ui->graphicsInflux->setChart(ChartInflux->m_chart);                           // 将图表对象设置到graphicsView上进行显示
//    ui->graphicsInflux->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
//    ui->graphicsInflux->setBackgroundBrush(QBrush(QColor(16,20,32)));//设置背景为钢蓝色
//    ui->graphicsInflux->setContentsMargins(0,0,0,0);

}

void LayerSense::initTableWidget()
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

void LayerSense::slotBtnClear()
{
    ChartStatic->BtnClear();
    ChartDynamic->BtnClear();
    ChartShear->BtnClear();
    ChartVelocity->BtnClear();
    ChartStrain->BtnClear();
    ChartTemperature->BtnClear();
    pointCount = 0;
}

void LayerSense::slotBtnStartAndStop()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
        ui->btn_StartAndStop->setText("开始采集");
    }else
    {
        //pointCount = 0;
        m_timer->start(200);
        ui->btn_StartAndStop->setText("停止采集");
    }
}

void LayerSense::slotTimeout()
{
    ChartStatic->Timeout(pointCount);//大槽函数负责pointCount统一清零，小函数负责用传递的pointCount更新坐标
    ChartDynamic->Timeout(pointCount);
    ChartShear->Timeout(pointCount);
    ChartVelocity->Timeout(pointCount);
    ChartStrain->Timeout(pointCount);
    ChartTemperature->Timeout(pointCount);
    pointCount++;
}

void LayerSense::initLab()
{
    IconHelper::Instance()->setIcon(ui->add_Row,0xf067,20);
    IconHelper::Instance()->setIcon(ui->delete_Row,0xf068,20);
    //连接槽函数
    connect(ui->add_Row, SIGNAL(clicked()), this, SLOT(on_addRow_clicked()));
    connect(ui->delete_Row, SIGNAL(clicked()), this, SLOT(on_deleteRow_clicked()));
}
void LayerSense::on_addRow_clicked()
{
    DigitalTwin::showMessageBoxInfo("传感器添加成功!");
}
void LayerSense::on_deleteRow_clicked()
{
    DigitalTwin::showMessageBoxInfo("传感器删除成功!");
}

void LayerSense::InitMenu()
{
//    this->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
//    senseMenu = new QMenu(this);
//    senseMenu->setFont(QFont("Microsoft Yahei", 12));
//    QStringList str;
//    str << u8"测点信息设置" << u8"传感类型设置"<< u8"滤波器选择"<< u8"窗函数选择"<< u8"通道设置";
//    QVector<QAction*> action_vector(5);//1.防止内存拷贝给了14。2.容器内最好是指针类型。
//    for(int i = 0;i<action_vector.size();i++)
//    {
//        action_vector[i] = new QAction();//不可以直接在后面加父窗口
//        action_vector[i]->setText(str.at(i));
//        senseMenu->addAction(action_vector[i]);
//        connect(action_vector[i], SIGNAL(triggered()), this, SLOT(slotTest()));
//    }
//    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu()));
}
void LayerSense::slotContextMenu()
{
    senseMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}
void LayerSense::slotTest()
{
   //DigitalTwin::showMessageBoxInfo("传感器添加成功!");
    DigitalTwin::showMessageBoxInfo("传感器添加成功!");
}

void LayerSense::initToolBar()
{
//    QWidget *btn1 = ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/10.png"),tr("打开")));//工具栏响应按钮
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/11.png"),tr("删除")));
//    ui->toolBar->widgetForAction(ui->toolBar->addAction(QIcon(":/logo/12.png"),tr("测试")));


    connect(ui->home, SIGNAL(triggered()), this, SLOT(slotTest()));

//    ui->toolBar->setIconSize(QSize(60,36));//宽 高  5-3

//    ui->toolBar->setFixedSize(1000,80);

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



