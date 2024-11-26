#include <stdio.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int start_time;
    int completion_time;
} Process;

void fcfsScheduling(Process processes[], int n) {
    int time = 0;
    double total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Display Gantt Chart Header
    printf("Gantt Chart:\n|");
    
    // Calculate times for each process and display Gantt Chart in execution order
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;  // Wait for process arrival
        }
        processes[i].start_time = time;
        processes[i].completion_time = time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].start_time - processes[i].arrival_time;
        processes[i].response_time = processes[i].waiting_time;

        // Print process in Gantt chart
        printf(" P%d |", processes[i].process_id);

        time += processes[i].burst_time;

        // Update totals
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
    }
    printf("\n");

    // Print table with process details
    printf("\nProcess\tArrival \tBurst \tWaiting \tTurnaround \tResponse \n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
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

    fcfsScheduling(processes, n);

    return 0;
}
