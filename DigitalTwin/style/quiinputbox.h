#ifndef QUIINPUTBOX_H
#define QUIINPUTBOX_H

#include "head.h"
#include "iconhelper.h"
#include "quiconfig.h"


class QUIInputBox : public QDialog
{
    Q_OBJECT
public:
    explicit QUIInputBox(QWidget *parent = 0);
    ~QUIInputBox();

    static QUIInputBox *Instance()
    {
        static QMutex mutex;

        if (!self) {
            QMutexLocker locker(&mutex);

            if (!self) {
                self = new QUIInputBox;
            }
        }

        return self;
    }

protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    static QUIInputBox *self;

    QVBoxLayout *verticalLayout1;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout1;
    QLabel *labIco;
    QLabel *labTitle;
    QLabel *labTime;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout2;
    QPushButton *btnMenu_Close;
    QWidget *widgetMain;
    QVBoxLayout *verticalLayout2;
    QFrame *frame;
    QVBoxLayout *verticalLayout3;
    QLabel *labInfo;
    QLineEdit *txtValue;
    QComboBox *cboxValue;
    QHBoxLayout *lay;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;

private:
    int closeSec;                   //总显示时间
    int currentSec;                 //当前已显示时间
    QString value;                  //当前值

private slots:
    void initControl();             //初始化控件
    void initForm();                //初始化窗体
    void checkSec();                //校验倒计时

private slots:
    void on_btnOk_clicked();
    void on_btnMenu_Close_clicked();

public:
    QString getValue()const;

public Q_SLOTS:
    void setIconMain(QChar str, quint32 size = 9);
    void setParameter(const QString &title, int type = 0, int closeSec = 0,
                      QString defaultValue = QString(), bool pwd = false);
};

#endif // QUIINPUTBOX_H
