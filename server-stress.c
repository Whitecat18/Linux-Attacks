/*
C PROGRAM TO STRESS LINUX SERVERS . 
TESTED CONFIGS : 
        INTEL XEON E7-8870 v3 , 515 GIGS OF RAM , NO V-RAM
        UBUNTU 20.04 (FOCAL FOSS) 
        
CODED BY SMUKX -> https://github.com/Whitecat18/Linux-Attacks
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stress_cpu() {
    while (1) {
        for (int i = 0; i < 10000000; ++i) {
            int result = 1 + 1;
            result++; 
        }
    }
}

// Function to stress the RAM
void stress_ram() {
    unsigned long long chunk_size = 100 * 1024 * 1024; 
    unsigned long long allocation_count = 0;
    
    while (1) {
        void* memory = malloc(chunk_size);
        if (memory == NULL) {
            break;
        }
        
        memset(memory, 0, chunk_size);
        allocation_count++;
    }
    
    printf("Allocated %llu chunks of %lluMB\n", allocation_count, chunk_size / (1024 * 1024));
}

int main() {
    printf("Starting CPU and RAM stress test for Intel Xeon E7-8870 v3 CPU and 500 GB of RAM.\n");
    printf("Press Ctrl+C to stop the stress test.\n");

    while (1) {
        stress_cpu();
        stress_ram();
    }

    return 0;
}

  
