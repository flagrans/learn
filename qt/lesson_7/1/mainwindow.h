#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextFormat>

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
    void onAlign(QString);
    void onChangeFont();
    void onCopyFormat();
    void onApplyFormat();

private:
    Ui::MainWindow *ui;
    QTextCharFormat *textChFmt = nullptr;
};
#endif // MAINWINDOW_H
