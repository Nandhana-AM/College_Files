#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // Open the file "example.txt" for reading
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1; // Exit with an error code
    }

    char buffer[128];
    ssize_t bytes_read;

    // Read the file content in a loop
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("%s", buffer); // Print the buffer content
    }

    // Check for errors during reading
    if (bytes_read == -1) {
        perror("Error reading file");
    }

    // Close the file descriptor
    close(fd);
    return 0; // Exit successfully
}
