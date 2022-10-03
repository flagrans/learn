import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    width: 425
    height: 340
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
    //property alias test_clear_button: m_but_clear
    Row {
        id: count_tasks
        x: 5
        y: 5
        leftPadding: 5
        topPadding: 5
        Label {
            id: count_text
            text: "Всего задач в базе:"
            width: 190
        }
        Label {
            id: label_tasks
        }
    }
    Row {
        id: row1
        anchors.left: count_tasks.left
        anchors.top: count_tasks.bottom
        leftPadding: 5
        topPadding: 5
        Label {
            id: l1
            text: "Введите название новой задачи:"
            width: 190
        }
        TextField {
            id: name_z
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
        Label {
            id: lt
            text: "Выберите дату дедлайна:"
            width: 190
        }
        Tumbler {
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
        Tumbler {
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
        Tumbler {
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
        // Не понятно почему тут привязка к row2 работает и если перемещаем row2 то перемещается и row3 а в row2->row1 не работает
        anchors.left: row2.left
        anchors.top: row2.bottom
        anchors.topMargin: 10
        spacing: 5
        Label {
            id: l3
            text: "Выберите степень завершенности задачи (от 0 до 10):"
        }
        Slider {
            stepSize: 1.0
            id: m_slider
            from: 0
            value: 0
            to: 10
            onMoved: m_label.text = m_slider.value
        }
        Label {
            id: m_label
            width: 20
            height: 30
            text: "0"
        }
    }
    MyBut{
        id: m_but_add
        text: "Добавить задачу"
        anchors.left: row3.left
        anchors.top: row3.bottom
        anchors.topMargin: 5
        onClicked: {
            if (name_z.text !== "") {
                var resultStr = name_z.text + "###" + (control_d.currentIndex + 1)
                        + "." + (control_m.currentIndex + 1) + "."
                        + control_y.model[control_y.currentIndex] + "###"
                        + m_slider.value.toString();
                task.addTask = resultStr
                clearForms()
                label_tasks.text = task.getCountTasks()
            }
        }
    }
    MyBut {
        id: m_but_clear
        text: "Очистить форму"
        anchors.left: m_but_add.right
        anchors.top: m_but_add.top
        anchors.leftMargin: 5
        onClicked: {
            clearForms()
            //task.testTask("asdasd", 2)
        }
    }
}
