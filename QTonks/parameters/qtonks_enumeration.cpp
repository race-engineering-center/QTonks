#include "qtonks_enumeration.h"

#include <QRadioButton>
#include <QJsonArray>

namespace QTonks
{

EnumerationParameter::EnumerationParameter(QGroupBox* groupBox, QButtonGroup *buttonGroup) :
    m_groupBox(groupBox),
    m_buttonGroup(buttonGroup)
{

}

QJsonObject EnumerationParameter::getCurrentSettings() const
{
    QJsonObject result;
    result["selectedIndex"] = m_buttonGroup->checkedId();
    return result;
}

void EnumerationParameter::setCurrentSettings(const QJsonObject &settings)
{
    if (settings.contains("selectedIndex") && settings["selectedIndex"].isDouble())
    {
        int selectedIndex = settings["selectedIndex"].toInt();
        auto buttons = m_buttonGroup->buttons();
        if (selectedIndex >= 0 && selectedIndex < buttons.size())
        {
            m_buttonGroup->button(selectedIndex)->setChecked(true);
        }
    }
}

std::unique_ptr<Parameter> EnumerationParameterBuilder::build(const QJsonObject &object, Widget *widget)
{
    QString label = object["label"].toString();

    auto groupBox = new QGroupBox();
    groupBox->setTitle(label);

    auto groupBoxLayout = new QVBoxLayout;
    groupBox->setLayout(groupBoxLayout);

    auto buttonGroup = new QButtonGroup(groupBox);

    if (object.contains("labels") && object["labels"].isArray())
    {
        auto labelsArray = object["labels"].toArray();

        for (qsizetype i = 0; i < labelsArray.size(); i++)
        {
            QRadioButton *radioButton = new QRadioButton(labelsArray[i].toString());
            buttonGroup->addButton(radioButton, i);
            groupBox->layout()->addWidget(radioButton);

            QObject::connect(radioButton, &QRadioButton::toggled, widget, [widget](bool on) {
                if (on == false)
                    return;
                emit widget->currentSettingsChanged(widget->getCurrentSettings());
            });
        }

        int currentIndex = object["defaultSelectedOption"].toInt(0);
        if (currentIndex < 0 || currentIndex >= labelsArray.size())
            currentIndex = 0;

        auto currentButton = qobject_cast<QRadioButton*>(buttonGroup->button(currentIndex));
        Q_ASSERT(currentButton != nullptr);
        currentButton->setChecked(true);
    }

    auto layout = qobject_cast<QFormLayout*>(widget->layout());
    Q_ASSERT(layout != nullptr);
    layout->addRow(groupBox);

    return std::make_unique<EnumerationParameter>(groupBox, buttonGroup);
}

const char *EnumerationParameterBuilder::name()
{
    return "enumeration";
}

}

