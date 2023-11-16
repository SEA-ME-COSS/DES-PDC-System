#include "ReadCANThread.h"
#include "SendSomeipThread.hpp"

int main ()
{
    // Declare pthread variables.
    pthread_t readCANThread, sendSomeipThread;
    
    // Create a new thread for the ReadCANThread, which is responsible for reading from CAN.
    pthread_create(&readCANThread, NULL, ReadCANThread, NULL);

    // Create a new thread for the SendSomeipThread, which sends data using the SomeIP protocol.
    pthread_create(&sendSomeipThread, NULL, SendSomeipThread, NULL);

    // Wait for the speed thread, distance thread and SomeIP thread to finish execution.
    pthread_join(readCANThread, NULL);
    pthread_join(sendSomeipThread, NULL);

    // Return 0 to indicate successful execution of the program.
    return 0;
}

