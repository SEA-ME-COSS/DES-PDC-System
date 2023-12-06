#include "ControllerClass.hpp"

ControllerClass::ControllerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.gamepads");
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");
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

ControllerClass::~ControllerClass()
{
    Py_DECREF(pThrottle);
    Py_DECREF(pSteering);
    Py_DECREF(pInput);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

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

    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    
    pThrottle = PyObject_GetAttrString(pInput, "analog_stick_right");
    pThrottle = PyObject_GetAttrString(pThrottle, "y");
    throttle = PyFloat_AsDouble(pThrottle) * -1.0;
    if ((-1.0 <= throttle) && (throttle < -0.8))
    {
        throttle = -1.0;
    }
    else if ((-0.8 <= throttle) && (throttle < -0.2))
    {
        throttle = -0.5;
    }
    else if ((-0.2 <= throttle) && (throttle <= 0.2))
    {
        throttle = 0.0;
    }
    else if ((0.2 < throttle) && (throttle <= 0.8))
    {
        throttle = 0.5;
    }
    else if ((0.8 < throttle) && (throttle <= 1.0))
    {
        throttle = 1.0;
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
    
    button_p = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_a"));
    button_r = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_y"));
    button_n = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_b"));
    button_d = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_x"));
    
    button_left_turn = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_l1"));
    button_right_turn = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_r1"));
    
    return;
}

double ControllerClass::getThrottle()
{
    return throttle;
}

double ControllerClass::getSteering()
{
    return steering;
}

double ControllerClass::getPreThrottle()
{
    return pre_throttle;
}

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

