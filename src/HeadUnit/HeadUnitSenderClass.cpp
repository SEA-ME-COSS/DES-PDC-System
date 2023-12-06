#include "HeadUnitSenderClass.hpp"

using namespace v1_0::commonapi;

HeadUnitSenderClass::HeadUnitSenderClass()
{
    runtime = CommonAPI::Runtime::get();

    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
}

HeadUnitSenderClass::~HeadUnitSenderClass() { }

