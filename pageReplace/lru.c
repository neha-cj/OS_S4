#include<stdio.h>
#include <limits.h>
int checkHit(int incoming_page,int queue[],int occupied){
    for(int i=0;i<occupied;i++){
        if(incoming_page==queue[i])
            return 1;
    }
    return 0;
}
void printFrame(int queue[],int occupied){
    for(int i=0;i<occupied;i++)
        printf("%d\t",queue[i]);
}

void main(){
    int incomingStream[20];
    int n,f;
    printf("LRU page Replacement..\n");
    printf("enter the number of pages\n");
    scanf("%d",&n);
    printf("enter the incoming stream\n");
    for(int i=0;i<n;i++)
        scanf("%d",&incomingStream[i]);
    printf("enter the no of frames\n");
    scanf("%d",&f);
    int queue[f];
    int distance[n];
    int occupied=0;
    int pF=0;
    printf("Page\t Frame1\t Frame2\t Frame3\n");
    
    for(int i=0;i<n;i++){  //loop through incoming stram'
        printf("%d:  \t\t",incomingStream[i]);
        if(checkHit(incomingStream[i],queue,occupied)){  //check for hi
            printFrame(queue,occupied);
        }
        else if(occupied<f){        //handle empty frames
            queue[occupied]=incomingStream[i];
            pF++;
            occupied++;
            printFrame(queue,occupied);
        }
        else{                   //handle page replacement using LRU
            int max=INT_MIN;          //to find max distance
            int index;             //store position of frame to be replaces
            
            for(int j=0;j<f;j++){       //for each frame j the distcace since ists last use is calculated
                distance[j]=0;          //keeps track of how many page requests have passed since the frame queue[j] wa last used
                //traverse in reverse to find at what distance frame item occured last
                for(int k=i-1;k>=0;k--){
                    ++distance[j];
                    if(queue[j]==incomingStream[k])
                        break;
                }
                //find frame item with max distance for LRU 
                if(distance[j]>max){ 
                    max=distance[j];      
                    index=j;
                }
                
            }
            queue[index]=incomingStream[i];
            printFrame(queue,occupied);
            pF++;
            
        }
        printf("\n");
    }
    printf("Page Faults: %d",pF);
}
/*OUPTUT
LRU page Replacement..
enter the number of pages
7
enter the incoming stream
1 3 0 3 5 6 3
enter the no of frames
3
Page     Frame1  Frame2  Frame3
1:              1
3:              1       3
0:              1       3       0
3:              1       3       0
5:              5       3       0
6:              5       3       6
3:              5       3       6
Page Faults: 5
*/
