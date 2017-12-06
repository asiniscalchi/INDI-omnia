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
            id: hostTextField
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
            checked: indiClient.connected
            spacing: -3
            checkable: false
            onClicked: indiClient ? indiClient.connect(hostTextField.text, portTextField.text) : indiClient.disconnect()
        }
    }
}

