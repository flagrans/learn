#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void insertRowTable(QString, QString, QString, QString);
    ~MainWindow();

private slots:
    void pushColorButton();
    void pushResetColorButton();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model_;
};

void insertRowTable(QString, QString, QString, QString);
#endif // MAINWINDOW_H
