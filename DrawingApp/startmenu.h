#ifndef STARTMENU_H
#define STARTMENU_H

#include "mainwindow.h"
#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class StartMenu; }
QT_END_NAMESPACE

class StartMenu : public QWidget
{
    Q_OBJECT

public:
    StartMenu(QWidget *parent = nullptr);
    ~StartMenu();
    void GetImages();

private slots:
    void SetImage();
    void OpenNewDrawingWindow();

private:
    Ui::StartMenu *ui;
    MainWindow* drawing;
    QTimer* timer;
    QList<QString> files;
    QString dir_name;
    int i;
};
#endif
