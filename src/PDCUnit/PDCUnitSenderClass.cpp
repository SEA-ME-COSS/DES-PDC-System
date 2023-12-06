#include "PDCUnitSenderClass.hpp"

using namespace v1_0::commonapi;

PDCUnitSenderClass::PDCUnitSenderClass()
{
    runtime = CommonAPI::Runtime::get();
    
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
}

PDCUnitSenderClass::~PDCUnitSenderClass() { }

