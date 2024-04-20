#ifndef QTONKS_PARAMETER_H
#define QTONKS_PARAMETER_H

#include <QJsonObject>

namespace QTonks
{

class Parameter
{
public:
    virtual QJsonObject getCurrentSettings() const = 0;
    virtual void setCurrentSettings(const QJsonObject& settings) = 0;
};

}

#endif // QTONKS_PARAMETER_H
