#include "IVICompositorStubImpl.hpp"

IVICompositorStubImpl::IVICompositorStubImpl() { }
IVICompositorStubImpl::~IVICompositorStubImpl() { }

void IVICompositorStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    carinfo.setGear(_gear);

    _reply("");
    
    return;
}

