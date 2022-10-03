#ifndef MYSUBWINDOW_H
#define MYSUBWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MySubWindow : public QTextEdit {
    Q_OBJECT
public:
    MySubWindow(const QString &fn, QAction *action);
    ~MySubWindow();
    QString getFN();
    QAction *getAction();

private:
    QString filename;
    QAction *action;
};

#endif // MYSUBWINDOW_H
