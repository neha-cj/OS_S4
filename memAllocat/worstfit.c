#include <stdio.h>
#include <string.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++) {
        int wst = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wst == -1 || blockSize[wst] < blockSize[j])
                    wst = j;
            }
        }
        if (wst!= -1) {
            allocation[i] = wst;
            blockSize[wst] -= processSize[i];
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
    printf("Worst Fit Allocation\n");
    int m,n;
    printf("enter number of blocks: ");
    scanf("%d", &m);
    printf("enter number of process: ");
    scanf("%d",&n);
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
    worstFit(blockSize, m, processSize, n);
    return 0;
}

/*OUPUT
Worst Fit Allocation
enter number of blocks: 5
enter number of process: 4
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
 1              212             5
 2              417             2
 3              112             5
 4              426             Not Allocated
Free Blocks
100->83->200->300->276->

*/
