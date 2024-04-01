#ifndef QTONKS_GROUPPARAMETER_H
#define QTONKS_GROUPPARAMETER_H

#include "qtonks_parameter.h"
#include "qtonks_widget.h"

namespace QTonks
{

class GroupParameter : public Parameter
{
public:
    GroupParameter(Widget* widget);

    QJsonObject getCurrentSettings() const override;
    void setCurrentSettings(const QJsonObject& settings) override;

private:
    Widget* m_widget;
};

}

#endif // QTONKS_GROUPPARAMETER_H
