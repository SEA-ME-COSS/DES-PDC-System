#ifndef IVICOMPOSITORSTUBIMPL_HPP
#define IVICOMPOSITORSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IVICompositorStubDefault.hpp>

#include "IVICompositorQtClass.hpp"

class IVICompositorStubImpl : public v1_0::commonapi::IVICompositorStubDefault
{
public:
    IVICompositorStubImpl();
    virtual ~IVICompositorStubImpl();
    
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
};

#endif

