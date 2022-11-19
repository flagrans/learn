#include "task.h"
#include <QFile>
#include <QTextStream>

Task::Task(QObject *parent) : QObject{parent} {
    QFile file;
    file.setFileName("tasks.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while (!file.atEnd()) {
            v_.append(file.readLine().trimmed());
        }
        file.close();
    }
}

Task::~Task() {
    QFile file;
    file.setFileName("tasks.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream writeStream(&file);
        for (auto i : v_) {
            writeStream << i << "\n";
        }
        file.close();
    }
}

void Task::addTask(QString &b) { v_.append(b); }
int Task::getCountTasks() { return v_.count(); }
// void Task::testTask(QString &b, int a) { qDebug() << "TEST Task" << a; }
