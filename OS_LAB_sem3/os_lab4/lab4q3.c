// orphan process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    pid_t pid=fork();

    if(pid<0){
        perror("Forking failed");
        return 1;
    }
    else if (pid>0){
        printf("Parent process exiting. Pid: %d\n",getpid());
        exit(0);
    }
    else{
        sleep(5);
        printf("Child process (orphan) is now adopted by init. Pid of child: %d. Pid of parent: %d\n",getpid(),getppid());
    }
    return 0;
}