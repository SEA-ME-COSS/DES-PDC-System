#include "PDCUnitStubImpl.hpp"

// Constructor for PDCUnitStubImpl
PDCUnitStubImpl::PDCUnitStubImpl() { }

// Destructor for PDCUnitStubImpl
PDCUnitStubImpl::~PDCUnitStubImpl() { }

void PDCUnitStubImpl::setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _reply)
{
    // Update the distance property in the carinfo object.
    carinfo.setDistance(_distance);

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

void PDCUnitStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _reply)
{
    // Update the steering property in the carinfo object.
    carinfo.setSteering(_steering);

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

