#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Layouts");
    w.resize(400, 400);
    w.show();
    return a.exec();
}