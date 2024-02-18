#include "qtonks_switchparameter.h"

namespace QTonks
{

SwitchParameter::SwitchParameter(QCheckBox *checkBox) :
    m_checkBox(checkBox)
{

}

QJsonObject SwitchParameter::getCurrentSettings() const
{
    return {};
}

void SwitchParameter::setCurrentSettings(const QJsonObject &settings)
{

}

}
