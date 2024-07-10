#include <stdio.h>

struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int st;
    int wt;
    int tat;
    int pr;
};

void sortProcesses(struct Process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].at<p[i].at || p[j].at==p[i].at &&p[j].pr<p[i].pr){
                struct Process temp = p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
void calculateTimes(struct Process p[],int n){
    p[0].wt=0;
    p[0].st=p[0].at;
    p[0].ct=p[0].st+p[0].bt;
    
    for(int i=1;i<n;i++){
        p[i].st=p[i-1].ct;
        p[i].ct=p[i].st+p[i].bt;
        p[i].wt=p[i].st-p[i].at;
    }
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
    }
}

void main(){
    int n;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    struct Process p[n];
    printf("enter the (at,bt,priority) \n");
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("P%d: ",p[i].pid);
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
    }
    sortProcesses(p,n);
    calculateTimes(p,n);
    
    
    float awt=0,atat=0;
    printf("\nProcess\tAT\tBT\tP\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at,p[i].bt, p[i].pr, p[i].wt, p[i].tat);
        awt+=p[i].wt;
        atat+=p[i].tat;
        
    }
    printf("AWT=%f\t ATAT=%f",awt/n,atat/n);
    
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[i].pid);
    }
    
    printf("\n%d", p[0].st);
    for (int i = 0; i < n; i++) {
        printf("  %d", p[i].ct);
    }
    printf("\n");
}






