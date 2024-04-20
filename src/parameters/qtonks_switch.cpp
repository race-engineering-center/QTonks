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

std::unique_ptr<Parameter> SwitchParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    QString label = object["label"].toString();

    auto checkBox = new QCheckBox();
    checkBox->setText(label);

    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(checkBox);

    QObject::connect(checkBox, &QCheckBox::toggled, widget, [widget](bool on){
        Q_UNUSED(on);
        emit widget->currentSettingsChanged(widget->getCurrentSettings());
    });

    return std::make_unique<SwitchParameter>(checkBox);
}

const char* SwitchParameterBuilder::name()
{
    return "switch";
}

}
