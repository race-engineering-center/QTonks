#ifndef QTONKS_COLORARAMETER_H
#define QTONKS_COLORARAMETER_H

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

#include <QLabel>

namespace QTonks
{

class ColorParameter : public Parameter
{
public:
    explicit ColorParameter(QLabel* colorPicker);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    QLabel* m_colorPicker;
};

class ColorParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_COLORARAMETER_H