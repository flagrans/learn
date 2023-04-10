import QtQuick 2.15
import QtQuick.Controls 2.15
import com.Task 1.0

Window {
    width: 445
    height: 400
    visible: true
    title: qsTr("Домашнее задание №11")
    id: mainw
    Task {
        id: task
    }
    Loader {
        id: loader
        anchors.fill: parent
        onSourceChanged: animation.running = true
        NumberAnimation {
            id: animation
            target: loader.item
            property: "opacity"
            from: 0
            to: 1
            duration: 500
        }
    }
    Component.onCompleted: {
        loader.source = "./MyWindow.qml"
    }
}


