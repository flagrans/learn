import QtQuick 2.15

Window {
    property int rad: 0
    width: 640
    height: 480
    visible: true
    title: qsTr("Lesson #2")
    Rectangle {
        id: rect
        width: 150
        height: 150
        anchors.centerIn: parent
        color: "darkred"
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: (mouse)=> {
                if (mouse.button === Qt.RightButton)
                    ra.start();
                else
                   rect.color = Qt.rgba(Math.random(),Math.random(),Math.random(),1);
            }
            onDoubleClicked: (mouse)=> {
                if (mouse.button === Qt.LeftButton) {
                    if (parent.radius === 0) {
                        rad = 150;
                    } else {
                        rad = 0
                    }
                    pa.start();
                }
            }
        }
    }
    PropertyAnimation {
        id: pa
        duration: 1000
        target: rect
        property: "radius"
        to: rad
    }
    RotationAnimation {
        id: ra
        duration: 2000
        target: rect
        from: 0
        to: 360
    }
}
