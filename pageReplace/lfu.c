#include <stdio.h>

int pageIsFound(int f[],int count,int a){
    for(int i=0;i<count;i++){
        if(f[i]==a)
            return 1;
    }
    return 0;
}
int totalAccessed(int arr[],int i,int a){    //calculate how frequenty each page in frame has been accessed
    int count = 0;
    for(int j=i;j>=0;j--){
        if(arr[j]==a)
            count++;
    }
    return count;
}
int recentAccess(int arr[],int i,int a){  //how recently each page in frame was last accesses.
    int count=0;
    for(int j=i;j>=0;j--){
        count++;
        if(arr[j]==a)
            return count;
    }
}
void lfu(int arr[],int n, int f[],int fno){
    int index=-1,count=0,p=0,i,j,k,lfuArr[fno][n];
    
    int temp[fno][2];
    for( i=0;i<n;i++){        //loop iterates over each page requests 
        if(pageIsFound(f,count,arr[i])){}    //check hit..if hit do nothing
        else{      //pf is incremented as miss occurs
            p++;
            if(count == fno){      //no of pages in frames equals the frame size, we need to replace a page.
                int min = n;
                for(k=0;k<fno;k++){    //iterate over each frame 
                    temp[k][1]=totalAccessed(arr,i,f[k]);
                    temp[k][2]=recentAccess(arr,i,f[k]);
                    if(min>temp[k][1]){   //frame with minimum access count 
                        min = temp[k][1];
                        index = k;
                    }
                    else if(min == temp[k][1]){   //if multiple pages with min access count .mostly recently accessed page is selected
                        if(temp[k][2] > temp[index][2])
                            index = k;
                    }
                }
                f[index] = arr[i];   //selected page in frame is replaced with current page
            }
            else{
                f[count++]=arr[i];  //if empty frames, the current page is added to next available frame. count is incremented to keep track of number of pages
            }
        }
        for(j=0,k=0;j<fno;j++){   //loop stores the state of frames after processing eacj page request
            if(k<count)
                lfuArr[k++][i] = f[j];   //lfuArr keeps a record of the frames contents at each step
            else 
                lfuArr[k++][i] = -1;
        }
    }
    for(i=0;i<fno;i++){   //prints the state of each frame over all page requests
        for(j=0;j<n;j++){
            if(lfuArr[i][j] != -1)   //shows how the contents of frames change with each page request
                printf("%d  ",lfuArr[i][j]);
            else 
                printf("   ");
        }
        printf("\n");
    }
    printf("Page Faults(in LFU) = %d\n",p);
}

void main(){
    printf("LFU Page Replacement Algorithm\n");
    int n,i,frameNum;
    printf("Enter the number of frames: ");
    scanf("%d",&frameNum);
    printf("Enter the number of page requests: ");
    scanf("%d",&n);
    printf("Enter the page string each seperated by a space\n");
    int arr[n],F[frameNum];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nPages\n");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nPage Frames\n");
    lfu(arr,n ,F,frameNum);
}

/*OUTPUT 
LFU Page Replacement Algorithm
Enter the number of frames: 3
Enter the number of page requests: 7
Enter the page string each seperated by a space
1 3 0 3 5 6 3

Pages
1  3  0  3  5  6  3  
Page Frames
1  1  1  1  5  5  5  
   3  3  3  3  3  3  
      0  0  0  6  6  
Page Faults(in LFU) = 5
*/
