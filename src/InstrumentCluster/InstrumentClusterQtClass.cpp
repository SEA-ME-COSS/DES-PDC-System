#include "InstrumentClusterQtClass.hpp"

// Constructor for InstrumentClusterQtClass
InstrumentClusterQtClass::InstrumentClusterQtClass(QObject *parent) : QObject(parent)
{
    Qspeed = 0;                  // Initialize speed to 0.
    Qrpm = 0;                    // Initialize RPM to 0.
    Qbattery = 0;                // Initialize battery level to 0.
}

// Getter for speed
quint16 InstrumentClusterQtClass::speed() const
{
    return Qspeed;
}

// Getter for RPM
quint16 InstrumentClusterQtClass::rpm() const
{
    return Qrpm;
}

// Getter for battery level
quint16 InstrumentClusterQtClass::battery() const
{
    return Qbattery;
}

// Getter for gear mode
quint16 InstrumentClusterQtClass::gear() const
{
    return Qgear;
}

// Getter for direction
quint16 InstrumentClusterQtClass::direction() const
{
    return Qdirection;
}

// Getter for light color
QString InstrumentClusterQtClass::light() const
{
    return Qlight;
}

// Setter for speed
void InstrumentClusterQtClass::setSpeed(uint16_t _speed)
{
    Qspeed = _speed;
    emit speedChanged(); // Emit a signal to notify that the speed has changed.
}

// Setter for RPM
void InstrumentClusterQtClass::setRpm(uint16_t _rpm)
{
    Qrpm = _rpm;
    emit rpmChanged(); // Emit a signal to notify that the RPM has changed.
}

// Setter for battery level
void InstrumentClusterQtClass::setBattery(uint16_t _battery)
{
    Qbattery = _battery;
    emit batteryChanged(); // Emit a signal to notify that the battery level has changed.
}

// Setter for gear mode
void InstrumentClusterQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    emit gearChanged(); // Emit a signal to notify that the gear mode has changed.
}

// Setter for direction
void InstrumentClusterQtClass::setDirection(uint16_t _direction)
{
    Qdirection = _direction;
    emit directionChanged(); // Emit a signal to notify that the direction has changed.
}

// Setter for light color
void InstrumentClusterQtClass::setLight(QString _light)
{
    Qlight = _light;
    emit lightChanged(); // Emit a signal to notify that the light color has changed.
}

Q_INVOKABLE void InstrumentClusterQtClass::getIPCManagerDirection()
{
    sender.IPCManagerTargetProxy->getDirection("InstrumentCluster", sender.callStatus, sender.returnMessage);
}

InstrumentClusterQtClass carinfo; // Create an instance of the InstrumentClusterQtClass.

