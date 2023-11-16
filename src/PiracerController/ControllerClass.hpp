#ifndef CONTROLLERCLASS_HPP
#define CONTROLLERCLASS_HPP

#include <Python.h>

class ControllerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pInput, *pThrottle, *pSteering;
    
    double throttle;  // Stores the throttle value
    double steering;  // Stores the steering value
    
    double pre_throttle;  // Stores the previous throttle value
    double pre_steering;  // Stores the previous steering value
    
    bool button_p;
    bool button_r;
    bool button_n;
    bool button_d;
    
    bool pre_button_p;
    bool pre_button_r;
    bool pre_button_n;
    bool pre_button_d;
    
    bool button_left_turn;
    bool button_right_turn;
    
    bool pre_button_left_turn;
    bool pre_button_right_turn;
    
public:
    // Constructor for the ControllerClass
    ControllerClass();

    // Destructor for the ControllerClass
    ~ControllerClass();

    // Read control input from the gamepad
    void readControl();

    // Get the current throttle value
    double getThrottle();

    // Get the current steering value
    double getSteering();
    
    // Get the previous throttle value
    double getPreThrottle();

    // Get the previous steering value
    double getPreSteering();
    
    bool getButtonP();
    bool getButtonR();
    bool getButtonN();
    bool getButtonD();
    
    bool getPreButtonP();
    bool getPreButtonR();
    bool getPreButtonN();
    bool getPreButtonD();
    
    bool getButtonLeftTurn();
    bool getButtonRightTurn();
    
    bool getPreButtonLeftTurn();
    bool getPreButtonRightTurn();
};

#endif

