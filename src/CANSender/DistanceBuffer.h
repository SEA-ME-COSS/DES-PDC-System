#ifndef DISTANCEBUFFER_H
#define DISTANCEBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

// Define the size of the distance buffer as 10.
#define DistanceBuffer_SIZE 10

// Declare an array of unsigned 16-bit integers to represent the distance buffer.
extern uint16_t DistanceBuffer[DistanceBuffer_SIZE];

// Declare an integer variable to keep track of the current index in the distance buffer.
extern int DistanceBufferIndex;

// Declare a mutex for thread synchronization to protect the distance buffer.
extern pthread_mutex_t DistanceBufferMutex;

#ifdef __cplusplus
}
#endif

#endif

