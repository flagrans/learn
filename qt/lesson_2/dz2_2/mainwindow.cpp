#include <QApplication>
#include <QCheckBox>
#include <QDebug>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    // Попытался скомпоновать GUI без диизайнера.
    // Назначаем иконку по умолчанию:
    default_icon = QIcon(
        QApplication::style()->standardIcon(QStyle::SP_MessageBoxQuestion));

    QVBoxLayout *vbox_right =
        new QVBoxLayout(); // Сразу вопрос почему в этом layout
                           // не нужно указывать this?
    // Без this вся разметка плывет! Не совсем еще разобрался с this здесь.
    QHBoxLayout *hbox = new QHBoxLayout();
    QVBoxLayout *vbox_left = new QVBoxLayout();
    QHBoxLayout *hbox_left = new QHBoxLayout();

    // Создаем QListView, назначаем ему модель:
    // Так же вопрос??? В задании сказано
    lw = new QListView(this);
    lw->setModel(&model_);
    // Так же делаем первоначальную настройку:
    lw->setViewMode(QListView::ListMode);
    lw->setMinimumHeight(150);
    lw->setSelectionMode(QAbstractItemView::SingleSelection);
    //  и добавляем первоначальные элементы:
    model_.appendRow(new QStandardItem(QIcon(":/C++.png"), "C++"));
    model_.appendRow(new QStandardItem(QIcon(":/js.png"), "JavaScript"));
    model_.appendRow(new QStandardItem(QIcon(":/python.png"), "Python"));
    model_.appendRow(new QStandardItem(QIcon(":/csh.png"), "C#"));
    model_.appendRow(new QStandardItem(QIcon(":/java.png"), "Java"));
    model_.appendRow(new QStandardItem(QIcon(":/qt.png"), "Qt"));
    model_.appendRow(new QStandardItem(default_icon, "Rust"));

    //Создаем правый layout и его элементы:
    up = new QPushButton(
        QIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp)), "",
        this);
    down = new QPushButton(
        QIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown)), "",
        this);
    view_mode = new QCheckBox("IconMode", this);

    vbox_right->setSpacing(3);
    vbox_right->addWidget(up);
    vbox_right->addWidget(down);
    vbox_right->addStretch(1);
    vbox_right->addWidget(view_mode);

    // Создаем кнопки и поля левой части и добавляем их в свой layout:
    remove = new QPushButton("Remove", this);
    add = new QPushButton("Add", this);
    ledit = new QLineEdit(this);

    hbox_left->addWidget(remove);
    hbox_left->addWidget(ledit);
    hbox_left->addWidget(add);

    vbox_left->setSpacing(3);
    vbox_left->addWidget(lw);
    vbox_left->addLayout(hbox_left);

    // Добавляем все в общий hbox:
    hbox->addLayout(vbox_left);
    hbox->addSpacing(3);
    hbox->addLayout(vbox_right);

    // Назначаем layout:
    setLayout(hbox);

    connect(view_mode, &QCheckBox::stateChanged, this,
            &MainWindow::onChangeViewModeCheckBox);
    connect(up, &QPushButton::clicked, this, &MainWindow::onUpButton);
    connect(down, &QPushButton::clicked, this, &MainWindow::onDownButton);
    connect(remove, &QPushButton::clicked, this, &MainWindow::onRemoveButton);
    connect(add, &QPushButton::clicked, this, &MainWindow::onAddButton);
}

MainWindow::~MainWindow() {}

// qDebug() << "Change" << view_mode->isChecked();

void MainWindow::onChangeViewModeCheckBox() {
    if (MainWindow::view_mode->isChecked()) {
        lw->setViewMode(QListView::IconMode);
    } else {
        lw->setViewMode(QListView::ListMode);
    }
}
// Функция перемещения строки - подскажите здесь правильно сделал или можно было
// как-то проще?
void MainWindow::moveRow(QModelIndex &a, int dir) {
    QModelIndex b = model_.index(a.row() + dir, 0, a.parent());
    auto t_next = model_.itemFromIndex(b);
    auto t_cur = model_.itemFromIndex(a);
    auto ti = t_cur->icon();
    auto ts = t_cur->text();
    t_cur->setIcon(t_next->icon());
    t_cur->setText(t_next->text());
    t_next->setIcon(ti);
    t_next->setText(ts);
    lw->setCurrentIndex(b);
}

void MainWindow::onUpButton() {
    auto selection_model = lw->selectionModel();
    if (selection_model->hasSelection()) {
        auto cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid()) {
            if (!cur_ind.row()) {
                return;
            }
            moveRow(cur_ind, -1);
        }
    }
}

void MainWindow::onDownButton() {
    auto selection_model = lw->selectionModel();
    if (selection_model->hasSelection()) {
        auto cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid()) {
            if (cur_ind.row() + 1 == model_.rowCount()) {
                return;
            }
            moveRow(cur_ind, +1);
        }
    }
}

void MainWindow::onRemoveButton() {
    auto selection_model = lw->selectionModel();
    if (selection_model->hasSelection()) {
        auto cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid()) {
            model_.removeRow(cur_ind.row());
        }
    }
}

void MainWindow::onAddButton() {
    if (!ledit->text().isEmpty()) {
        model_.appendRow(new QStandardItem(default_icon, ledit->text()));
        QModelIndex b = model_.index(model_.rowCount() - 1, 0);
        lw->selectionModel()->clearSelection();
        lw->selectionModel()->setCurrentIndex(b, QItemSelectionModel::Select);
        ledit->clear();
    }
}
