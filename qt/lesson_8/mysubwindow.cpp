#include "mysubwindow.h"

MySubWindow::MySubWindow(const QString &fn, QAction *act)
    : filename(fn), action(act) {}

MySubWindow::~MySubWindow() {}

QString MySubWindow::getFN() { return filename; }

QAction *MySubWindow::getAction() { return action; }
