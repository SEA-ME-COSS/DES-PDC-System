#ifndef PDCUNITSTUBIMPL_HPP
#define PDCUNITSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/PDCUnitStubDefault.hpp>

#include "PDCUnitQtClass.hpp"

// Define the PDCUnitStubImpl class, which is derived from PDCUnitStubDefault
class PDCUnitStubImpl : public v1_0::commonapi::PDCUnitStubDefault
{
public:
    // Constructor for PDCUnitStubImpl
    PDCUnitStubImpl();

    // Destructor for PDCUnitStubImpl
    virtual ~PDCUnitStubImpl();
    
    // Handle a request to update the distance of the PDC Unit
    virtual void setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _return);
    
    // Handle a request to update the steering of the PDC Unit
    virtual void setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _return);
};

#endif

