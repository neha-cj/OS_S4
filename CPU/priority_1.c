#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int priority;
    int wt;
    int tat;
};

void sortProcesses(struct Process proc[], int n) {
    // Sort processes based on arrival time and priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc[j].at< proc[i].at ||
                (proc[j].at == proc[i].at && proc[j].priority < proc[i].priority)) {
                // Swap processes
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process proc[],int n) {
    proc[0].wt=0;
    int pstart[n];
    pstart[0]=0;
    for (int i = 1; i < n; i++) {
        pstart[i]=pstart[i-1]+proc[i - 1].bt;
        proc[i].wt = pstart[i]-proc[i].at;
        
    }
    for(int i=0;i<n;i++){
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}



int main() {
    int n;
    printf("Priority scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    printf("Enter process details (arrival time, burst time, priority):\n");
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &proc[i].at, &proc[i].bt, &proc[i].priority);
    }

    // Sort processes based on arrival time and priority
    sortProcesses(proc, n);

    // Calculate waiting time and turnaround time
    calculateTimes(proc,n);
  

    // Display results
    float awt=0,atat=0;
    printf("\nProcess\tAT\tBT\tP\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].at,proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
        awt+=proc[i].wt;
        atat+=proc[i].tat;
        
    }
    printf("AWT=%f\t ATAT=%f",awt/n,atat/n);
    return 0;
}

