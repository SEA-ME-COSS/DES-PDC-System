#ifndef CONTROLLERCLASS_HPP
#define CONTROLLERCLASS_HPP

#include <Python.h>

class ControllerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pInput, *pThrottle, *pSteering;
    
    double throttle;
    double steering;
    
    double pre_throttle;
    double pre_steering;
    
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
    ControllerClass();
    ~ControllerClass();

    void readControl();

    double getThrottle();
    double getSteering();
    double getPreThrottle();
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

