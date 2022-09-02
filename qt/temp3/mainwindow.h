#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myqgraphicsscene.h"
#include <QGraphicsView>

class ItemEventFilter;

class MainWindow : public QGraphicsView {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;
    bool event(QEvent *event) override;

private:
    void addItems(QMouseEvent *event);
    QBrush brushRandQColor();
    QRectF makeRectF(int x, int y);

private:
    MyQGraphicsScene *scene_;
    ItemEventFilter *filter_{};
};
#endif // MAINWINDOW_H
