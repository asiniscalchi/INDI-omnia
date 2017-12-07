import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 600

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Item {
            ConnectionBar {
                id: connectionBar
                height: 60
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right:parent.right
            }

            LogBox {
                id: logBox
                anchors.top: connectionBar.bottom
                anchors.topMargin: 20
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
            }
        }

        Item {
            DeviceList {
                anchors.fill: parent
            }
        }
    }

    PageIndicator {
        x: 303
        y: 580
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        currentIndex: swipeView.currentIndex
        count: swipeView.count
    }
}
