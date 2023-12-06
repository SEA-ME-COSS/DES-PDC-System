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

int open_port(const char *port);
void read_port();
int close_port();
void *ReadCANThread(void *arg);

#ifdef __cplusplus
}
#endif

#endif

