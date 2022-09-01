#include "star.h"
#include <QPainter>

Star::Star(const int &extRadius, const int &intRadius, const int &vertex,
           const int &x, const int &y, const QPen &pen, const QBrush &brush)
    : extRadius_(extRadius), intRadius_(intRadius), vertex_(vertex), x_(x),
      y_(y), pen_(pen), brush_(brush) {
    if (extRadius_ < intRadius_) {
        int temp = extRadius_;
        extRadius_ = intRadius_;
        intRadius_ = temp;
    }
    setPos(QPointF(x_, y_));
}

Star::~Star() {}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {

    painter->setPen(pen_);
    painter->setBrush(brush_);

    QPainterPath starPath;

    double alpha{3.14 / vertex_};

    int startX = extRadius_ * cos(alpha * (2 * vertex_ - 1));
    int startY = extRadius_ * sin(alpha * (2 * vertex_ - 1));

    starPath.moveTo(startX, startY);

    int x{0};
    int y{0};

    for (int i = 0; i < 2 * vertex_; i++) {
        if (i % 2 == 1) {
            x = extRadius_ * cos(alpha * i);
            y = extRadius_ * sin(alpha * i);
        } else {
            x = intRadius_ * cos(alpha * i);
            y = intRadius_ * sin(alpha * i);
        }

        starPath.lineTo(x, y);
    }

    starPath.closeSubpath();
    painter->drawPath(starPath);
}

QRectF Star::boundingRect() const {
    return QRectF(QPointF(-extRadius_, -extRadius_),
                  QPointF(extRadius_, extRadius_));
}
