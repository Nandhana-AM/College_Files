// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>

// int main() {
//     // Open a file for writing, creating it if it doesn't exist
//     int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1) {
//         perror("Error opening file");
//         return 1;
//     }

//     // Define the message to write
//     const char *message = "Hello, World!"; // Make sure to include the full message
//     ssize_t result = write(fd, message, strlen(message)); // Use strlen to get the correct length
//     if (result == -1) {
//         perror("Error writing to file");
//         close(fd);
//         return 1;
//     }

//     // Close the file descriptor
//     close(fd);
//     printf("Message written successfully: %s\n", message); // Print the complete message
//     return 0;
// }


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int fd=open("example.txt",O_WRONLY|O_TRUNC|O_CREAT,0644);
    if(fd==-1) perror("Error opening the file!");
    else{
        const char *message="Hello practical on Friday you are dead :)\n";
        ssize_t result=write(fd,message,strlen(message));
        if (result==-1){
            perror("Error while writing in file!");
            close(fd);
        }
        else{
            close(fd);
            printf("Message succesfully written: %s",message);
        }
    }
    return 0;
}