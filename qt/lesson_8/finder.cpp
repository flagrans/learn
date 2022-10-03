#include "finder.h"
#include <QDirIterator>

Finder::Finder(QObject *parent) : QObject(parent) {}

void Finder::doFind(const QString &path, const QString &mask) {
    QVector<QString> results{};
    QDirIterator it(path, QStringList() << mask, QDir::NoFilter,
                    QDirIterator::Subdirectories);
    while (it.hasNext()) {
        results.append(it.next());
    }
    emit resultReady(results);
}
