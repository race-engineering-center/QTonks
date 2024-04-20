#include "qtonks_integer.h"

#include <QLabel>

namespace QTonks
{

IntegerParameter::IntegerParameter(QSpinBox *spinBox) :
    m_spinBox(spinBox)
{

}

QJsonObject IntegerParameter::getCurrentSettings() const
{
    QJsonObject result;
    result["value"] = m_spinBox->value();
    return result;
}

void IntegerParameter::setCurrentSettings(const QJsonObject &settings)
{
    if (settings.contains("value") && settings["value"].isDouble())
    {
        m_spinBox->setValue(settings["value"].toInt());
    }
}

std::unique_ptr<Parameter> IntegerParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    auto spinBox = new QSpinBox;
    auto label = new QLabel;

    QString nameLabel = object["label"].toString();
    int minValue = object["min"].toInt();
    int maxValue = object["max"].toInt();
    int defaultValue = object["default"].toInt();

    spinBox->setMinimum(minValue);
    spinBox->setMaximum(maxValue);
    spinBox->setValue(defaultValue);

    label->setText(nameLabel);

    auto horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(label);
    horizontalLayout->addWidget(spinBox);

    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(horizontalLayout);

    return std::make_unique<IntegerParameter>(spinBox);
}

const char *IntegerParameterBuilder::name()
{
    return "integer";
}

}
