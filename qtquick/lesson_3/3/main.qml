import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 432
    height: 768
    visible: true
    title: qsTr("Lesson #3")
    ListModel{
        id: books
        ListElement {
            name: "ЛЮБИ"
            author: "Камал Равикант"
            genre: "роман"
            cover: "qrc:/images/4.png"
        }
        ListElement {
            name: "Я наблюдаю за тобой"
            author: "Лайза Джуэлл"
            genre: "роман"
            cover: "qrc:/images/5.png"
        }
        ListElement {
            name: "Спаси меня"
            author: "Мона Кастен"
            genre: "роман"
            cover: "qrc:/images/6.png"
        }
        ListElement {
            name: "От Лукова с любовью"
            author: "Мариана Запата"
            genre: "роман"
            cover: "qrc:/images/8.png"
        }
        ListElement {
            name: "Мама Мама"
            author: "Корен Зайлукас"
            genre: "детектив"
            cover: "qrc:/images/7.png"
        }
        ListElement {
            name: "День Ангела"
            author: "Юлия Варенцова"
            genre: "детектив"
            cover: "qrc:/images/9.png"
        }
        ListElement {
            name: "Войны Милли Гана."
            author: "Дэниэл Киз"
            genre: "детектив"
            cover: "qrc:/images/1.png"
        }
        ListElement {
            name: "Лягушки"
            author: "Мо Янь"
            genre: "публицистика"
            cover: "qrc:/images/10.png"
        }
        ListElement {
            name: "Убить большого соню в себе."
            author: "Джен Синсеро"
            genre: "публицистика"
            cover: "qrc:/images/2.png"
        }
        ListElement {
            name: "НИЗЯ"
            author: "Джен Синсеро"
            genre: "публицистика"
            cover: "qrc:/images/3.png"
        }
    }


    ListView {
        id: list
        anchors.fill: parent
        model: books
        spacing: 1
        // Хэдер
        header:
            Rectangle {
                width: parent.width
                height: 20
                color: "darkblue"
                Text {
                    anchors.centerIn: parent
                    text: "БИБЛИОТЕКА"
                    color: "white"
                }
            }
        // Футер
        footer:
            Rectangle {
                width: parent.width
                height: 20
                color: "darkgreen"
                Text {
                    anchors.centerIn: parent
                    text: "@ Андрей Кузнецов, 2023"
                    color: "white"
                }
            }
        // Секции по группам пользователей
        section.delegate:
            Rectangle {
                width: parent.width
                height: 20
                color: "lightblue"
                Text {
                    anchors.centerIn: parent
                    text: section
                    color: "darkblue"
                    font.weight: Font.Bold
                }
            }
        section.property: "genre"
        // Сами элементы
        delegate:
            Rectangle {
                width: list.width
                height: 70
                radius: 3
                border.width: 1
                border.color: "darkgray"
                color: "lightgray"
                MouseArea {
                    anchors.fill: parent
                    onDoubleClicked: {
                        list.model.remove(index)
                    }
                }
                Row {
                    width: parent.width
                    height: 70
                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.height
                        Image {
                            height: parent.height
                            width: 50
                            source: cover
                        }
                    }
                    Column {
                        height: parent.height
                        Row {
                            Text { text: "Наименование: "; font.weight: Font.Bold}
                            Text { text: name }
                        }
                        Row {
                            Text { text: "Автор: "; font.weight: Font.Bold}
                            Text { text: author }
                        }
                        Row {
                            Text { text: "Жанр: "; font.weight: Font.Bold}
                            Text { text: genre }
                        }
                    }
                }
            }// Rectangle
            focus: true
            // Анимация появления элементов модели
            populate:
                Transition {
                    NumberAnimation {
                        properties: "x,y"; duration: 1500; easing.type: Easing.OutExpo
                    }
                }
            // Анимация добавления элементов
            add:
                Transition {
                    NumberAnimation {
                        property: "opacity"; from: 0; to: 1.0; duration: 400
                    }
                    NumberAnimation {
                        property: "scale"; from: 0; to: 1.0; duration: 100
                    }
                }
                // Удаление элемента
            remove:
                Transition {
                    PropertyAnimation {
                        property: "opacity"; to: 0; duration: 1000
                    }
                }
    }// ListView
}
