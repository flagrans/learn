#ifndef ITEMEVENTFILTER_H
#define ITEMEVENTFILTER_H

#include "myqgraphicsscene.h"

#include <QGraphicsItem>

class ItemEventFilter : public QGraphicsItem {
public:
    QRectF boundingRect() const override;
    void paint(QPainter *, const QStyleOptionGraphicsItem *,
               QWidget * = nullptr) override;
    void setScene(MyQGraphicsScene *sc);

protected:
    bool sceneEventFilter(QGraphicsItem *item, QEvent *event) override;

private:
    bool pressBut(QGraphicsItem *item, QEvent *event);

private:
    MyQGraphicsScene *sc_;
};

#endif // ITEMEVENTFILTER_H
