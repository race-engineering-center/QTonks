#ifndef QTONKS_GROUPPARAMETER_H
#define QTONKS_GROUPPARAMETER_H

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

namespace QTonks
{

class GroupParameter : public Parameter
{
public:
    GroupParameter(Widget* widget);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    Widget* m_widget;
};

class GroupParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_GROUPPARAMETER_H
