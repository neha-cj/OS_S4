#include <stdio.h>
struct Proc{
    int pid;
    int at;
    int bt;
    int rt; //remaining bt
    int ct;
    int wt;
    int tat;
};

void calculateTimes(struct Proc p[],int n,int order[],int *totalTime){
    int currentTime=0,completed=0;
    int nextP=-1,orderIndex=0;
    while(completed<n){
        nextP=-1;
        int minDuration=9999;
        for(int i=0;i<n;i++){
            if(p[i].at<=currentTime&&p[i].rt<minDuration&&p[i].rt>0){
                minDuration=p[i].rt;
                nextP=i;
            }
        }
        if(nextP==-1){
            currentTime++;
            continue;
        }
        p[nextP].rt--;
        currentTime++;
        order[orderIndex++]=nextP;
        if(p[nextP].rt==0){
            completed++;
            p[nextP].ct=currentTime;
            p[nextP].tat=p[nextP].ct-p[nextP].at;
            p[nextP].wt=p[nextP].tat-p[nextP].bt;
        }
        
    }
    *totalTime=currentTime;
}

void main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int order[n*100]; //overestimate to store order of execeution
    struct Proc p[n];
    int totalTime;
    
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("enter arrival time and burst times for p%d: ",i+1);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;//initial remaining bt
        p[i].ct=0;
        p[i].wt=0;
        p[i].tat=0;
    }
    calculateTimes(p,n,order,&totalTime);
    double totalWT=0,totalTAT=0;
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
        totalTAT+=p[i].tat;
        totalWT+=p[i].wt;
    } 
    printf("Average Waiting Time: %.2f mins\n", totalWT / n);
    printf("Average Turnaround Time: %.2f mins\n", totalTAT / n);

    printf("\nGantt Chart:\n");
    printf("\n|");
    for (int i = 0; i < totalTime; i++) {
        if (i == 0 || order[i] != order[i - 1]) {
            printf(" (%d) P%d |", i,p[order[i]].pid);
        }
    }
    printf("\n");
    
    printf("  %d\n", totalTime);

}
