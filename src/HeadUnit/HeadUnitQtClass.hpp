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
    HeadUnitSenderClass sender;

    quint16 QsensorRpm;
    quint16 Qgear;
    quint16 Qdirection;
    QString Qlight;

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);

    quint16 sensorRpm() const;
    quint16 gear() const;
    quint16 direction() const;
    QString light() const;

    void setSensorRpm(uint16_t _sensorRpm);
    void setGear(uint16_t _gear);
    void setDirection(uint16_t _direction);
    void setLight(QString _light);

public Q_SLOTS:
    Q_INVOKABLE void setIPCManagerGear(quint16 _gear);
    Q_INVOKABLE void setIPCManagerDirection(quint16 _direction);
    Q_INVOKABLE void setIPCManagerLight(QString _light);
    Q_INVOKABLE void poweroff();

signals:
    void sensorRpmChanged();
    void gearChanged();
    void directionChanged();
    void lightChanged();
};

extern HeadUnitQtClass carinfo;

#endif

