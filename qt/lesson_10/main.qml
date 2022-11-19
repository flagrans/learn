import QtQuick 2.15
import QtQuick.Controls 2.15
import com.Task 1.0

Window {
    width: 425
    height: 340
    visible: true
    title: qsTr("Домашнее задание №10")
    MyWindow{
        id: mw
    }
    Task {
        id: task
    }
}


