import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtMultimedia 5.15
import DataModule 1.0

Window {
    id: root
    title: "PDC Unit"
    width: 1024
    height: 600
    visible: true

    FontLoader {
        id: font
        source: "../font/Nebula-Regular.otf"
    }

    PDCUnitQtClass {
        id: manager
    }

    Item {
        id: container
        width: 1024
        height: 600
        anchors.centerIn: parent

        Camera {
            id: camera
            objectName: "camera"
            captureMode: Camera.CaptureViewfinder
        }

        VideoOutput {
            id: viewfinder
            objectName: "viewfinder"
            source: camera
            anchors.fill: parent
        }

        Rectangle {
            color: "white"
            opacity: 0.5
            anchors.fill: parent
        }

        Text {
            text: "Parking Distance Control"
            font.family: font.name
            font.pixelSize: 40
            color: "white"
            x: parent.width / 2 + width / 2
            y: 30

            transform: Scale {
                xScale: -1
            }
        }

        Image {
            source: "../image/pdc_red_indicator.png"
            visible: (carinfo.distance < 20)
            width: 675
            height: 675
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent

            rotation: carinfo.steering * 30
        }

        Image {
            source: "../image/pdc_yellow_indicator.png"
            visible: (carinfo.distance < 40)
            width: 675
            height: 675
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            
            rotation: carinfo.steering * 30
        }

        Image {
            source: "../image/pdc_green_indicator.png"
            visible: (carinfo.distance < 60)
            width: 675
            height: 675
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            
            rotation: carinfo.steering * 30
        }
    }

    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: manager.getIPCManagerSteering()
    }
}
