#ifndef QTONKSWIDGET_H
#define QTONKSWIDGET_H

#include <QWidget>
#include <QFormLayout>

#include "qtonks_parameterbuilder.h"

namespace QTonks
{

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

    void setSchema(const QJsonArray& schema);

    QJsonObject getCurrentSettings() const;
    void setCurrentSettings(const QJsonObject& settings);

    void clear();

signals:

protected:
    QFormLayout* m_mainLayout;
    std::map<QString, std::unique_ptr<Parameter>> m_parameters;
};

}

#endif // QTONKSWIDGET_H
