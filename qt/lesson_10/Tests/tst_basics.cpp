#include "../task.h"
#include <QtTest/QTest>

class BasicsTest : public QObject {
    Q_OBJECT

private slots:
    void testGetCount();
};

void BasicsTest::testGetCount() {
    Task *testtask = new Task();
    auto cnt = testtask->getCountTasks();
    QString testString = "Test Task";
    testtask->addTask(testString);
    QCOMPARE(cnt + 1, testtask->getCountTasks());
    delete testtask;
}

QTEST_APPLESS_MAIN(BasicsTest)

#include "tst_basics.moc"
