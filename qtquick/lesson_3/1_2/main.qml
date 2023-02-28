import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 432
    height: 768
    visible: true
    title: qsTr("Lesson #3")
    Item {
        anchors.fill: parent
        id: root
        state: "state_1"
        states: [
            State {
                name: "state_1"
                PropertyChanges { target: r4; visible: false }
                PropertyChanges { target: r1; visible: true }
                PropertyChanges { target: r1; opacity: 1 }
                PropertyChanges { target: r4; opacity: 0 }
            },
            State {
                name: "state_2"
                PropertyChanges { target: r1; visible: false }
                PropertyChanges { target: r2; visible: true }
                PropertyChanges { target: r2; opacity: 1 }
                PropertyChanges { target: r1; opacity: 0 }
            },
            State {
                name: "state_3"
                PropertyChanges { target: r2; visible: false }
                PropertyChanges { target: r3; visible: true }
                PropertyChanges { target: bi; running: true }
                PropertyChanges { target: r3; opacity: 1 }
                PropertyChanges { target: r2; opacity: 0 }
            },
            State {
                name: "state_4"
                PropertyChanges { target: r3; visible: false }
                PropertyChanges { target: r4; visible: true }
                PropertyChanges { target: r4; opacity: 1 }
                PropertyChanges { target: r3; opacity: 0 }
            }
        ]
        transitions: [
            Transition {
                to: "*"
                 NumberAnimation { property: "opacity"; easing.type: Easing.InOutQuad; duration: 2000 }
            },
            Transition {
                to: "state_3"
                PropertyAnimation {
                    duration: 5000
                }
                NumberAnimation { property: "opacity"; easing.type: Easing.InOutQuad; duration: 2000 }

                onRunningChanged: {
                    root.state = "state_4"
                }
            }
        ]

        Rectangle {
            id: r1
            anchors.fill: parent
            color: "darkred"
            visible: false
            opacity: 0
            Rectangle {
                id: r1_top
                anchors.top: parent.top
                width: parent.width
                height: 50
                color: "yellow"
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 20
                    text: "Авторизация"
                }
            }
            TextField {
                id: r1_login
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: r1_top.bottom
                anchors.topMargin: 30
                font.pointSize: 20
                placeholderText: "login"
            }
            TextField {
                id: r1_pass
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: r1_login.bottom
                anchors.topMargin: 30
                font.pointSize: 20
                placeholderText: "password"
                echoMode: TextInput.Password
            }
            Button {
                id: r1_but_login
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                font.pointSize: 20
                text: "Войти"
                onClicked: root.state = "state_2"
            }
        }
        Rectangle {
            id: r2
            anchors.fill: parent
            color: "darkcyan"
            visible: false
            opacity: 0
            Rectangle {
                id: r2_top
                anchors.top: parent.top
                width: parent.width
                height: 50
                color: "yellow"
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 20
                    text: "Поиск"
                }
            }
            TextField {
                id: r2_search
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: r2_top.bottom
                anchors.topMargin: 30
                font.pointSize: 20
                placeholderText: "Введите строку для поиска"
            }
            Button {
                id: r2_but_search
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                font.pointSize: 20
                text: "Поиск"
                onClicked: root.state = "state_3"
            }
        }
        Rectangle {
            id: r3
            anchors.fill: parent
            color: "darkblue"
            visible: false
            opacity: 0
            Rectangle {
                id: r3_top
                anchors.top: parent.top
                width: parent.width
                height: 50
                color: "yellow"
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 20
                    text: "Выполняется поиск..."
                }
            }
            TextField {
                id: r3_search
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: r3_top.bottom
                anchors.topMargin: 30
                font.pointSize: 20
                text: r2_search.text
                readOnly: true
            }
            Button {
                id: r3_but_search
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                font.pointSize: 20
                text: "Поиск"
            }
            Rectangle {
                anchors.fill: parent
                color: "black"
                opacity: 0.6
                BusyIndicator {
                    id: bi
                    width: 80
                    height: 80
                    anchors.centerIn: parent
                    running: false
                }
            }
        }
        Rectangle {
            id: r4
            anchors.fill: parent
            color: "darkgreen"
            visible: false
            opacity: 0
            Rectangle {
                id: r4_top
                anchors.top: parent.top
                width: parent.width
                height: 50
                color: "yellow"
                Text {
                    anchors.centerIn: parent
                    font.pointSize: 20
                    text: "Результаты поиска"
                }
            }
            Button {
                id: r4_but_back
                width: 200
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                font.pointSize: 20
                text: "Назад"
                onClicked: root.state = "state_1"
            }
        }
    }
}
