//Inter Process Communucation - Reader Program
//This program attaches to the shared memory segment created by the Writer and reads the data.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(){
    key_t key=ftok("shmfile",65);
    int shmid=shmget(key,SHM_SIZE,0666);

    if (shmid==-1){
        perror("Opening shared memory");
        return 1;
    }
    char *data=(char*)shmat(shmid,NULL,0);
    if (data==(char*)-1){
        perror("Attacthing shared memory");
        return 1;
    }
    printf("Data read from producer: %s",data);
    shmdt(data);

    return 0;
}