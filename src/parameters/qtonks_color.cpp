#include "qtonks_color.h"

namespace QTonks
{

ColorParameter::ColorParameter(QLabel *label)
    : m_colorPicker(label)
{

}

QJsonObject ColorParameter::getCurrentSettings() const
{
    return {};
}

void ColorParameter::setCurrentSettings(const QJsonObject &settings)
{

}

std::unique_ptr<Parameter> ColorParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    auto label = new QLabel;
    auto colorPicker = new QLabel;

    QString nameLabel = object["label"].toString();
    label->setText(nameLabel);

    auto horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(label);
    horizontalLayout->addWidget(colorPicker);

    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(horizontalLayout);

    return std::make_unique<ColorParameter>(colorPicker);
}

const char *ColorParameterBuilder::name()
{
    return "color";
}

}
