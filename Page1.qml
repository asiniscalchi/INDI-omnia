import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: item1
    RowLayout {
        id: prova
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 2.8
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: hostTextField
            text: "localhost"
            placeholderText: qsTr("host")
        }

        TextField {
            id: portTextField
            text: "7624"
            placeholderText: qsTr("port")
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

    Rectangle {
        color: "#000000"
        anchors.top: prova.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        ScrollView {
            anchors.fill: parent

            TextArea
            {
                id: logTextArea
                verticalAlignment: Text.AlignTop
                readOnly: true
                color: "green"

                Connections {
                    target: indiClient
                    onMessage: logTextArea.append(msg)
                }
            }
        }

    }
}

