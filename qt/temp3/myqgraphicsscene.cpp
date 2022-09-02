#include "myqgraphicsscene.h"

#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>

MyQGraphicsScene::MyQGraphicsScene(QObject *parent) : QGraphicsScene{parent} {}

MyQGraphicsScene::~MyQGraphicsScene() {}

void MyQGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) {
    if (wheelEvent->delta() > 0) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(1.2, 1.2);

    } else if (wheelEvent->delta() < 0) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(1 / 1.2, 1 / 1.2);
    }
}
