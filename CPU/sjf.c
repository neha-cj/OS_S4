#include <stdio.h>
#include <stdbool.h>

// Structure to represent a process
struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
};

// Function to sort processes based on burst time
void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                // Swap processes[j] and processes[j + 1]
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n, int wt[], int tat[]) {
    wt[0] = 0;
    tat[0] = wt[0] + processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + processes[i - 1].burst_time;
        tat[i] = wt[i] + processes[i].burst_time;
    }
}

// Function to calculate average waiting time and turnaround time
void calculateAvgTimes(struct Process processes[], int n) {
    int wt[n], tat[n];
    calculateTimes(processes, n, wt, tat);

    float avg_wt = 0, avg_tat = 0;
    printf("PID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid,processes[i].arrival_time,processes[i].burst_time,wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", avg_wt / n);
    printf("Average turnaround time = %.2f\n", avg_tat / n);
}

int main() {
    int n;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Get the burst time and arrival time of each process
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }

    // Sort processes based on burst time
    sortProcesses(processes, n);

    // Calculate average waiting time and turnaround time
    calculateAvgTimes(processes, n);

    return 0;
}
/*output
Enter the number of processes: 5
Enter burst time for process 1: 8 
Enter arrival time for process 1: 0
Enter burst time for process 2: 1
Enter arrival time for process 2: 1
Enter burst time for process 3: 3
Enter arrival time for process 3: 2
Enter burst time for process 4: 2
Enter arrival time for process 4: 3
Enter burst time for process 5: 6
Enter arrival time for process 5: 4
PID     AT      BT      WT      TAT
2       1       1       0       1
4       3       2       1       3
3       2       3       3       6
5       4       6       6       12
1       0       8       12      20
Average waiting time = 4.40
Average turnaround time = 8.40
*/
