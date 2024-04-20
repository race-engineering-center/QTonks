#ifndef QTONKS_PARAMETERBUILDER_H
#define QTONKS_PARAMETERBUILDER_H

#include <QJsonObject>

#include <memory>

#include "qtonks_widget.h"
#include "qtonks_parameter.h"

namespace QTonks
{

class ParameterBuilder
{
public:
    virtual std::unique_ptr<Parameter> build(const QJsonObject& object, Widget* widget) = 0;
};

}

#endif // QTONKS_PARAMETERBUILDER_H
