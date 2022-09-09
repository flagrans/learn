#ifndef FINDER_H
#define FINDER_H
#include <QObject>

class Finder : public QObject {
    Q_OBJECT
public:
    explicit Finder(QObject *parent = nullptr);

public slots:
    void doFind(const QString &path, const QString &mask);
signals:
    void resultReady(QVector<QString> results);
};

#endif // FINDER_H
