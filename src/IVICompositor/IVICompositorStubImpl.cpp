#include "IVICompositorStubImpl.hpp"

// Constructor for IVICompositorStubImpl
IVICompositorStubImpl::IVICompositorStubImpl() { }

// Destructor for IVICompositorStubImpl
IVICompositorStubImpl::~IVICompositorStubImpl() { }

void IVICompositorStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    // Update the gear mode property in the carinfo object.
    carinfo.setGear(_gear);
    
    // Respond to the client's request by invoking the reply callback.
    _reply("");
    
    return;
}

