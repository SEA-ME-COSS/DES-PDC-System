#ifndef IPCMANAGERSTUBIMPL_HPP
#define IPCMANAGERSTUBIMPL_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>    // Include the CommonAPI library.
#include <v1/commonapi/IPCManagerStubDefault.hpp>    // Include the IPCManagerStubDefault interface.
#include "IPCManagerSenderClass.hpp"    // Include the IPCManagerSenderClass, which provides communication with other services.
#include "PiracerClass.hpp"

// Define a class IPCManagerStubImpl that inherits from IPCManagerStubDefault.
class IPCManagerStubImpl : public v1_0::commonapi::IPCManagerStubDefault {
private:
    IPCManagerSenderClass sender;    // Create an instance of IPCManagerSenderClass for communication.
    PiracerClass piracer;    // Create an instance of PiracerClass for operation

public:
    // Constructor for IPCManagerStubImpl.
    IPCManagerStubImpl();

    // Destructor for IPCManagerStubImpl.
    virtual ~IPCManagerStubImpl();

    // Define a function to set sensor RPM and reply to the caller.
    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);

    // Define a function to set battery level and reply to the caller.
    virtual void setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _return);

    // Define a function to set gear mode and relay it to other services, then reply to the caller.
    virtual void setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _return);

    // Define a function to set direction and relay it to other services, then reply to the caller.
    virtual void setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _return);

    // Define a function to set light status and relay it to other services, then reply to the caller.
    virtual void setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _return);

    // Define a function to set throttle and relay it to other services, then reply to the caller.
    virtual void setThrottle(const std::shared_ptr<CommonAPI::ClientId> _client, double _throttle, setThrottleReply_t _return);

    // Define a function to set steering and relay it to other services, then reply to the caller.
    virtual void setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _return);
    
    // Define a function to set distance and relay it to other services, then reply to the caller.
    virtual void setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _return);
    
    // Define a function to get gear mode.
    virtual void getGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getGearModeReply_t _return);
    
    // Define a function to get direction.
    virtual void getDirection(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getDirectionReply_t _return);
    
    // Define a function to get light.
    virtual void getLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getLightReply_t _return);
    
    // Define a function to get steering.
    virtual void getSteering(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getSteeringReply_t _return);
};

#endif

