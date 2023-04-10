import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    anchors.fill: parent
    function getDaysInMonth(month,year) {
        return new Date(year, month, 0).getDate();
    }
    function clearForms() {
        var today = new Date();
        control_y.currentIndex = 0
        control_m.currentIndex = today.getMonth()
        control_d.currentIndex = today.getDate() - 1
        control_y.update()
        control_m.update()
        control_d.update()
        name_z.clear()
        m_slider.value = 0
        m_label.text = "0"
    }
    Component.onCompleted: {
        clearForms()
        label_tasks.text = task.getCountTasks()
    }
    property string test_task_name: name_z.text

    Row {
        id: count_tasks
        leftPadding: 5
        topPadding: 5
        Text {
            id: count_text
            text: "Всего задач в базе:"
            width: 200
        }
        Text {
            id: label_tasks
        }
    }
    Row {
        id: row1
        anchors.left: count_tasks.left
        anchors.top: count_tasks.bottom
        leftPadding: 5
        topPadding: 5
        Text {
            id: l1
            text: "Введите название новой задачи:"
            width: 200
        }
        TextField {
            id: name_z
            objectName: "name_z"
            focus: true
            width: 200
        }
    }
    Row {
        id: row2
        anchors.left: row1.left
        anchors.top: row1.bottom
        anchors.leftMargin: 5
        anchors.topMargin: 5
        Text {
            id: lt
            text: "Выберите дату дедлайна:"
            width: 200
        }
    }
    Row {
        id: row_tumbler
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: row2.bottom
        anchors.leftMargin: 5
        anchors.topMargin: 5
        Tumbler { // Day
            id: control_d
            model: 30
            //currentIndex: 3

            background: Item {
                Rectangle {
                    opacity: control_d.enabled ? 0.2 : 0.1
                    border.color: "#000000"
                    width: parent.width
                    height: 1
                    anchors.top: parent.top
                }

                Rectangle {
                    opacity: control_d.enabled ? 0.2 : 0.1
                    border.color: "#000000"
                    width: parent.width
                    height: 1
                    anchors.bottom: parent.bottom
                }
            }

            delegate: Text {
                text: modelData + 1
                font: control_d.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                opacity: 1.0 - Math.abs(Tumbler.displacement) / (control_d.visibleItemCount / 2)

                required property var modelData
                required property int index
            }

            Rectangle {
                anchors.horizontalCenter: control_d.horizontalCenter
                y: control_d.height * 0.4
                width: 40
                height: 1
                color: "#21be2b"
            }

            Rectangle {
                anchors.horizontalCenter: control_d.horizontalCenter
                y: control_d.height * 0.6
                width: 40
                height: 1
                color: "#21be2b"
            }
        }
        Tumbler { // Mouth
            id: control_m
            model: ["января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря"]

            background: Item {
                Rectangle {
                    opacity: control_m.enabled ? 0.2 : 0.1
                    border.color: "#000000"
                    width: parent.width
                    height: 1
                    anchors.top: parent.top
                }

                Rectangle {
                    opacity: control_m.enabled ? 0.2 : 0.1
                    border.color: "#000000"
                    width: parent.width
                    height: 1
                    anchors.bottom: parent.bottom
                }
            }

            delegate: Text {
                text: modelData
                font: control_m.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                opacity: 1.0 - Math.abs(Tumbler.displacement) / (control_m.visibleItemCount / 2)

                required property var modelData
                required property int index
                onIndexChanged: {
                    control_d.model = getDaysInMonth(control_m.currentIndex + 1, control_y.model[control_y.currentIndex])
                    control_d.update()
                }
                Component.onCompleted: {
                    var today = new Date();
                    var listYears = []
                    for (var i = today.getFullYear(); i < today.getFullYear() + 10; i ++ ){
                        listYears.push(i)
                    }
                    control_y.model = listYears
                }
            }

            Rectangle {
                anchors.horizontalCenter: control_m.horizontalCenter
                y: control_m.height * 0.4
                width: 40
                height: 1
                color: "#21be2b"
            }

            Rectangle {
                anchors.horizontalCenter: control_m.horizontalCenter
                y: control_m.height * 0.6
                width: 40
                height: 1
                color: "#21be2b"
            }
        }
        Tumbler { // Year
            id: control_y
            background: Item {
                Rectangle {
                    opacity: control_y.enabled ? 0.2 : 0.1
                    border.color: "#000000"
                    width: parent.width
                    height: 1
                    anchors.top: parent.top
                }

                Rectangle {
                    opacity: control_y.enabled ? 0.2 : 0.1
                    border.color: "#000000"
                    width: parent.width
                    height: 1
                    anchors.bottom: parent.bottom
                }
            }

            delegate: Text {
                text: modelData
                font: control_y.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                opacity: 1.0 - Math.abs(Tumbler.displacement) / (control_y.visibleItemCount / 2)

                required property var modelData
                required property int index

                onIndexChanged: {
                    control_d.model = getDaysInMonth(control_m.currentIndex + 1, control_y.model[control_y.currentIndex])
                    control_d.update()
                }
            }

            Rectangle {
                anchors.horizontalCenter: control_y.horizontalCenter
                y: control_y.height * 0.4
                width: 40
                height: 1
                color: "#21be2b"
            }

            Rectangle {
                anchors.horizontalCenter: control_y.horizontalCenter
                y: control_y.height * 0.6
                width: 40
                height: 1
                color: "#21be2b"
            }
        }


    }
    Row {
        id: row3
        anchors.left: row2.left
        anchors.top: row_tumbler.bottom
        anchors.topMargin: 10
        spacing: 5
        Text {
            id: l3
            text: "Выберите степень завершенности задачи (от 0 до 10):"
        }
    }
    Row {
        id: row4
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: row3.bottom
        anchors.topMargin: 10
        spacing: 5
        Slider {
            stepSize: 1.0
            id: m_slider
            from: 0
            value: 0
            to: 10
            onMoved: m_label.text = m_slider.value
        }
        Text {
            id: m_label
            width: 20
            height: 30
            text: "0"
        }
    }
    Row {
        id: row5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: row4.bottom
        anchors.topMargin: 5
        spacing: 5
        MyBut{
            id: m_but_add
            text: "Добавить задачу"
            onClicked: {
                if (name_z.text !== "") {
                    var m = (control_m.currentIndex + 1).toString();
                    var d = (control_d.currentIndex + 1).toString();
                    if (m.length === 1) {
                        m = "0" + m;
                    }
                    if (d.length === 1) {
                        d = "0" + d;
                    }
                    var resultStr = control_y.model[control_y.currentIndex] + "-" + m + "-" + d;
                    task.addTask(name_z.text, resultStr, m_slider.value.toString());
                    clearForms();
                    label_tasks.text = task.getCountTasks();
                }
            }
        }
        MyBut {
            id: m_but_clear
            objectName: "m_but_clear"
            text: "Очистить форму"
            onClicked: {
                clearForms()
            }
        }
        MyBut {
            id: m_but_view
            text: "Просмотреть задачи"
            onClicked: {
                loader.source = "./table.qml"
            }
        }
    }
}
