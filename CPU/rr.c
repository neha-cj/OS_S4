// better method
#include <stdio.h>

struct Process{
    int id;
    int bt;
    int at;
    int wt;
    int tat;
    int ct;
};

void roundRobin(struct Process proc[],int n,int time_q){
    int remaining_time[n];
    //int wt[n],tat[n];
    for(int i=0;i<n;i++){
        remaining_time[i]=proc[i].bt;
    }
    int current_time=0;
    int completed=0;
    
    while(completed<n){
        int flag=0;
        for(int i=0;i<n;++i){
            if(remaining_time[i]>0){
                flag=1;
                if(remaining_time[i]<=time_q){
                    current_time+=remaining_time[i];
                    remaining_time[i]=0;
                    proc[i].ct=current_time;
                   
                    proc[i].tat=proc[i].ct-proc[i].at;
                    proc[i].wt=proc[i].tat-proc[i].bt;
                   
                    completed++;
                }
                else{
                    current_time+=time_q;
                    remaining_time[i]-=time_q;
                }
            }
            
        }
        if(!flag)
            break;
    }
    
}

void main(){
    int n,time_q;
    printf("Round Robin Scheduling..\n");
    printf("enter the number of processes: ");
    scanf("%d",&n);
    struct Process proc[n];
    printf("enter the time quanta: ");
    scanf("%d",&time_q);
    
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter the arrival time for process %d: ",i+1);
        scanf("%d",&proc[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
    }
    roundRobin(proc,n,time_q);
    float awt=0;
    float atat=0;
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,proc[i].at,proc[i].bt,proc[i].ct,proc[i].wt,proc[i].tat);
        awt+=proc[i].wt;
        atat+=proc[i].tat;
    }
 
    printf("Average Waiting time %f,Average TurnaroundTime =%f",awt/n,atat/n);
    
    
}

