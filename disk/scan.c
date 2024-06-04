#include<stdio.h>
#include<stdlib.h>

void main() {
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move,temp,index;
    printf("Enter the no of requests: ");
    scanf("%d",&n);
    printf("Enter the requests sequence: ");
    for(i=0;i<n;i++) {
        scanf("%d",&RQ[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    printf("Enter total disk size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction(1/0): ");
    scanf("%d",&move);
    
    //Sort the request array
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
            if(RQ[j]>RQ[j+1]) {
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++) {
        if(initial<RQ[i]) {
            index=i;
            break;
        }
    }
    int ind=0;
    int seekSequence[100];
    seekSequence[ind++]=initial;
    //if movement is towards high value
    if(move==1) {
        for(i=index;i<n;i++) {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
            seekSequence[ind++]=initial;
        }
        //last movement for max size
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        initial=size-1;
        seekSequence[ind++]=initial;
        for(i=index-1;i>=0;i--) {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
            seekSequence[ind++]=initial;
        }
    }
    
    //if movement is towards low value
    else{
        for(i=index-1;i>=0;i--) {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
            seekSequence[ind++]=initial;
        }
        //last movement for min size
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        initial=0;
        seekSequence[ind++]=initial;
        for(i=index;i<n;i++) {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
            seekSequence[ind++]=initial;
        }
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    printf("\nseekSequence is: ");
    for(int i=0;i<ind;i++){
        printf("%d  ",seekSequence[i]);
    }
}

/*OUTPUT 
Enter the no of requests: 7
Enter the requests sequence: 82 170 43 140 24 16 190
Enter initial head position: 53
Enter total disk size: 200
Enter the head movement direction(1/0): 0
Total head movement is 243
seekSequence is: 53  43  24  16  0  82  140  170  190
*/
