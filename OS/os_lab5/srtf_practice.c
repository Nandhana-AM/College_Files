#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct{
    int pid;
    int at;
    int bt;
    int rbt;
    int wt;
    int tat;
    int ct;
    bool is_completed;
}Process;

void srtf_sch(Process processes[],int n){
    int time=0,completed=0;
    double total_wt=0,total_tat=0;

    for (int i=0;i<n;i++){
        processes[i].is_completed=false;
        processes[i].rbt=processes[i].bt;
    }
    printf("Gantt Chart: \n|");
    while(completed!=n){
        int min_bt=INT_MAX;
        int shortest=-1;

        for (int i=0;i<n;i++){
            if(processes[i].at<=time && !processes[i].is_completed && processes[i].rbt<min_bt){
                shortest=i;
                min_bt=processes[i].rbt;
            }
        }
        if (shortest==-1){
            time++;
            continue;
        }
        
        processes[shortest].rbt--;
        printf(" P%d (%d-%d) | ",processes[shortest].pid,time,time+1);
        time++;
        if (processes[shortest].rbt==0){
            processes[shortest].is_completed=true;
            processes[shortest].ct=time;
            processes[shortest].tat=processes[shortest].ct-processes[shortest].at;
            processes[shortest].wt=processes[shortest].tat-processes[shortest].bt;
            total_tat+=processes[shortest].tat;
            total_wt+=processes[shortest].wt;
            completed++;
        }
    }
    printf("\nProcess id\t\tArrival\tBurst\tCompletion\tWaiting\tTurnaround");
    for (int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t\t%d\t%d",
        processes[i].pid,
        processes[i].at,
        processes[i].bt,
        processes[i].ct,
        processes[i].wt,
        processes[i].tat);
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
        processes[i].pid=i+1;
        printf("Enter the arrival time of P%d: ",processes[i].pid);
        scanf("%d",&processes[i].at);
        printf("Enter the burst time of P%d: ",processes[i].pid);
        scanf("%d",&processes[i].bt);
    }
    srtf_sch(processes,n);
    return 0;
}