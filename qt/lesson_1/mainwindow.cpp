#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore/qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/t_cos.png"); // Картинка треугольника
    int w = ui->label_9->width();
    int h = ui->label_9->height();
    ui->label_9->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio)); // Конец картинка треугольника
    ui->tabWidget->setCurrentIndex(0); // Устанавливаем текущей первую вкладку
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // Расчет Задание №1
{
    ui->label_7->setStyleSheet("color: black");
    ui->label_7->setText("");
    // Сохраняем введенные значения
    QString str_a = ui->lineEdit->text();
    QString str_b = ui->lineEdit_2->text();
    QString str_c = ui->lineEdit_3->text();
    // Проверяем введенные значения на число
    bool ok_a, ok_b, ok_c;
    int a = str_a.toInt(&ok_a, 10);
    int b = str_b.toInt(&ok_b, 10);
    int c = str_c.toInt(&ok_c, 10);
    if (!ok_a || !ok_b || !ok_c) { // Если какое-либо из 3-х значений - не число
        ui->label_7->setStyleSheet("color: red");
        ui->label_7->setText("Вы ввели некорректные данные");
    } else {
        if (!a) { // т.к. в условии сказано что только а может быть = 0
            ui->label_7->setStyleSheet("color: green");
            ui->label_7->setText("x=" + QString::number(-c/b));
        } else {
            double D = qPow(b, 2) - 4 * a * c;
            if (D < 0) {
                ui->label_7->setStyleSheet("color: red");
                ui->label_7->setText("Корней нет");
            } else if (D == 0) {
                ui->label_7->setStyleSheet("color: green");
                ui->label_7->setText("X=" + QString::number(-b/(2*a)));
            } else {
                ui->label_7->setStyleSheet("color: blue");
                ui->label_7->setText("x1=" + QString::number((-b - qSqrt(D))/(2 * a)) + ", x2=" + QString::number((-b + qSqrt(D))/(2 * a)));
            }
        }
    }
}


void MainWindow::on_pushButton_2_clicked() // По кнопке очищаем форму Задание №1 (Сброс)
{
    ui->label_7->setStyleSheet("color: black");
    ui->label_7->setText("");
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}


void MainWindow::on_tabWidget_tabBarClicked(int index) // Если перешли на другую вкладку - очищаем формы
{
    if (index == 0) {
        ui->lineEdit->setFocus();
        on_pushButton_2_clicked();
    } else if(index == 1) {
        ui->lineEdit_4->setFocus();
        on_pushButton_4_clicked();
    } else if(index == 2) {
        on_pushButton_5_clicked();
    }
}


void MainWindow::on_pushButton_3_clicked() // Расчет Задание №2
{
    ui->label_12->setStyleSheet("color: black");
    ui->label_12->setText("");
    // Сохраняем введенные значения
    QString str_a = ui->lineEdit_4->text();
    QString str_b = ui->lineEdit_5->text();
    QString str_c = ui->lineEdit_6->text();
    // Проверяем введенные значения на число (так же для длин сторон взяты целые числа)
    bool ok_a, ok_b, ok_c;
    int a = str_a.toInt(&ok_a, 10);
    int b = str_b.toInt(&ok_b, 10);
    float c = str_c.toFloat(&ok_c);
    if (!ok_a || !ok_b || !ok_c || (ui->radioButton_2->isChecked() && c > 3.14)) { // Если какое-либо из 3-х значений - не число, и если угол в радианах > pi
        ui->label_12->setStyleSheet("color: red");
        ui->label_12->setText("Вы ввели некорректные данные");
    } else {
        if (ui->radioButton->isChecked()) {
            c = qDegreesToRadians(c);
        }
        ui->label_12->setStyleSheet("color: green");
        ui->label_12->setText("c=" + QString::number(qSqrt(qPow(a, 2) + qPow(b, 2) - 2 * a * b * qCos(c))));

    }
}


void MainWindow::on_pushButton_4_clicked() // Сброс Задание №2
{
    ui->label_12->setStyleSheet("color: black");
    ui->label_12->setText("");
    ui->radioButton->setChecked(true);
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
}



void MainWindow::on_pushButton_5_clicked() // Сброс Задание №3
{
    ui->textEdit->setText("Пример 1");
    ui->textEdit_2->setText("Пример 2");
    ui->textEdit->setFocus();
}


void MainWindow::on_pushButton_6_clicked() // Здесь берем текст из Поле №2 и добавляем к тексту в Поле №1
{
    ui->textEdit->setText(ui->textEdit->toPlainText() + ui->textEdit_2->toPlainText());
}


void MainWindow::on_pushButton_7_clicked() // Здесь берем текст из Поле №1 и вставляем в Поле №2
{
    ui->textEdit_2->setText(ui->textEdit->toPlainText());
}


void MainWindow::on_pushButton_8_clicked() // Здесь берем текст из Поле №1 добавляем тэги и вставляем в Поле №2
{
    ui->textEdit_2->setHtml("<font color='red'><b>" + ui->textEdit->toPlainText() + "</b></font>");
}

