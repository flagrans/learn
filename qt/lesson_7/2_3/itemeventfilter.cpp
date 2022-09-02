#include "itemeventfilter.h"
#include <QGraphicsSceneMouseEvent>

QRectF ItemEventFilter::boundingRect() const { return {}; }
void ItemEventFilter::paint(QPainter *, const QStyleOptionGraphicsItem *,
                            QWidget *) {}
void ItemEventFilter::setScene(MyQGraphicsScene *sc) { sc_ = sc; }

bool ItemEventFilter::sceneEventFilter(QGraphicsItem *item, QEvent *event) {
    if (pressBut(item, event)) {
        return true;
    }
    return false;
}

bool ItemEventFilter::pressBut(QGraphicsItem *item, QEvent *event) {

    auto pressEvent = static_cast<QGraphicsSceneMouseEvent *>(event);

    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (pressEvent->button() == Qt::RightButton) {
            sc_->removeItem(item);
            return true;
        }
    }
    if (event->type() == QEvent::GraphicsSceneMouseMove) {
        if (pressEvent->buttons() == Qt::LeftButton) {
            event->ignore();
            return false;
        }
        if (pressEvent->buttons() == Qt::MiddleButton) {

            item->setTransformOriginPoint(item->boundingRect().center());

            auto lsp = pressEvent->lastScreenPos().x();
            auto sp = pressEvent->screenPos().x();

            auto temp = item->rotation();

            if (sp > lsp) {
                ++temp;
            }
            if (sp < lsp) {
                --temp;
            }
            if (temp == 360 || temp == -360) {
                item->setRotation(0);
            } else {
                item->setRotation(temp);
            }
            return true;
        }
    }
    return false;
}
