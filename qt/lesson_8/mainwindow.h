#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mysubwindow.h"
#include "settings.h"

#include <QFileSystemModel>
#include <QMainWindow>
#include <QMdiArea>
#include <QShortcut>
#include <QThread>

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
    void addOpenWin(const QString &fn);

private slots:
    void on_mReference_trigger();
    void on_mExit_trigger();
    void on_mOpen_trigger();
    void on_mSaveAs_trigger();
    void on_mSave_trigger();
    void on_mSettings_trigger();
    void on_mPrint_trigger();
    void on_textEdit_textChange();
    void on_mOpenReadOnly();
    void switchLang();
    void saveSettings();
    void on_minSub_trigger();
    void on_cascadeSub_trigger();
    void on_maxSub_trigger();
    void on_tileSub_trigger();
    void on_changeActive_trigger(const QString &fn);
    void on_treeView_clicked(const QModelIndex &index);
    void on_treeView_doubleClicked(const QModelIndex &index);
    void on_mPasteDate_trigger();

    void pushSearch();
    void searchResult(QVector<QString> results);

signals:
    void startSearch(const QString &path, const QString &mask);

private:
    void save_file();
    void on_quit();
    bool open_file();
    void shortCutSetup();
    void setsStyle();
    void initLang(const QString &lang);
    bool openFileWithTree();
    QString getFileName(const QString &fn);
    void rebuildOpenWindows();
    bool isReopen(const QString &fn);

    bool isChange = false;
    QString filename = tr("Новый файл") + ".txt";
    Ui::MainWindow *ui;
    Settings *s;
    QVector<QString> mydata;
    QFileSystemModel *modelFS;

    QThread searchThread;
};
#endif // MAINWINDOW_H
