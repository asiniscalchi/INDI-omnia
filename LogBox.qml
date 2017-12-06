import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    Rectangle {
        anchors.fill: parent
        color: "#000000"

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

