#include <stdio.h>

struct Proc{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
};


void calculateTimes(struct Proc p[],int n,int order[]){
   int currentTime=0, completed=0;
   int nextP, orderIndex=0;
   while(completed<n){
       int minDuration=9999;
       nextP =-1;
       for(int i=0;i<n;i++){
           if(p[i].at<=currentTime && p[i].bt<minDuration && p[i].ct==0){
               minDuration=p[i].bt;
               nextP=i;
           }
        }
        if(nextP==-1){
            currentTime++;
            continue;
        }
        p[nextP].ct=currentTime+p[nextP].bt;
        p[nextP].tat=p[nextP].ct-p[nextP].at;
        p[nextP].wt=p[nextP].tat-p[nextP].bt;
        currentTime=p[nextP].ct;
        order[orderIndex++]=nextP;
        completed++;
    }
}

void main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int order[n];
    struct Proc p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("enter burst time and arrival times for p%d: ",i+1);
        scanf("%d %d",&p[i].bt,&p[i].at);
        p[i].ct=0;
        p[i].wt=0;
        p[i].tat=0;
    }
    
    calculateTimes(p,n,order);
    double totalWT=0, totalTAT=0;
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, p[i].at, p[i].bt, p[i].ct,p[i].wt, p[i].tat);
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    printf("Average Waiting Time: %.2f mins\n", totalWT / n);
    printf("Average Turnaround Time: %.2f mins\n", totalTAT / n);
    
    printf("\nGantt Chart:\n");
    printf("\n|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |",  p[order[i]].pid);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("   %d", p[order[i]].ct);
    }
    //printf("\n");
}
