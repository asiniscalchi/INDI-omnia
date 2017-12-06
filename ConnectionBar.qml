import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    RowLayout {
        anchors.topMargin: 20
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 2.8

        TextField {
            id: hostTextField
            enabled: !indiClient.connected
            text: "localhost"
            placeholderText: qsTr("host")
        }

        TextField {
            id: portTextField
            enabled: !indiClient.connected
            text: "7624"
            placeholderText: qsTr("port")
        }

        Button {
            id: connectButton
            text: indiClient.connected ? qsTr("Disconnect") : qsTr("Connect")
            checked: indiClient.connected
            spacing: -3
            checkable: false
            onClicked: indiClient.connected ? indiClient.disconnect() : indiClient.connect(hostTextField.text, portTextField.text)
        }
    }
}
