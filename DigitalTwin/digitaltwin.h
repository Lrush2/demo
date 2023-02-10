#ifndef DIGITALTWIN_H
#define DIGITALTWIN_H

#define TIMEMS qPrintable (QTime::currentTime().toString("HH:mm:ss zzz"))
#define TIME qPrintable (QTime::currentTime().toString("HH:mm:ss"))
#define QDATE qPrintable (QDate::currentDate().toString("yyyy-MM-dd"))
#define QTIME qPrintable (QTime::currentTime().toString("HH-mm-ss"))
#define DATETIME qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
#define STRDATETIME qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss"))
#define STRDATETIMEMS qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss-zzz"))

#ifdef Q_OS_WIN
#define NEWLINE "\r\n"
#else
#define NEWLINE "\n"
#endif

#include "style/head.h"
#include <QDialog>
#include "style/quiinputbox.h"
#include "style/quimessagebox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DigitalTwin; }
QT_END_NAMESPACE

class DigitalTwin : public QDialog
{
    Q_OBJECT
    Q_ENUMS(Style)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(Qt::Alignment alignment READ getAlignment WRITE setAlignment)

public:
    //将部分对象作为枚举值暴露给外部
    enum Widget {
        Lab_Ico = 0,                //左上角图标
        BtnMenu = 1,                //下拉菜单按钮
        BtnMenu_Min = 2,            //最小化按钮
        BtnMenu_Max = 3,            //最大化按钮
        BtnMenu_Normal = 4,         //还原按钮
        BtnMenu_Close = 5           //关闭按钮
    };

    //样式枚举
    enum Style {
        Style_Silvery = 0,          //银色样式
        Style_Blue = 1,             //蓝色样式
        Style_LightBlue = 2,        //淡蓝色样式
        Style_DarkBlue = 3,         //深蓝色样式
        Style_Gray = 4,             //灰色样式
        Style_LightGray = 5,        //浅灰色样式
        Style_DarkGray = 6,         //深灰色样式
        Style_Black = 7,            //黑色样式
        Style_LightBlack = 8,       //浅黑色样式
        Style_DarkBlack = 9,        //深黑色样式
        Style_PSBlack = 10,         //PS黑色样式
        Style_FlatBlack = 11,       //黑色扁平样式
        Style_FlatWhite = 12        //白色扁平样式
    };

    //全局静态方法集合开始--------------------------------
public:
    //桌面宽度高度
    static int deskWidth();
    static int deskHeight();

    //程序本身文件名称
    static QString appName();
    //程序当前所在路径
    static QString appPath();

    //新建目录
    static void newDir(const QString &dirName);

    //写入消息到额外的的消息日志文件
    static void writeInfo(const QString &info, const QString &filePath = "log");

    //设置全局样式
    static void setStyle(DigitalTwin::Style style);
    static void setStyle(const QString &qssFile, QString &paletteColor, QString &textColor);
    static void setStyle(const QString &qssFile, QString &textColor,
                         QString &panelColor, QString &borderColor,
                         QString &normalColorStart, QString &normalColorEnd,
                         QString &darkColorStart, QString &darkColorEnd,
                         QString &highColor);

    //根据QSS样式获取对应颜色值
    static void getQssColor(const QString &qss, QString &textColor,
                            QString &panelColor, QString &borderColor,
                            QString &normalColorStart, QString &normalColorEnd,
                            QString &darkColorStart, QString &darkColorEnd,
                            QString &highColor);

    //设置窗体居中显示
    static void setFormInCenter(QWidget *frm);
    //设置翻译文件
    static void setTranslator(const QString &qmFile = ":/image/qt_zh_CN.qm");
    //设置编码
    static void setCode();
    //设置延时
    static void sleep(int sec);
    //设置系统时间
    static void setSystemDateTime(const QString &year, const QString &month, const QString &day,
                                  const QString &hour, const QString &min, const QString &sec);
    //设置开机自启动
    static void runWithSystem(const QString &strName, const QString &strPath, bool autoRun = true);

    //判断是否是IP地址
    static bool isIP(const QString &ip);

    //判断是否是MAC地址
    static bool isMac(const QString &mac);

    //判断是否是合法的电话号码
    static bool isTel(const QString &tel);

    //判断是否是合法的邮箱地址
    static bool isEmail(const QString &email);


    //16进制字符串转10进制
    static int strHexToDecimal(const QString &strHex);

    //10进制字符串转10进制
    static int strDecimalToDecimal(const QString &strDecimal);

    //2进制字符串转10进制
    static int strBinToDecimal(const QString &strBin);

    //16进制字符串转2进制字符串
    static QString strHexToStrBin(const QString &strHex);

    //10进制转2进制字符串一个字节
    static QString decimalToStrBin1(int decimal);

    //10进制转2进制字符串两个字节
    static QString decimalToStrBin2(int decimal);

    //10进制转16进制字符串,补零.
    static QString decimalToStrHex(int decimal);


    //int转字节数组
    static QByteArray intToByte(int i);

    //字节数组转int
    static int byteToInt(const QByteArray &data);

    //ushort转字节数组
    static QByteArray ushortToByte(ushort i);

    //字节数组转ushort
    static int byteToUShort(const QByteArray &data);

    //异或加密算法
    static QString getXorEncryptDecrypt(const QString &str, char key);

    //异或校验
    static uchar getOrCode(const QByteArray &data);

    //计算校验码
    static uchar getCheckCode(const QByteArray &data);


    //字节数组转Ascii字符串
    static QString byteArrayToAsciiStr(const QByteArray &data);

    //16进制字符串转字节数组
    static QByteArray hexStrToByteArray(const QString &str);
    static char convertHexChar(char ch);

    //Ascii字符串转字节数组
    static QByteArray asciiStrToByteArray(const QString &str);

    //字节数组转16进制字符串
    static QString byteArrayToHexStr(const QByteArray &data);

    //获取选择的文件
    static QString getFileName(const QString &filter, QString defaultDir = QCoreApplication::applicationDirPath());

    //获取选择的文件集合
    static QStringList getFileNames(const QString &filter, QString defaultDir = QCoreApplication::applicationDirPath());

    //获取选择的目录
    static QString getFolderName();

    //获取文件名,含拓展名
    static QString getFileNameWithExtension(const QString &strFilePath);

    //获取选择文件夹中的文件
    static QStringList getFolderFileNames(const QStringList &filter);

    //文件夹是否存在
    static bool folderIsExist(const QString &strFolder);

    //文件是否存在
    static bool fileIsExist(const QString &strFile);

    //复制文件
    static bool copyFile(const QString &sourceFile, const QString &targetFile);

    //删除文件夹下所有文件
    static void deleteDirectory(const QString &path);

    //判断IP地址及端口是否在线
    static bool ipLive(const QString &ip, int port, int timeout = 1000);

    //获取网页所有源代码
    static QString getHtml(const QString &url);

    //获取本机公网IP地址
    static QString getNetIP(const QString &webCode);

    //获取本机IP
    static QString getLocalIP();

    //Url地址转为IP地址
    static QString urlToIP(const QString &url);

    //判断是否通外网
    static bool isWebOk();


    //弹出消息框
    static void showMessageBoxInfo(const QString &info, int closeSec = 0);
    //弹出错误框
    static void showMessageBoxError(const QString &info, int closeSec = 0);
    //弹出询问框
    static int showMessageBoxQuestion(const QString &info);

    //弹出输入框
    static QString showInputBox(bool &ok, const QString &title, int type = 0, int closeSec = 0,
                                QString defaultValue = QString(), bool pwd = false);

    //全局静态方法集合结束--------------------------------

public:
    DigitalTwin(QWidget *parent = nullptr);
    ~DigitalTwin();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    QVBoxLayout *verticalLayout1;
    QWidget *widgetMain;
    QVBoxLayout *verticalLayout2;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout4;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnMenu;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Close;
    QWidget *widget;
    QVBoxLayout *verticalLayout3;

private:
    bool max;                       //是否处于最大化状态
    QRect location;                 //鼠标移动窗体后的坐标位置

    QString title;                  //标题
    Qt::Alignment alignment;        //标题文本对齐
    bool minHide;                   //最小化隐藏
    QWidget *mainWidget;            //主窗体对象

public:
    QLabel *getLabIco()             const;
    QLabel *getLabTitle()           const;
    QToolButton *getBtnMenu()       const;
    QPushButton *getBtnMenuMin()    const;
    QPushButton *getBtnMenuMax()    const;
    QPushButton *getBtnMenuMClose() const;

    Style getStyle()                const;
    QString getTitle()              const;
    Qt::Alignment getAlignment()    const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

private slots:
    void initControl();             //初始化控件
    void initForm();                //初始化窗体
    void changeStyle();             //更换样式

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

public Q_SLOTS:
    //设置部件图标
    void setIcon(DigitalTwin::Widget widget, QChar str, quint32 size = 9);
    void setIconMain(QChar str, quint32 size = 9);
    //设置部件图片
    void setPixmap(DigitalTwin::Widget widget, const QString &file, const QSize &size = QSize(16, 16));
    //设置部件是否可见
    void setVisible(DigitalTwin::Widget widget, bool visible = true);
    //设置只有关闭按钮
    void setOnlyCloseBtn();

    //设置标题栏高度
    void setTitleHeight(int height);
    //设置按钮统一宽度
    void setBtnWidth(int width);

    //设置标题及文本样式
    void setTitle(const QString &title);
    void setAlignment(Qt::Alignment alignment);

    //设置最小化隐藏
    void setMinHide(bool minHide);

    //设置主窗体
    void setMainWidget(QWidget *mainWidget);

Q_SIGNALS:
    void changeStyle(const QString &qssFile);
    void closing();

private:
    Ui::DigitalTwin *ui;
};
#endif // DIGITALTWIN_H
