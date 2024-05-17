//fork
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t p = fork();

    if (p < 0) {
        perror("fork failed");
        exit(1);
    } else if (p == 0) {
        printf("Hello from Child! (PID: %d)\n", getpid());
        exit(0);  
    } else {
        wait(NULL);  // Wait for the child process to finish
        printf("Hello from Parent! (Child PID: %d)\n", getpid());
    }

    return 0;
}
/*OUPUT
Hello from Child! (PID: 608)
Hello from Parent! (Child PID: 604)
*/

//fork,exec


//opendir ,readdir, closedir
#include <dirent.h> 
#include <stdio.h> 
 int main() 
{ 
 DIR *dir = opendir("."); 
 if (dir) {
 struct dirent *entry; 
 printf("Current Directory Contents\n");
 while ((entry = readdir(dir)) != NULL) 
{ 
 printf("%s\n", entry->d_name); 
 } 
 closedir(dir); } 
 return 0; 
}
/*output

Current Directory Contents
hello.c
main.c
..
.
a.out
*/

