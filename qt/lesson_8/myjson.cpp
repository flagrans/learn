#include "myjson.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

MyJson::MyJson() {}
MyJson::~MyJson() {}

bool MyJson::read(QString filename, QVector<QString> &data) {
    QString val;
    QFile file;

    data.append("ru");
    data.append("white");
    data.append("Ctrl+O");
    data.append("Ctrl+R");
    data.append("Ctrl+S");
    data.append("Alt+F1");
    data.append("F2");
    data.append("Alt+X");
    data.append("Ctrl+P");
    data.append("Ctrl+D");

    file.setFileName(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        val = file.readAll();
        file.close();

        // QList<QString> data;

        QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject json = doc.object();
        data.replace(0, json["lang"].toString());
        data.replace(1, json["theme"].toString());
        QJsonArray ar = json["hotkeys"].toArray();
        data.replace(2, ar[0].toString());
        data.replace(3, ar[1].toString());
        data.replace(4, ar[2].toString());
        data.replace(5, ar[3].toString());
        data.replace(6, ar[4].toString());
        data.replace(7, ar[5].toString());
        data.replace(8, ar[6].toString());
        data.replace(9, ar[7].toString());

        return true;
    } else {
        return false;
    }
}

bool MyJson::save(QString filename, QVector<QString> &dat) {
    QJsonObject recordObject;

    QJsonArray numbersArray;
    numbersArray.push_back(dat.at(2));
    numbersArray.push_back(dat.at(3));
    numbersArray.push_back(dat.at(4));
    numbersArray.push_back(dat.at(5));
    numbersArray.push_back(dat.at(6));
    numbersArray.push_back(dat.at(7));
    numbersArray.push_back(dat.at(8));
    numbersArray.push_back(dat.at(9));
    recordObject.insert("hotkeys", numbersArray);
    recordObject.insert("theme", QJsonValue::fromVariant(dat.at(1)));
    recordObject.insert("lang", QJsonValue::fromVariant(dat.at(0)));

    QJsonDocument doc(recordObject);
    QString jsonString = doc.toJson(QJsonDocument::Indented);
    //Записываем данные в файл
    QFile file;
    file.setFileName("settings.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << jsonString;
        file.close();
        return true;
    } else {
        return false;
    }
}
