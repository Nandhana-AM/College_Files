#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct{
    int process_id;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
}Process;

void sjf_scheduling(Process processes[],int n){
    int time=0,completed=0;
    double total_wt=0,total_tat=0;
printf("\nGantt Chart:\n| ");
    for (int i=0;i<n;i++){
        processes[i].completed=false;
    }

    while(completed!=n){
        int shortest=-1;
        int min_bt=INT_MAX;

        for (int i=0;i<n;i++){
            if (processes[i].arrival_time<=time && processes[i].completed==false&&processes[i].burst_time<min_bt){
                shortest=i;
                min_bt=processes[i].burst_time;

            }
        }
        if (shortest==-1){
            time++;
            continue;
        }
        processes[shortest].start_time=time;
        processes[shortest].completion_time=time+processes[shortest].burst_time;
        processes[shortest].turnaround_time=processes[shortest].completion_time-processes[shortest].arrival_time;
        processes[shortest].waiting_time=processes[shortest].turnaround_time-processes[shortest].burst_time;

        total_tat+=processes[shortest].turnaround_time;
        total_wt+=processes[shortest].waiting_time;

        printf("%d (%d-%d) | ",processes[shortest].process_id,processes[shortest].start_time,processes[shortest].completion_time);

        processes[shortest].completed=true;
        time=processes[shortest].completion_time;
        completed++;
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
    printf("\nAverage turnaround time: %lf",total_tat/n);
    printf("\nAverage waiting time: %lf",total_wt/n);

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
    sjf_scheduling(processes,n);
    return 0;
}