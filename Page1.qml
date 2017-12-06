import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: item1
    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 2.8
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: hostTextField
            text: "localhost"
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: portTextField
            text: "7624"
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: connectButton
            text: checked ? qsTr("Disconnect") : qsTr("Connect")
            checked: indiClient.connected
            spacing: -3
            checkable: false
            onClicked: indiClient.connected ? indiClient.disconnect() : indiClient.connect(hostTextField.text, portTextField.text)
        }
    }

    TextArea
    {
        id: logTextArea
        verticalAlignment: Text.AlignTop
        readOnly: true
        Connections {
            target: indiClient
            onMessage: logTextArea.append(msg)
        }
    }
}

