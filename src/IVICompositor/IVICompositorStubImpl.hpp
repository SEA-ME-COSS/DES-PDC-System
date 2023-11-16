#ifndef IVICOMPOSITORSTUBIMPL_HPP
#define IVICOMPOSITORSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IVICompositorStubDefault.hpp>

#include "IVICompositorQtClass.hpp"

// Define the IVICompositorStubImpl class, which is derived from IVICompositorStubDefault
class IVICompositorStubImpl : public v1_0::commonapi::IVICompositorStubDefault
{
public:
    // Constructor for IVICompositorStubImpl
    IVICompositorStubImpl();

    // Destructor for IVICompositorStubImpl
    virtual ~IVICompositorStubImpl();
    
    // Handle a request to update the gear mode of the IVI Compositor
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
};

#endif

