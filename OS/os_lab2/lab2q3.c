#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd=open("exampl.txt",O_RDONLY);
    if(fd==-1){
        perror("Error!\n");
    }
    else{
        printf("Successfully opened file!\n");
    }
    close(fd);
    return 0;
}