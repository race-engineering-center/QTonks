#ifndef QTONKS_PARAMETERBUILDER_H
#define QTONKS_PARAMETERBUILDER_H

#include <QFormLayout>
#include <QJsonObject>

#include <memory>

#include "qtonks_parameter.h"

namespace QTonks
{

class ParameterBuilder
{
public:
    virtual std::unique_ptr<Parameter> build(const QJsonObject& object, QFormLayout* layout) = 0;
};

}

#endif // QTONKS_PARAMETERBUILDER_H
