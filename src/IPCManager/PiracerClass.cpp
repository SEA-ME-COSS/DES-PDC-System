#include "PiracerClass.hpp"

PiracerClass::PiracerClass()
{
    Py_Initialize(); // Initialize the Python interpreter
    pModule = PyImport_ImportModule("piracer.vehicles"); // Import the Python module "piracer.vehicles"
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard"); // Get the Python class "PiRacerStandard" from the module
    pInstance = PyObject_CallObject(pClass, NULL); // Create an instance of the Python class

    sensorRpm = 0; // Initialize the sensor rpm to 0 (default)
    gearMode = 0; // Initialize the gear mode to 0 (default)
    direction = 0; // Initialize the direction to 0 (default)
    light = "#808080"; // Initialize the light to #808080 (default)
    freeDirection = false; // Initialize the direction-freeing condition to false (default)
}

PiracerClass::~PiracerClass()
{
    Py_DECREF(pInstance); // Release the Python instance
    Py_DECREF(pClass); // Release the Python class
    Py_DECREF(pModule); // Release the Python module
    Py_Finalize(); // Finalize the Python interpreter to clean up resources
}

void PiracerClass::setSensorRpm(uint16_t _sensorRpm)
{
    sensorRpm = _sensorRpm; // Update the sensor rpm

    return;
}

void PiracerClass::setGearMode(uint16_t _gearMode)
{
    gearMode = _gearMode; // Update the gear mode

    return;
}

void PiracerClass::setDirection(uint16_t _direction)
{
    direction = _direction; // Update the direction

    return;
}

void PiracerClass::setLight(std::string _light)
{
    light = _light; // Update the light

    return;
}

void PiracerClass::setFreeDirection(bool _freeDirection)
{
    freeDirection = _freeDirection;
    
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

void PiracerClass::applyThrottle(double throttle)
{
    switch (gearMode)
    {
        case 0: // P (Parking)
            PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0); // Call the Python method "set_throttle_percent" with the throttle value
	    break;
	    
        case 1: // R (Reverse)
	    if (throttle <= 0)
	    {
	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle * 0.3); // Call the Python method "set_throttle_percent" with the throttle value
	    }
	    else
	    {
	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0); // Call the Python method "set_throttle_percent" with the throttle value
	    }
	    break;
	    
        case 2: // N (Neutral)
            PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0); // Call the Python method "set_throttle_percent" with the throttle value
	    break;
	    
        case 3: // D (Drive)
	    if (throttle >= 0)
	    {
      	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle * 0.5); // Call the Python method "set_throttle_percent" with the throttle value
	    }
	    else
	    {
	        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", 0.0); // Call the Python method "set_throttle_percent" with the throttle value
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
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", 0.0); // Call the Python method "set_steering_percent" with the steering value
	    break;
	    
        case 1: // R (Reverse)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering * -1.0); // Call the Python method "set_steering_percent" with the steering value
	    break;
	    
        case 2: // N (Neutral)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering * -1.0); // Call the Python method "set_steering_percent" with the steering value
	    break;
	    
        case 3: // D (Drive)
            PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering * -1.0); // Call the Python method "set_steering_percent" with the steering value
	    break;
    }

    return;
}

