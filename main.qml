import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 400
    title: qsTr("indi-omnia")

    Page1 {
        anchors.fill: parent
    }

//    SwipeView {
//        id: swipeView
//        anchors.fill: parent
//        //currentIndex: tabBar.currentIndex


//    }

////    footer: TabBar {
////        id: tabBar
////        currentIndex: swipeView.currentIndex
////        TabButton {
//            text: qsTr("First")
//        }
//        TabButton {
//            text: qsTr("Second")
//        }
//    }
}
