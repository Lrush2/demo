#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMenu>
#include "layer/layersense.h"
#include "layer/layerdata.h"
#include "layer/layermodel.h"
#include "layer/layerfunction.h"
#include "layer/layerdecision.h"
#include "welcome.h"
#include "workwidget.h"
#include "configform.h"
#include "configwizard.h"

//class DigitalTwin;
//class LayerSense;
//class LayerData;
//class LayerModel;
//class LayerFunction;
//class LayerDecision;
//class Welcome;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    //界面初始化
    void initForm();
//    void InitMenu();

private:
    Ui::MainWidget *ui;
    QFont iconFont;             //图形字体

    QString currentFile;        //当前QSS文件
    QString currentQSS;         //当前QSS文本

    WorkWidget *workWidget;

    title *title_window;
    ConfigForm *configForm;

    ConfigWizard *configWizard;


private slots:

//    void switchPage();
//    void slotContextMenu();
//    void slotTest();
    void on_NewConfig_clicked();

};

#endif // MAINWIDGET_H
