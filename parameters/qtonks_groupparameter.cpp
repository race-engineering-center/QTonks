#include "qtonks_groupparameter.h"

namespace QTonks {

GroupParameter::GroupParameter(Widget *widget) :
    m_widget(widget)
{

}

QJsonObject GroupParameter::getCurrentSettings() const
{
    return {};
}

void GroupParameter::setCurrentSettings(const QJsonObject &settings)
{

}

}
