#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle(filename + " - Текстовый редактор");

    connect(ui->mReference, &QAction::triggered, this,
            &MainWindow::on_mReference_trigger);
    connect(ui->mExit, &QAction::triggered, this,
            &MainWindow::on_mExit_trigger);
    connect(ui->mOpen, &QAction::triggered, this,
            &MainWindow::on_mOpen_trigger);
    connect(ui->mSaveAs, &QAction::triggered, this,
            &MainWindow::on_mSaveAs_trigger);
    connect(ui->mSave, &QAction::triggered, this,
            &MainWindow::on_mSave_trigger);
    connect(ui->textEdit, &QTextEdit::textChanged, this,
            &MainWindow::on_textEdit_textChange);
}

MainWindow::~MainWindow() {
    if (this->isChange)
        on_quit();
    delete ui;
}

void MainWindow::on_mExit_trigger() { QApplication::quit(); }

void MainWindow::on_mReference_trigger() {
    QString data;
    QString fileName(":/help.txt");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        data = "Файл справки отсутствует.";
    } else {
        data = file.readAll();
    }
    file.close();
    QMessageBox::about(this, "Справка", data);
}

void MainWindow::on_mOpen_trigger() {
    filename = QFileDialog::getOpenFileName(this, tr("Выберите текстовый файл"),
                                            "", tr("Text files (*.txt)"));
    QString data;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    } else {
        data = file.readAll();
    }
    file.close();
    ui->textEdit->setText(data);
    setWindowTitle(filename + " - Текстовый редактор");
}

void MainWindow::on_mSaveAs_trigger() {
    filename = QFileDialog::getSaveFileName(this, tr("Сохранить как..."),
                                            filename, tr("Text files (*.txt)"));

    save_file();
}

void MainWindow::on_mSave_trigger() { save_file(); }

void MainWindow::on_textEdit_textChange() {
    isChange = true;
    setWindowTitle("* " + filename + " - Текстовый редактор");
}
void MainWindow::save_file() {

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    } else {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
    }
    setWindowTitle(filename + " - Текстовый редактор");
}

void MainWindow::on_quit() {
    int ret = QMessageBox::warning(this, tr("Текстовый редактор"),
                                   tr("Документ был изменен.\n"
                                      "Сохранить изменения?"),
                                   QMessageBox::Save | QMessageBox::Cancel,
                                   QMessageBox::Save);
    if (ret == QMessageBox::Save) {
        save_file();
    }
}
