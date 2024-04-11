#include "qtonks_parameterbuildermanager.h"

namespace QTonks
{

void ParameterBuilderManager::addBuilder(QString name, std::unique_ptr<ParameterBuilder> builder)
{
    instance().m_builders.emplace(std::move(name), std::move(builder));
}

ParameterBuilder* ParameterBuilderManager::builder(const QString& type)
{
    auto it = instance().m_builders.find(type);
    if (it == instance().m_builders.end())
        return nullptr;
    return it->second.get();
}

ParameterBuilderManager &QTonks::ParameterBuilderManager::instance()
{
    static ParameterBuilderManager manager;
    return manager;
}

}
