#include "qtonks_switchparameterbuilder.h"

#include <QCheckBox>

#include "qtonks_switchparameter.h"

namespace QTonks
{

std::unique_ptr<Parameter> SwitchParameterBuilder::build(const QJsonObject &object, QFormLayout *layout)
{
    QString label = object["label"].toString();

    QCheckBox* checkBox = new QCheckBox();
    checkBox->setText(label);

    layout->addRow(checkBox);

    return std::make_unique<SwitchParameter>(checkBox);
}

const char* SwitchParameterBuilder::name()
{
    return "switch";
}

}
