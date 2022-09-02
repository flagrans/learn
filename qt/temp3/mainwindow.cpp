#include "mainwindow.h"
#include "itemeventfilter.h"
#include <QEvent>
#include <QMouseEvent>
#include <QRandomGenerator>

constexpr int rectWidth = 50;
constexpr int rectHeight = 70;

MainWindow::MainWindow(QWidget *parent) : QGraphicsView(parent) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene_ = new MyQGraphicsScene(this);
    setScene(scene_);
    setSceneRect(0, 0, this->width(), this->height());

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
    auto rect = makeRectF(event->position().x(), event->position().y());
    auto item = (scene_->addRect(rect, Qt::NoPen, brushRandQColor()));
    item->installSceneEventFilter(filter_);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF MainWindow::makeRectF(int x, int y) {
    auto tlPoint = this->mapToScene(x - rectWidth / 2, y - rectHeight / 2);
    auto brPoint = this->mapToScene(x + rectWidth / 2, y + rectHeight / 2);
    return QRectF(tlPoint, brPoint);
}

QBrush MainWindow::brushRandQColor() {
    int r = QRandomGenerator::global()->bounded(255);
    int g = QRandomGenerator::global()->bounded(255);
    int b = QRandomGenerator::global()->bounded(255);
    return QBrush(QColor(r, g, b), Qt::SolidPattern);
}
