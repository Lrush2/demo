#include "title.h"
#include "ui_title.h"




title::title(QWidget *parent, QString text) :
    QWidget(parent),
    ui(new Ui::title)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);    //隐藏标题栏（无边框）
    connect(ui->btn_close,SIGNAL(clicked(bool)),this, SLOT(onClicked()));
    //connect(ui->pushButton,SIGNAL(clicked(bool)),this, SLOT(onClicked()));
    //connect(ui->pushButton_3,SIGNAL(clicked(bool)),this, SLOT(onClicked()));

    IconHelper::Instance()->setIcon(ui->label_icon, QChar(0xf1d8), 15);
    IconHelper::Instance()->setIcon(ui->btn_close, QUIConfig::TitleClose, 15);
    ui->label_title->setText(text);

    //单个控件自定义底纹显示，不能加btn_close，在QSS里要加，不然格式不对
    //关闭按钮红色背景-悬停
//    ui->btn_close->setStyleSheet("QPushButton:hover{"
//                                     "color:#FFFFFF;"
//                                     "margin:1px 1px 2px 1px;"
//                                     "background-color:rgba(238,0,0,128);"
//                                     "}");


}

title::~title()
{
    delete ui;
}

void title::mousePressEvent(QMouseEvent *event)
{
    //鼠标左键按下事件
    if(event->button()==Qt::LeftButton)
    {
        //记录鼠标左键状态
        m_leftButtonPressed = true;
        //记录鼠标在屏幕中的位置
        m_start = event->globalPos();
//        qDebug()<<QString::fromLocal8Bit("左键被按下了");
    }
}

void title::mouseMoveEvent(QMouseEvent *event)
{
    if(m_leftButtonPressed)
    {
        //将父窗体移动到父窗体原来的位置加上鼠标移动的位置:event->globalPos()-m_start
        //this->window（）获取
        this->window()->move(this->window()->geometry().topLeft()+event->globalPos()-m_start);
        //将鼠标在屏幕中的位置替换为新的位置
        m_start = event->globalPos();
    }
}

void title::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_leftButtonPressed = false;
    }
}

//void title::mouseDoubleClickEvent(QMouseEvent *event)
//{
//    Q_UNUSED(event);
//    ui->pushButton_3->click();
//}

void title::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();

    if (pWindow->isTopLevel())
    {
        if(pButton == ui->btn_close)
        {
            pWindow->close();
        }
//        else if(pButton == ui->pushButton)
//        {
//            pWindow->showMinimized();
//        }
//        else if(pButton == ui->pushButton_3)
//        {
//            pWindow->isMaximized()?pWindow->showNormal():pWindow->showMaximized();
//        }
    }
}

//重写事件解除父窗口QSS对子窗口的覆盖
void title::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
