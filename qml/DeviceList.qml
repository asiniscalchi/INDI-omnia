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

import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    Component {
        id: viewDelegate
        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            height: childrenRect.height

            Text {
                anchors.right: connectedSwitch.left
                anchors.rightMargin: 10
                text: name
            }

            Switch {
                id: connectedSwitch
                checked: connected
                anchors.right: parent.right
                MouseArea {
                    anchors.fill: parent
                    onClicked: deviceModelFacade.setDeviceConnected(index, !connected)
                }
            }

        }
    }

    ListView {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        height: childrenRect.height
        model: deviceModel
        delegate: viewDelegate
    }
}
