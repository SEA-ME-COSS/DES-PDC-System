#include <unistd.h>
#include <cstdlib>
#include <CommonAPI/CommonAPI.hpp>

#include "IPCManagerStubImpl.hpp"
#include "IPCManagerSenderClass.hpp"

using namespace v1_0::commonapi;

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;

    runtime = CommonAPI::Runtime::get();
    IPCManagerService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManagerService);

    IPCManagerSenderClass sender;
    int exitCode;

    while (1)
    {
        usleep(1000000);
    }

    return 0;
}

