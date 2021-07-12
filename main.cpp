#include "mainwindow.h"

#include <QApplication>

#include "timewheel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    TimeWheel tw;

    return a.exec();
}
