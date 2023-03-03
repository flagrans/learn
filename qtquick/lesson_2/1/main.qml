import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 540
    visible: true
    title: qsTr("Lesson #2")
    color: "#76cfba"
    Item {
        anchors.fill: parent
        Text {
            id: zag
            text: "Форма регистрации:"
            font.pointSize: 14
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            height: 30
        }
        Text {
            id: about
            text: "О себе:"
            font.pointSize: 14
            anchors.left: parent.left
            anchors.top: zag.bottom
            anchors.leftMargin: 30
            height: 30
        }
        Row {
            id:m_name
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: about.bottom
            width: parent.width
            Column {
                width: parent.width / 3
                Text {
                    text: "Имя:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                TextField {
                    id: vm_name
                    width: 150
                    height: 20
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                }
            }
        }
        Row {
            id:m_pol
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: m_name.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Пол:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                    Row {
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        RadioButton {
                        id: rbm
                        text: qsTr("М")
                        checked: true
                        }
                        RadioButton {
                        id: rbf
                        text: qsTr("Ж")
                        }
                    }
            }
        }
        Row {
            id:m_age
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: m_pol.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Возраст:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                Row {
                    id: rdial
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    Text {
                        id: age
                        text: dial_age.value
                        width: 50
                    }
                    Dial {
                        id: dial_age
                        height: 50
                        from: 18
                        to: 120
                        snapMode: Dial.SnapAlways
                        stepSize: 1
                    }
                }
            }
        }
        Row {
            id:m_edu
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: m_age.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Образование:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                ComboBox {
                    id: vm_edu
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    width: 220
                    height: 20
                    model: ["начальное", "неполное среднее", "среднее", "средне-специальное", "средне-техническое", "высшее"]
                }
            }
        }
        Row {
            id:m_hobbi
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: m_edu.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Хобби:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                Row {
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    CheckBox {
                        id: vm_hobbi_1
                        text: qsTr("готовка")
                    }
                    CheckBox {
                        id: vm_hobbi_2
                        text: qsTr("велоспорт")
                    }
                    CheckBox {
                        id: vm_hobbi_3
                        text: qsTr("плаванье")
                    }
                    CheckBox {
                        id: vm_hobbi_4
                        text: qsTr("шопинг")
                    }
                }
            }
        }
        Row {
            id:m_city
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: m_hobbi.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Город:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                TextField {
                    id: vm_city
                    width: 150
                    height: 20
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                }
            }
        }
        Row {
            id:m_advanced
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: m_city.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Доп. информация:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                TextArea {
                    id: vm_about
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    width: 300
                    height: 55
                    background: Rectangle { color: "white" }
                }
            }
        }
        Text {
            id: partner
            text: "Параметры поиска партнера:"
            font.pointSize: 14
            anchors.left: parent.left
            anchors.top: m_advanced.bottom
            anchors.leftMargin: 30
            anchors.topMargin: 20
            height: 30
        }
        Row {
            id:p_pol
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: partner.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Пол:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                    Row {
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        RadioButton {
                        id: p_rbm
                        text: qsTr("М")
                        checked: true
                        }
                        RadioButton {
                        id: p_rbf
                        text: qsTr("Ж")
                        }
                    }
            }
        }
        Row {
            id:p_age
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: p_pol.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Возрастные границы:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                Row {
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    Text {
                        width: 20
                        text: p_ages.first.value
                    }
                    RangeSlider  {
                        id: p_ages
                        from: 18
                        to: 120
                        first.value: 18
                        second.value: 120
                        stepSize: 1
                        snapMode: RangeSlider.SnapAlways
                    }
                    Text {
                        width: 20
                        text: " " + p_ages.second.value
                    }
                }
            }
        }
        Row {
            id:p_edu
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: p_age.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Образование:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                ComboBox {
                    id: vp_edu
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    width: 220
                    height: 20
                    model: ["начальное", "неполное среднее", "среднее", "средне-специальное", "средне-техническое", "высшее"]
                }
            }
        }
        Row {
            id:p_kv
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.top: p_edu.bottom
            Column {
                width: parent.width / 3
                Text {
                    text: "Наличие жилплощади:"
                    font.pointSize: 12
                    anchors.right: parent.right
                    height: 30
                }

            }
            Column {
                width: (parent.width / 3) * 2
                Switch {
                    id: vp_kv
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                }
            }
        }
        Button {
            id: but
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            height: 40
            width: parent.width / 3
            text: "Зарегистрироваться"
            onClicked: printValues()
        }
    }
    function printValues() {
        let temp_m_pol;
        if(rbm.checked) {
            temp_m_pol = "М"
        } else {
            temp_m_pol = "Ж"
        }

        let temp_p_pol;
        if(p_rbm.checked) {
            temp_p_pol = "М"
        } else {
            temp_p_pol = "Ж"
        }

        let temp_m_hobbi="";
        if(vm_hobbi_1.checked) {
            temp_m_hobbi = temp_m_hobbi + " " + vm_hobbi_1.text
        }
        if(vm_hobbi_2.checked) {
            temp_m_hobbi = temp_m_hobbi + " " + vm_hobbi_2.text
        }
        if(vm_hobbi_3.checked) {
            temp_m_hobbi = temp_m_hobbi + " " + vm_hobbi_3.text
        }
        if(vm_hobbi_4.checked) {
            temp_m_hobbi = temp_m_hobbi + " " + vm_hobbi_4.text
        }

        let temp_p_kv;
        if(vp_kv.checked) {
            temp_p_kv = "есть"
        } else {
            temp_p_kv = "не важно"
        }

        console.log("\n" +
                    "О себе:" + "\n" +
                    "Имя: " + vm_name.text + "\n" +
                    "Пол: " + temp_m_pol + "\n" +
                    "Возраст: " + dial_age.value + "\n" +
                    "Образование: " + vm_edu.currentText + "\n" +
                    "Хобби: " + temp_m_hobbi + "\n" +
                    "Город: " + vm_city.text + "\n" +
                    "Доп. информация: " + vm_about.text + "\n\n\n" +
                    "Параметры партнера:" + "\n" +
                    "Пол: " + temp_p_pol + "\n" +
                    "Возраст: " + "от " + p_ages.first.value + " до " + p_ages.second.value + "\n" +
                    "Образование: " + vp_edu.currentText + "\n" +
                    "Наличие жилплощади: " + temp_p_kv + "\n"
        );
    }
}
