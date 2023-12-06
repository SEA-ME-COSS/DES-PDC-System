#include "IPCManagerStubImpl.hpp"

IPCManagerStubImpl::IPCManagerStubImpl() { }
IPCManagerStubImpl::~IPCManagerStubImpl() { }

void IPCManagerStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    piracer.setSensorRpm(_sensorRpm);
    
    sender.InstrumentClusterTargetProxy->setSpeedRpm(_sensorRpm, sender.callStatus, sender.returnMessage);
    sender.HeadUnitTargetProxy->setSensorRpm(_sensorRpm, sender.callStatus, sender.returnMessage);

    _reply("");

    return;
}

void IPCManagerStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _reply)
{
    sender.InstrumentClusterTargetProxy->setBattery(_batteryLevel, sender.callStatus, sender.returnMessage);
    
    _reply("");

    return;
}

void IPCManagerStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply)
{
    if (piracer.getSensorRpm() == 0)
    {
        piracer.setGearMode(_gearMode);
        
        sender.InstrumentClusterTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);
        sender.IVICompositorTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);
        sender.RemoteSpeakerTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);
    }

    _reply("");

    return;
}

void IPCManagerStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    if (piracer.getDirection() == _direction)
    {
        piracer.setDirection(0);
        piracer.setFreeDirection(false);
        
        sender.InstrumentClusterTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setDirection(0, sender.callStatus, sender.returnMessage);
    }
    else if (piracer.getDirection() != 3)
    {
        piracer.setDirection(_direction);
        piracer.setFreeDirection(false);
        
        sender.InstrumentClusterTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
        sender.HeadUnitTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
    }

    _reply("");

    return;
}

void IPCManagerStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    piracer.setLight(_light);

    sender.InstrumentClusterTargetProxy->setLight(_light, sender.callStatus, sender.returnMessage);
    sender.HeadUnitTargetProxy->setLight(_light, sender.callStatus, sender.returnMessage);

    _reply("");

    return;
}

void IPCManagerStubImpl::setThrottle(const std::shared_ptr<CommonAPI::ClientId> _client, double _throttle, setThrottleReply_t _reply)
{
    piracer.applyThrottle(_throttle);
    
    _reply("");

    return;
}

void IPCManagerStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _reply)
{
    piracer.applySteering(_steering);
    piracer.setSteering(_steering);
    
    // ==================================================
    
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
    
    _reply("");

    return;
}

void IPCManagerStubImpl::setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _reply)
{
    sender.PDCUnitTargetProxy->setDistance(_distance, sender.callStatus, sender.returnMessage);
    sender.RemoteSpeakerTargetProxy->setDistance(_distance, sender.callStatus, sender.returnMessage);
    
    _reply("");

    return;
}

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
    else if (_input == "IVICompositor")
    {
        sender.IVICompositorTargetProxy->setGear(piracer.getGearMode(), sender.callStatus, sender.returnMessage);
    }
    else if (_input == "RemoteSpeaker")
    {
        sender.RemoteSpeakerTargetProxy->setGear(piracer.getGearMode(), sender.callStatus, sender.returnMessage);
    }

    _reply("");

    return;
}

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

    _reply("");

    return;
}

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

    _reply("");

    return;
}

void IPCManagerStubImpl::getSteering(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _input, getSteeringReply_t _reply)
{    
    if (_input == "PDCUnit")
    {
        sender.PDCUnitTargetProxy->setSteering(piracer.getSteering(), sender.callStatus, sender.returnMessage);
    }
    
    _reply("");

    return;
}
