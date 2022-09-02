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
    QGraphicsItem *it = nullptr;
    auto pressEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
    it = sc_->itemAt(QPointF(sc_->mouseGrabberItem()->x() + 25,
                             sc_->mouseGrabberItem()->y() + 35),
                     QTransform());
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (pressEvent->button() == Qt::RightButton) {
            if (it != nullptr) {
                sc_->removeItem(it);
                return true;
            }
        }
    }
    return false;
}
