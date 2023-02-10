#ifndef QUICONFIG_H
#define QUICONFIG_H

#include "head.h"

class QUIConfig
{
public:
    QUIConfig();
public:
    //全局图标
    static QChar IconMain;          //标题栏左上角图标
    static QChar IconMenu;          //下拉菜单图标
    static QChar IconMin;           //最小化图标
    static QChar IconMax;           //最大化图标
    static QChar IconNormal;        //还原图标
    static QChar IconClose;         //关闭图标

    static QChar TitleClose;       //弹窗关闭图标

    static QString FontName;        //全局字体名称
    static int FontSize;            //全局字体大小
    static QString ConfigFile;      //配置文件文件路径及名称

    //样式表颜色值
    static QString TextColor;       //文字颜色
    static QString PanelColor;      //面板颜色
    static QString BorderColor;     //边框颜色
    static QString NormalColorStart;//正常状态开始颜色
    static QString NormalColorEnd;  //正常状态结束颜色
    static QString DarkColorStart;  //加深状态开始颜色
    static QString DarkColorEnd;    //加深状态结束颜色
    static QString HighColor;       //高亮颜色

    static void ReadConfig();       //读取配置文件,在main函数最开始加载程序载入
    static void WriteConfig();      //写入配置文件,在更改配置文件程序关闭时调用
    static void NewConfig();        //以初始值新建配置文件
    static bool CheckConfig();      //校验配置文件
};

#endif // QUICONFIG_H
