#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <star.h>

class MyQGraphicsScene : public QGraphicsScene {
public:
    explicit MyQGraphicsScene(QObject *parent = nullptr);
    ~MyQGraphicsScene();

    Star *addStar(const int &extRadius, const int &intRadius, const int &vertex,
                  const int &x, const int &y, const QPen &pen = QPen(),
                  const QBrush &brush = QBrush());

    void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) override;
};

#endif // MYQGRAPHICSSCENE_H
