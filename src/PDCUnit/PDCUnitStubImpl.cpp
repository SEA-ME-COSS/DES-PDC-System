#include "PDCUnitStubImpl.hpp"

PDCUnitStubImpl::PDCUnitStubImpl() { }
PDCUnitStubImpl::~PDCUnitStubImpl() { }

void PDCUnitStubImpl::setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _reply)
{
    carinfo.setDistance(_distance);

    _reply("");

    return;
}

void PDCUnitStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _reply)
{
    carinfo.setSteering(_steering);

    _reply("");

    return;
}

