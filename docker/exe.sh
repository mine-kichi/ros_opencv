#!/bin/bash

nvidia-docker run \
-e DISPLAY=172.17.0.1$DISPLAY \
-v /mnt/HDD/work:/home/mine/work \
-v /usr/local/driveworks:/usr/local/driveworks \
-v /usr/local/driveworks-0.3:/usr/local/driveworks-0.3 \
-v /etc:/etc \
--rm=true \
-u mine \
-it \
ros_kinetic:1.0
