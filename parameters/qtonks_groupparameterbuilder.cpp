#include "qtonks_groupparameterbuilder.h"

#include <QGroupBox>
#include <QJsonArray>

#include "qtonks_groupparameter.h"
#include "qtonks_parameterbuilderinjector.h"

namespace QTonks
{

std::unique_ptr<Parameter> GroupParameterBuilder::build(const QJsonObject &object, QFormLayout *layout)
{
    QString label = object["label"].toString();

    QGroupBox* groupBox = new QGroupBox(label);
    layout->addRow(groupBox);

    auto widget = new Widget;
    QJsonArray contentArray = object["content"].toArray();
    widget->setSchema(contentArray);

    groupBox->setLayout(new QVBoxLayout());
    groupBox->layout()->addWidget(widget);

    return std::make_unique<GroupParameter>(std::move(widget));
}

const char* GroupParameterBuilder::name()
{
    return "group";
}

}
