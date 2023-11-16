#include "IPCManagerSenderClass.hpp"  // Include the IPCManagerSenderClass header

using namespace v1_0::commonapi;  // Use the v1_0::commonapi namespace

IPCManagerSenderClass::IPCManagerSenderClass()
{
    // Get the CommonAPI runtime
    runtime = CommonAPI::Runtime::get();

    // Build proxies for different services
    CANSenderTargetProxy = runtime->buildProxy<CANSenderProxy>("local", "CANSender");
    // Create a proxy for the CANSender service

    PiracerSenderTargetProxy = runtime->buildProxy<PiracerSenderProxy>("local", "PiracerSender");
    // Create a proxy for the PiracerSender service

    PiracerControllerTargetProxy = runtime->buildProxy<PiracerControllerProxy>("local", "PiracerController");
    // Create a proxy for the PiracerController service

    InstrumentClusterTargetProxy = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    // Create a proxy for the InstrumentCluster service

    HeadUnitTargetProxy = runtime->buildProxy<HeadUnitProxy>("local", "HeadUnit");
    // Create a proxy for the HeadUnit service
    
    PDCUnitTargetProxy = runtime->buildProxy<PDCUnitProxy>("local", "PDCUnit");
    // Create a proxy for the PDCUnit service
    
    IVICompositorTargetProxy = runtime->buildProxy<IVICompositorProxy>("local", "IVICompositor");
    // Create a proxy for the IVICompositor service
    
    RemoteSpeakerTargetProxy = runtime->buildProxy<RemoteSpeakerProxy>("local", "RemoteSpeaker");
    // Create a proxy for the RemoteSpeaker service
}
 
IPCManagerSenderClass::~IPCManagerSenderClass()
{
    // Destructor
}

