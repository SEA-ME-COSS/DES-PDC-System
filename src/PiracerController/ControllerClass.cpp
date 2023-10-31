#include "ControllerClass.hpp"
#include <iostream>

// Constructor for the ControllerClass
ControllerClass::ControllerClass()
{
    // Initialize the Python interpreter
    Py_Initialize();
    
    // Import the "piracer.gamepads" module
    pModule = PyImport_ImportModule("piracer.gamepads");

    // Get the "ShanWanGamepad" class from the module
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");

    // Create an instance of the "ShanWanGamepad" class
    pInstance = PyObject_CallObject(pClass, NULL);
    
    throttle = 0.0;
    steering = 0.0;
    
    pre_throttle = 0.0;
    pre_steering = 0.0;
    
    button_p = false;
    button_r = false;
    button_n = false;
    button_d = false;
    
    pre_button_p = false;
    pre_button_r = false;
    pre_button_n = false;
    pre_button_d = false;
}

// Destructor for the ControllerClass
ControllerClass::~ControllerClass()
{
    // Release Python objects to avoid memory leaks
    Py_DECREF(pThrottle);
    Py_DECREF(pSteering);
    Py_DECREF(pInput);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    
    // Finalize the Python interpreter
    Py_Finalize();
}

// Read control input from the gamepad
void ControllerClass::readControl()
{
    pre_throttle = throttle;
    pre_steering = steering;
    
    pre_button_p = button_p;
    pre_button_r = button_r;
    pre_button_n = button_n;
    pre_button_d = button_d;

    // Call the "read_data" method on the gamepad instance
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    
    pThrottle = PyObject_GetAttrString(pInput, "analog_stick_right");
    pThrottle = PyObject_GetAttrString(pThrottle, "y");
    throttle = PyFloat_AsDouble(pThrottle);
    
    pSteering = PyObject_GetAttrString(pInput, "analog_stick_left");
    pSteering = PyObject_GetAttrString(pSteering, "x");
    steering = PyFloat_AsDouble(pSteering);
    
    button_p = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_x"));
    button_r = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_y"));
    button_n = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_b"));
    button_d = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_l1"));
    
    return;
}

// Get the current throttle value
double ControllerClass::getThrottle()
{
    return throttle;
}

// Get the current steering value
double ControllerClass::getSteering()
{
    return steering;
}

// Get the previous throttle value
double ControllerClass::getPreThrottle()
{
    return pre_throttle;
}

// Get the previous steering value
double ControllerClass::getPreSteering()
{
    return pre_steering;
}

bool ControllerClass::getButtonP()
{
    return button_p;
}

bool ControllerClass::getButtonR()
{
    return button_r;
}

bool ControllerClass::getButtonN()
{
    return button_n;
}

bool ControllerClass::getButtonD()
{
    return button_d;
}

bool ControllerClass::getPreButtonP()
{
    return pre_button_p;
}

bool ControllerClass::getPreButtonR()
{
    return pre_button_r;
}

bool ControllerClass::getPreButtonN()
{
    return pre_button_n;
}

bool ControllerClass::getPreButtonD()
{
    return pre_button_d;
}

