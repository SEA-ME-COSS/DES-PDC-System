#include "InstrumentClusterStubImpl.hpp"

InstrumentClusterStubImpl::InstrumentClusterStubImpl() { }
InstrumentClusterStubImpl::~InstrumentClusterStubImpl() { }

void InstrumentClusterStubImpl::setSpeedRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSpeedRpmReply_t _reply)
{
    temp = (uint16_t)((float)_sensorRpm / 2.6);
    carinfo.setRpm(temp);

    temp = (uint16_t)((float)temp * 3.4);
    carinfo.setSpeed(temp);

    _reply("");

    return;
}

void InstrumentClusterStubImpl::setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _reply)
{
    carinfo.setBattery(_battery);

    _reply("");

    return;
} 

void InstrumentClusterStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    carinfo.setGear(_gear);
    
    _reply("");
    
    return;
}

void InstrumentClusterStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    carinfo.setDirection(_direction);

    _reply("");

    return;
}

void InstrumentClusterStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    carinfo.setLight(QString::fromStdString(_light));

    _reply("");

    return;
}

