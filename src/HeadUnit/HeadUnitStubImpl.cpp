#include "HeadUnitStubImpl.hpp"

HeadUnitStubImpl::HeadUnitStubImpl() { }
HeadUnitStubImpl::~HeadUnitStubImpl() { }

void HeadUnitStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    uint16_t calculatedRpm = (uint16_t)((float)((uint16_t)((float)_sensorRpm / 2.6)) * 3.4);
    carinfo.setSensorRpm(calculatedRpm);

    _reply("");
    
    return;
}

void HeadUnitStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    carinfo.setGear(_gear);

    _reply("");
    
    return;
}

void HeadUnitStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    carinfo.setDirection(_direction);

    _reply("");

    return;
}

void HeadUnitStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    carinfo.setLight(QString::fromStdString(_light));

    _reply("");

    return;
}

