#include <stdio.h>
#include <stdlib.h>
int main(){
    int RQ[100],i,n,TotalHeadMoment =0,initial;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the requests sequence\n");
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    
    for(i=0;i<n;i++){
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("Total head moment is %d",TotalHeadMoment);
    return 0;
}

/*OUTPUT
Enter the number of requests
8
Enter the requests sequence
98 183 37 122 14 124 65 67
Enter initial head position
53
Total head moment is 640
*/
