#ifndef IVICOMPOSITORSENDERCLASS_HPP
#define IVICOMPOSITORSENDERCLASS_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

// Import necessary namespaces
using namespace v1_0::commonapi;

// Define the IVICompositorSenderClass
class IVICompositorSenderClass
{
public:
    // Constructor for IVICompositorSenderClass
    IVICompositorSenderClass();
    
    // Destructor for IVICompositorSenderClass
    ~IVICompositorSenderClass();

    // Shared pointer to the CommonAPI runtime
    std::shared_ptr<CommonAPI::Runtime> runtime;

    // Shared pointer to the IPCManagerProxy for communication
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;

    // Call status for the last communication
    CommonAPI::CallStatus callStatus;

    // Return message from the last communication
    std::string returnMessage;
};

#endif

