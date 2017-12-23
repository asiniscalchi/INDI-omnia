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

Rectangle {
    color: "#000000"

    ListView {
        property bool followNewLines: true

        id: listView
        anchors.fill: parent
        highlightFollowsCurrentItem: true
        model: logFilterModel
        currentIndex: followNewLines ? count - 1 : -1

        delegate: TextInput {
            anchors.left: parent.left
            anchors.right: parent.right
            color: "green"
            text: display
            font.pointSize: 11
            //selectByMouse: true
            readOnly: true
        }

        ScrollBar.vertical: ScrollBar { id: scroolBar}

        MouseArea {
            anchors.fill: parent
            enabled: listView.followNewLines
            onPositionChanged: listView.followNewLines = false
            onWheel: listView.followNewLines = false
        }

        Image {
            id: connectButton
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.right: scroolBar.left
            anchors.rightMargin: 5
            height: 20
            source: listView.followNewLines ? "log_lock_on.svg" : "log_lock_off.svg"
            sourceSize.width: width
            sourceSize.height: height
            MouseArea {
                anchors.fill: parent
                onClicked: listView.followNewLines = !listView.followNewLines
            }
        }
    }
}

