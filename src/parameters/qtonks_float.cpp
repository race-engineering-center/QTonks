#include "qtonks_float.h"

#include <QLabel>

namespace QTonks
{

FloatParameter::FloatParameter(QDoubleSpinBox *spinBox) :
    m_spinBox(spinBox)
{

}

QJsonObject FloatParameter::getCurrentSettings() const
{
    QJsonObject result;
    result["value"] = m_spinBox->value();
    return result;
}

void FloatParameter::setCurrentSettings(const QJsonObject &settings)
{
    if (settings.contains("value") && settings["value"].isDouble())
    {
        m_spinBox->setValue(settings["value"].toDouble());
    }
}

std::unique_ptr<Parameter> FloatParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    auto spinBox = new QDoubleSpinBox;
    auto label = new QLabel;

    QString nameLabel = object["label"].toString();
    double minValue = object["min"].toDouble();
    double maxValue = object["max"].toDouble();
    double defaultValue = object["default"].toDouble();
    double stepValue = object["step"].toDouble(1.0);

    spinBox->setMinimum(minValue);
    spinBox->setMaximum(maxValue);
    spinBox->setSingleStep(stepValue);
    spinBox->setValue(defaultValue);

    QObject::connect(spinBox, &QDoubleSpinBox::valueChanged, widget, [widget](double){
        emit widget->currentSettingsChanged(widget->getCurrentSettings());
    });

    label->setText(nameLabel);

    auto horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(label);
    horizontalLayout->addWidget(spinBox);

    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(horizontalLayout);

    return std::make_unique<FloatParameter>(spinBox);
}

const char *FloatParameterBuilder::name()
{
    return "float";
}

}
