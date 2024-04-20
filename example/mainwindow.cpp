#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QJsonDocument>
#include <QJsonArray>

#include "qtonks_parameterbuilderinjector.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setSizes({250, 250});

    connect(ui->actionUpdate, &QAction::triggered, this, &MainWindow::onUpdate);
    connect(ui->actionGetCurrentSettings, &QAction::triggered, this, &MainWindow::onGetCurrentSettings);
    connect(ui->actionSetCurrentSettings, &QAction::triggered, this, &MainWindow::onSetCurrentSettings);

    QTonks::injectAllParameterBuilders();

    connect(ui->widget, &QTonks::Widget::currentSettingsChanged, this, &MainWindow::onSettingsUpdated);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUpdate()
{
    ui->widget->clear();

    QString jsonString = ui->plainTextEdit->toPlainText();
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    if (jsonDocument.isNull())
    {
        qDebug() << "Error parsing JSON: " << error.errorString();
        return;
    }

    QJsonObject object = jsonDocument.object();
    QJsonArray schema = object["schema"].toArray();
    ui->widget->setSchema(schema);
}

void MainWindow::onGetCurrentSettings()
{
    auto settings = ui->widget->getCurrentSettings();
    qDebug()<<settings;
}

void MainWindow::onSetCurrentSettings()
{
    QString jsonString = ui->plainTextEdit->toPlainText();
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    if (jsonDocument.isNull())
    {
        qDebug() << "Error parsing JSON: " << error.errorString();
        return;
    }

    QJsonObject object = jsonDocument.object();
    ui->widget->setCurrentSettings(object);
}

void MainWindow::onSettingsUpdated(QJsonObject settings)
{
    qDebug() << "Settings updated:" <<settings;
}
