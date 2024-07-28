#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100

struct File {
    char filename[20];
    int start_block;
    int next_block[MAX_BLOCKS]; 
};

// Function to allocate blocks using Linked Allocation
void allocateLinked(struct File* f, const char* filename, int startBlock, int nextBlocks[]) {
    strcpy(f->filename, filename);
    f->start_block = startBlock;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        f->next_block[i] = nextBlocks[i];
    }
}

int main() {
    struct File myfile;
    char filename[20];
    int start;
    int lnkBlocks[MAX_BLOCKS] = { [0 ... 99] = -1 }; // Initialize all blocks to -1 (indicating end of file)
    int numBlocks, nextBlock;

    printf("Enter the filename for Linked Allocation: ");
    scanf("%19s", filename);

    printf("Enter the start block: ");
    scanf("%d", &start);

    printf("Enter the number of blocks: ");
    scanf("%d", &numBlocks);

    // Get the blocks from the user
    printf("Enter the blocks in sequence (-1 to end):\n");
    for (int i = 0; i < numBlocks; i++) {
        int currentBlock;
        printf("Block %d: ", i + 1);
        scanf("%d", &currentBlock);
        if (currentBlock == -1) {
            break;
        }
        if (i == 0) {
            lnkBlocks[start] = currentBlock;
        } else {
            lnkBlocks[nextBlock] = currentBlock;
        }
        nextBlock = currentBlock;
    }
    lnkBlocks[nextBlock] = -1; // Mark the end of the file

    // Allocate linked blocks for the file
    allocateLinked(&myfile, filename, start, lnkBlocks);

    printf("Linked Allocation:\n");
    printf("File Name: %s\n", myfile.filename);
    printf("Start Block: %d\n", myfile.start_block);
    printf("Blocks: ");
    
    int currentBlock = myfile.start_block;
    while (currentBlock != -1) {
        printf("%d -> ", currentBlock);
        currentBlock = myfile.next_block[currentBlock];
    }
    printf("NULL\n");

    return 0;
}
