#ifndef HEADUNITQTCLASS_HPP
#define HEADUNITQTCLASS_HPP

#include <string>
#include <QObject>
#include <QString>
#include <cstdlib>

#include "HeadUnitSenderClass.hpp"

class HeadUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 sensorRpm READ sensorRpm WRITE setSensorRpm NOTIFY sensorRpmChanged)
    Q_PROPERTY(quint16 gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(quint16 direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(QString light READ light WRITE setLight NOTIFY lightChanged)

private:
    HeadUnitSenderClass sender;  // Create an instance of HeadUnitSenderClass for communication

    quint16 QsensorRpm;  // Store sensor RPM data
    quint16 Qgear;       // Gear mode property.
    quint16 Qdirection;  // Direction property.
    QString Qlight;      // Light color property.

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);

    quint16 sensorRpm() const;  // Getter for sensor RPM
    quint16 gear() const;
    quint16 direction() const;
    QString light() const;

    void setSensorRpm(uint16_t _sensorRpm);  // Setter for sensor RPM
    void setGear(uint16_t _gear);
    void setDirection(uint16_t _direction);
    void setLight(QString _light);

public Q_SLOTS:
    Q_INVOKABLE void setIPCManagerGear(quint16 _gear);          // QML-invokable method to set gear
    Q_INVOKABLE void setIPCManagerDirection(quint16 _direction);  // QML-invokable method to set direction
    Q_INVOKABLE void setIPCManagerLight(QString _light);         // QML-invokable method to set light
    Q_INVOKABLE void poweroff();                       // QML-invokable method to power off the system

signals:
    void sensorRpmChanged();   // Signal for sensor RPM changes
    void gearChanged();
    void directionChanged();
    void lightChanged();
};

extern HeadUnitQtClass carinfo;  // Create a global instance of HeadUnitQtClass named 'carinfo'

#endif

