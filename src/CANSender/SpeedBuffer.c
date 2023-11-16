// Include the header file for SpeedBuffer.
#include "SpeedBuffer.h"

// Define an array of unsigned 16-bit integers to represent the speed buffer.
uint16_t SpeedBuffer[SpeedBuffer_SIZE] = {0};

// Initialize an integer variable to keep track of the current index in the speed buffer.
int SpeedBufferIndex = 0;

// Initialize a mutex for thread synchronization to protect the speed buffer.
pthread_mutex_t SpeedBufferMutex = PTHREAD_MUTEX_INITIALIZER;

