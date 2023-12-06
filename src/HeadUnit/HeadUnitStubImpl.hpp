#ifndef HEADUNITSTUBIMPL_HPP
#define HEADUNITSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HeadUnitStubDefault.hpp>

#include "HeadUnitQtClass.hpp"

class HeadUnitStubImpl : public v1_0::commonapi::HeadUnitStubDefault
{
public:
    HeadUnitStubImpl();
    virtual ~HeadUnitStubImpl();

    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
    virtual void setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _return);
    virtual void setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _return);
};

#endif

