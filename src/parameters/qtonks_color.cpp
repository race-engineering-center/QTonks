#include "qtonks_color.h"

#include <QColorDialog>
#include <QPainter>

namespace QTonks
{

void ColorPickerLabel::setColor(QColor color)
{
    m_color = color;
}

QColor ColorPickerLabel::color() const
{
    return m_color;
}

void ColorPickerLabel::mousePressEvent(QMouseEvent *ev)
{
    QColor color = QColorDialog::getColor(m_color, window());
    if (!color.isValid())
        return;

    if (color == m_color)
        return;

    m_color = color;
    update();
    emit sendColorChanged();
}

void ColorPickerLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.setBrush(m_color);

    painter.drawRect(0, 0, width(), height());
}

ColorParameter::ColorParameter(ColorPickerLabel *label, QColor color)
    : m_colorPicker(label)
    , m_color(color)
{
    m_colorPicker->setColor(color);
}

QJsonObject ColorParameter::getCurrentSettings() const
{
    QJsonObject result;

    result["color"] = m_colorPicker->color().name(QColor::HexRgb);

    return result;
}

void ColorParameter::setCurrentSettings(const QJsonObject &settings)
{
    QString repr = settings["color"].toString();
    QColor color(repr);
    m_colorPicker->setColor(color);
    m_color = color;
}

std::unique_ptr<Parameter> ColorParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    auto label = new QLabel;
    auto colorPicker = new ColorPickerLabel;

    QString repr = object["default"].toString();
    QColor color(repr);
    qDebug()<<color<<repr;

    QString nameLabel = object["label"].toString();
    label->setText(nameLabel);

    auto horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(label);
    horizontalLayout->addWidget(colorPicker);

    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(horizontalLayout);

    QObject::connect(colorPicker, &ColorPickerLabel::sendColorChanged, widget, [widget]() {
        emit widget->currentSettingsChanged(widget->getCurrentSettings());
    });

    return std::make_unique<ColorParameter>(colorPicker, color);
}

const char *ColorParameterBuilder::name()
{
    return "color";
}

}
