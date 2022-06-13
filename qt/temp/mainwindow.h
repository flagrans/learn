#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QStandardItemModel>
#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void onUpButton();
    // void onDownButton();
    void onChangeViewModeCheckBox();
    // void onRemoveButton();
    // void onAddButton();

private:
    QStandardItemModel model_;
    QCheckBox view_mode;
};
#endif // MAINWINDOW_H
