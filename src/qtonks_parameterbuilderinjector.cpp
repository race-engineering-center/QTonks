#include "qtonks_parameterbuilderinjector.h"

#include "qtonks_parameterbuildermanager.h"

#include "qtonks_switch.h"
#include "qtonks_enumeration.h"
#include "qtonks_integer.h"
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
    addParameterBuilder<EnumerationParameterBuilder>();
    addParameterBuilder<IntegerParameterBuilder>();
    addParameterBuilder<GroupParameterBuilder>();
}

}
