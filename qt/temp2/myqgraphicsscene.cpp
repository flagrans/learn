#include "myqgraphicsscene.h"

#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>

MyQGraphicsScene::MyQGraphicsScene(QObject *parent) : QGraphicsScene{parent} {}

MyQGraphicsScene::~MyQGraphicsScene() {}

Star *MyQGraphicsScene::addStar(const int &extRadius, const int &intRadius,
                                const int &vertex, const int &x, const int &y,
                                const QPen &pen, const QBrush &brush) {

    auto star = new Star{extRadius, intRadius, vertex, x, y, pen, brush};
    addItem(star);
    return star;
}

void MyQGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) {
    // Тут не понятно мне почему после масштаба новый фигуры рисуеюся так,
    // причем перетаскиваются фигуры нормально
    if (wheelEvent->delta() > 0) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(2, 2);
        ff->mapToScene(0, 0, ff->width(), ff->height());

    } else if (wheelEvent->delta() < 0) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(0.5, 0.5);
    }
}
