#include "qtonks_parameterbuildermanager.h"

void QTonks::ParameterBuilderManager::addBuilder(QString name, std::unique_ptr<ParameterBuilder> builder)
{
    instance().m_builders.emplace(std::move(name), std::move(builder));
}

QTonks::ParameterBuilder *QTonks::ParameterBuilderManager::builder(const QString& type)
{
    auto it = instance().m_builders.find(type);
    if (it == instance().m_builders.end())
        return nullptr;
    return it->second.get();
}

QTonks::ParameterBuilderManager &QTonks::ParameterBuilderManager::instance()
{
    static ParameterBuilderManager manager;
    return manager;
}
