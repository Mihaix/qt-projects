#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile style(":/style_f/style_file.qss");
    style.open(QFile::ReadOnly);

    QString s = QLatin1String(style.readAll());
    a.setStyleSheet(s);

    MainWindow w;
    w.show();
    return a.exec();
}
