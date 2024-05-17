#include <stdio.h>

struct Process{
    int id;
    int bt;
};

void roundRobin(struct Process proc[],int n,int time_q){
    int remaining_time[n];
    int wt[n],tat[n];
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
                    printf("Process P%d completed at time %d\n",proc[i].id,current_time);
                    tat[i]=current_time;
                    wt[i]=tat[i]-proc[i].id;
                    printf("Process P%d WT =%d TAT=%d \n",proc[i].id,wt[i],tat[i]);
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
    
    float awt=0;
    float atat=0;
    for(int i=0;i<n;i++){
        awt+=wt[i];
        atat+=tat[i];
    }
    printf("Average Waiting time %f,Average TurnaroundTime =%f",awt/n,atat/n);
    
}

void main(){
    int n,time_q;
    printf("Round Robin Scheduling..\n");
    printf("enter the number of processes: ");
    scanf("%d",&n);
    struct Process proc[n];
    printf("enter the time quanta\n");
    scanf("%d",&time_q);
    
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
    }
    roundRobin(proc,n,time_q);
    
}

/*Output 
Round Robin Scheduling..
enter the number of processes: 5
enter the time quanta
2
Enter burst time for process 1: 8
Enter burst time for process 2: 4
Enter burst time for process 3: 3
Enter burst time for process 4: 7
Enter burst time for process 5: 1
Process P5 completed at time 9
Process P5 WT =4 TAT=9 
Process P2 completed at time 13
Process P2 WT =11 TAT=13 
Process P3 completed at time 14
Process P3 WT =11 TAT=14 
Process P1 completed at time 22
Process P1 WT =21 TAT=22 
Process P4 completed at time 23
Process P4 WT =19 TAT=23 
Average Waiting time 13.200000,Average TurnaroundTime =16.200001
*/
