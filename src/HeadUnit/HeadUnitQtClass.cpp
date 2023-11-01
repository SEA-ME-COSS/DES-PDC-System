#include "HeadUnitQtClass.hpp"

// Constructor for HeadUnitQtClass
HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent)
{
    // Initialize sensorRpm and steering to 0
    QsensorRpm = 0;
    Qlight = QString::fromStdString("#808080")
}

// Getter for sensorRpm
quint16 HeadUnitQtClass::sensorRpm() const
{
    return QsensorRpm;
}

// Getter for gear
quint16 HeadUnitQtClass::gear() const
{
    return Qgear;
}

// Getter for direction
quint16 HeadUnitQtClass::direction() const
{
    return Qdirection;
}

// Getter for light
QString HeadUnitQtClass::light() const
{
    return Qlight;
}

// Setter for sensorRpm
void HeadUnitQtClass::setSensorRpm(uint16_t _sensorRpm)
{
    QsensorRpm = _sensorRpm;
    // Emit the signal to notify changes to QML
    emit sensorRpmChanged();
}

// Setter for gear
void HeadUnitQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    // Emit the signal to notify changes to QML
    emit gearChanged();
}

// Setter for direction
void HeadUnitQtClass::setDirection(uint16_t _direction)
{
    Qdirection = _direction;
    // Emit the signal to notify changes to QML
    emit directionChanged();
}

// Setter for light
void HeadUnitQtClass::setLight(QString _light)
{
    Qlight = _light;
    // Emit the signal to notify changes to QML
    emit lightChanged();
}

// QML-invokable method to set the gear using IPCManagerTargetProxy
Q_INVOKABLE void HeadUnitQtClass::setIPCManagerGear(quint16 _gear)
{
    sender.IPCManagerTargetProxy->setGearMode(_gear, sender.callStatus, sender.returnMessage);
}

// QML-invokable method to set the direction using IPCManagerTargetProxy
Q_INVOKABLE void HeadUnitQtClass::setIPCManagerDirection(quint16 _direction)
{
    sender.IPCManagerTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
}

// QML-invokable method to set the light using IPCManagerTargetProxy
Q_INVOKABLE void HeadUnitQtClass::setIPCManagerLight(QString _light)
{
    sender.IPCManagerTargetProxy->setLight(_light.toStdString(), sender.callStatus, sender.returnMessage);
}

// QML-invokable method to power off the system
Q_INVOKABLE void HeadUnitQtClass::poweroff()
{
    // Execute the system command to power off the system
    int exitCode = system("poweroff");
}

// Create an instance of HeadUnitQtClass named carinfo
HeadUnitQtClass carinfo;

