#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);

    if (fork() == 0) {
        // Child process
        char *str = (char*) shmat(shmid, (void*)0, 0);
        printf("Enter some data to write to shared memory: ");
        fgets(str, SHM_SIZE, stdin);
        shmdt(str);
    } else {
        // Parent process
        wait(NULL);
        char *str = (char*) shmat(shmid, (void*)0, 0);
        printf("Data read from shared memory: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

/*Output 
Enter some data to write to shared memory: hallo World
Data read from shared memory: hallo World*/
