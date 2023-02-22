#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
    if (ui->lineEdit->text() == "login" && ui->lineEdit_2->text() == "password")
        success();
    else
        fail();
}

void MainWindow::success() {
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect();
    ui->widget->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *anim = new QPropertyAnimation(opacityEffect);
    anim->setTargetObject(opacityEffect);
    anim->setPropertyName("opacity");
    anim->setDuration(1000);
    anim->setEndValue(0.0);
    anim->start();
    anim->setEasingCurve(QEasingCurve::InBounce);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::fail() {
    QSequentialAnimationGroup *sg1 = new QSequentialAnimationGroup;
    int x = ui->lineEdit->pos().x();
    int y = ui->lineEdit->pos().y();
    QPropertyAnimation *anim = new QPropertyAnimation(ui->lineEdit, "pos");
    anim->setDuration(50);
    anim->setStartValue(QPointF(x,y));
    anim->setEndValue(QPointF(x-5,y));
    sg1->addAnimation(anim);

    QPropertyAnimation *anim2 = new QPropertyAnimation(ui->lineEdit, "pos");
    anim2->setDuration(100);
    anim2->setStartValue(QPointF(x-5,y));
    anim2->setEndValue(QPointF(x+5,y));
    sg1->addAnimation(anim2);

    QPropertyAnimation *anim3 = new QPropertyAnimation(ui->lineEdit, "pos");
    anim3->setDuration(50);
    anim3->setStartValue(QPointF(x+5,y));
    anim3->setEndValue(QPointF(x,y));
    sg1->addAnimation(anim3);


    QSequentialAnimationGroup *sg2 = new QSequentialAnimationGroup;
    x = ui->lineEdit_2->pos().x();
    y = ui->lineEdit_2->pos().y();
    QPropertyAnimation *anim2_1 = new QPropertyAnimation(ui->lineEdit_2, "pos");
    anim2_1->setDuration(50);
    anim2_1->setStartValue(QPointF(x,y));
    anim2_1->setEndValue(QPointF(x-5,y));
    sg2->addAnimation(anim2_1);

    QPropertyAnimation *anim2_2 = new QPropertyAnimation(ui->lineEdit_2, "pos");
    anim2_2->setDuration(100);
    anim2_2->setStartValue(QPointF(x-5,y));
    anim2_2->setEndValue(QPointF(x+5,y));
    sg2->addAnimation(anim2_2);

    QPropertyAnimation *anim2_3 = new QPropertyAnimation(ui->lineEdit_2, "pos");
    anim2_3->setDuration(50);
    anim2_3->setStartValue(QPointF(x+5,y));
    anim2_3->setEndValue(QPointF(x,y));
    sg2->addAnimation(anim2_3);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(sg1);
    group->addAnimation(sg2);
    group->start();

    // Попытался реализовать, понял что каки говорилось в лекции на qml это делать гораздо интереснее.
    // Тут даже цвет не победил, не могу понять как можно сделать какое либо действие допустим до анимации и после,
    // получается анимация в отдельном потоке живет


}
