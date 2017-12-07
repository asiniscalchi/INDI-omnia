import QtQuick 2.0

Rectangle {
    Component {
        id: deviceDelegate
        Item {
            width: 300; height: 60
            Column {
                Text { text: '<b>Name:</b> ' + name }
                Text { text: '<b>Connected:</b> ' + connected }
                Text { text: '<b>Interface:</b> ' + deviceInterface }
            }
        }
    }
    ListView {
        anchors.fill: parent
        model: deviceModel
        delegate: deviceDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
    }
}
