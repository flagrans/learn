#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mReference_trigger();
    void on_mExit_trigger();
    void on_mOpen_trigger();
    void on_mSaveAs_trigger();
    void on_mSave_trigger();
    void on_textEdit_textChange();

private:
    void save_file();
    void on_quit();

    bool isChange = false;
    QString filename = "New_file.txt";
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
