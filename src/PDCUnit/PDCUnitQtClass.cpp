#include "PDCUnitQtClass.hpp"

PDCUnitQtClass::PDCUnitQtClass(QObject *parent) : QObject(parent)
{
    Qdistance = 50;
    Qsteering = 0.0;
}

quint16 PDCUnitQtClass::distance() const
{
    return Qdistance;
}

qreal PDCUnitQtClass::steering() const
{
    return Qsteering;
}

void PDCUnitQtClass::setDistance(uint16_t _distance)
{
    Qdistance = _distance;
    emit distanceChanged();
}

void PDCUnitQtClass::setSteering(double _steering)
{
    Qsteering = _steering;
    emit steeringChanged();
}

Q_INVOKABLE void PDCUnitQtClass::getIPCManagerSteering()
{
    sender.IPCManagerTargetProxy->getSteering("PDCUnit", sender.callStatus, sender.returnMessage);
}

PDCUnitQtClass carinfo;

