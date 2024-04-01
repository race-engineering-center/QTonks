#include "qtonks_group.h"

#include <QGroupBox>
#include <QJsonArray>

namespace QTonks
{

GroupParameter::GroupParameter(Widget *widget) :
    m_widget(widget)
{

}

QJsonObject GroupParameter::getCurrentSettings() const
{
    return m_widget->getCurrentSettings();
}

void GroupParameter::setCurrentSettings(const QJsonObject &settings)
{
    m_widget->setCurrentSettings(settings);
}

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

    return std::make_unique<GroupParameter>(widget);
}

const char* GroupParameterBuilder::name()
{
    return "group";
}

}
