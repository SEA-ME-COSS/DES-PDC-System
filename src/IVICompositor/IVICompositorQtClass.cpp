#include "IVICompositorQtClass.hpp"

IVICompositorQtClass::IVICompositorQtClass(QObject *parent) : QObject(parent) { }

quint16 IVICompositorQtClass::gear() const
{
    return Qgear;
}

void IVICompositorQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    
    emit gearChanged();
}

IVICompositorQtClass carinfo;

