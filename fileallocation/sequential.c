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
