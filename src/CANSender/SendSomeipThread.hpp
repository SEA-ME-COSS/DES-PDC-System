#ifndef SENDSOMEIPTHREAD_HPP
#define SENDSOMEIPTHREAD_HPP

#include <string>
#include <unistd.h>
#include <math.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "CANSenderStubImpl.hpp"
#include "SpeedBuffer.h"
#include "DistanceBuffer.h"

#define SIZE 2
#define MEASURE_SIZE 1

// Function declarations
void kalmanFilter_(double measuredstate, double estimation[SIZE], double letterP[SIZE][SIZE], double dt, double renewed_e[SIZE], double renewed_P[SIZE][SIZE]);
void matrix_multiply(double A[SIZE][SIZE], double B[SIZE][SIZE], double result[SIZE][SIZE]);

void *SendSomeipThread(void *arg);

#endif

