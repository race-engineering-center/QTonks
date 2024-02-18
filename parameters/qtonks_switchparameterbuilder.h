#ifndef QTONKS_SWITCHPARAMETERBUILDER_H
#define QTONKS_SWITCHPARAMETERBUILDER_H

#include "qtonks_parameterbuilder.h"

namespace QTonks
{

class SwitchParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, QFormLayout* layout) override;

    static const char* name();
};

}

#endif // QTONKS_SWITCHPARAMETERBUILDER_H
