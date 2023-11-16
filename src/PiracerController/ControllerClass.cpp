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
    
    button_left_turn = false;
    button_right_turn = false;
    
    pre_button_left_turn = false;
    pre_button_right_turn = false;
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
    
    pre_button_left_turn = button_left_turn;
    pre_button_right_turn = button_right_turn;

    // Call the "read_data" method on the gamepad instance
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    
    pThrottle = PyObject_GetAttrString(pInput, "analog_stick_right");
    pThrottle = PyObject_GetAttrString(pThrottle, "y");
    throttle = PyFloat_AsDouble(pThrottle);
    if ((-0.5 <= throttle) && (throttle < -0.4))
    {
        throttle = -0.5;
    }
    else if ((-0.4 <= throttle) && (throttle < -0.1))
    {
        throttle = -0.25;
    }
    else if ((-0.1 <= throttle) && (throttle <= 0.1))
    {
        throttle = 0.0;
    }
    else if ((0.1 < throttle) && (throttle <= 0.4))
    {
        throttle = 0.25;
    }
    else if ((0.4 < throttle) && (throttle <= 0.5))
    {
        throttle = 0.5;
    }
    
    pSteering = PyObject_GetAttrString(pInput, "analog_stick_left");
    pSteering = PyObject_GetAttrString(pSteering, "x");
    steering = PyFloat_AsDouble(pSteering);
    if ((-1.0 <= steering) && (steering < -0.8))
    {
        steering = -1.0;
    }
    else if ((-0.8 <= steering) && (steering < -0.2))
    {
        steering = -0.5;
    }
    else if ((-0.2 <= steering) && (steering <= 0.2))
    {
        steering = 0.0;
    }
    else if ((0.2 < steering) && (steering <= 0.8))
    {
        steering = 0.5;
    }
    else if ((0.8 < steering) && (steering <= 1.0))
    {
        steering = 1.0;
    }
    
    button_p = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_x"));
    button_r = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_y"));
    button_n = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_b"));
    button_d = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_l1"));
    
    button_left_turn = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_l2"));
    button_right_turn = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_r2"));
    
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

bool ControllerClass::getButtonLeftTurn()
{
    return button_left_turn;
}

bool ControllerClass::getButtonRightTurn()
{
    return button_right_turn;
}

bool ControllerClass::getPreButtonLeftTurn()
{
    return pre_button_left_turn;
}

bool ControllerClass::getPreButtonRightTurn()
{
    return pre_button_right_turn;
}

