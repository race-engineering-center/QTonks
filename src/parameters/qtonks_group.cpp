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

std::unique_ptr<Parameter> GroupParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    QString label = object["label"].toString();

    QGroupBox* groupBox = new QGroupBox(label);
    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(groupBox);

    auto nestedWidget = new Widget;
    QObject::connect(nestedWidget, &Widget::currentSettingsChanged, widget, [widget](QJsonObject settings) {
        Q_UNUSED(settings);
        emit widget->currentSettingsChanged(widget->getCurrentSettings());
    });
    QJsonArray contentArray = object["content"].toArray();
    nestedWidget->setSchema(contentArray);

    groupBox->setLayout(new QVBoxLayout());
    groupBox->layout()->addWidget(nestedWidget);

    return std::make_unique<GroupParameter>(nestedWidget);
}

const char* GroupParameterBuilder::name()
{
    return "group";
}

}
