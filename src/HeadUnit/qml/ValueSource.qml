import QtQuick 2.2
import DataModule 1.0

Item {
    id: valueSource

    HeadUnitQtClass {
        id: manager
    }

    // Properties to manage gear and direction
    property int gear: carinfo.gear
    property int direction: carinfo.direction

    // Properties for controlling blinking and direction indicators
    property bool blink: !(valueSource.direction === 0)
    property bool left_direction: (valueSource.direction === 1 || valueSource.direction === 3)
    property bool right_direction: (valueSource.direction === 2 || valueSource.direction === 3)
    property bool left_on_off: false
    property bool right_on_off: false
    property bool initial_delay: !(valueSource.direction === 0)

    // Handler for direction changes
    onDirectionChanged: {
        valueSource.blink = !(valueSource.direction === 0);
        valueSource.left_direction = (valueSource.direction === 1 || valueSource.direction === 3);
        valueSource.right_direction = (valueSource.direction === 2 || valueSource.direction === 3);
        valueSource.left_on_off = false;
        valueSource.right_on_off = false;
        valueSource.initial_delay = !(valueSource.direction === 0)
    }

    // Function to control the blinking behavior
    function blinking() {
        if (valueSource.left_direction) {
            valueSource.left_on_off = !valueSource.left_on_off
        }
        if (valueSource.right_direction) {
            valueSource.right_on_off = !valueSource.right_on_off
        }
    }

    // Timer to trigger the blinking function
    Timer {
        interval: 500; running: valueSource.blink; repeat: true
        onTriggered: {
            if (valueSource.initial_delay) {
                valueSource.initial_delay = false
            } else {
                valueSource.blinking()
            }
        }
    }

    // RGB color properties to manage the instrument cluster's light
    property string light: carinfo.light
    property int red: 0
    property int green: 0
    property int blue: 0
    property bool first_update: false

    onLightChanged: {
        valueSource.red = parseInt(valueSource.light.substring(1, 3), 16)
        valueSource.green = parseInt(valueSource.light.substring(3, 5), 16)
        valueSource.blue = parseInt(valueSource.light.substring(5, 7), 16)

        if (!valueSource.first_update) {
            valueSource.first_update = true
        }
    }

    property string red_string: ""
    property string green_string: ""
    property string blue_string: ""

    // Property to manage the clock display
    property int mode: 0
    property var currentTime: 0
    property int hours: 0
    property int minutes: 0
    property string formattedHours: ""
    property string formattedMinutes: ""
    property string clock: "00:00"

    // Timer to update the clock every second
    Timer {
        interval: 1000; running: true; repeat: true
        onTriggered: {
            valueSource.currentTime = new Date();
            valueSource.hours = (valueSource.currentTime.getHours() + 2) % 24;
            valueSource.minutes = valueSource.currentTime.getMinutes();
            valueSource.formattedHours = (valueSource.hours < 10 ? "0" : "") + valueSource.hours;
            valueSource.formattedMinutes = (valueSource.minutes < 10 ? "0" : "") + valueSource.minutes;
            valueSource.clock = valueSource.formattedHours + ":" + valueSource.formattedMinutes;
        }
    }
}
