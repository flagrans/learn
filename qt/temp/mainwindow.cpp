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
    auto default_icon = QIcon(
        QApplication::style()->standardIcon(QStyle::SP_MessageBoxQuestion));

    QVBoxLayout *vbox_right =
        new QVBoxLayout(); // Сразу вопрос почему в этом layout
                           // не нужно указывать this?
    // Без this вся разметка плывет! Не совсем еще разобрался с this здесь.
    QHBoxLayout *hbox = new QHBoxLayout(this);
    QVBoxLayout *vbox_left = new QVBoxLayout(this);
    QHBoxLayout *hbox_left = new QHBoxLayout(this);

    // Создаем QListView, назначаем ему модель:
    // Так же вопрос??? В задании сказано
    QListView *lw = new QListView(this);
    lw->setModel(&model_);
    // Так же делаем первоначальную настройку:
    lw->setViewMode(QListView::ListMode);
    lw->setMinimumHeight(150);
    lw->setSelectionMode(QAbstractItemView::SingleSelection);
    // и добавляем первоначальные элементы:
    model_.appendRow(new QStandardItem(QIcon(":/C++.png"), "C++"));
    model_.appendRow(new QStandardItem(QIcon(":/js.png"), "JavaScript"));
    model_.appendRow(new QStandardItem(QIcon(":/python.png"), "Python"));
    model_.appendRow(new QStandardItem(QIcon(":/csh.png"), "C#"));
    model_.appendRow(new QStandardItem(QIcon(":/java.png"), "Java"));
    model_.appendRow(new QStandardItem(QIcon(":/qt.png"), "Qt"));
    model_.appendRow(new QStandardItem(default_icon, "Rust"));

    //Создаем правый layout и его элементы:
    QPushButton *up = new QPushButton(
        QIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp)), "",
        this);
    QPushButton *down = new QPushButton(
        QIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown)), "",
        this);
    QCheckBox *view_mode = new QCheckBox("IconMode", this);

    vbox_right->setSpacing(3);
    vbox_right->addWidget(up);
    vbox_right->addWidget(down);
    vbox_right->addStretch(1);
    vbox_right->addWidget(view_mode);

    // Создаем кнопки и поля левой части и добавляем их в свой layout:
    QPushButton *remove = new QPushButton("Remove", this);
    QPushButton *add = new QPushButton("Add", this);
    QLineEdit *ledit = new QLineEdit(this);

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
}

MainWindow::~MainWindow() {}

void MainWindow::onChangeViewModeCheckBox() {
    qDebug() << "Change" << MainWindow::view_mode.isChecked();
}
