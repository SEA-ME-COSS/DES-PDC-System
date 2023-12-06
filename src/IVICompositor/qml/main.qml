import QtQuick 2.2
import QtQuick.Window 2.1
import QtWayland.Compositor 1.0

WaylandCompositor {
    WaylandOutput {
        sizeFollowsWindow: true
        window: Window {
            width: 1024
            height: 600
            visible: true

            Item {
                id: container
                width: 1024
                height: 600
                anchors.centerIn: parent
                scale: 0.5

                Rectangle {
                    id: headUnitArea
                    width: 1024
                    height: 600
                    anchors.centerIn: parent
                    z: !(carinfo.gear === 1)
                }

                Rectangle {
                    id: pdcUnitArea
                    width: 850
                    height: 600
                    x: 1024
                    anchors.verticalCenter: parent.verticalCenter
                    opacity: container.pdcOpacity
                    z: (carinfo.gear === 1)

                    transform: Scale {
                        xScale: -1
                    }
                }

                property real pdcOpacity: (carinfo.gear === 1 ? 1.0 : 0.0)

                Behavior on pdcOpacity {
                    NumberAnimation {
                        target: container
                        property: "pdcOpacity"
                        easing.type: Easing.InOutSine
                        duration: 1000
                    }
                }
            }
        }
    }

    Component {
        id: chromeComponent
        ShellSurfaceItem {
            anchors.fill: parent
            onSurfaceDestroyed: destroy()
            onWidthChanged: handleResized()
            onHeightChanged: handleResized()
            function handleResized() {
                shellSurface.sendConfigure(Qt.size(width, height));
            }
        }
    }

    IviApplication {
        onIviSurfaceCreated: {
            var surfaceArea = iviSurface.iviId === 1111 ? pdcUnitArea : headUnitArea;
            var item = chromeComponent.createObject(surfaceArea, { "shellSurface": iviSurface } );
            item.handleResized();
        }
    }
}
