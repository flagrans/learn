#ifndef MYJSON_H
#define MYJSON_H

#include <QString>

class MyJson {

public:
    MyJson();
    ~MyJson();
    bool read(QString filename, QVector<QString> &data);
    bool save(QString filename, QVector<QString> &data);
};

#endif // MYJSON_H
