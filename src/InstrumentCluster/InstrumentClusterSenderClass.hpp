#ifndef INSTRUMENTCLUSTERSENDERCLASS_HPP
#define INSTRUMENTCLUSTERSENDERCLASS_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

// Import necessary namespaces
using namespace v1_0::commonapi;

// Define the InstrumentClusterSenderClass
class InstrumentClusterSenderClass
{
public:
    // Constructor for InstrumentClusterSenderClass
    InstrumentClusterSenderClass();
    
    // Destructor for InstrumentClusterSenderClass
    ~InstrumentClusterSenderClass();

    // Shared pointer to the CommonAPI runtime
    std::shared_ptr<CommonAPI::Runtime> runtime;

    // Shared pointer to the IPCManagerProxy for communication
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;

    // Call status for the last communication
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
};

#endif

