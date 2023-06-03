#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stress_cpu(unsigned long duration) {
    unsigned long start_time = time(NULL);
    unsigned long end_time = start_time + duration;
    
    while (time(NULL) < end_time) {
        // Perform some CPU-intensive operations
        for (int i = 0; i < 10000000; ++i) {
            int result = 1 + 1;
            result++; 
        }
    }
}

void stress_ram(unsigned long duration) {
    unsigned long start_time = time(NULL);
    unsigned long end_time = start_time + duration;
    
    unsigned long chunk_size = 100 * 1024 * 1024; // 100MB
    unsigned long allocation_count = 0;
    
    while (time(NULL) < end_time) {
        void* memory = malloc(chunk_size);
        if (memory == NULL) {
            break;
        }
        
        memset(memory, 0, chunk_size);
        allocation_count++;
    }
    
    printf("Allocated %lu chunks of %luMB\n", allocation_count, chunk_size / (1024 * 1024));
}

int main() {
    unsigned long duration;
    printf("Enter stress duration in seconds: ");
    scanf("%lu", &duration);
    printf("Starting CPU and RAM stress test. Press Ctrl+C to stop.\n");
    
    while (1) {
        stress_cpu(duration);
        stress_ram(duration);
    }
    
    return 0;
}
