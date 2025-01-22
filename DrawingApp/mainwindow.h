#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawing.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void createActions();
    void createMenu();

private:
    Drawing *drawingArea;
    QMenu *optionMenu;

    QAction *exitAction;
    QAction *penColorAction;
    QAction *penWidthAction;
    QAction *clearAction;

};

#endif
