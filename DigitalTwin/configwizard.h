#ifndef CONFIGWIZARD_H
#define CONFIGWIZARD_H

#include <QWizard>

namespace Ui {
class ConfigWizard;
}

class ConfigWizard : public QWizard
{
    Q_OBJECT

public:
    explicit ConfigWizard(QWidget *parent = nullptr);
    ~ConfigWizard();

private:
    Ui::ConfigWizard *ui;
};

#endif // CONFIGWIZARD_H
