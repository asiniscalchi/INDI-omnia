/*
* Copyright (C) 2017 Alessandro Siniscalchi <asiniscalchi@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Qt.labs.settings 1.0

Rectangle {
    id: item1
    TextField {
        id: hostTextField
        anchors.left: parent.left
        anchors.leftMargin: 10
        enabled: !deviceModel.connected
        text: "localhost"
        anchors.verticalCenter: parent.verticalCenter
        placeholderText: qsTr("host")
    }

    TextField {
        id: portTextField
        anchors.left: hostTextField.right
        anchors.leftMargin: 5
        enabled: !deviceModel.connected
        text: "7624"
        anchors.verticalCenter: parent.verticalCenter
        placeholderText: qsTr("port")
    }

    Button {
        id: connectButton
        anchors.right: parent.right
        anchors.rightMargin: 10
        text: deviceModel.connected ? qsTr("Disconnect") : qsTr("Connect")
        anchors.verticalCenter: parent.verticalCenter
        checked: deviceModel.connected
        checkable: false
        onClicked: deviceModel.connected ? deviceModel.disconnect() : deviceModel.connect(hostTextField.text, portTextField.text)
    }

    Settings {
        property alias host: hostTextField.text
        property alias port: portTextField.text
    }
}
