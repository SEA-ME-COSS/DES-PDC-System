#include "ReadCANThread.h"
#include "SendSomeipThread.hpp"

int main ()
{
    pthread_t readCANThread, sendSomeipThread;
    
    pthread_create(&readCANThread, NULL, ReadCANThread, NULL);
    pthread_create(&sendSomeipThread, NULL, SendSomeipThread, NULL);

    pthread_join(readCANThread, NULL);
    pthread_join(sendSomeipThread, NULL);

    return 0;
}

