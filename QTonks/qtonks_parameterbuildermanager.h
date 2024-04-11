#ifndef PARAMETERBUILDERMANAGER_H
#define PARAMETERBUILDERMANAGER_H

#include "qtonks_parameterbuilder.h"

namespace QTonks
{

class ParameterBuilderManager
{
public:
    static void addBuilder(QString name, std::unique_ptr<ParameterBuilder> builder);
    static ParameterBuilder* builder(const QString& type);
private:
    ParameterBuilderManager() = default;

    static ParameterBuilderManager& instance();

private:
    std::map<QString, std::unique_ptr<ParameterBuilder>> m_builders;
};

}

#endif // PARAMETERBUILDERMANAGER_H
