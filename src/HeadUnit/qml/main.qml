import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.15
import QtMultimedia 5.15
import DataModule 1.0

Window {
    id: root
    title: "Head Unit"
    width: 1024
    height: 600
    visible: true

    FontLoader {
        id: font
        source: "../font/Nebula-Regular.otf"
    }

    ValueSource {
        id: valueSource
    }

    HeadUnitQtClass {
        id: manager
    }

    Item {
        id: container
        width: 1024
        height: 600
        anchors.centerIn: parent

        Rectangle {
            id: background
            width: 600
            height: 1024
            anchors.centerIn: parent
            rotation: 90
            gradient: Gradient {
                GradientStop { position: 0.0; color: valueSource.light }
                GradientStop { position: 0.4; color: "white" }
                GradientStop { position: 0.6; color: "white" }
                GradientStop { position: 1.0; color: valueSource.light }
            }
        }

        // Rectangle and functionality for the "P" gear
        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 - 210
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 0) ? ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "P"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 0) ? "white" : ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            // # Mouse area to handle clicks on "P" gear
            // # Uncomment the following code if you want to change the gear mode by touching the head unit display
            // MouseArea {
            //     anchors.fill: parent
            //     onClicked: {
            //         if (carinfo.sensorRpm === 0) {
            //             manager.setIPCManagerGear(0)
            //         }
            //     }
            // }
        }

        // Rectangle and functionality for the "R" gear
        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 - 70
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 1) ? ((carinfo.sensorRpm === 0) ? "#FF6868" : "#FFCECE") : "white"
                radius: 22

                Text {
                    text: "R"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 1) ? "white" : ((carinfo.sensorRpm === 0) ? "#FF6868" : "#FFCECE")
                    x: 13
                    y: -20
                }
            }

            // # Mouse area to handle clicks on "R" gear
            // # Uncomment the following code if you want to change the gear mode by touching the head unit display
            // MouseArea {
            //     anchors.fill: parent
            //     onClicked: {
            //         if (carinfo.sensorRpm === 0) {
            //             manager.setIPCManagerGear(1)
            //         }
            //     }
            // }
        }

        // Rectangle and functionality for the "N" gear
        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 + 70
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 2) ? ((carinfo.sensorRpm === 0) ? "#35CA3D" : "#AEFFAE") : "white"
                radius: 22

                Text {
                    text: "N"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 2) ? "white" : ((carinfo.sensorRpm === 0) ? "#35CA3D" : "#AEFFAE")
                    x: 13
                    y: -20
                }
            }

            // # Mouse area to handle clicks on "N" gear
            // # Uncomment the following code if you want to change the gear mode by touching the head unit display
            // MouseArea {
            //     anchors.fill: parent
            //     onClicked: {
            //         if (carinfo.sensorRpm === 0) {
            //             manager.setIPCManagerGear(2)
            //         }
            //     }
            // }
        }

        // Rectangle and functionality for the "D" gear
        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 + 210
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 3) ? ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "D"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 3) ? "white" : ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            // # Mouse area to handle clicks on "D" gear
            // # Uncomment the following code if you want to change the gear mode by touching the head unit display
            // MouseArea {
            //     anchors.fill: parent
            //     onClicked: {
            //         if (carinfo.sensorRpm === 0) {
            //             manager.setIPCManagerGear(3)
            //         }
            //     }
            // }
        }

        Rectangle {
            width: 5
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            x: parent.width / 2 - width / 2 - 340
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
        }

        Text {
            text: carinfo.sensorRpm
            font.family: font.name
            font.pixelSize: 70
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            x: 200
            y: 5
        }

        // Left turn indicator
        Image {
            source: "../image/turn-icon.png"
            width: 100
            height: 100
            rotation: -90
            fillMode: Image.PreserveAspectFit
            opacity: (valueSource.left_on_off) ? 0.2 : 1.0
            x: parent.width / 2 - width / 2 - 170
            y: 485

            Image {
                source: "../image/turn-icon.png"
                width: 80
                height: 80
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                y: 12
            }

            // Mouse area for handling left turn indicator interaction
            // # Uncomment the following code if you want to control turn indicator by touching the head unit display
            // MouseArea {
            //     anchors.fill: parent
            //     onClicked: {
            //         manager.setIPCManagerDirection(1)
            //     }
            // }
        }

        // Right turn indicator
        Image {
            source: "../image/turn-icon.png"
            width: 100
            height: 100
            rotation: 90
            fillMode: Image.PreserveAspectFit
            opacity: (valueSource.right_on_off) ? 0.2 : 1.0
            x: parent.width / 2 - width / 2 + 170
            y: 485

            Image {
                source: "../image/turn-icon.png"
                width: 80
                height: 80
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                y: 12
            }

            // Mouse area for handling right turn indicator interaction
            // # Uncomment the following code if you want to control turn indicator by touching the head unit display
            // MouseArea {
            //     anchors.fill: parent
            //     onClicked: {
            //         manager.setIPCManagerDirection(2)
            //     }
            // }
        }

        // Warning icon with multiple layers
        Image {
            source: "../image/warning-icon.png"
            opacity: (valueSource.direction === 3) ? 1.0 : 0.3
            width: 120
            height: 120
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 475

            Image {
                source: "../image/warning-icon.png"
                width: 90
                height: 90
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                y: 20

                Image {
                    source: "../image/warning-icon.png"
                    width: 65
                    height: 65
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 17
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    manager.setIPCManagerDirection(3)
                }
            }
        }

        Rectangle {
            width: 5
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            x: parent.width / 2 - width / 2 + 340
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
        }

        Image {
            source: "../image/logo.png"
            width: 320
            height: 320
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 80
        }

        Image {
            source: "../image/seame.png"
            width: 240
            height: 240
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 315
        }

        Image {
            source: "../image/wolfsberg.png"
            width: 220
            height: 220
            fillMode: Image.PreserveAspectFit
            x: 830
            y: -40
        }

        Item {
            width: 230
            height: 70
            x: 605
            y: 5

            Text {
                text: valueSource.clock
                font.family: font.name
                font.pixelSize: 70
                color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
                anchors.right: parent.right
                y: 0
            }
        }

        // Red color slider
        Slider {
            id: redSlider
            width: 140
            x: 870
            y: 130
            minimumValue: 0
            maximumValue: 128
            stepSize: 16
            value: valueSource.red

            style: SliderStyle {
                groove: Rectangle {
                    implicitWidth: 140
                    implicitHeight: 8
                    color: "#FFCECE"
                    radius: 30
                }

                handle: Rectangle {
                    implicitWidth: 23
                    implicitHeight: 23
                    color: "#FF6868"
                    radius: 30
                }
            }

            // Update red value and set light color
            onValueChanged: {
                if (valueSource.initial_update) {
                    valueSource.red_string = redSlider.value.toString(16)
                    if (valueSource.red_string.length === 1) {
                        valueSource.red_string = "0" + valueSource.red_string
                    }

                    valueSource.green_string = greenSlider.value.toString(16)
                    if (valueSource.green_string.length === 1) {
                        valueSource.green_string = "0" + valueSource.green_string
                    }

                    valueSource.blue_string = blueSlider.value.toString(16)
                    if (valueSource.blue_string.length === 1) {
                        valueSource.blue_string = "0" + valueSource.blue_string
                    }

                    manager.setIPCManagerLight("#" + valueSource.red_string + valueSource.green_string + valueSource.blue_string)
                }
            }
        }

        // Green color slider
        Slider {
            id: greenSlider
            width: 140
            x: 870
            y: 160
            minimumValue: 0
            maximumValue: 128
            stepSize: 16
            value: valueSource.green

            style: SliderStyle {
                groove: Rectangle {
                    implicitWidth: 140
                    implicitHeight: 8
                    color: "#AEFFAE"
                    radius: 30
                }

                handle: Rectangle {
                    implicitWidth: 23
                    implicitHeight: 23
                    color: "#35CA3D"
                    radius: 30
                }
            }

            // Update green value and set light color
            onValueChanged: {
                if (valueSource.initial_update) {
                    valueSource.red_string = redSlider.value.toString(16)
                    if (valueSource.red_string.length === 1) {
                        valueSource.red_string = "0" + valueSource.red_string
                    }

                    valueSource.green_string = greenSlider.value.toString(16)
                    if (valueSource.green_string.length === 1) {
                        valueSource.green_string = "0" + valueSource.green_string
                    }

                    valueSource.blue_string = blueSlider.value.toString(16)
                    if (valueSource.blue_string.length === 1) {
                        valueSource.blue_string = "0" + valueSource.blue_string
                    }

                    manager.setIPCManagerLight("#" + valueSource.red_string + valueSource.green_string + valueSource.blue_string)
                }
            }
        }

        // Blue color slider
        Slider {
            id: blueSlider
            width: 140
            x: 870
            y: 190
            minimumValue: 0
            maximumValue: 128
            stepSize: 16
            value: valueSource.blue

            style: SliderStyle {
                groove: Rectangle {
                    implicitWidth: 140
                    implicitHeight: 8
                    color: "#B1CAFF"
                    radius: 30
                }

                handle: Rectangle {
                    implicitWidth: 23
                    implicitHeight: 23
                    color: "#4D86FF"
                    radius: 30
                }
            }

            // Update blue value and set light color
            onValueChanged: {
                if (valueSource.initial_update) {
                    valueSource.red_string = redSlider.value.toString(16)
                    if (valueSource.red_string.length === 1) {
                        valueSource.red_string = "0" + valueSource.red_string
                    }

                    valueSource.green_string = greenSlider.value.toString(16)
                    if (valueSource.green_string.length === 1) {
                        valueSource.green_string = "0" + valueSource.green_string
                    }

                    valueSource.blue_string = blueSlider.value.toString(16)
                    if (valueSource.blue_string.length === 1) {
                        valueSource.blue_string = "0" + valueSource.blue_string
                    }

                    manager.setIPCManagerLight("#" + valueSource.red_string + valueSource.green_string + valueSource.blue_string)
                }
            }
        }

        // GPS mode button
        Rectangle {
            width: 140
            height: 60
            x: 870
            y: 240
            color: "black"
            radius: 20

            Rectangle {
                width: 130
                height: 50
                anchors.centerIn: parent
                color: (valueSource.mode === 1) ? "#555555" : "white"
                radius: 15

                Text {
                    text: "GPS"
                    font.family: font.name
                    font.pixelSize: 40
                    color: (valueSource.mode === 1) ? "white" : "555555"
                    x: 17
                    y: 1
                }
            }

            // Toggle GPS mode
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.mode === 1) {
                        valueSource.mode = 0
                    } else {
                        valueSource.mode = 1
                        mp4Player.pause()
                    }
                }
            }
        }

        // GPS content display (visible when in GPS mode)
        Rectangle {
            visible: (valueSource.mode === 1)
            width: 675
            height: 395
            color: "#555555"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 75

            Image {
                source: "../image/gps.png"
                width: 645
                height: 650
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent
            }
        }

        // MP3 mode button
        Rectangle {
            width: 140
            height: 60
            x: 870
            y: 310
            color: "black"
            radius: 20

            Rectangle {
                width: 130
                height: 50
                anchors.centerIn: parent
                color: (valueSource.mode === 2) ? "#555555" : "white"
                radius: 15

                Text {
                    text: "MP3"
                    font.family: font.name
                    font.pixelSize: 40
                    color: (valueSource.mode === 2) ? "white" : "555555"
                    x: 17
                    y: 1
                }
            }

            // Toggle MP3 mode
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.mode === 2) {
                        valueSource.mode = 0
                    } else {
                        valueSource.mode = 2
                        mp4Player.pause()
                    }
                }
            }
        }

        // MP3 content display (visible when in MP3 mode)
        Rectangle {
            visible: (valueSource.mode === 2)
            width: 675
            height: 395
            color: "#555555"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 75

            Image {
                source: "../image/album.jpg"
                width: 580
                height: 580
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent

                Text {
                    text: "Solo Cello Suite No.1"
                    font.pixelSize: 40
                    color: "white"
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 120
                }
            }

            MediaPlayer {
                id: mp3Player
            }

            Image {
                source: "../image/play.png"
                width: 60
                height: 50
                rotation: 90
                x: 360
                y: 305

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mp3Player.source = "../media/music.mp3"
                        mp3Player.play()
                    }
                }
            }

            Image {
                source: "../image/pause.png"
                width: 60
                height: 60
                fillMode: Image.PreserveAspectFit
                x: 440
                y: 300

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mp3Player.pause()
                    }
                }
            }

            Rectangle {
                width: 60
                height: 60
                color: "white"
                x: 530
                y: 300

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mp3Player.stop()
                    }
                }
            }
        }

        // MP4 mode button
        Rectangle {
            width: 140
            height: 60
            x: 870
            y: 380
            color: "black"
            radius: 20

            Rectangle {
                width: 130
                height: 50
                anchors.centerIn: parent
                color: (valueSource.mode === 3) ? "#555555" : "white"
                radius: 15

                Text {
                    text: "MP4"
                    font.family: font.name
                    font.pixelSize: 40
                    color: (valueSource.mode === 3) ? "white" : "555555"
                    x: 17
                    y: 1
                }
            }

            // Toggle MP4 mode
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.mode === 3) {
                        valueSource.mode = 0
                        mp4Player.pause()
                    } else {
                        valueSource.mode = 3
                    }
                }
            }
        }

        // MP4 content display (visible when in MP4 mode)
        Rectangle {
            visible: (valueSource.mode === 3)
            width: 675
            height: 395
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 75

            Video {
                id: mp4Player
                anchors.fill: parent
            }

            Image {
                source: "../image/play.png"
                width: 40
                height: 30
                rotation: 90
                x: parent.width / 2 - width / 2 - 80
                y: 350

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (carinfo.sensorRpm === 0) {
                            mp4Player.source = "../media/movie.mp4"
                            mp4Player.play()
                        }
                    }
                }
            }

            Image {
                source: "../image/pause.png"
                width: 40
                height: 40
                fillMode: Image.PreserveAspectFit
                x: parent.width / 2 - width / 2
                y: 345

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mp4Player.pause()
                    }
                }
            }

            Rectangle {
                width: 40
                height: 40
                color: "white"
                x: parent.width / 2 - width / 2 + 90
                y: 345

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mp4Player.stop()
                    }
                }
            }

            property int sensorRpm: carinfo.sensorRpm

            onSensorRpmChanged: {
                if ((valueSource.mode === 3) && (sensorRpm !== 0)) {
                    mp4Player.pause()
                }
            }

            property int gear: carinfo.gear

            onGearChanged: {
                if ((valueSource.mode === 3) && (gear === 1)) {
                    mp4Player.pause()
                }
            }
        }

        // Poweroff button
        Image {
            source: "../image/off.png"
            width: 100
            height: 100
            fillMode: Image.PreserveAspectFit
            opacity: ((carinfo.sensorRpm === 0) && (valueSource.gear === 0)) ? 1.0 : 0.5
            x: 888
            y: 470

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if ((carinfo.sensorRpm === 0) && (valueSource.gear === 0)) {
                        Qt.quit()
                        manager.poweroff()
                    }
                }
            }
        }
    }
}
