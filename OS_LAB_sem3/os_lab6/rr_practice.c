#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int pid;
    int at;
    int bt;
    int rbt;
    int wt;
    int ct;
    int tat;
    bool is_completed;
}Process;

void rr_sch(Process processes[],int n,int tq){
    int time=0,completed=0,front=0,rear=0,queue[100];
    double total_tat=0,total_wt=0;
    for (int i=0;i<n;i++){
        processes[i].rbt=processes[i].bt;
        processes[i].is_completed=false;
    }
    printf("Gantt Chart:\n|");
    while (completed!=n){
        for (int i=0;i<n;i++){
            if (processes[i].at<=time && !processes[i].is_completed){
                int in_queue=0;
                for (int j=front;j<rear;j++){
                    if (i==queue[j]){
                        in_queue=1;
                        break;
                    }
                }
                if (in_queue==0){
                    queue[rear++]=i;
                }
            }
        }
        if (front<rear){
            Process *temp=&processes[queue[front]];
            if(temp->rbt<=tq){
                printf("P%d (%d-%d) | ",temp->pid,time,time+temp->rbt);
                time+=temp->rbt;
                temp->ct=time;
                temp->tat=temp->ct-temp->at;
                temp->wt=temp->tat-temp->bt;
                temp->is_completed=true;
                completed++;
                temp->rbt=0;
                front++;
                total_tat+=temp->tat;
                total_wt+=temp->wt;
            }
            else{
                printf("P%d (%d-%d) | ",temp->pid,time,time+tq);
                
                time+=tq;
                for (int i=0;i<n;i++){
                    if (processes[i].at<time && !processes[i].is_completed){
                        int in_queue=0;
                        for (int j=front;j<rear;j++){
                            if (i==queue[j]){
                                in_queue=1;
                                break;
                            }
                        }
                        if (in_queue==0){
                            queue[rear++]=i;
                        }
                    }
                }
                temp->rbt-=tq;
                queue[rear++]=queue[front];
                front++;
            }
        }
        else time++;
    }
    printf("\nProcess id\tArrival\tBurst\tCompletion\tWaiting\tTurnaround");
    for (int i=0;i<n;i++){
        printf("\n%d\t\t%d\t%d\t%d\t\t%d\t%d",
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
    int n,tq;
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
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    rr_sch(processes,n,tq);
    return 0;
}