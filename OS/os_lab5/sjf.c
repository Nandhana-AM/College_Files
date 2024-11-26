#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int start_time;
    int completion_time;
    bool completed;
} Process;


void sjfScheduling(Process processes[], int n) {
    int completed = 0, time = 0;
    double total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;

    // Initialize all processes as not completed
    for (int i = 0; i < n; i++) {
        processes[i].completed = false;
    }

    printf("\nGantt Chart:\n|");  // Start of the Gantt chart

    // Main loop to process all processes
    while (completed != n) {
        int shortest = -1;
        int min_burst_time = INT_MAX;

        // Find the process with the shortest burst time among available processes
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && !processes[i].completed && processes[i].burst_time < min_burst_time) {
                min_burst_time = processes[i].burst_time;
                shortest = i;
            }
        }

        // If no process is ready to execute, increment the time
        if (shortest == -1) {
            time++;
            continue;
        }

        // Set start time for the first time the process starts
        processes[shortest].start_time = time;
        processes[shortest].completion_time = time + processes[shortest].burst_time;
        processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
        processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
        processes[shortest].response_time = processes[shortest].waiting_time;
        
        // Update totals
        total_waiting_time += processes[shortest].waiting_time;
        total_turnaround_time += processes[shortest].turnaround_time;
        total_response_time += processes[shortest].response_time;

        // Print Gantt chart details for the current process
        printf(" P%d (%d-%d) |", processes[shortest].process_id, time, time + processes[shortest].burst_time);

        // Mark process as completed
        processes[shortest].completed = true;
        completed++;
        
        // Move time forward by the burst time of the completed process
        time += processes[shortest].burst_time;
    }
    printf("\n");

    // Print table with process details
    printf("\nProcess\tArrival\tBurst\tComepletion\tWaiting\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n", processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time,
               processes[i].response_time);
    }

    // Display averages
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Response Time: %.2f\n", total_response_time / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter the arrival time of process P%d: ", processes[i].process_id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process P%d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
    }

    sjfScheduling(processes, n);

    return 0;
}
