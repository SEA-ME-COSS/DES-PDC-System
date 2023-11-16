#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "ControllerClass.hpp"
#include "PiracerControllerStubImpl.hpp"

using namespace v1_0::commonapi;

int main()
{
    // Initialize the CommonAPI runtime
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerControllerStubImpl> PiracerControllerService;
    std::shared_ptr<IPCManagerProxy<>> IPCManagertargetProxy;

    runtime = CommonAPI::Runtime::get();

    // Create the Piracer Controller service
    PiracerControllerService = std::make_shared<PiracerControllerStubImpl>();
    runtime->registerService("local", "PiracerController", PiracerControllerService);
    IPCManagertargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");

    // Initialize the controller class for interacting with the game controller
    ControllerClass controller;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    while (1)
    {
        // Read control input from the game controller
        controller.readControl();

	// Send control data to IPCManager
	if (controller.getPreThrottle() != controller.getThrottle())
	{
            IPCManagertargetProxy->setThrottle(controller.getThrottle(), callStatus, returnMessage);
	}
	if (controller.getPreSteering() != controller.getSteering())
	{
	    IPCManagertargetProxy->setSteering(controller.getSteering(), callStatus, returnMessage);
        }
        if (controller.getPreButtonP() != controller.getButtonP())
	{
	    IPCManagertargetProxy->setGearMode(0, callStatus, returnMessage);
        }
        if (controller.getPreButtonR() != controller.getButtonR())
	{
	    IPCManagertargetProxy->setGearMode(1, callStatus, returnMessage);
        }
        if (controller.getPreButtonN() != controller.getButtonN())
	{
	    IPCManagertargetProxy->setGearMode(2, callStatus, returnMessage);
        }
        if (controller.getPreButtonD() != controller.getButtonD())
	{
	    IPCManagertargetProxy->setGearMode(3, callStatus, returnMessage);
        }
        if ((!controller.getPreButtonLeftTurn()) && (controller.getButtonLeftTurn()))
	{
	    IPCManagertargetProxy->setDirection(1, callStatus, returnMessage);
        }
        if ((!controller.getPreButtonRightTurn()) && (controller.getButtonRightTurn()))
	{
	    IPCManagertargetProxy->setDirection(2, callStatus, returnMessage);
        }
    }

    return 0;
}

