#include <stdio.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int completion_time;
    int turnaround_time;
    int start_time;
} Process;

void fcfs_scheduling(Process processes[],int n){
    int time=0;
    double total_waiting_time=0,total_turnaround_time=0;

    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if(processes[i].arrival_time>processes[j].arrival_time){
                Process temp=processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }

        }
    }
    printf("\nGantt Chart:\n|");
    for (int i=0;i<n;i++){
        if (time<processes[i].arrival_time){
            time=processes[i].arrival_time;
        }
        processes[i].start_time=time;
        processes[i].completion_time=processes[i].start_time+processes[i].burst_time;
        processes[i].turnaround_time=processes[i].completion_time-processes[i].arrival_time;
        processes[i].waiting_time=processes[i].start_time-processes[i].arrival_time;

        printf(" %d |",processes[i].process_id);

        time=processes[i].completion_time;

        total_turnaround_time+=processes[i].turnaround_time;
        total_waiting_time+=processes[i].waiting_time;
    }
    printf("\nProcess id\tArrival time\tBurst time\tCompletion time\tWaiting time\tTurnaround time");
    for (int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
        processes[i].process_id,
        processes[i].arrival_time,
        processes[i].burst_time,
        processes[i].completion_time,
        processes[i].waiting_time,
        processes[i].turnaround_time);
    }
    printf("\nAverage turnaround time: %lf",total_turnaround_time/n);
    printf("\nAverage waiting time: %lf",total_waiting_time/n);
}

int main(){
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    Process processes[n];
    for (int i=0;i<n;i++){
        processes[i].process_id=i+1;
        printf("Enter the arrival time of P%d: ",processes[i].process_id);
        scanf("%d",&processes[i].arrival_time);
        printf("Enter the burst time of P%d: ",processes[i].process_id);
        scanf("%d",&processes[i].burst_time);
    }
    fcfs_scheduling(processes,n);
    return 0;
}