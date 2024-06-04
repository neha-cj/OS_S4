
/*scenario: You are managing a car wash service. Cars arrive at different times, and each car takes a different 
amount of time to wash. You decide to use the Shortest Job Next scheduling algorithm to minimize the waiting time for all customers.

Describe how the Shortest Job Next scheduling algorithm would be implemented in this context.
Given the following car arrival times and wash durations: Car1 (arrival at 0 mins, takes 8 mins), 
Car2 (arrival at 1 min, takes 4 mins), Car3 (arrival at 2 mins, takes 9 mins), Car4 (arrival at 3 mins, takes 5 mins),
simulate the car wash schedule using SJN.
Calculate the average waiting time and average turnaround time for the cars.

*/

#include <stdio.h>

 

typedef struct {
    int arrivalTime;
    int burstTime;
    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateTimes(Process cars[],int n) {
    int currentTime = 0;
    int finishedCars = 0;
    int nextCarIndex;

    while (finishedCars < n) {
        int minDuration = 9999;
        nextCarIndex = -1;

        for (int i = 0; i < n; i++) {
            if (cars[i].arrivalTime <= currentTime && cars[i].burstTime < minDuration && cars[i].finishTime == 0) {
                minDuration = cars[i].burstTime;
                nextCarIndex = i;
            }
        }

        if (nextCarIndex == -1) {
            currentTime++;
            continue;
        }

        cars[nextCarIndex].startTime = currentTime;
        cars[nextCarIndex].finishTime = currentTime + cars[nextCarIndex].burstTime;
        cars[nextCarIndex].waitingTime = cars[nextCarIndex].startTime - cars[nextCarIndex].arrivalTime;
        cars[nextCarIndex].turnaroundTime = cars[nextCarIndex].finishTime - cars[nextCarIndex].arrivalTime;

        currentTime = cars[nextCarIndex].finishTime;
        finishedCars++;
    }
}

int main() {
    int NUM;
    printf("enter the number of cars: ");
    scanf("%d",&NUM);
    Process cars[NUM];

    // Taking user input for car details
    for (int i = 0; i < NUM; i++) {
        printf("Enter arrival time P%d: ", i + 1);
        scanf("%d", &cars[i].arrivalTime);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &cars[i].burstTime);
        // Initializing other fields
        cars[i].startTime = 0;
        cars[i].finishTime = 0;
        cars[i].waitingTime = 0;
        cars[i].turnaroundTime = 0;
    }

    calculateTimes(cars,NUM);

    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    printf("\nCar\tArrival\tWash\tStart\tFinish\tWaiting\tTurnaround\n");
    for (int i = 0; i < NUM; i++) {
        printf("Car%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, cars[i].arrivalTime, cars[i].burstTime, cars[i].startTime, cars[i].finishTime, cars[i].waitingTime, cars[i].turnaroundTime);
        totalWaitingTime += cars[i].waitingTime;
        totalTurnaroundTime += cars[i].turnaroundTime;
    }

    printf("Average Waiting Time: %.2f mins\n", totalWaitingTime / NUM);
    printf("Average Turnaround Time: %.2f mins\n", totalTurnaroundTime / NUM);

    return 0;
}


