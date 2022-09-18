#include "myqgraphicsscene.h"

#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>
#include <QKeyEvent>

MyQGraphicsScene::MyQGraphicsScene(QObject *parent) : QGraphicsScene{parent} {}

MyQGraphicsScene::~MyQGraphicsScene() {}

Star *MyQGraphicsScene::addStar(const QRectF rect, const int &extRadius,
                                const int &intRadius, const int &vertex,
                                const QPen &pen, const QBrush &brush) {

    auto star = new Star{rect, extRadius, intRadius, vertex, pen, brush};
    addItem(star);
    return star;
}

void MyQGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) {
    if (wheelEvent->delta() > 0) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(1.2, 1.2);

    } else if (wheelEvent->delta() < 0) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(1 / 1.2, 1 / 1.2);
    }
}

void MyQGraphicsScene::keyPressEvent(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Plus) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(1.2, 1.2);
    } else if (keyEvent->key() == Qt::Key_Minus) {
        auto ff = static_cast<QGraphicsView *>(this->parent());
        ff->scale(1 / 1.2, 1 / 1.2);
    }
}
