#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    model_ = new QStandardItemModel(this);
    ui->tableView->setModel(model_);

    QList<QString> list;
    list.append("№");
    list.append("Имя компьютера");
    list.append("IP адрес");
    list.append("MAC адрес");
    model_->setHorizontalHeaderLabels(list);
    ui->tableView->verticalHeader()->hide();

    insertRowTable("1", "compname_1", "172.111.130.136", "EE:3A:5F:DD:F1:41");
    insertRowTable("2", "compname_2", "177.211.140.147", "3D:A0:0D:52:FC:52");
    insertRowTable("3", "compname_3", "129.43.238.123", "E3:AA:02:3A:70:7C");
    insertRowTable("4", "compname_4", "252.136.159.58", "5C:49:E2:D1:CD:B9");
    insertRowTable("5", "compname_5", "226.211.240.124", "55:53:FA:F1:42:F7");
    insertRowTable("6", "compname_6", "154.185.152.163", "2D:FB:02:DD:4B:B9");
    insertRowTable("7", "compname_7", "6.40.66.209", "48:DB:F4:55:80:EE");
    insertRowTable("8", "compname_8", "157.65.128.5", "53:91:71:3B:54:03");
    insertRowTable("9", "compname_9", "110.117.135.83", "8F:54:02:FF:D7:7B");
    insertRowTable("10", "compname_10", "222.189.253.81", "58:68:3B:B9:25:49");

    ui->tableView->resizeColumnsToContents();

    connect(ui->colorButton, &QPushButton::clicked, this,
            &MainWindow::pushColorButton);
    connect(ui->resetColorButton, &QPushButton::clicked, this,
            &MainWindow::pushResetColorButton);
}

void MainWindow::pushColorButton() {
    auto selection_model = ui->tableView->selectionModel();
    if (selection_model->hasSelection()) {
        auto cur_ind = selection_model->selectedIndexes();
        QSet<int> set;
        for (auto temp : cur_ind) {
            if (temp.isValid()) {
                set.insert(temp.row());
            }
        }
        for (auto temp : set) {
            for (int i = 0; i < model_->columnCount(); i++) {
                model_->setData(model_->index(temp, i), QColor(147, 250, 207),
                                Qt::BackgroundRole);
            }
        }
    }
    selection_model->clearSelection();
}

void MainWindow::pushResetColorButton() {
    auto col = model_->columnCount();
    auto row = model_->rowCount();
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < row; j++) {
            model_->setData(model_->index(j, i), QColor(255, 255, 255),
                            Qt::BackgroundRole);
        }
    }
    ui->tableView->clearSelection();
}

void MainWindow::insertRowTable(QString num, QString name, QString ip,
                                QString mac) {
    QList<QStandardItem *> list;
    list.append(new QStandardItem(num));
    list.append(new QStandardItem(name));
    list.append(new QStandardItem(ip));
    list.append(new QStandardItem(mac));
    model_->appendRow(list);
}

MainWindow::~MainWindow() { delete ui; }
