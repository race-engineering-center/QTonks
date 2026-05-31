#ifndef QTONKS_FLOAT_H
#define QTONKS_FLOAT_H

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

#include <QDoubleSpinBox>

namespace QTonks
{

class FloatParameter : public Parameter
{
public:
    FloatParameter(QDoubleSpinBox* spinBox);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    QDoubleSpinBox* m_spinBox;
};

class FloatParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_FLOAT_H
