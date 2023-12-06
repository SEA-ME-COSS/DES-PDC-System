#ifndef INSTRUMENTCLUSTERSENDERCLASS_HPP
#define INSTRUMENTCLUSTERSENDERCLASS_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

using namespace v1_0::commonapi;

class InstrumentClusterSenderClass
{
public:
    InstrumentClusterSenderClass();
    ~InstrumentClusterSenderClass();

    std::shared_ptr<CommonAPI::Runtime> runtime;

    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
};

#endif

