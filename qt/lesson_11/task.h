#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

struct oneRow
{
    int id;
    QString task;
    QString date;
    int progress;
};

class Task : public QObject
{
    Q_OBJECT
  public:
    // Q_PROPERTY(QString addTask WRITE addTask)
    Task(QObject *parent = nullptr);
    ~Task() override;

    // void addTask(QString &b);
    Q_INVOKABLE void addTask(QString &task, QString &date, QString &progress);
    Q_INVOKABLE int getCountTasks();
    Q_INVOKABLE QVariantList getList();

  private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // TASK_H
