#include "SpeedBuffer.h"

uint16_t SpeedBuffer[SpeedBuffer_SIZE] = {0};
int SpeedBufferIndex = 0;

pthread_mutex_t SpeedBufferMutex = PTHREAD_MUTEX_INITIALIZER;
