#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "ControllerClass.hpp"
#include "PiracerControllerStubImpl.hpp"

using namespace v1_0::commonapi;

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerControllerStubImpl> PiracerControllerService;
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;

    runtime = CommonAPI::Runtime::get();
    PiracerControllerService = std::make_shared<PiracerControllerStubImpl>();
    runtime->registerService("local", "PiracerController", PiracerControllerService);
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");

    ControllerClass controller;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    while (1)
    {
        controller.readControl();

        if (controller.getPreThrottle() != controller.getThrottle())
        {
            IPCManagerTargetProxy->setThrottle(controller.getThrottle(), callStatus, returnMessage);
        }
        if (controller.getPreSteering() != controller.getSteering())
        {
            IPCManagerTargetProxy->setSteering(controller.getSteering(), callStatus, returnMessage);
        }
        if (controller.getPreButtonP() != controller.getButtonP())
        {
            IPCManagerTargetProxy->setGearMode(0, callStatus, returnMessage);
        }
        if (controller.getPreButtonR() != controller.getButtonR())
        {
            IPCManagerTargetProxy->setGearMode(1, callStatus, returnMessage);
        }
        if (controller.getPreButtonN() != controller.getButtonN())
        {
            IPCManagerTargetProxy->setGearMode(2, callStatus, returnMessage);
        }
        if (controller.getPreButtonD() != controller.getButtonD())
        {
            IPCManagerTargetProxy->setGearMode(3, callStatus, returnMessage);
        }
        if ((!controller.getPreButtonLeftTurn()) && (controller.getButtonLeftTurn()))
        {
            IPCManagerTargetProxy->setDirection(1, callStatus, returnMessage);
        }
        if ((!controller.getPreButtonRightTurn()) && (controller.getButtonRightTurn()))
        {
            IPCManagerTargetProxy->setDirection(2, callStatus, returnMessage);
        }
    }

    return 0;
}

