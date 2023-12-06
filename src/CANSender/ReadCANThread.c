#include <stdio.h>

#include "ReadCANThread.h"

int soc;  // Socket descriptor for CAN communication
uint16_t speed_sensor_rpm;
uint16_t distance;

// Function to open and configure the CAN port
int open_port(const char *port) {
    struct ifreq ifr;
    struct sockaddr_can addr;
    struct can_filter rfilter[2];

    // Create a raw CAN socket
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (soc < 0) {
        printf("Error opening socket!");
        return (-1);
    }

    // Configure the CAN socket address
    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);

    // Retrieve the interface index
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0) {
        printf("Error retrieving interface index!");
        return (-1);
    }

    addr.can_ifindex = ifr.ifr_ifindex;
    fcntl(soc, F_SETFL, O_NONBLOCK);

    // Bind the socket to the address
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error binding to the socket!");
        return (-1);
    }

    // Set a CAN filter to receive specific messages
    rfilter[0].can_id   = 0x0F6;
    rfilter[0].can_mask = CAN_SFF_MASK;
    rfilter[1].can_id   = 0x0F7;
    rfilter[1].can_mask = CAN_SFF_MASK;
    if (setsockopt(soc, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter)) < 0) {
        printf("Error setting CAN filter!");
        return (-1);
    }

    return 0;
}

// Function to read data from the CAN port
void read_port() {
    struct can_frame frame;
    int recvbytes = 0;
    struct timeval timeout = {1, 0};
    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(soc, &readSet);

    if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(soc, &readSet)) {
            recvbytes = read(soc, &frame, sizeof(struct can_frame));
    
            if (recvbytes) {
                if (frame.can_id == 0x0F6) {
                    speed_sensor_rpm = (frame.data[0] << 8) + frame.data[1];
                    
        	    pthread_mutex_lock(&SpeedBufferMutex);
        	    SpeedBuffer[SpeedBufferIndex] = speed_sensor_rpm;
        	    SpeedBufferIndex = (SpeedBufferIndex + 1) % SpeedBuffer_SIZE;
        	    pthread_mutex_unlock(&SpeedBufferMutex);
                }
                else if (frame.can_id == 0x0F7) {
                    distance = (frame.data[0] << 8) + frame.data[1];
                    
        	    pthread_mutex_lock(&DistanceBufferMutex);
        	    DistanceBuffer[DistanceBufferIndex] = distance;
        	    DistanceBufferIndex = (DistanceBufferIndex + 1) % DistanceBuffer_SIZE;
        	    pthread_mutex_unlock(&DistanceBufferMutex);
                }
            }
        }
    }
}

// Function to close the CAN port
int close_port() {
    close(soc);
    
    return 0;
}

// Thread function to read CAN data continuously
void *ReadCANThread(void *arg) {
    open_port("can0");

    while (1) {
        read_port();
    }

    close_port();
    
    return NULL;
}

