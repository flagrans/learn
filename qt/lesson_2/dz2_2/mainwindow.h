#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onUpButton();
    void onDownButton();
    void onChangeViewModeCheckBox();
    void onRemoveButton();
    void onAddButton();

private:
    void moveRow(QModelIndex &, int);
    QStandardItemModel model_;
    QCheckBox *view_mode;
    QListView *lw;
    QPushButton *down;
    QPushButton *up;
    QPushButton *remove;
    QPushButton *add;
    QLineEdit *ledit;
    QIcon default_icon;
};
#endif // MAINWINDOW_H
