#include "IPCManagerSenderClass.hpp"

using namespace v1_0::commonapi;

IPCManagerSenderClass::IPCManagerSenderClass()
{
    runtime = CommonAPI::Runtime::get();

    CANSenderTargetProxy = runtime->buildProxy<CANSenderProxy>("local", "CANSender");
    PiracerSenderTargetProxy = runtime->buildProxy<PiracerSenderProxy>("local", "PiracerSender");
    PiracerControllerTargetProxy = runtime->buildProxy<PiracerControllerProxy>("local", "PiracerController");
    InstrumentClusterTargetProxy = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    HeadUnitTargetProxy = runtime->buildProxy<HeadUnitProxy>("local", "HeadUnit");
    PDCUnitTargetProxy = runtime->buildProxy<PDCUnitProxy>("local", "PDCUnit");
    IVICompositorTargetProxy = runtime->buildProxy<IVICompositorProxy>("local", "IVICompositor");
    RemoteSpeakerTargetProxy = runtime->buildProxy<RemoteSpeakerProxy>("local", "RemoteSpeaker");
}
 
IPCManagerSenderClass::~IPCManagerSenderClass() { }

