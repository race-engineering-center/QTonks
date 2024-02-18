#ifndef QTONKS_GROUPPARAMETERBUILDER_H
#define QTONKS_GROUPPARAMETERBUILDER_H

#include "qtonks_parameterbuilder.h"

namespace QTonks
{

class GroupParameterBuilder : public ParameterBuilder
{
public:
    std::unique_ptr<Parameter> build(const QJsonObject& object, QFormLayout* layout) override;

    static const char* name();
};

}

#endif // QTONKS_GROUPPARAMETERBUILDER_H
