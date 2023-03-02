import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 360
    height: 690
    visible: true
    title: qsTr("Расчет площади треугольника")
    Column {
        width: 360
        height: 690
        anchors.centerIn: parent
        Rectangle {
            id: frame1
            width: 300
            height: 300
            radius: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
            color: "darkseagreen"
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10
                font.pointSize: 14
                text: qsTr("По формуле Герона:")
            }
            TextField {
                id:sta
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 40
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                placeholderText: qsTr("Введите сторону A")
            }
            TextField {
                id: stb
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 80
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                placeholderText: qsTr("Введите сторону B")
            }
            TextField {
                id:stc
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 120
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                placeholderText: qsTr("Введите сторону C")
            }
            Text {
                id:result1
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 160
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                text: qsTr("S= ")
            }
            Button {
                id:bt1
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                text: qsTr("Расчитать площадь")
                background: Rectangle {
                    radius: 5
                    color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
                onClicked: res1()
            }
        }
        Rectangle {
            id: frame2
            width: 300
            height: 300
            radius: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: frame1.bottom
            anchors.topMargin: 30
            color: "darkseagreen"
            Text {
                id:tx
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10
                font.pointSize: 14
                text: qsTr("По координатам вершин:")
            }
            Row {
                anchors.top: tx.bottom
                anchors.topMargin: 10
                Text {
                    id:txa
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    text: qsTr("Точка А:")
                }
                TextField {
                    id:xa
                    width: 40
                    anchors.left: txa.right
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    placeholderText: qsTr("X")
                }
                TextField {
                    id:ya
                    width: 40
                    anchors.left: xa.right
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    placeholderText: qsTr("Y")
                }
            }
            Row {
                anchors.top: tx.bottom
                anchors.topMargin: 50
                Text {
                    id:txb
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    text: qsTr("Точка Б:")
                }
                TextField {
                    id:xb
                    width: 40
                    anchors.left: txb.right
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    placeholderText: qsTr("X")
                }
                TextField {
                    id:yb
                    width: 40
                    anchors.left: xb.right
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    placeholderText: qsTr("Y")
                }
            }
            Row {
                anchors.top: tx.bottom
                anchors.topMargin: 90
                Text {
                    id:txc
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    text: qsTr("Точка С:")
                }
                TextField {
                    id:xc
                    width: 40
                    anchors.left: txc.right
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    placeholderText: qsTr("X")
                }
                TextField {
                    id:yc
                    width: 40
                    anchors.left: xc.right
                    anchors.leftMargin: 10
                    font.pointSize: 14
                    placeholderText: qsTr("Y")
                }
            }
            Text {
                id:result2
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 160
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                text: qsTr("S= ")
            }
            Button {
                id:bt2
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                font.pointSize: 14
                text: qsTr("Расчитать площадь")
                background: Rectangle {
                    radius: 5
                    color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
                onClicked: res2()
            }
        }
    }
function res1() {
    let a = Number(sta.text)
    let b = Number(stb.text)
    let c = Number(stc.text)
    if(((a + b) <= c) || ((b + c) <= a) || ((c + a) <= b)) {
        result1.color = "red"
        result1.text = qsTr("Не верно введены данные")
    } else {
        let p = (a + b + c) / 2
        let S = (Math.sqrt(p*(p-a)*(p-b)*(p-c))).toFixed(2)
        result1.color = "black"
        result1.text = "S = " + S
    }

}
function res2() {
    let a = Math.sqrt(Math.pow((Number(xb.text) - Number(xa.text)), 2) + Math.pow((Number(yb.text) - Number(ya.text)), 2))
    let b = Math.sqrt(Math.pow((Number(xc.text) - Number(xb.text)), 2) + Math.pow((Number(yc.text) - Number(yb.text)), 2))
    let c = Math.sqrt(Math.pow((Number(xa.text) - Number(xc.text)), 2) + Math.pow((Number(ya.text) - Number(yc.text)), 2))
    if(((a + b) <= c) || ((b + c) <= a) || ((c + a) <= b)) {
        result2.color = "red"
        result2.text = qsTr("Не верно введены данные")
    } else {
        let p = (a + b + c) / 2
        let S = (Math.sqrt(p*(p-a)*(p-b)*(p-c))).toFixed(2)
        result2.color = "black"
        result2.text = "S = " + S
    }

}
}
