#include <stdio.h>

struct Process {
    int processNo;
    int arrivalTime;
    int burstTime;
    int priority;
};

void sortProcesses(struct Process proc[], int n) {
    // Sort processes based on arrival time and priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[j].arrivalTime < proc[i].arrivalTime ||
                (proc[j].arrivalTime == proc[i].arrivalTime && proc[j].priority < proc[i].priority)) {
                // Swap processes
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calculateWaitingTime(struct Process proc[], int wt[], int n) {
    wt[0] = 0; // Waiting time for the first process is zero
    int pstart[n];
    pstart[0]=0;
    for (int i = 1; i < n; i++) {
        pstart[i]=pstart[i-1]+proc[i - 1].burstTime;
        wt[i] = pstart[i]-proc[i].arrivalTime;
    }
}

void calculateTurnaroundTime(struct Process proc[], int wt[], int tat[], int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].burstTime + wt[i];
    }
}

int main() {
    int n;
    printf("Priority scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    int wt[n], tat[n];

    printf("Enter process details (arrival time, burst time, priority):\n");
    for (int i = 0; i < n; i++) {
        proc[i].processNo = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &proc[i].arrivalTime, &proc[i].burstTime, &proc[i].priority);
    }

    // Sort processes based on arrival time and priority
    sortProcesses(proc, n);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(proc, wt, n);
    calculateTurnaroundTime(proc, wt, tat, n);

    // Display results
    float awt=0,atat=0;
    printf("\nProcess\tAT\tBT\tP\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].processNo, proc[i].arrivalTime,
               proc[i].burstTime, proc[i].priority, wt[i], tat[i]);
    awt=awt+wt[i];
    atat=atat+tat[i];
        
    }
  printf("AWT=%f\t ATAT=%f",awt/n,atat/n);
    return 0;
}

/* output
Priority scheduling...
Enter the number of processes: 5
Enter process details (arrival time, burst time, priority):
P1: 0 4 1
P2: 0 3 2
P3: 6 7 1
P4: 11 2 2
P5: 12 4 3

Process AT      BT      P       WT      TAT
P1      0       4       1       0       4
P2      0       3       2       4       7
P3      6       7       1       1       8
P4      11      2       2       3       5
P5      12      4       3       4       8
AWT=2.400000     ATAT=6.400000
*/
