// Include the header file for DistanceBuffer.
#include "DistanceBuffer.h"

// Define an array of unsigned 16-bit integers to represent the distance buffer.
uint16_t DistanceBuffer[DistanceBuffer_SIZE] = {0};

// Initialize an integer variable to keep track of the current index in the distance buffer.
int DistanceBufferIndex = 0;

// Initialize a mutex for thread synchronization to protect the distance buffer.
pthread_mutex_t DistanceBufferMutex = PTHREAD_MUTEX_INITIALIZER;

