#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stress_cpu() {
    while (1) {
        for (int i = 0; i < 10000000; ++i) {
            int result = 1 + 1;
            result++; 
        }
    }
}

void stress_ram() {
    unsigned long chunk_size = 100 * 1024 * 1024; 
    unsigned long allocation_count = 0;
    
    while (1) {
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
    printf("Starting CPU and RAM stress test. Press Ctrl+C to stop.\n");
    
    while (1) {
        stress_cpu();
        stress_ram();
    }
    
    return 0;
}
