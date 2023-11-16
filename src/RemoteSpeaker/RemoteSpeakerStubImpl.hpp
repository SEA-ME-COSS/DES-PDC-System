#ifndef REMOTESPEAKERSTUBIMPL_HPP
#define REMOTESPEAKERSTUBIMPL_HPP


#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/RemoteSpeakerStubDefault.hpp>

#include "DataBuffer.hpp"

class RemoteSpeakerStubImpl: public v1_0::commonapi::RemoteSpeakerStubDefault
{
public:
    RemoteSpeakerStubImpl();
    virtual ~RemoteSpeakerStubImpl();
    
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
    virtual void setDistance(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _distance, setDistanceReply_t _return);
};

#endif

