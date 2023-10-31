#ifndef INSTRUMENTCLUSTERQTCLASS_HPP
#define INSTRUMENTCLUSTERQTCLASS_HPP

#include <string>
#include <QObject>
#include <QString>

#include "InstrumentClusterSenderClass.hpp"

class InstrumentClusterQtClass : public QObject
{
    Q_OBJECT  // Macro that indicates this class uses Qt's object system.
    
    // Define properties that can be accessed from QML and signal changes.
    Q_PROPERTY(quint16 speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(quint16 rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(quint16 battery READ battery WRITE setBattery NOTIFY batteryChanged)
    Q_PROPERTY(quint16 gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(quint16 direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(QString light READ light WRITE setLight NOTIFY lightChanged)

private:
    InstrumentClusterSenderClass sender;  // Create an instance of InstrumentClusterSenderClass for communication

    quint16 Qspeed;      // Speed property.
    quint16 Qrpm;        // RPM (Revolutions Per Minute) property.
    quint16 Qbattery;    // Battery level property.
    quint16 Qgear;       // Gear mode property.
    quint16 Qdirection;  // Direction property.
    QString Qlight;      // Light color property.

public:
    explicit InstrumentClusterQtClass(QObject *parent = nullptr);
    
    // Getter methods for properties.
    quint16 speed() const;
    quint16 rpm() const;
    quint16 battery() const;
    quint16 gear() const;
    quint16 direction() const;
    QString light() const;

    // Setter methods for properties.
    void setSpeed(uint16_t _speed);
    void setRpm(uint16_t _rpm);
    void setBattery(uint16_t _battery);
    void setGear(uint16_t _gear);
    void setDirection(uint16_t _direction);
    void setLight(QString _light);
    
public Q_SLOTS:
    Q_INVOKABLE void getIPCManagerDirection();  // QML-invokable method to get direction

signals:
    // Signals to notify property changes.
    void speedChanged();
    void rpmChanged();
    void batteryChanged();
    void gearChanged();
    void directionChanged();
    void lightChanged();
};

// Declare an external instance of InstrumentClusterQtClass for access.
extern InstrumentClusterQtClass carinfo;

#endif

