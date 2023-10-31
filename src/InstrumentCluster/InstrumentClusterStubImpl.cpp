#include "InstrumentClusterStubImpl.hpp"

InstrumentClusterStubImpl::InstrumentClusterStubImpl() { }

InstrumentClusterStubImpl::~InstrumentClusterStubImpl() { }

void InstrumentClusterStubImpl::setSpeedRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSpeedRpmReply_t _reply)
{
    // Convert sensor RPM to a format suitable for the instrument cluster.
    temp = (uint16_t)((float)_sensorRpm / 2.6);

    // Update the RPM property in the carinfo object with the converted value.
    carinfo.setRpm(temp);

    // Calculate the speed based on the converted RPM and update the property.
    temp = (uint16_t)((float)temp * 3.4);
    carinfo.setSpeed(temp);

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

void InstrumentClusterStubImpl::setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _reply)
{
    // Update the battery level property in the carinfo object.
    carinfo.setBattery(_battery);

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
} 

void InstrumentClusterStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    // Update the gear mode property in the carinfo object.
    carinfo.setGear(_gear);
    
    // Respond to the client's request by invoking the reply callback.
    _reply("");
    
    return;
}

void InstrumentClusterStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    // Update the direction property in the carinfo object.
    carinfo.setDirection(_direction);

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

void InstrumentClusterStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    // Update the light color property in the carinfo object.
    carinfo.setLight(QString::fromStdString(_light));

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

