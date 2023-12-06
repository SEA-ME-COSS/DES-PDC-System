#ifndef CANSENDERSTUBIMPL_HPP
#define CANSENDERSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANSenderStubDefault.hpp>

class CANSenderStubImpl: public v1_0::commonapi::CANSenderStubDefault
{
public:
    CANSenderStubImpl();
    virtual ~CANSenderStubImpl();
};

#endif

