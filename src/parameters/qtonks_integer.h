#ifndef QTONKS_INTEGER_H
#define QTONKS_INTEGER_H

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

#include <QSpinBox>

namespace QTonks
{

class IntegerParameter : public Parameter
{
public:
    IntegerParameter(QSpinBox* spinBox);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    QSpinBox* m_spinBox;
};

class IntegerParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_INTEGER_H
