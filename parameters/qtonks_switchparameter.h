#ifndef QTONKS_SWITCHPARAMETER_H
#define QTONKS_SWITCHPARAMETER_H

#include <QCheckBox>

#include "qtonks_parameter.h"

namespace QTonks
{

class SwitchParameter : public Parameter
{
public:
    SwitchParameter(QCheckBox* checkBox);
    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    QCheckBox* m_checkBox;
};

}

#endif // QTONKS_SWITCHPARAMETER_H
