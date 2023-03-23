import QtQuick 2.15
import Qt.labs.qmlmodels 1.0
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {

    property int cellHorizontalSpacing: 5

    TableModel {
        id: tableModel
        TableModelColumn { display: "id" }
        TableModelColumn { display: "task" }
        TableModelColumn { display: "date" }
        TableModelColumn { display: "progress" }
        rows: []
    }
    ColumnLayout {
        anchors.fill: parent
        spacing: 1
        HorizontalHeaderView {
            id: horizontalHeader
            syncView: table_
            implicitHeight: 30
            reuseItems: false
            Layout.fillWidth: true
            boundsBehavior:Flickable.StopAtBounds
            delegate: DelegateChooser {
                DelegateChoice {
                    column: 0
                    delegate: Rectangle {
                        color: "#efefef"
                        border.color: "#bbb"
                        border.width: 1
                        implicitWidth: Math.max(100, cellHorizontalSpacing * 2 + headerText.width)
                        implicitHeight: 30
                        z: -1
                        Text {
                            id: headerText
                            anchors.centerIn: parent
                            text: "ID"
                        }
                    }
                }
                DelegateChoice {
                    column: 1
                    delegate: Rectangle {
                        color: "#efefef"
                        border.color: "#bbb"
                        border.width: 1
                        implicitWidth: Math.max(100, cellHorizontalSpacing * 2 + headerText1.width)
                        implicitHeight: 30
                        z: -1
                        Text {
                            id: headerText1
                            anchors.centerIn: parent
                            text: "Задача"
                        }
                    }
                }
                DelegateChoice {
                    column: 2
                    delegate: Rectangle {
                        color: "#efefef"
                        border.color: "#bbb"
                        border.width: 1
                        implicitWidth: Math.max(100, cellHorizontalSpacing * 2 + headerText2.width)
                        implicitHeight: 30
                        z: -1
                        Text {
                            id: headerText2
                            anchors.centerIn: parent
                            text: "Дата окончания"
                        }
                    }
                }
                DelegateChoice {
                    column: 3
                    delegate: Rectangle {
                        color: "#efefef"
                        border.color: "#bbb"
                        border.width: 1
                        implicitWidth: Math.max(100, cellHorizontalSpacing * 2 + headerText3.width)
                        implicitHeight: 30
                        z: -1
                        Text {
                            id: headerText3
                            anchors.centerIn: parent
                            text: "Прогресс (0-10)"
                        }
                    }
                }
            }
        }

        TableView {
            id: table_
            model: tableModel
            interactive : false
            Layout.fillWidth: true
            Layout.fillHeight: true
            boundsBehavior:Flickable.StopAtBounds
            columnSpacing: 1
            rowSpacing: 1

            delegate: Rectangle {
                implicitWidth: Math.max(100, cellHorizontalSpacing * 2 + innerT.width)
                implicitHeight: Math.max(30, innerT.height + 10)
                border.width: 1
                color: "#efefef"
                z: -1
                Text {
                    id: innerT
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    text: model.display
                    padding: 12
                }
            }
        }
    }
    MyBut {
        id: m_but_view
        width: Math.max(150, cellHorizontalSpacing * 2 + m_but_t.width)
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: m_but_t
            anchors.centerIn: parent
            text: "Вернуться"
        }
        onClicked: {
            loader.source = "./MyWindow.qml"
        }
    }
    Component.onCompleted: {
        var answer = task.getList();
        for(var i = 0; i < task.getCountTasks(); ++i) {
            var srok = new Date(answer[i][2]);
            tableModel.appendRow({
                                id: answer[i][0],
                                task: answer[i][1],
                                date: srok.toLocaleDateString("ru-RU"),
                                progress: answer[i][3]
             })
        }
    }
}
