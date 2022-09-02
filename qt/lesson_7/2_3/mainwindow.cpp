#include "mainwindow.h"
#include "itemeventfilter.h"
#include <QEvent>
#include <QMouseEvent>
#include <QRandomGenerator>

constexpr int rectWidth = 50;
constexpr int rectHeight = 70;
constexpr int exRadius = 40;
constexpr int intRadius = 7;
constexpr int vertex = 7;

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
    auto rect = makeRectF(event->position().x(), event->position().y());
    bool flag = true;
    if (currentFigure == RECT && flag) {
        item = static_cast<QGraphicsItem *>(
            scene_->addRect(rect, Qt::NoPen, brushRandQColor()));
        currentFigure = ELLIPSE;
        flag = false;
    }
    if (currentFigure == ELLIPSE && flag) {
        item = static_cast<QGraphicsItem *>(
            scene_->addEllipse(rect, Qt::NoPen, brushRandQColor()));
        currentFigure = STAR;
        flag = false;
    }
    if (currentFigure == STAR && flag) {
        item = static_cast<QGraphicsItem *>(scene_->addStar(
            rect, exRadius, intRadius, vertex, Qt::NoPen, brushRandQColor()));
        currentFigure = RECT;
        flag = false;
    }
    if (item != nullptr && !flag) {
        item->installSceneEventFilter(filter_);
        item->setFlag(QGraphicsItem::ItemIsMovable);
    }
}

QRectF MainWindow::makeRectF(int x, int y) {
    auto mappedPoint = mapToScene(x, y);
    QPointF tlPoint(0, 0);
    QPointF brPoint(0, 0);
    if (currentFigure == STAR) {
        tlPoint = QPointF(mappedPoint.x() - exRadius / 2,
                          mappedPoint.y() - exRadius / 2);
        brPoint = QPointF(mappedPoint.x() + exRadius / 2,
                          mappedPoint.y() + exRadius / 2);
    } else {
        tlPoint = QPointF(mappedPoint.x() - rectWidth / 2,
                          mappedPoint.y() - rectHeight / 2);
        brPoint = QPointF(mappedPoint.x() + rectWidth / 2,
                          mappedPoint.y() + rectHeight / 2);
    }
    return QRectF(tlPoint, brPoint);
}

QBrush MainWindow::brushRandQColor() {
    int r = QRandomGenerator::global()->bounded(255);
    int g = QRandomGenerator::global()->bounded(255);
    int b = QRandomGenerator::global()->bounded(255);
    return QBrush(QColor(r, g, b), Qt::SolidPattern);
}
