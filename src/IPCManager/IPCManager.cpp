#include <unistd.h>                 // Include the unistd.h library for system calls and sleep
#include <cstdlib>                 // Include the cstdlib library for system function
#include <CommonAPI/CommonAPI.hpp>  // Include the CommonAPI framework

#include "IPCManagerStubImpl.hpp"  // Include the IPCManagerStubImpl header
#include "IPCManagerSenderClass.hpp" // Include the IPCManagerSenderClass header

using namespace v1_0::commonapi;    // Use the v1_0::commonapi namespace

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;             // Create a shared pointer for CommonAPI runtime
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;   // Create a shared pointer for IPCManagerStubImpl

    runtime = CommonAPI::Runtime::get();                    // Get the CommonAPI runtime instance
    IPCManagerService = std::make_shared<IPCManagerStubImpl>(); // Create an instance of IPCManagerStubImpl
    runtime->registerService("local", "IPCManager", IPCManagerService);
    // Register the IPCManagerService with CommonAPI runtime

    IPCManagerSenderClass sender; // Create an instance of IPCManagerSenderClass
    int exitCode;

    while (1)
    {
        usleep(1000000); // Sleep for one second
    }

    return 0;
}

