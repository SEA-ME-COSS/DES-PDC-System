#include "InstrumentClusterSenderClass.hpp"

using namespace v1_0::commonapi;

InstrumentClusterSenderClass::InstrumentClusterSenderClass()
{
    runtime = CommonAPI::Runtime::get();

    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
}

InstrumentClusterSenderClass::~InstrumentClusterSenderClass() { }

