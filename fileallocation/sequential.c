#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of blocks (assuming 100 blocks)
#define MAX_BLOCKS 100

// Structure to represent a file
struct File {
    char filename[20];
    int start_block;
    int num_blocks;
};

// Function to allocate contiguous blocks for a file
void allocateContiguous(struct File* file, const char* filename,int startBlock,int numBlocks) {
    strcpy(file->filename, filename);  // Set the file name
    file->start_block = startBlock;    // Set the start block
    file->num_blocks = numBlocks;      // Set the number of blocks
}

int main() {
    struct File myFile;
    char filename[20];
    int start,num;

    
    printf("Enter the filename: ");
    scanf("%s", filename); 
    
    printf("Enter the start block: ");
    scanf("%d",&start);
    
    printf("enter the number of blocks: ");
    scanf("%d",&num);

    // Allocate contiguous blocks starting from block 10
    allocateContiguous(&myFile, filename,start,num);

    // Display file details
    printf("File Name: %s\n", myFile.filename);
    printf("Start Block: %d\n", myFile.start_block);
    printf("Number of Blocks: %d\n", myFile.num_blocks);

    return 0;
}
//better method
#include<stdio.h>
#include<stdlib.h>

void main(){
    int n, i, j, b[20], sb[20], mem[100], ch, count=0;
    for (i=0 ; i<100 ; i++)
        mem[i]=0;
    for (i=0 ; i<20 ; i++){
        b[i]=0;
        sb[i]=0;
    }
    do{
        count++;
        printf("\nEnter the number of blocks occupied by file %d: ", count);
        scanf("%d", &b[count]);
        int success = 0;
        while (!success) {
            success = 1;
            printf("\nEnter the starting block of file %d: ", count);
            scanf("%d", &sb[count]);
            for (j=sb[count] ; j<(sb[count]+b[count]) ; j++){
                if (mem[j] == 0){
                    mem[j]=j;
                    printf("Block %d has been allocated for file %d\n", j, count);
                }
                else{
                    printf("\nBlock %d is already allocated", j);
                    printf("\nTry again!!\n");
                    for (int k=sb[count] ; k<j ; k++)
                        mem[k]=0;
                    success = 0;
                    break;
                }
            }
        }
        printf("\nFile Allocation Successful\n");
        printf("\nPress 1 to continue allocation, Press 0 to stop allocation: ");
        scanf("%d", &ch);
    }
    while (ch==1);
    printf("\nFile\tStart\tBlock Length\n");
    for (j=1 ; j<=count ; j++)
        printf("%2d %9d %10d\n", j, sb[j], b[j]);
}
/*OUTPT
Enter the number of blocks occupied by file 1: 3

Enter the starting block of file 1: 3
Block 3 has been allocated for file 1
Block 4 has been allocated for file 1
Block 5 has been allocated for file 1

File Allocation Successful

Press 1 to continue allocation, Press 0 to stop allocation: 1

Enter the number of blocks occupied by file 2: 2

Enter the starting block of file 2: 4

Block 4 is already allocated
Try again!!

Enter the starting block of file 2: 6
Block 6 has been allocated for file 2
Block 7 has been allocated for file 2

File Allocation Successful

Press 1 to continue allocation, Press 0 to stop allocation: 0

File    Start   Block Length
 1         3          3
 2         6          2
*/
