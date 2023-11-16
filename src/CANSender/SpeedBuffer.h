#ifndef SPEEDBUFFER_H
#define SPEEDBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

// Define the size of the speed buffer as 10.
#define SpeedBuffer_SIZE 10

// Declare an array of unsigned 16-bit integers to represent the speed buffer.
extern uint16_t SpeedBuffer[SpeedBuffer_SIZE];

// Declare an integer variable to keep track of the current index in the speed buffer.
extern int SpeedBufferIndex;

// Declare a mutex for thread synchronization to protect the speed buffer.
extern pthread_mutex_t SpeedBufferMutex;

#ifdef __cplusplus
}
#endif

#endif

