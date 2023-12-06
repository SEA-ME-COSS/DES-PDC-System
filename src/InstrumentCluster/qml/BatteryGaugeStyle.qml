import QtQuick 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

BasicGaugeStyle {
    minimumValueAngle: -60
    maximumValueAngle: 60

    tickmarkStepSize: 25
    minorTickmarkCount: 4

    needleLength: 70
    needleBaseWidth: 5
    needleTipWidth: 1

    halfGauge: true

    property string icon: ""

    tickmark: Rectangle {
        implicitWidth: 2
        antialiasing: true
        implicitHeight: 10
        color: "black"
    }

    minorTickmark: Rectangle {
        implicitWidth: 1
        antialiasing: true
        implicitHeight: 5
        color: "black"
    }

    background: Item {
        Image {
            source: icon
            width: 70
            height: 70
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 13
        }
    }
}
