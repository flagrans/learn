#ifndef STAR_H
#define STAR_H

#include <QBrush>
#include <QGraphicsItem>
#include <QPen>

class Star : public QGraphicsItem {
public:
    Star(const int &extRadius, const int &intRadius, const int &vertex,
         const int &x, const int &y, const QPen &pen = QPen(),
         const QBrush &brush = QBrush());
    ~Star();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QRectF boundingRect() const override;

private:
    int extRadius_;
    int intRadius_;
    int x_;
    int y_;
    int vertex_;
    QPen pen_;
    QBrush brush_;
};

#endif // STAR_H
