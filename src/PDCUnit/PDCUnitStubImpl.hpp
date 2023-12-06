#ifndef PDCUNITSTUBIMPL_HPP
#define PDCUNITSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/PDCUnitStubDefault.hpp>

#include "PDCUnitQtClass.hpp"

class PDCUnitStubImpl : public v1_0::commonapi::PDCUnitStubDefault
{
public:
    PDCUnitStubImpl();
    virtual ~PDCUnitStubImpl();
    
    virtual void setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _return);
    virtual void setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _return);
};

#endif

