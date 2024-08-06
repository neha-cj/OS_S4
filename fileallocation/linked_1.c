#include <stdio.h>

int main() {
    int allocatedBlocks[100] = {0}; // Array to keep track of allocated blocks
    int numAllocated, block, choice, numToAllocate, startBlock,cnt=0;

    printf("Enter the number of blocks which are already allocated:\n");
    scanf("%d", &numAllocated);

    printf("Enter the blocks which are already allocated:\n");
    for (int i = 0; i < numAllocated; i++) {
        scanf("%d", &block);
        allocatedBlocks[block] = 1;
    }

    while (1) {
        printf("1. add file 2. exit:\n");
        scanf("%d", &choice);

        if (choice == 2) break;

        printf("Enter the no of blocks to be allocated and starting block:\n");
        scanf("%d %d", &numToAllocate, &startBlock);

        for (int i = 0; i < numToAllocate; i++) {
            while(1){
                if (allocatedBlocks[startBlock + cnt] == 0) {
                    allocatedBlocks[startBlock + cnt] = 1;
                    printf("bno: %d --->1\n", startBlock + cnt);
                    break;
                }
                cnt++;
            }
        }
    }

    return 0;
}
