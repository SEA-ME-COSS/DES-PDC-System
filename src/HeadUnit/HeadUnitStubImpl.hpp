#ifndef HEADUNITSTUBIMPL_HPP
#define HEADUNITSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HeadUnitStubDefault.hpp>

#include "HeadUnitQtClass.hpp"

// Define the HeadUnitStubImpl class, which is derived from HeadUnitStubDefault
class HeadUnitStubImpl : public v1_0::commonapi::HeadUnitStubDefault
{
public:
    // Constructor for HeadUnitStubImpl
    HeadUnitStubImpl();

    // Destructor for HeadUnitStubImpl
    virtual ~HeadUnitStubImpl();

    // Override the setSensorRpm function to handle RPM value updates
    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);
    
    // Handle a request to update the gear mode of the Head Unit
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
    
    // Handle a request to update the direction indicator of the Head Unit
    virtual void setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _return);
    
    // Handle a request to update the light color of the Head Unit
    virtual void setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _return);
};

#endif

