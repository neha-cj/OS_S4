#include <stdio.h>

int main() {
    int num_files;
    printf("Enter the number of files to be allocated: ");
    scanf("%d", &num_files);
    
    int start_address[num_files], length[num_files], blocks[num_files], i, j;
    int allocated_blocks[100]; // Assuming a maximum of 100 blocks for simplicity
    int k=0;
    for(i = 0; i < num_files; i++) {
        printf("Enter the start address of file[%d]: ", i);
        scanf("%d", &start_address[i]);
        printf("Enter the length of the file[%d]: ", i);
        scanf("%d", &length[i]);
        printf("Enter the number of blocks for file[%d]: ", i);
        scanf("%d", &blocks[i]);
        
        printf("Enter the blocks allocated: ");
        for(j = 0; j < blocks[i]; j++) {
            scanf("%d", &allocated_blocks[k]);
            k++;
        }
        
        printf("\n");
    }
    int p=0;
    for(i = 0; i < num_files; i++) {
        printf("file no: %d\n", i);
        printf("no of blocks: %d length: %d\n", blocks[i], length[i]);
        printf("start addr: %d\n", start_address[i]);
        printf("Blocks allocated: ");
        
        for(j = 0; j < blocks[i]; j++) {
            printf("%d ", allocated_blocks[p]);
            p++;
        }
        
        printf("\n\n");
    }
    
    return 0;
}
