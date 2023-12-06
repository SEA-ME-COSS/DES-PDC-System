#ifndef SPEEDBUFFER_H
#define SPEEDBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

#define SpeedBuffer_SIZE 10

extern uint16_t SpeedBuffer[SpeedBuffer_SIZE];
extern int SpeedBufferIndex;

extern pthread_mutex_t SpeedBufferMutex;

#ifdef __cplusplus
}
#endif

#endif

