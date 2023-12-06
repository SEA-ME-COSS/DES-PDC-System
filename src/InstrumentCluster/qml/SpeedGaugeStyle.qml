import QtQuick 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

BasicGaugeStyle {
    minimumValueAngle: -135
    maximumValueAngle: 135

    tickmarkStepSize: 25
    minorTickmarkCount: 4

    labelStepSize: 50
    labelInset: 45

    needleLength: 165
    needleBaseWidth: 10
    needleTipWidth: 1

    tickmark: Rectangle {
        implicitWidth: 3
        antialiasing: true
        implicitHeight: 15
        color: "black"
    }

    minorTickmark: Rectangle {
        implicitWidth: 2
        antialiasing: true
        implicitHeight: 7
        color: "black"
    }

    background: Canvas {
        FontLoader {
            id: font
            source: "../font/Nebula-Regular.otf"
        }

        Text {
            text: valueSource.speed
            color: "black"
            font.family: font.name
            font.pixelSize: 80
            anchors.horizontalCenter: parent.horizontalCenter
            y: 170
        }

        Text {
            text: "mm/s"
            color: "black"
            font.family: font.name
            font.pixelSize: 30
            anchors.horizontalCenter: parent.horizontalCenter
            y: 240
        }
    }
}
