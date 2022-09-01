#include "itemeventfilter.h"
#include <QGraphicsSceneMouseEvent>

QRectF ItemEventFilter::boundingRect() const { return {}; }
void ItemEventFilter::paint(QPainter *, const QStyleOptionGraphicsItem *,
                            QWidget *) {}
void ItemEventFilter::setScene(MyQGraphicsScene *sc) { sc_ = sc; }

bool ItemEventFilter::sceneEventFilter(QGraphicsItem *item, QEvent *event) {
    if (pressBut(event)) {
        return true;
    }
    return false;
}

bool ItemEventFilter::pressBut(QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        auto pressEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
        if (pressEvent->button() == Qt::RightButton) {
            auto it = sc_->itemAt(QPointF(sc_->mouseGrabberItem()->x(),
                                          sc_->mouseGrabberItem()->y()),
                                  QTransform());
            qDebug() << QPointF(sc_->mouseGrabberItem()->x(),
                                sc_->mouseGrabberItem()->y());
            sc_->removeItem(it);

            return true;
        }
    }
    return false;
}
