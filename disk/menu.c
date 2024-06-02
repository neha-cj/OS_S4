#include <stdio.h>
#include <stdlib.h>

void main(){
    
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move,choice;
    printf("enter no of requests\n");
    scanf("%d",&n);
    printf("enter the request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("enter direction(1/0): ");
    scanf("%d",&move);
    printf("enter initial head position: ");
    scanf("%d",&initial);
    printf("enter size of disk: ");
    scanf("%d",&size);
    while(1){
        printf("Choose(enter a number)\n");
        printf("1 SCAN\n");
        printf("2. C-SCAN\n");
        printf("3.Exit\n");
        scanf("%d",&choice);
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(RQ[j]>RQ[j+1]){
                    int temp=RQ[j];
                    RQ[j]=RQ[j+1];
                    RQ[j+1]=temp;
                }
            }
        }
        int index;
        for(i=0;i<n;i++){
            if(initial<RQ[i]){
                index=i;
                break;
            }
        }
    
        switch(choice){
            case 1: 
                printf("SCAN CPU scheduling..\n ");
                if (move==1){
                    for(i=index;i<n;i++){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                    TotalHeadMoment+=abs(size-RQ[i-1]-1);
                    initial=size-1;
                    for(i=index;i>=0;i--){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                }
                else{
                    for(i=index;i>=0;i--){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial+=RQ[i];
                    }
                    TotalHeadMoment+=abs(RQ[i+1]-0);
                    initial=0;
                    for(i=index;i<n;i++){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                }
                printf("The Total Head Movement is : %d",TotalHeadMoment);
                break;
            
            case 2:
                printf("C-SCAN CPU scheduling....\n");
                if(move==1){
                    for(i=index;i<n;i++){
                        TotalHeadMoment+abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                    TotalHeadMoment+=abs(size-RQ[i-1]-1);
                    TotalHeadMoment+=abs(size-1-0);
                    initial=0;
                    for(i=0;i<index;i++){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                }
                else{
                    for(i=index;i>=0;i--){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                    TotalHeadMoment+=abs(RQ[i+1]-0);
                    TotalHeadMoment+=abs(size-1-0);
                    initial=size-1;
                    for(i=n-1;i>=index;i--){
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                    }
                }
                printf("TotalHeadMoment is %d ",TotalHeadMoment);
                break;
            case 3: 
                exit(0);
        }
    }
}
