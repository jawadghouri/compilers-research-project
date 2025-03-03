#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h> // For resource usage

// Function to get current time in milliseconds
long long get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000LL + (long long)ts.tv_nsec / 1000000LL;
}

// Function to get memory usage in kilobytes
long get_memory_usage_kb() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        return usage.ru_maxrss; // Resident set size (in kilobytes on Linux, bytes on macOS)
    } else {
        return -1; // Error
    }
}

void my_function() {
    // Simulate a long-running task
    volatile int dummy = 0;
    for (long long i = 0; i < 1000000000; i++) {
        dummy++;
    }
}

int main() {
    long long start_time, end_time;
    long start_memory, end_memory;

    // Before function execution
    start_time = get_time_ms();
    start_memory = get_memory_usage_kb();
    printf("Function start time: %lld ms\n", start_time);
    printf("Function start memory: %ld KB\n", start_memory);

    my_function();

    // After function execution
    end_time = get_time_ms();
    end_memory = get_memory_usage_kb();
    printf("Function end time: %lld ms\n", end_time);
    printf("Function end memory: %ld KB\n", end_memory);

    // Calculate and print the differences
    printf("Time taken: %lld ms\n", end_time - start_time);
    printf("Memory used: %ld KB\n", end_memory - start_memory);

    return 0;
}