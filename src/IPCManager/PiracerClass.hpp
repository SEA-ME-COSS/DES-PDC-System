#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>
#include <string>

// Define the PiracerClass class
class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance; // Private Python objects and gearMode variable

        uint16_t sensorRpm; // Private member variable to store sensor rpm
        uint16_t gearMode; // Private member variable to store gear mode
        uint16_t direction; // Private member variable to store direction
        std::string light; // Private member variable to store light
        bool freeDirection; // Private member variable to store direction-freeing condition
        
    public:
        PiracerClass(); // Constructor for PiracerClass
        ~PiracerClass(); // Destructor for PiracerClass
        
        // Method to set the sensor rpm
        void setSensorRpm(uint16_t _sensorRpm);

        // Method to set the gear mode
        void setGearMode(uint16_t _gearMode);
        
        // Method to set the direction
        void setDirection(uint16_t _direction);
        
        // Method to set the light
        void setLight(std::string _light);
        
        // Method to set the direction-freeing condition
        void setFreeDirection(bool _freeDirection);
        
        // Method to get the gear mode
        uint16_t getGearMode();
        
        // Method to get the direction
        uint16_t getDirection();
        
        // Method to get the light
        std::string getLight();
        
        // Method to get the direction-freeing condition
        bool getFreeDirection();
        
        // Method to get the sensor rpm
        uint16_t getSensorRpm();
        
        // Method to apply throttle to the PiRacer vehicle
        void applyThrottle(double throttle);
        
        // Method to apply steering to the PiRacer vehicle
        void applySteering(double steering);
};

#endif

