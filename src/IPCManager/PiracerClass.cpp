#include "PiracerClass.hpp"

PiracerClass::PiracerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);

    sensorRpm = 0;
    gearMode = 0;
    direction = 0;
    light = "#808080";
    freeDirection = false;
    steering = 0.0;
}

PiracerClass::~PiracerClass()
{
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

void PiracerClass::setSensorRpm(uint16_t _sensorRpm)
{
    sensorRpm = _sensorRpm;

    return;
}

void PiracerClass::setGearMode(uint16_t _gearMode)
{
    gearMode = _gearMode;

    return;
}

void PiracerClass::setDirection(uint16_t _direction)
{
    direction = _direction;

    return;
}

void PiracerClass::setLight(std::string _light)
{
    light = _light;

    return;
}

void PiracerClass::setFreeDirection(bool _freeDirection)
{
    freeDirection = _freeDirection;
    
    return;
}

void PiracerClass::setSteering(double _steering)
{
    steering = _steering;
    
    return;
}

uint16_t PiracerClass::getGearMode()
{
    return gearMode;
}

uint16_t PiracerClass::getDirection()
{
    return direction;
}

std::string PiracerClass::getLight()
{
    return light;
}

bool PiracerClass::getFreeDirection()
{
    return freeDirection;
}

uint16_t PiracerClass::getSensorRpm()
{
    return sensorRpm;
}

double PiracerClass::getSteering()
{
    return steering;
}

void PiracerClass::applyThrottle(double throttle)
{
    switch (gearMode)
    {
        case 0: // P (Parking)
            PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0);
	    break;
	    
        case 1: // R (Reverse)
	    if (throttle <= 0)
	    {
	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle * 0.3);
	    }
	    else
	    {
	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0);
	    }
	    break;
	    
        case 2: // N (Neutral)
            PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0);
	    break;
	    
        case 3: // D (Drive)
	    if (throttle >= 0)
	    {
      	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle * 0.5);
	    }
	    else
	    {
	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0);
	    }
	    break;
    }

    return;
}

void PiracerClass::applySteering(double steering)
{
    switch (gearMode)
    {
        case 0: // P (Parking)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", 0.0);
	    break;
	    
        case 1: // R (Reverse)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering * -1.0);
	    break;
	    
        case 2: // N (Neutral)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering * -1.0);
	    break;
	    
        case 3: // D (Drive)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering * -1.0);
	    break;
    }

    return;
}

