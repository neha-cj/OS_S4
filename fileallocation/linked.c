#include<stdio.h>
#include<stdlib.h>
int main() 
{ 
    int f[50],p,a,st,len,n,c;
    for(int i=0;i<50;i++)
        f[i]=0; //initialize all blocks to 0 (unallocated)
    printf("Enter how many blocks that are already allocated :");
    scanf("%d",&p);
    if(p!=0)
    {
        printf("\nEnter the blocks no.s that are already allocated :");
        for(int i=0;i<p;i++)
        {
            scanf("%d",&a);
            f[a]=1; //allocate the blocks
        }
    }
    do{
        printf("Enter the starting index block & length :");
        scanf("%d%d",&st,&len);
        int k=len;

        for(int j=st;j<(k+st);j++)
        {
            if(f[j]==0)
            {
                f[j]=1;
                printf("\n%d->%d",j,f[j]);
            }
            else
            { 
                printf("\n %d->file is already allocated",j);
                k++;
            }
        }
        printf("\n If u want to enter one more file? (yes-1/no-0)");
        scanf("%d",&c);
    }while(c==1);
    
}

//another method
#include<stdio.h>
#include<stdlib.h>

int main() { 
    int f[50], st, len, n, k, j, nextBlock[50];

    // Initialize all blocks as free (0) and pointers as -1 (no next block)
    for(int i = 0; i < 50; i++) {
        f[i] = 0;           // 0 means free, 1 means allocated
        nextBlock[i] = -1;   // -1 means no next block
    }

    // Pre-allocated blocks
    int p,allocated;
    printf("Enter the number of blocks which are already allocated: ");
    scanf("%d", &p);
    if (p != 0) {
        printf("\nEnter the blocks which are already allocated: ");
        for (i = 0; i < p; i++) {
            scanf("%d", &allocated);
            f[allocated] = 1;  // allocate the blocks
        }
    }
    int ch;
    printf("\n1. Add file \t2. Exit\n");
    scanf("%d", &ch);
        
    // Main menu loop
    while (ch != 2) {
        if (ch == 1) {
            printf("Enter the starting block and length of the file: ");
            scanf("%d%d", &st, &len);

            // Check if starting block is available
            if (f[st] == 1) {
                printf("Starting block is already allocated, try another block.\n");
            } else {
                int count = 0;
                int prev = -1;
                for (j = 0; j < 50 && count < len; j++) {
                    if (f[j] == 0) {  // if block is free
                        f[j] = 1;     // allocate the block
                        count++;

                        if (prev != -1) {
                            nextBlock[prev] = j;  // link previous block to current
                        }
                        prev = j;
                    }
                }

                if (count == len) {
                    printf("\nFile allocated successfully!\n");
                    printf("Start block: %d\n", st);
                    printf("Blocks: ");
                    int temp = st;
                    while (temp != -1) {
                        printf("%d->", temp);
                        temp = nextBlock[temp];  // follow the linked blocks
                    }
                    printf("\n");
                } else {
                    printf("Not enough free blocks available to allocate the file.\n");
                }
            }
        } else if (ch == 2) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }

        printf("\n1. Add file\t2. Exit\n");
        scanf("%d", &ch);
    }

    return 0;
}
/*output
Enter the number of blocks which are already allocated: 2

Enter the blocks which are already allocated: 1 4

1. Add file     2. Exit
1
Enter the starting block and length of the file: 2 6

File allocated successfully!
Start block: 2
Blocks: 2->3->5->6->7->

1. Add file     2. Exit
2
*/

