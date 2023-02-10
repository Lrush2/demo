#include "layermodel.h"
#include "ui_layermodel.h"

LayerModel::LayerModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LayerModel)
{
    ui->setupUi(this);
    initLab();
    InitMenu();
    initToolBar();
}

LayerModel::~LayerModel()
{
    delete ui;
}

void LayerModel::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void LayerModel::initLab()
{
    //库文件资源：QUIMessageBox QUIInputBox
    //IconHelper图形字体处理类 QUIConfig全局变量控制类
    //IconHelper::Instance()->setIcon(this->btnMenu, str, size);
    //用对象指针访问成员函数setIcon
    IconHelper::Instance()->setIcon(ui->btnStart,0xf04b,20);
    IconHelper::Instance()->setIcon(ui->btnStop,0xf04d,20);
}

void LayerModel::InitMenu()
{
    this->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    senseMenu = new QMenu(this);
    senseMenu->setFont(QFont("Microsoft Yahei", 12));
    QStringList str;
    str << u8"新建模型" << u8"导入模型"<< u8"导入数据"<< u8"表四"<< u8"表五"<< u8"表六"<< u8"表七"<< u8"表八"
        << u8"表九"<< u8"表十"<< u8"表十一" << u8"表十二" << u8"表十三" << u8"表十四";
    QVector<QAction*> action_vector(14);//1.防止内存拷贝给了14。2.容器内最好是指针类型。
    for(int i = 0;i<action_vector.size();i++)
    {
        action_vector[i] = new QAction();//不可以直接在后面加父窗口
        action_vector[i]->setText(str.at(i));
        senseMenu->addAction(action_vector[i]);
        connect(action_vector[i], SIGNAL(triggered()), this, SLOT(slotTest()));
    }
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu()));
}
void LayerModel::slotContextMenu()
{
    senseMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}
void LayerModel::slotTest()
{
   DigitalTwin::showMessageBoxInfo("传感器添加成功!");
}

void LayerModel::initToolBar()
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

