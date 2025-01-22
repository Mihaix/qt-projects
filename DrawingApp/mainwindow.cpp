#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), drawingArea(new Drawing(this))
{
    setCentralWidget(drawingArea);

    createActions();
    createMenu();

    setWindowTitle(tr("Draw"));
    resize(1000, 500);
}

MainWindow::~MainWindow()
{
    delete drawingArea;
    delete optionMenu;
    delete exitAction;
    delete penColorAction;
    delete penWidthAction;
    delete clearAction;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::warning(this, tr("Drawing"),
                      tr("Are you sure you want to continue?\n"
                         "You will lose all your work."),
                      QMessageBox::Ok | QMessageBox::Cancel);

    if (btn == QMessageBox::Ok)
        event->accept();
    else if (btn == QMessageBox::Cancel)
        event->ignore();
}

void MainWindow::createMenu()
{
    optionMenu = new QMenu(tr("Options"), this);
    optionMenu->addAction(penColorAction);
    optionMenu->addAction(penWidthAction);
    optionMenu->addSeparator();
    optionMenu->addAction(clearAction);
    optionMenu->addSeparator();
    optionMenu->addAction(exitAction);

    menuBar()->addMenu(optionMenu);
}

void MainWindow::createActions()
{
    exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    penColorAction = new QAction(tr("Pen Color"), this);
    connect(penColorAction, &QAction::triggered, drawingArea, &Drawing::setPenColor);

    penWidthAction = new QAction(tr("Pen Width"), this);
    connect(penWidthAction, &QAction::triggered, drawingArea, &Drawing::setPenWidth);

    clearAction = new QAction(tr("Clear"), this);
    connect(clearAction, &QAction::triggered, drawingArea, &Drawing::clearImage);

}





































