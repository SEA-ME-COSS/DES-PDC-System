#include "PDCUnitQtClass.hpp"

// Constructor for PDCUnitQtClass
PDCUnitQtClass::PDCUnitQtClass(QObject *parent) : QObject(parent)
{
    // Initialize distance to 50
    Qdistance = 50;
    Qsteering = 0.0;
}

// Getter for distance
quint16 PDCUnitQtClass::distance() const
{
    return Qdistance;
}

qreal PDCUnitQtClass::steering() const
{
    return Qsteering;
}

// Setter for distance
void PDCUnitQtClass::setDistance(uint16_t _distance)
{
    Qdistance = _distance;
    // Emit the signal to notify changes to QML
    emit distanceChanged();
}

void PDCUnitQtClass::setSteering(double _steering)
{
    Qsteering = _steering;
    // Emit the signal to notify changes to QML
    emit steeringChanged();
}

Q_INVOKABLE void PDCUnitQtClass::getIPCManagerSteering()
{
    sender.IPCManagerTargetProxy->getSteering("PDCUnit", sender.callStatus, sender.returnMessage);
}

// Create an instance of PDCUnitQtClass named carinfo
PDCUnitQtClass carinfo;

