#include "InstrumentClusterQtClass.hpp"

InstrumentClusterQtClass::InstrumentClusterQtClass(QObject *parent) : QObject(parent)
{
    Qspeed = 0;
    Qrpm = 0;
    Qbattery = 0;
}

quint16 InstrumentClusterQtClass::speed() const
{
    return Qspeed;
}

quint16 InstrumentClusterQtClass::rpm() const
{
    return Qrpm;
}

quint16 InstrumentClusterQtClass::battery() const
{
    return Qbattery;
}

quint16 InstrumentClusterQtClass::gear() const
{
    return Qgear;
}

quint16 InstrumentClusterQtClass::direction() const
{
    return Qdirection;
}

QString InstrumentClusterQtClass::light() const
{
    return Qlight;
}

void InstrumentClusterQtClass::setSpeed(uint16_t _speed)
{
    Qspeed = _speed;
    emit speedChanged();
}

void InstrumentClusterQtClass::setRpm(uint16_t _rpm)
{
    Qrpm = _rpm;
    emit rpmChanged();
}

void InstrumentClusterQtClass::setBattery(uint16_t _battery)
{
    Qbattery = _battery;
    emit batteryChanged();
}

void InstrumentClusterQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    emit gearChanged();
}

void InstrumentClusterQtClass::setDirection(uint16_t _direction)
{
    Qdirection = _direction;
    emit directionChanged();
}

void InstrumentClusterQtClass::setLight(QString _light)
{
    Qlight = _light;
    emit lightChanged();
}

InstrumentClusterQtClass carinfo;
