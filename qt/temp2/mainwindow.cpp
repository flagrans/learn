#include "mainwindow.h"
#include "itemeventfilter.h"
#include <QEvent>
#include <QMouseEvent>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) : QGraphicsView(parent) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene_ = new MyQGraphicsScene(this);
    setScene(scene_);
    setSceneRect(0, 0, this->width(), this->height());

    currentFigure = RECT;

    filter_ = new ItemEventFilter{};
    filter_->setScene(scene_);
    scene_->addItem(filter_);
}

MainWindow::~MainWindow() {}

void MainWindow::resizeEvent(QResizeEvent *event) {
    setSceneRect(0, 0, this->width(), this->height());
}

bool MainWindow::event(QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        auto mouse_event = static_cast<QMouseEvent *>(event);
        if (mouse_event->button() == Qt::LeftButton) {
            addItems(mouse_event);
        }
        if (mouse_event->button() == Qt::RightButton) {
            qDebug() << mouse_event->position();
        }
        event->ignore();
        return false;
    }
    return QGraphicsView::event(event);
}

void MainWindow::addItems(QMouseEvent *event) {
    QGraphicsItem *item = nullptr;
    int flag = 1;
    if (currentFigure == RECT && flag) {
        item = static_cast<QGraphicsItem *>(scene_->addRect(
            event->position().x() - 25, event->position().y() - 35, 50, 70,
            Qt::NoPen, brushRandQColor()));

        // и вот тут у звезды все норм потому что видимо при перед ее рисованием
        // в конструкторе мы сделали setPos у остальных фигур координаты 0,0
        // заданы в точке рисования и как их привести к координатам сцены тоже
        // не понятно уже что только не перепробовал.

        //        auto left = this->mapToScene(event->position().x() - 25,
        //                                     event->position().y() - 35);
        //        auto right = this->mapToScene(event->position().x() + 25,
        //                                      event->position().y() + 35);

        //        item->setTransformOriginPoint(0, 0);
        //        item->setPos(event->position().x(), event->position().y());

        qDebug() << item->pos();

        item->sceneTransform().map(
            QPointF(event->position().x(), event->position().y()));
        qDebug() << item->pos();

        item->sceneTransform().inverted().map(
            QPointF(event->position().x(), event->position().y()));
        qDebug() << item->pos();

        currentFigure = ELLIPSE;
        flag = 0;
    }
    if (currentFigure == ELLIPSE && flag) {
        item = static_cast<QGraphicsItem *>(scene_->addEllipse(
            event->position().x() - 25, event->position().y() - 35, 50, 70,
            Qt::NoPen, brushRandQColor()));
        currentFigure = STAR;
        flag = 0;
    }
    if (currentFigure == STAR && flag) {
        item = static_cast<QGraphicsItem *>(scene_->addStar(
            40, 7, 7, event->position().x(), event->position().y(), Qt::NoPen,
            brushRandQColor()));
        currentFigure = RECT;
        flag = 0;
    }
    if (item != nullptr && !flag) {
        item->installSceneEventFilter(filter_);
        item->setFlag(QGraphicsItem::ItemIsMovable);
    }
}

QBrush MainWindow::brushRandQColor() {
    int r = QRandomGenerator::global()->bounded(255);
    int g = QRandomGenerator::global()->bounded(255);
    int b = QRandomGenerator::global()->bounded(255);
    return QBrush(QColor(r, g, b), Qt::SolidPattern);
}
