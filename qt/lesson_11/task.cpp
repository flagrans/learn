#include "task.h"
#include <QSqlError>
#include <QSqlRecord>

Task::Task(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./database.db");
    if (!db.open())
    {
        qDebug() << "Error. Can`t open database!";
        return;
    }
    query = QSqlQuery{db};
    qDebug() << "CONNECT DB";

    if (!query.exec(
            "CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY "
            "AUTOINCREMENT, task VARCHAR NOT NULL, date VARCHAR(10) NOT NULL, "
            "progress INT)"))
    {
        qDebug() << "Can`t create table TASKS";
        qDebug() << query.lastError();
        return;
    }
}

Task::~Task() { db.close(); }

void Task::addTask(QString &task, QString &date, QString &progress)
{
    query.clear();
    if (!query.exec("INSERT INTO tasks(task, date, progress) VALUES ('" + task +
                    "', '" + date + "', " + progress + ")"))
    {
        qDebug() << "Can`t insert data in table TASKS";
        qDebug() << query.lastError();
        return;
    }
}
int Task::getCountTasks()
{
    query.clear();
    if (!query.exec("SELECT count(*) FROM tasks"))
    {
        qDebug() << "Can`t count.";
        qDebug() << query.lastError();
        return 0;
    }
    int amount = 0;
    if (query.next())
    {
        amount = query.value(0).toInt();
    }
    return amount;
}

QVariantList Task::getList()
{
    QVariantList result;
    query.clear();

    if (!query.exec("SELECT id, task, date, progress FROM tasks"))
    {
        qDebug() << "Can`t insert data in table TASKS";
        qDebug() << query.lastError();
        return result;
    }

    QSqlRecord rec = query.record();

    while (query.next())
    {
        QVariantList tempList;
        auto t1 = query.value(rec.indexOf("id")).toString();
        auto t2 = query.value(rec.indexOf("task")).toString();
        auto t3 = query.value(rec.indexOf("date")).toString();
        auto t4 = query.value(rec.indexOf("progress")).toString();
        tempList.append(t1);
        tempList.append(t2);
        tempList.append(t3);
        tempList.append(t4);
        result.append(QVariant(tempList));
    }
    return result;
}
