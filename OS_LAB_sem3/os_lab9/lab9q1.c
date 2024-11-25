// Deadlock avoidance using Banker' algorithm

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n=5,m=3;
    int alloc[5][3],need[5][3],max[5][3],avail[3];
    int finish[n],sequence[n],index=0;
    srand(time(0));

    for (int i=0;i<n;i++){
        finish[i]=0;
        for (int j=0;j<m;j++){
            max[i][j]=rand()%10 +1;
            alloc[i][j]=rand()%(max[i][j]);
        }
    }
    for (int i=0;i<m;i++){
        avail[i]=rand()%10+1;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    //Bankers algorithm
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            if (finish[i]==0){
                int flag=0;
                for (int j=0;j<m;j++){
                    if (need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if (flag==0){
                    sequence[index++]=i;
                    finish[i]=1;
                    for(int y=0;y<m;y++){
                        avail[y]+=alloc[i][y];
                    }
                }
            }
        }
    }
    int safe=1;
    for (int i=0;i<n;i++){
        if (finish[i]==0){
            safe=0;
            printf("The system is not safe.\n");
            break;
        }
    }
    if (safe==1){
        printf("The system is safe and the the sequence is: \n");
        for (int i=0;i<n;i++){
            if (i!=n-1){
                printf("P%d -> ",sequence[i]);
            }
            else{
                printf("P%d\n",sequence[i]);
            }
        }
    }
}