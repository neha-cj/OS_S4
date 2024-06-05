#include <stdio.h>

void main(){
    int i,j,k,n,f,pf,count=0;
    printf("enter length of refernce string: ");
    scanf("%d",&n);
    int rs[n];
    printf("enter the string\n");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("enter number of frames: ");
    scanf("%d",&f);
    int frame[f];
    
    //set -1 for all frames
    for(i=0;i<f;i++){
        frame[i]=-1;
    }
    
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(frame[k]==rs[i]){ //page hit
                break;
            }
        }
        if(k==f){ //page not in frame page miss
            frame[count++]=rs[i];
            pf++;
        }
        for(j=0;j<f;j++){  //printing currrent contents of frame
            printf("\t%d",frame[j]);
            
        }
        if(k==f){         //writing page fault on side
            printf("\t PF no.%d",pf);
            
        }
        printf("\n");
        if(count==f){               //reset the count value (since in fifo older pages gets replaced)
            count=0;
        }
    }
    printf("\n The number of page faults : %d",pf);
}

//code from devi L r youtube
/*OUTPUT
FIFO Page replacement
enter the length of the refernce string
7
enter the string
1 3 0 3 5 6 3
enter the number of frames
3
page Replaemet...
        1       -1      -1       PF NO.1
        1       3       -1       PF NO.2
        1       3       0        PF NO.3
        1       3       0
        5       3       0        PF NO.4
        5       6       0        PF NO.5
        5       6       3        PF NO.6

 The number of page faults using FIFO : 6
*/
