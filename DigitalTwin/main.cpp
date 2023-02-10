//#include "digitaltwin.h"
#include "mainwidget.h"
#include "style/appinit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //测试代码
    qDebug()<<"argc is "<<argc;
    for(int i = 0;i<argc;i++){
        qDebug()<<"argv["<<i<<"] is"<<argv[i];
    }

    QApplication a(argc, argv);

    a.setFont(QFont("Microsoft Yahei", 12));
    a.setWindowIcon(QIcon(":/main.ico"));

    DigitalTwin::setCode();
    DigitalTwin::setTranslator(":/image/qt_zh_CN.qm");
    DigitalTwin::setTranslator(":/image/widgets.qm");
    AppInit::Instance()->start();

    //读取配置文件
    //QUIConfig::ConfigFile = QString("%1/%2").arg(DigitalTwin::appPath()).arg("qui_config.ini");
    //QUIConfig::ReadConfig();

    DigitalTwin digital;
    MainWidget *mainwidget = new MainWidget;
    //设置主窗体
    digital.setMainWidget(mainwidget);
    //信号和槽函数传递了相同的参数
    //QObject::connect(&digital, SIGNAL(changeStyle(QString)), mainwidget, SLOT(changeStyle(QString)));

    //设置标题
    digital.setTitle("智能蒙皮数字孪生系统");
    //digital.setStyle(DigitalTwin::Style_DarkBlue);
    digital.setStyle(DigitalTwin::Style_LightBlue);
    //设置标题文本居中
    //qui.setAlignment(Qt::AlignCenter);
    digital.setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);

    //设置窗体可拖动大小
    digital.setSizeGripEnabled(true);

    //设置换肤下拉菜单可见
    digital.setVisible(DigitalTwin::BtnMenu, true);

    //设置标题栏高度
    //qui.setTitleHeight(50);

    //设置按钮宽度
    //qui.setBtnWidth(50);

    //设置左上角图标-图形字体
    //qui.setIconMain(QChar(0xf099), 14);

    //设置左上角图标-图片文件
    //qui.setPixmap(DigitalTwin::Lab_Ico, ":/main.ico");

    digital.show();
    return a.exec();
}
