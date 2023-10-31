#include "IPCManagerStubImpl.hpp"

// Constructor for IPCManagerStubImpl
IPCManagerStubImpl::IPCManagerStubImpl() { }

// Destructor for IPCManagerStubImpl
IPCManagerStubImpl::~IPCManagerStubImpl() { }

// Set sensor RPM and relay it to appropriate services
void IPCManagerStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    // Set sensor rpm to piracer
    piracer.setSensorRpm(_sensorRpm);
    
    // Relay sensor RPM to InstrumentCluster and HeadUnit services
    sender.InstrumentClusterTargetProxy->setSpeedRpm(_sensorRpm, sender.callStatus, sender.returnMessage);
    sender.HeadUnitTargetProxy->setSensorRpm(_sensorRpm, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

// Set battery level and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _reply)
{
    // Relay battery level to the InstrumentCluster service
    sender.InstrumentClusterTargetProxy->setBattery(_batteryLevel, sender.callStatus, sender.returnMessage);
    
    // Reply to the caller
    _reply("");

    return;
}

// Set gear mode and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply)
{
    if (piracer.getSensorRpm() == 0)
    {
        // Set gear mode to piracer
        piracer.setGearMode(_gearMode);
        
        // Relay gear mode to the InstrumentCluster service
        sender.InstrumentClusterTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);
    }

    // Reply to the caller
    _reply("");

    return;
}

// Set direction and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    if (piracer.getDirection() == _direction)
    {
        // Set direction to piracer
        piracer.setDirection(0);
        piracer.setFreeDirection(false);
        
        // Relay direction to the InstrumentCluster and HeadUnit services
        sender.InstrumentClusterTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
    }
    else
    {
        // Set direction to piracer
        piracer.setDirection(_direction);
        piracer.setFreeDirection(false);
        
        // Relay direction to the InstrumentCluster and HeadUnit services
        sender.InstrumentClusterTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
    }

    // Reply to the caller
    _reply("");

    return;
}

// Set light status and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    // Set light to piracer
    piracer.setLight(_light);

    // Relay light status to the InstrumentCluster service
    sender.InstrumentClusterTargetProxy->setLight(_light, sender.callStatus, sender.returnMessage);
    sender.HeadUnitTargetProxy->setLight(_light, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

// Set throttle
void IPCManagerStubImpl::setThrottle(const std::shared_ptr<CommonAPI::ClientId> _client, double _throttle, setThrottleReply_t _reply)
{
    // Apply throttle to piracer
    piracer.applyThrottle(_throttle);
    
    // Reply to the caller
    _reply("");

    return;
}

// Set steering
void IPCManagerStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _reply)
{
    // Apply steering to piracer
    piracer.applySteering(_steering);
    
    if ((piracer.getDirection() == 1) && (piracer.getFreeDirection() == false) && (_steering == -1.0))
    {
        piracer.setFreeDirection(true);
    }
    else if ((piracer.getDirection() == 2) && (piracer.getFreeDirection() == false) && (_steering == 1.0))
    {
        piracer.setFreeDirection(true);
    }
    else if ((piracer.getDirection() == 1) && (piracer.getFreeDirection() == true) && (_steering >= 0.0))
    {
        piracer.setDirection(0);
        piracer.setFreeDirection(false);
        
        sender.InstrumentClusterTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
    }
    else if ((piracer.getDirection() == 2) && (piracer.getFreeDirection() == true) && (_steering <= 0.0))
    {
        piracer.setDirection(0);
        piracer.setFreeDirection(false);
        
        sender.InstrumentClusterTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
    }
    
    // Reply to the caller
    _reply("");

    return;
}

// Get gear mode
void IPCManagerStubImpl::getGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getGearModeReply_t _reply)
{   
    if (_input == "InstrumentCluster")
    {
        sender.InstrumentClusterTargetProxy->setGear(piracer.getGearMode(), sender.callStatus, sender.returnMessage);
    }
    else if (_input == "HeadUnit")
    {
        sender.HeadUnitTargetProxy->setGear(piracer.getGearMode(), sender.callStatus, sender.returnMessage);
    }

    // Reply to the caller
    _reply("");

    return;
}

// Get direction
void IPCManagerStubImpl::getDirection(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getDirectionReply_t _reply)
{    
    if (_input == "InstrumentCluster")
    {
        sender.InstrumentClusterTargetProxy->setDirection(piracer.getDirection(), sender.callStatus, sender.returnMessage);
    }
    else if (_input == "HeadUnit")
    {
        sender.HeadUnitTargetProxy->setDirection(piracer.getDirection(), sender.callStatus, sender.returnMessage);
    }

    // Reply to the caller
    _reply("");

    return;
}

// Get light
void IPCManagerStubImpl::getLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getLightReply_t _reply)
{    
    if (_input == "InstrumentCluster")
    {
        sender.InstrumentClusterTargetProxy->setLight(piracer.getLight(), sender.callStatus, sender.returnMessage);
    }
    else if (_input == "HeadUnit")
    {
        sender.HeadUnitTargetProxy->setLight(piracer.getLight(), sender.callStatus, sender.returnMessage);
    }

    // Reply to the caller
    _reply("");

    return;
}
