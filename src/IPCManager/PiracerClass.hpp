#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>
#include <string>

class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance;

        uint16_t sensorRpm;
        uint16_t gearMode;
        uint16_t direction;
        std::string light;
        bool freeDirection;
        double steering;
        
    public:
        PiracerClass();
        ~PiracerClass();
        
        void setSensorRpm(uint16_t _sensorRpm);
        void setGearMode(uint16_t _gearMode);
        void setDirection(uint16_t _direction);
        void setLight(std::string _light);
        void setFreeDirection(bool _freeDirection);
        void setSteering(double _steering);
        
        uint16_t getGearMode();
        uint16_t getDirection();
        std::string getLight();
        bool getFreeDirection();
        uint16_t getSensorRpm();
        double getSteering();
        
        void applyThrottle(double throttle);
        void applySteering(double steering);
};

#endif

