#include "PiracerClass.hpp"

PiracerClass::PiracerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

PiracerClass::~PiracerClass()
{
    Py_DECREF(pVoltage);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

uint16_t PiracerClass::getBatteryLevel()
{
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltageLevel = PyFloat_AsDouble(pVoltage);
    batteryLevel = (uint16_t) ((voltageLevel - 2.8 * 3.0) / (12.3 - 2.8 * 3.0) * 100.0);
    
    return batteryLevel;
}

