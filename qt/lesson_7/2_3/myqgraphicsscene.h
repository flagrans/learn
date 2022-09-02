#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <star.h>

class MyQGraphicsScene : public QGraphicsScene {
public:
    explicit MyQGraphicsScene(QObject *parent = nullptr);
    ~MyQGraphicsScene();

    Star *addStar(const QRectF rect, const int &extRadius, const int &intRadius,
                  const int &vertex, const QPen &pen = QPen(),
                  const QBrush &brush = QBrush());

protected:
    void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) override;
    void keyPressEvent(QKeyEvent *keyEvent) override;
};

#endif // MYQGRAPHICSSCENE_H
