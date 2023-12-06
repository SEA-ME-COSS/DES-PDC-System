#ifndef PDCUNITQTCLASS_HPP
#define PDCUNITQTCLASS_HPP

#include <QObject>

#include "PDCUnitSenderClass.hpp"

class PDCUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 distance READ distance WRITE setDistance NOTIFY distanceChanged)
    Q_PROPERTY(qreal steering READ steering WRITE setSteering NOTIFY steeringChanged)

private:
    PDCUnitSenderClass sender;

    quint16 Qdistance;
    qreal Qsteering;

public:
    explicit PDCUnitQtClass(QObject *parent = nullptr);

    quint16 distance() const;
    qreal steering() const;

    void setDistance(uint16_t _distance);
    void setSteering(double _steering);
    
public Q_SLOTS:
    Q_INVOKABLE void getIPCManagerSteering();
    
signals:
    void distanceChanged();
    void steeringChanged();
};

extern PDCUnitQtClass carinfo;

#endif

