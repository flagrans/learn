#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->alignLeft, &QPushButton::clicked, this,
            [=]() { this->onAlign("left"); });
    connect(ui->alignRight, &QPushButton::clicked,
            [=]() { this->onAlign("right"); });
    connect(ui->alignCenter, &QPushButton::clicked, this,
            [=]() { this->onAlign("center"); });
    connect(ui->changeFont, &QPushButton::clicked, this,
            &MainWindow::onChangeFont);
    connect(ui->copyFormat, &QPushButton::clicked, this,
            &MainWindow::onCopyFormat);
    connect(ui->applyFormat, &QPushButton::clicked, this,
            &MainWindow::onApplyFormat);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onAlign(QString s) {
    if (s == "center")
        ui->textEdit->setAlignment(Qt::AlignHCenter);
    if (s == "right")
        ui->textEdit->setAlignment(Qt::AlignRight);
    if (s == "left")
        ui->textEdit->setAlignment(Qt::AlignLeft);
    return;
}

void MainWindow::onChangeFont() {
    QFont font = ui->textEdit->textCursor().charFormat().font();
    QFontDialog fontD(font, this);
    bool ok = false;
    font = fontD.getFont(&ok);
    if (ok) {
        QTextCharFormat fmt;
        fmt.setFont(font);
        ui->textEdit->textCursor().setCharFormat(fmt);
    }
    return;
}

void MainWindow::onCopyFormat() {
    textChFmt = new QTextCharFormat(ui->textEdit->textCursor().charFormat());
    ui->applyFormat->setEnabled(true);
    return;
}

void MainWindow::onApplyFormat() {
    if (textChFmt == nullptr) // Вопрос, если у меня кнопка применить стиль не
                              // активна пока стиль не будет скопирован, то эту
                              // проверку наверное можно вовсем убрать?
        return;
    ui->textEdit->textCursor().setCharFormat(*textChFmt);
    return;
}
