/*Fork:
The fork() command is a system call in Unix-based OS that creates a new process by
duplicating the calling process.*/
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from the child process!\n");
    } else {
        // Parent process
        printf("Hello from the parent process! Child PID: %d\n", pid);
    }

    return 0;
}
