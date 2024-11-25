//Deadlock Detection
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    int alloc[5][3];   // Allocation Matrix
    int request[5][3]; // Request (Need) Matrix
    int avail[3];      // Available Resources
    bool finish[n];    // Finish array to mark completed processes

    // Seed the random number generator
    srand(time(0));

    // Randomly generate Allocation and Request matrices
    for (int i = 0; i < n; i++) {
        finish[i] = false;
        for (int j = 0; j < m; j++) {
            alloc[i][j] = rand() % 10;              // Random allocation (0 to 9)
            request[i][j] = rand() % (10 - alloc[i][j]); // Request <= (10 - allocated)
        }
    }

    // Randomly generate Available resources
    for (int j = 0; j < m; j++) {
        avail[j] = rand() % 10 + 1; // Available resources (1 to 10)
    }

    // Deadlock Detection Algorithm
    for (int k = 0; k < n; k++) { // Up to n iterations to check for deadlock
        bool progress = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) { // If process i is not finished
                bool can_allocate = true;
                for (int j = 0; j < m; j++) {
                    if (request[i][j] > avail[j]) { // Check if resources can be allocated
                        can_allocate = false;
                        break;
                    }
                }

                if (can_allocate) { // If resources can be allocated
                    for (int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j]; // Release resources
                    }
                    finish[i] = true; // Mark process as finished
                    progress = true;
                }
            }
        }
        if (!progress) break; // Exit if no progress made in this pass
    }

    // Check for deadlock by finding any unfinished process
    bool deadlock = false;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            printf("Process P%d is in deadlock.\n", i);
            deadlock = true;
        }
    }

    if (!deadlock) {
        printf("No deadlock detected. System is in a safe state.\n");
    }

    return 0;
}