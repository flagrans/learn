#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"

#include <QFileSystemModel>
#include <QMainWindow>
#include <QShortcut>

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
    void on_mSettings_trigger();
    void on_textEdit_textChange();
    void on_mOpenReadOnly();
    void switchLang();
    void saveSettings();

    void on_treeView_clicked(const QModelIndex &index);

    void on_treeView_doubleClicked(const QModelIndex &index);

private:
    void save_file();
    void on_quit();
    bool open_file();
    void shortCutSetup();
    void setsStyle();
    void initLang(const QString &lang);
    bool openFileWithTree();

    bool isChange = false;
    QString filename = tr("Новый файл") + ".txt";
    // Во-вторых, если переменная после инициализации не меняет свое значение,
    // делайте ее константной. Если это поле класса, то лучше еще и статической.
    // В вашем случае это filename.
    // Но она у меня меняется по коду если я открываю файл.
    Ui::MainWindow *ui;
    Settings *s;
    QVector<QString> mydata;
    QFileSystemModel *modelFS;
};
#endif // MAINWINDOW_H
