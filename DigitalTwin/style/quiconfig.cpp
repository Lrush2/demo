#include "quiconfig.h"

QUIConfig::QUIConfig()
{

}

QChar QUIConfig::IconMain = QChar(0xf072);
QChar QUIConfig::IconMenu = QChar(0xf0d7);
QChar QUIConfig::IconMin = QChar(0xf068);
QChar QUIConfig::IconMax = QChar(0xf2d2);
QChar QUIConfig::IconNormal = QChar(0xf2d0);
QChar QUIConfig::IconClose = QChar(0xf00d);

QChar QUIConfig::TitleClose = QChar(0xf00d);

#ifdef __arm__
QString QUIConfig::FontName = "Droid Sans Fallback";
int QUIConfig::FontSize = 13;
#else
QString QUIConfig::FontName = "Microsoft Yahei";
int QUIConfig::FontSize = 9;
#endif

QString QUIConfig::ConfigFile = "config.ini";
QString QUIConfig::TextColor = "#F0F0F0";
QString QUIConfig::PanelColor = "#F0F0F0";
QString QUIConfig::BorderColor = "#F0F0F0";
QString QUIConfig::NormalColorStart = "#F0F0F0";
QString QUIConfig::NormalColorEnd = "#F0F0F0";
QString QUIConfig::DarkColorStart = "#F0F0F0";
QString QUIConfig::DarkColorEnd = "#F0F0F0";
QString QUIConfig::HighColor = "#F0F0F0";

void QUIConfig::ReadConfig()
{
    if (!CheckConfig()) {
        return;
    }

    QSettings set(QUIConfig::ConfigFile, QSettings::IniFormat);

    set.beginGroup("BaseConfig");
    set.endGroup();
}

void QUIConfig::WriteConfig()
{
    QSettings set(QUIConfig::ConfigFile, QSettings::IniFormat);

    set.beginGroup("BaseConfig");
    set.endGroup();
}

void QUIConfig::NewConfig()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#endif
    WriteConfig();
}

bool QUIConfig::CheckConfig()
{
    //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
    QFile file(QUIConfig::ConfigFile);

    if (file.size() == 0) {
        NewConfig();
        return false;
    }

    //如果配置文件不完整,则以初始值继续运行,并生成配置文件
    if (file.open(QFile::ReadOnly)) {
        bool ok = true;

        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            QStringList list = line.split("=");

            if (list.count() == 2) {
                if (list.at(1) == "") {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            NewConfig();
            return false;
        }
    } else {
        NewConfig();
        return false;
    }

    return true;
}
