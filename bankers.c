#include<stdio.h>

int main() {
    printf("Bankers ALgorithm\n");
    int P,R;
    printf("Enter the number of processes: ");
    scanf("%d",&P);
    printf("Enter the number of resources: ");
    scanf("%d",&R);
    int available[R];
    printf("Enter the available resources vector\n");
    for(int i=0;i<R;i++)
        scanf("%d",&available[i]);
    int allot[P][R];
    int max[P][R];
    int need[P][R];
    printf("Enter the allocation matrix\n");
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            scanf("%d",&allot[i][j]);
        }
    }
    printf("Enter the max matrix\n");
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            scanf("%d",&max[i][j]);
        }
    }
    int ind=0;
    int safeSequence[P],finish[P];
    for(int i=0;i<P;i++)
        finish[i]=0; //set every process finish to false
    
    printf("Resource need\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
            printf("%2d ",need[i][j]);
        }
        printf("\n");
    }
    int work[R];
    for (int i = 0; i < R; i++) {
        work[i] = available[i];   //set work as available
    }
    
    //int count=0;
    //find i such such that finish[i]=false and need<=work
    
    for(int k=0;k<P;k++){
        for(int i=0;i<P;i++)
        {
            if(finish[i]==0){
                int flag =0;
                
                for(int j=0;j<R;j++){
                    
                    if(need[i][j]>work[j]){
                        flag=1;break;            //exit
                    }
                }
                if(flag==0){
                    safeSequence[ind++]=i;
                    for(int y=0;y<R;y++)
                        work[y]+=allot[i][y];
                    finish[i]=1;
                }
            }
        }
    }
    printf("\nFollowing is the Safe sequence\n");
    for(int i=0;i<=P-1;i++)
        printf(" P%d ",safeSequence[i]);

    return 0;
}

/*
        OUTPUT
Bankers ALgorithm
Enter the number of processes: 5
Enter the number of resources: 4
Enter the available resources vector
1 5 2 0
Enter the allocation matrix
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Enter the max matrix
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Resource need
 0  0  0  0 
 0  7  5  0 
 1  0  0  2 
 0  0  2  0 
 0  6  4  2 

Following is the Safe sequence
 P0  P2  P3  P4  P1 

*/
