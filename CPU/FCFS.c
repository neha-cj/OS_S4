#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[],int at[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = at[i-1]+ wt[i - 1]+bt[i - 1] -at[i];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[],int at[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = wt[i]+bt[i];
}

void findAvgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt,at);
    findTurnAroundTime(processes, n, bt, wt,at, tat);

    printf("Processes\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, at[i],bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n],burst_time[n],arrival_time[n];
    printf("Enter burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    findAvgTime(processes, n, burst_time, arrival_time);
    return 0;
}

/* Output
FCFS CPU Scheduling..
Enter the number of processes: 5
Enter burst time and arrival time for each process:
Process 1 burst time: 8
Process 1 arrival time: 0
Process 2 burst time: 1
Process 2 arrival time: 1
Process 3 burst time: 3
Process 3 arrival time: 2
Process 4 burst time: 2
Process 4 arrival time: 3
Process 5 burst time: 6
Process 5 arrival time: 4
Processes       Arrival time    Burst time      Waiting time    Turnaround time
1               0               8               0      8
2               1               1               7      8
3               2               3               7      10
4               3               2               9      11
5               4               6               10     16
Average waiting time = 6.60
Average turnaround time = 10.60
*/
