#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_INDEX_BLOCKS 10

// Structure to represent a file in Indexed Allocation
struct IndexedFile {
    char filename[20];
    int index_block;
    int blocks[MAX_INDEX_BLOCKS]; // Array to store pointers to data blocks
};

// Function to allocate blocks using Indexed Allocation
void allocateIndexed(struct IndexedFile* f, const char* filename, int indexBlock, int numBlocks, int dataBlocks[]) {
    strcpy(f->filename, filename);
    f->index_block = indexBlock;
    for (int i = 0; i < numBlocks; i++) {
        f->blocks[i] = dataBlocks[i];
    }
    for (int i = numBlocks; i < MAX_INDEX_BLOCKS; i++) {
        f->blocks[i] = -1; // Indicate end of blocks with -1
    }
}

int main() {
    struct IndexedFile myfile;
    char filename[20];
    int indexBlock;
    int numBlocks;
    int dataBlocks[MAX_INDEX_BLOCKS];

    // Get the filename from the user
    printf("Enter the filename for Indexed Allocation: ");
    scanf("%19s", filename);

    // Get the index block from the user
    printf("Enter the index block: ");
    scanf("%d", &indexBlock);

    // Get the number of data blocks from the user
    printf("Enter the number of data blocks: ");
    scanf("%d", &numBlocks);

    // Ensure the number of blocks does not exceed MAX_INDEX_BLOCKS
    if (numBlocks > MAX_INDEX_BLOCKS) {
        printf("Number of blocks exceeds the maximum limit of %d\n", MAX_INDEX_BLOCKS);
        return 1;
    }

    // Get the data blocks from the user
    printf("Enter the data blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &dataBlocks[i]);
    }

    // Allocate indexed blocks for the file
    allocateIndexed(&myfile, filename, indexBlock, numBlocks, dataBlocks);

    // Display the file allocation details
    printf("Indexed Allocation:\n");
    printf("File Name: %s\n", myfile.filename);
    printf("Index Block: %d\n", myfile.index_block);
    printf("Data Blocks: ");
    for (int i = 0; i < numBlocks; i++) {
        printf("%d ", myfile.blocks[i]);
    }
    printf("\n");

    return 0;
}


//simpler

#include <stdio.h>
#include <string.h>

#define MAX_INDEX_BLOCKS 10

struct IndexedFile {
    char filename[20];
    int index_block;
    int blocks[MAX_INDEX_BLOCKS];
};

int main() {
    struct IndexedFile file;
    int numBlocks;

    // Get file name from user
    printf("Enter the filename: ");
    scanf("%s", file.filename);

    // Get index block from user
    printf("Enter the index block: ");
    scanf("%d", &file.index_block);

    // Get the number of data blocks
    printf("Enter the number of data blocks (max %d): ", MAX_INDEX_BLOCKS);
    scanf("%d", &numBlocks);

    // Ensure the number of blocks does not exceed MAX_INDEX_BLOCKS
    if (numBlocks > MAX_INDEX_BLOCKS) {
        printf("Error: Number of blocks exceeds the maximum limit of %d\n", MAX_INDEX_BLOCKS);
        return 1;
    }

    // Get data blocks from user
    printf("Enter the data blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &file.blocks[i]);
    }

    // Mark remaining blocks as -1 (unused)
    for (int i = numBlocks; i < MAX_INDEX_BLOCKS; i++) {
        file.blocks[i] = -1;
    }

    // Display file allocation details
    printf("\nIndexed Allocation:\n");
    printf("File Name: %s\n", file.filename);
    printf("Index Block: %d\n", file.index_block);
    printf("Data Blocks: ");
    for (int i = 0; i < numBlocks; i++) {
        printf("%d ", file.blocks[i]);
    }
    printf("\n");

    return 0;
}
/*output
Enter the filename: file1
Enter the index block: 10
Enter the number of data blocks (max 10): 3
Enter the data blocks:
Block 1: 5
Block 2: 12
Block 3: 18

Indexed Allocation:
File Name: file1
Index Block: 10
Data Blocks: 5 12 18
*/
