#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID=%d, Parent PID=%d\n", getpid(), getppid());
        
        // Replace the current process with a new program
        // Example: execute 'ls' command
        execlp("ls", "ls", NULL);

        // If execlp() fails
        perror("execlp failed");
        exit(1);
    } else {
        
        wait(NULL);// Parent process
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), pid);
        
        // Wait for the child process to finish
        wait(NULL);
        
        printf("Child process completed.\n");
    }

    return 0;
}
