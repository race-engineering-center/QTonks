#include "qtonks_parameterbuilderinjector.h"

#include "qtonks_parameterbuildermanager.h"

#include "qtonks_switch.h"
#include "qtonks_group.h"

namespace QTonks
{

namespace
{

template<typename Builder>
void addParameterBuilder()
{
    ParameterBuilderManager::addBuilder(Builder::name(), std::make_unique<Builder>());
}

}

void injectAllParameterBuilders()
{
    addParameterBuilder<SwitchParameterBuilder>();
    addParameterBuilder<GroupParameterBuilder>();
}

}
