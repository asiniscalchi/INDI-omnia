import QtQuick 2.7

import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: ipTextField
            text: "ip address"
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: portTextField
            text: "port"
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: connectButton
            text: checked ? qsTr("Disconnect") : qsTr("Connect")
            spacing: -3
            checkable: true
            onClicked: console.log("Button Pressed. Entered text: " + ipTextField.text);
        }
    }
}

