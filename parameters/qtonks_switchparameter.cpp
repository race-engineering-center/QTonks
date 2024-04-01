#include "qtonks_switchparameter.h"

namespace QTonks
{

SwitchParameter::SwitchParameter(QCheckBox *checkBox) :
    m_checkBox(checkBox)
{

}

QJsonObject SwitchParameter::getCurrentSettings() const
{
    QJsonObject result;
    result["enabled"] = m_checkBox->isChecked();
    return result;
}

void SwitchParameter::setCurrentSettings(const QJsonObject &settings)
{
    m_checkBox->setChecked(settings.value("enabled").toBool());
}

}
