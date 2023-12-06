import QtQuick 2.2

Item {
    id: valueSource

    property int speed: carinfo.speed
    property int rpm: carinfo.rpm
    property int battery: carinfo.battery
    property int gear: carinfo.gear
    property int direction: carinfo.direction
    property string light: (carinfo.light[0] === '#' ? carinfo.light : "#808080")

    property bool blink: !(valueSource.direction === 0)
    property bool left_direction: (valueSource.direction === 1 || valueSource.direction === 3)
    property bool right_direction: (valueSource.direction === 2 || valueSource.direction === 3)
    property bool left_on_off: false
    property bool right_on_off: false

    onDirectionChanged: {
        valueSource.blink = !(valueSource.direction === 0);
        valueSource.left_direction = (valueSource.direction === 1 || valueSource.direction === 3);
        valueSource.right_direction = (valueSource.direction === 2 || valueSource.direction === 3);
        valueSource.left_on_off = false;
        valueSource.right_on_off = false;
    }

    Behavior on speed {
        NumberAnimation {
            target: valueSource
            property: "speed"
            easing.type: Easing.InOutSine
            duration: 500
        }
    }
    Behavior on rpm {
        NumberAnimation {
            target: valueSource
            property: "rpm"
            easing.type: Easing.InOutSine
            duration: 500
        }
    }
    Behavior on battery {
        NumberAnimation {
            target: valueSource
            property: "battery"
            easing.type: Easing.InOutSine
            duration: 500
        }
    }

    function blinking() {
        if (valueSource.left_direction) {
            valueSource.left_on_off = !valueSource.left_on_off;
        }
        if (valueSource.right_direction) {
            valueSource.right_on_off = !valueSource.right_on_off;
        }
    }

    Timer {
        interval: 500; running: valueSource.blink; repeat: true
        onTriggered: valueSource.blinking()
    }
}
