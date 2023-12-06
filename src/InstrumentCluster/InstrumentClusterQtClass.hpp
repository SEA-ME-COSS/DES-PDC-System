#ifndef INSTRUMENTCLUSTERQTCLASS_HPP
#define INSTRUMENTCLUSTERQTCLASS_HPP

#include <string>
#include <QObject>
#include <QString>

#include "InstrumentClusterSenderClass.hpp"

class InstrumentClusterQtClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint16 speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(quint16 rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(quint16 battery READ battery WRITE setBattery NOTIFY batteryChanged)
    Q_PROPERTY(quint16 gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(quint16 direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(QString light READ light WRITE setLight NOTIFY lightChanged)

private:
    InstrumentClusterSenderClass sender;

    quint16 Qspeed;
    quint16 Qrpm;
    quint16 Qbattery;
    quint16 Qgear;
    quint16 Qdirection;
    QString Qlight;

public:
    explicit InstrumentClusterQtClass(QObject *parent = nullptr);
    
    quint16 speed() const;
    quint16 rpm() const;
    quint16 battery() const;
    quint16 gear() const;
    quint16 direction() const;
    QString light() const;

    void setSpeed(uint16_t _speed);
    void setRpm(uint16_t _rpm);
    void setBattery(uint16_t _battery);
    void setGear(uint16_t _gear);
    void setDirection(uint16_t _direction);
    void setLight(QString _light);

signals:
    void speedChanged();
    void rpmChanged();
    void batteryChanged();
    void gearChanged();
    void directionChanged();
    void lightChanged();
};

extern InstrumentClusterQtClass carinfo;

#endif

