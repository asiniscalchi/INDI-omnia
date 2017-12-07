import QtQuick 2.0

Rectangle {
    Component {
        id: deviceDelegate
        Item {
            width: 300; height: 20
            Column {
                Text { text: '<b>Name:</b> ' + name }
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
