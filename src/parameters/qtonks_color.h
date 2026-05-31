#ifndef QTONKS_COLORPARAMETER_H
#define QTONKS_COLORPARAMETER_H

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

#include <QLabel>
#include <QColor>

namespace QTonks
{

class ColorPickerLabel : public QLabel
{
    Q_OBJECT

public:
    void setColor(QColor color);
    QColor color() const;

    void mousePressEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent *) override;
private:
    QColor m_color;

signals:
    void colorChanged();
};

class ColorParameter : public Parameter
{
public:
    explicit ColorParameter(ColorPickerLabel* colorPicker, QColor color);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    ColorPickerLabel* m_colorPicker;
};

class ColorParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_COLORPARAMETER_H