#ifndef READCANTHREAD_H
#define READCANTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include "SpeedBuffer.h"
#include "DistanceBuffer.h"

int open_port(const char *port);       // Function to open and configure the CAN port
void read_port();  // Function to read data from the CAN port
int close_port();                      // Function to close the CAN port
void *ReadCANThread(void *arg);         // Thread function to read speed data continuously

#ifdef __cplusplus
}
#endif

#endif

