#include "qtonks_groupparameter.h"

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

}
