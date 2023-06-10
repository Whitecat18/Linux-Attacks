#!/usr/bin/python3
# Code By Smukx : https://github.com/Whitecat18/Linux-Attacks
# stress the CPU and RAM until it is manually stopped using Ctrl+C:
# Install this advance module called psutil ` pip install psutil`

import psutil
import time

def stress_cpu(duration):
    start_time = time.time()
    end_time = start_time + duration
    
    while time.time() < end_time:

        for _ in range(10**7):
            _ = 1 + 1

def stress_ram(duration):
    start_time = time.time()
    end_time = start_time + duration
    

    data = []
    while time.time() < end_time:
        data.append(' ' * 1024) 

    data.clear()

try:
    duration = int(input("Enter stress duration in seconds: "))
    print("Starting CPU and RAM stress test. Press Ctrl+C to stop.")
    
    stress_cpu(duration)
    stress_ram(duration)

except KeyboardInterrupt:
    print("Stress test stopped manually.")
