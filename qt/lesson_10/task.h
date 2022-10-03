#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject {
    Q_OBJECT
public:
    Q_PROPERTY(QString addTask WRITE addTask)
    Task(QObject *parent = nullptr);
    ~Task() override;

    void addTask(QString &b);
    Q_INVOKABLE int getCountTasks();

private:
    QVector<QString> v_;
};

#endif // TASK_H
