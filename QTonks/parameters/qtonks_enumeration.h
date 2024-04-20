#ifndef QTONKS_ENUMERATION_H
#define QTONKS_ENUMERATION_H

#include "qtonks_parameter.h"
#include "qtonks_parameterbuilder.h"

#include <QGroupBox>
#include <QButtonGroup>

namespace QTonks
{

class EnumerationParameter : public Parameter
{
public:
    EnumerationParameter(QGroupBox* groupBox, QButtonGroup* buttonGroup);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    QGroupBox* m_groupBox;
    QButtonGroup* m_buttonGroup;
};

class EnumerationParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) override;

    static const char* name();
};

}

#endif // QTONKS_ENUMERATION_H
