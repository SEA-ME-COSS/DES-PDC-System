#include "DistanceBuffer.h"

uint16_t DistanceBuffer[DistanceBuffer_SIZE] = {0};
int DistanceBufferIndex = 0;

pthread_mutex_t DistanceBufferMutex = PTHREAD_MUTEX_INITIALIZER;
