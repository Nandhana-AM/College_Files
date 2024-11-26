//Inter Process Communication - Writer Program 
//This program creates a shared memory segment, attaches it, writes a message to it, and then detaches it.
//create key, create shm, attatch shm, write
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 

int main(){
    key_t key=ftok("shmfile",65);
    int shmid=shmget(key,SHM_SIZE,IPC_CREAT|0666);
    
    if (shmid==-1){
        perror("Creation of shared memory");
        return 1;
    }
    char *data=(char*) shmat(shmid,NULL,0);
    if (data==(char*)-1){
        perror("Attatching shared memory");
        return 1;
    }
    char str[50];
    printf("Enter to write in shm: ");
    fgets(str,50,stdin);
    strcpy(data,str);
    shmdt(data);
    return 0;
}