#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "PiracerSenderStubImpl.hpp"
#include "PiracerClass.hpp"

using namespace v1_0::commonapi;

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    runtime = CommonAPI::Runtime::get();
    std::shared_ptr<PiracerSenderStubImpl> PiracerSenderService = std::make_shared<PiracerSenderStubImpl>();

    runtime->registerService("local", "PiracerSender", PiracerSenderService);
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");

    PiracerClass piracer;
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    while (1)
    {
        IPCManagerTargetProxy->setBatteryLevel(piracer.getBatteryLevel(), callStatus, returnMessage);

        usleep(500000);
    }

    return 0;
}

