#!/usr/bin/python3
# Code By Smukx
# IF PIP IS INSTALLED ON EXPLOITING LINUX . INSTALL psutil and RUN
import psutil
import time

def stress_cpu(duration):
    start_time = time.time()
    end_time = start_time + duration
    
    while time.time() < end_time:
        # Perform some CPU-intensive operations
        for _ in range(10**7):
            _ = 1 + 1

def stress_ram(duration):
    start_time = time.time()
    end_time = start_time + duration
    
    # Allocate memory in chunks of 100MB
    chunk_size = 100 * 1024 * 1024  # 100MB
    data = []
    
    while time.time() < end_time:
        try:
            data.append(bytearray(chunk_size))
        except MemoryError:
            break
    
    # Release the memory
    data.clear()

try:
    duration = int(input("Enter stress duration in seconds: "))
    print("Starting CPU and RAM stress test. Press Ctrl+C to stop.")

    while True:
        stress_cpu(duration)
        stress_ram(duration)

except KeyboardInterrupt:
    print("Stress test stopped manually.")
