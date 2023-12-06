#ifndef DISTANCEBUFFER_H
#define DISTANCEBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

#define DistanceBuffer_SIZE 10

extern uint16_t DistanceBuffer[DistanceBuffer_SIZE];
extern int DistanceBufferIndex;

extern pthread_mutex_t DistanceBufferMutex;

#ifdef __cplusplus
}
#endif

#endif
