import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

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

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 600

    LogBox {
        id: logBox
        anchors.top: divider.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
    }

    ConnectionBar {
        id: connectionBar
        color: "whitesmoke"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right:parent.right
        height: 60
    }

    DeviceList {
        id: deviceList
        color: "whitesmoke"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: connectionBar.bottom
        height: childrenRect.height
    }

    Rectangle {
        id: divider
        color: "whitesmoke"
        anchors.top: deviceList.bottom
        anchors.left: parent.left
        anchors.right:parent.right
        height: 5
    }


}
