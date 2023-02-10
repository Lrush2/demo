#ifndef CONFIGFORM_H
#define CONFIGFORM_H

#include <QWidget>
#include "style/title.h"
#include <QVBoxLayout>

namespace Ui {
class ConfigForm;
}

class ConfigForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigForm(QWidget *parent = nullptr);
    ~ConfigForm();
    void paintEvent(QPaintEvent *e);
    void initTableWidget();

private:
    Ui::ConfigForm *ui;
    title *mytitle;
    //表格项名称
    QVector<QString> check_str;
};

#endif // CONFIGFORM_H
