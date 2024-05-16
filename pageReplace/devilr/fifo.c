#include <stdio.h>
void main(){
    int i,j,k,n,f,pf,count=0;
    printf("enter the length of the refernce string\n");
    scanf("%d",&n);
    int rs[n];
    printf("enter the string\n");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("enter the number of frames\n");
    scanf("%d",&f);
    int m[f];
    for(i=0;i<f;i++){
        m[i]=-1;
    }
    printf("page Replaemet...\n");
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==rs[i]){
                break;
            }
        }
        if(k==f){
            m[count++]=rs[i];
            pf++;
        }
    for(j=0;j<f;j++)
     printf("\t%d",m[j]);
        
    if(k==f)
     printf("\t PF NO.%d",pf);
     printf("\n");
    if(count==f)
    count=0;
        
    }
     printf("\n The number of page faults using FIFO : %d",pf);
    
}

//code from devi L r youtube
/*OUTPUT
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
