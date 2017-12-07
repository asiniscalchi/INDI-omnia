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
