#include <stdio.h>
#include <string.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (best== -1)
                    best = j;
                else if (blockSize[best] > blockSize[j])
                    best = j;
            }
        }
        if (best!= -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("Free Blocks\n");
    for (int i = 0; i < m; i++) printf("%d->",blockSize[i]);
}
int main() {
    int m, n;
    printf("Best Fit Allocation\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &m);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int blockSize[m], processSize[n];

    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}
/*ouptut
Best Fit Allocation
Enter the number of blocks: 5
Enter the number of processes: 4
Enter the sizes of the blocks:
Block 1: 100
Block 2: 500
Block 3: 200
Block 4: 300
Block 5: 600
Enter the sizes of the processes:
Process 1: 212
Process 2: 417
Process 3: 112
Process 4: 426

Process No.     Process Size    Block no.
 1              212             4
 2              417             2
 3              112             3
 4              426             5
Free Blocks
100->83->88->88->174->
*/
