#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

FILE *file = NULL;

void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

void handle_sigint(int sig) {
    printf("\n[Signal Caught] Shutting down gracefully...\n");
    if (file != NULL) {
        fclose(file);
        printf("File closed safely. Exiting.\n");
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    // Default values if no arguments are passed
    int interval_ms = 1000;
    const char *filename = "sensor_log.csv";

    // Parse command-line arguments if provided
    if (argc > 1) {
        interval_ms = atoi(argv[1]); // First argument: interval in ms
    }
    if (argc > 2) {
        filename = argv[2];          // Second argument: custom filename
    }

    signal(SIGINT, handle_sigint);

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "Timestamp,SimulatedValue,Status\n");
    srand(time(NULL));

    printf("Starting sensor stream -> Interval: %dms | Output: %s\n", interval_ms, filename);
    printf("Press Ctrl+C to stop safely...\n");

    int counter = 0;
    while (1) {
        counter++;
        int simulated_value = 20 + (rand() % 31);
        time_t current_time = time(NULL);

        // Simulate an occasional warning status (e.g., value > 45 triggers "WARNING")
        const char *status = (simulated_value > 45) ? "WARNING" : "OK";

        fprintf(file, "%ld,%d,%s\n", current_time, simulated_value, status);
        fflush(file);

        printf("[%d] Time: %ld | Value: %d | Status: %s\n", counter, current_time, simulated_value, status);

        sleep_ms(interval_ms);
    }

    return 0;
}