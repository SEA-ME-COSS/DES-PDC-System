#include "PDCUnitSenderClass.hpp"

// Import the necessary namespaces
using namespace v1_0::commonapi;

// Constructor for the PDCUnitSenderClass
PDCUnitSenderClass::PDCUnitSenderClass()
{
    // Get the CommonAPI runtime instance
    runtime = CommonAPI::Runtime::get();
    
    // Build a proxy to the IPCManager service on the "local" transport with the name "IPCManager"
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
}

// Destructor for the PDCUnitSenderClass
PDCUnitSenderClass::~PDCUnitSenderClass() { }

