import QtQuick 2.0

ListView {
    width: 180; height: 200

    model: deviceModel
    delegate: Text {
        text: name
    }
}
