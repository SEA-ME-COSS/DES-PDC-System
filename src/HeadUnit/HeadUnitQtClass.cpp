#include "HeadUnitQtClass.hpp"

HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent)
{
    QsensorRpm = 0;
}

quint16 HeadUnitQtClass::sensorRpm() const
{
    return QsensorRpm;
}

quint16 HeadUnitQtClass::gear() const
{
    return Qgear;
}

quint16 HeadUnitQtClass::direction() const
{
    return Qdirection;
}

QString HeadUnitQtClass::light() const
{
    return Qlight;
}

void HeadUnitQtClass::setSensorRpm(uint16_t _sensorRpm)
{
    QsensorRpm = _sensorRpm;
    emit sensorRpmChanged();
}

void HeadUnitQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    emit gearChanged();
}

void HeadUnitQtClass::setDirection(uint16_t _direction)
{
    Qdirection = _direction;
    emit directionChanged();
}

void HeadUnitQtClass::setLight(QString _light)
{
    Qlight = _light;
    emit lightChanged();
}

Q_INVOKABLE void HeadUnitQtClass::setIPCManagerGear(quint16 _gear)
{
    sender.IPCManagerTargetProxy->setGearMode(_gear, sender.callStatus, sender.returnMessage);
}

Q_INVOKABLE void HeadUnitQtClass::setIPCManagerDirection(quint16 _direction)
{
    sender.IPCManagerTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
}

Q_INVOKABLE void HeadUnitQtClass::setIPCManagerLight(QString _light)
{
    sender.IPCManagerTargetProxy->setLight(_light.toStdString(), sender.callStatus, sender.returnMessage);
}

Q_INVOKABLE void HeadUnitQtClass::poweroff()
{
    int exitCode = system("sudo poweroff");
}

HeadUnitQtClass carinfo;

