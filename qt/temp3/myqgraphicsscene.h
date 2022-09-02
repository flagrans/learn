#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>

class MyQGraphicsScene : public QGraphicsScene {
public:
    explicit MyQGraphicsScene(QObject *parent = nullptr);
    ~MyQGraphicsScene();

    void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) override;
};

#endif // MYQGRAPHICSSCENE_H
