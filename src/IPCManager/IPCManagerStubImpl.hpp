#ifndef IPCMANAGERSTUBIMPL_HPP
#define IPCMANAGERSTUBIMPL_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerStubDefault.hpp>

#include "IPCManagerSenderClass.hpp"
#include "PiracerClass.hpp"

class IPCManagerStubImpl : public v1_0::commonapi::IPCManagerStubDefault {
private:
    IPCManagerSenderClass sender;
    PiracerClass piracer;

public:
    IPCManagerStubImpl();
    virtual ~IPCManagerStubImpl();

    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);
    virtual void setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _return);
    virtual void setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _return);
    virtual void setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _return);
    virtual void setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _return);
    virtual void setThrottle(const std::shared_ptr<CommonAPI::ClientId> _client, double _throttle, setThrottleReply_t _return);
    virtual void setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _return);
    virtual void setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _return);
    
    virtual void getGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getGearModeReply_t _return);
    virtual void getDirection(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getDirectionReply_t _return);
    virtual void getLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getLightReply_t _return);
    virtual void getSteering(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getSteeringReply_t _return);
};

#endif

