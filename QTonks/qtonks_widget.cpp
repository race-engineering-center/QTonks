#include "qtonks_widget.h"

#include <QJsonArray>
#include <QJsonValue>

#include "qtonks_parameterbuildermanager.h"

namespace QTonks
{

Widget::Widget(QWidget *parent)
    : QWidget{parent}
{
    m_mainLayout = new QFormLayout(this);
    setLayout(m_mainLayout);
}

void Widget::setSchema(const QJsonArray &schema)
{
    clear();
    for (const QJsonValue& entity: schema)
    {
        QString type = entity["type"].toString();
        auto builder = ParameterBuilderManager::builder(type);
        if (builder == nullptr)
        {
            qDebug() << "QTonks error: builder with type " << type << " not found!";
            continue;
        }
        QString name = entity["name"].toString();
        if (name.isEmpty())
        {
            qDebug() << "QTonks error: empty parameter name!";
            continue;
        }
        if (m_parameters.find(name) != m_parameters.end())
        {
            qDebug() << "QTonks error: parameter with name " << name << " already exists!";
            continue;
        }
        QJsonObject object = entity.toObject();
        auto parameter = builder->build(object, this);
        m_parameters.emplace(std::move(name), std::move(parameter));
    }
}

QJsonObject Widget::getCurrentSettings() const
{
    QJsonObject result;

    for (const auto& [name, parameter]: m_parameters)
    {
        QJsonObject settings = parameter->getCurrentSettings();
        result[name] = settings;
    }

    return result;
}

void Widget::setCurrentSettings(const QJsonObject &settings)
{
    QSignalBlocker blocker(this);
    Q_UNUSED(blocker);
    for (const auto& [name, parameter]: m_parameters)
    {
        QJsonObject s = settings.value(name).toObject();
        if (s.isEmpty())
            continue;
        parameter->setCurrentSettings(s);
    }
}

void Widget::clear()
{
    m_parameters.clear();
    for (int i = m_mainLayout->rowCount(); i > 0; i--)
        m_mainLayout->removeRow(i - 1);
}

QFormLayout *Widget::getLayout()
{
    return m_mainLayout;
}

}
