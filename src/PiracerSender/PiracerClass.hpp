#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

class PiracerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pVoltage;
    double voltageLevel;
    uint16_t batteryLevel;

public:
    PiracerClass();
    ~PiracerClass();

    uint16_t getBatteryLevel();
};

#endif

