#include "qtonks_switch.h"

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

std::unique_ptr<Parameter> SwitchParameterBuilder::build(const QJsonObject &object, QFormLayout *layout)
{
    QString label = object["label"].toString();

    auto checkBox = new QCheckBox();
    checkBox->setText(label);

    layout->addRow(checkBox);

    return std::make_unique<SwitchParameter>(checkBox);
}

const char* SwitchParameterBuilder::name()
{
    return "switch";
}

}
