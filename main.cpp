#include "mainwindow.h"
#include "menuwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuWindow w;
    w.setWindowTitle("Ping Pong Game");
    w.show();
    return a.exec();
}
