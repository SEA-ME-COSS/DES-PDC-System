#include "IVICompositorQtClass.hpp"

// Constructor for IVICompositorQtClass
IVICompositorQtClass::IVICompositorQtClass(QObject *parent) : QObject(parent)
{
    Qgear = 0;
}

// Getter for gear
quint16 IVICompositorQtClass::gear() const
{
    return Qgear;
}

// Setter for gear
void IVICompositorQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    // Emit the signal to notify changes to QML
    emit gearChanged();
}

// Create an instance of IVICompositorQtClass named carinfo
IVICompositorQtClass carinfo;

