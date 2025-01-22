#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CreateConnections();
    void CreateNewTask(QString const& taskName, QString const& taskDate);

public slots:
    void OnAddNewTask();
    void OnDeleteTask();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
