#include "RemoteSpeakerStubImpl.hpp"

RemoteSpeakerStubImpl::RemoteSpeakerStubImpl() { }
RemoteSpeakerStubImpl::~RemoteSpeakerStubImpl() { }

void RemoteSpeakerStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    GearBuffer = _gear;
    
    _reply("");
    
    return;
}

void RemoteSpeakerStubImpl::setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _reply)
{
    DistanceBuffer = _distance;
    
    _reply("");
    
    return;
}
