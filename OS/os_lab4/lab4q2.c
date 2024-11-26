// zombie process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid=fork();

    if (pid<0){
        perror("Fork creation failed");
        return 1;
    }
    else if (pid>0){
        printf("Parent process is going to sleep. Pid: %d\n",getpid());
        sleep(10);
        printf("Parent process has woken up\n");
    }
    else if (pid==0){
        printf("Child process exiting. Pid: %d\n",getpid());
        exit(0);
    }
    wait(NULL);
    printf("Parent has reaped the child process. Pid: %d\n",getpid);
    return 0;
}