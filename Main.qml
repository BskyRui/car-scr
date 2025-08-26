import QtQuick
import "./HMI"

Window {
    width: 1520
    height: 856
    visible: true
    title: qsTr("CAR")
    // page index
    property int pageIndex: ui.pageIndex
    property int previousPageIndex : ui.previousPageIndex

    Component.onCompleted: {
        pageIndex = 1
    }

    // page load
    Loader {
        id: pageLoader
        anchors.fill: parent
    }

    onPageIndexChanged: {
        switch (pageIndex) {
            case ui.PAGE_HOME: {
                pageLoader.source = "HMI/Home.qml"
                break
            }
            case ui.PAGE_AC: {
                pageLoader.source = "HMI/AC.qml"
                break
            }
            case ui.PAGE_APP: {
                pageLoader.source = "HMI/App.qml"
                break
            }
            case ui.PAGE.SETTINGS: {
                pageLoader.source = "HMI/Settings.qml"
                break
            }
            case ui.PAGE_HOME: {
                pageLoader.source = "HMI/Home.qml"
                break
            }
        }
    }
}
