#ifndef QTONKS_SWITCHPARAMETER_H
#define QTONKS_SWITCHPARAMETER_H

#include <QCheckBox>

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

namespace QTonks
{

class SwitchParameter : public Parameter
{
public:
    SwitchParameter(QCheckBox* checkBox);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    QCheckBox* m_checkBox;
};

class SwitchParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_SWITCHPARAMETER_H
