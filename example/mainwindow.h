#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onUpdate();
    void onGetCurrentSettings();
    void onSetCurrentSettings();

    void onSettingsUpdated(QJsonObject settings);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
