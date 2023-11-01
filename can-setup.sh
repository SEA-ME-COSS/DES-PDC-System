#!/bin/bash

# Set CAN interface 
sudo ip link set can0 up type can bitrate 500000

# Set txqueuelen 
sudo ifconfig can0 txqueuelen 65536