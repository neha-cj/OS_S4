
//easier method
#include <stdio.h>

struct file {
    char name[20];
    int sb;      // Starting block
    int length;  // Number of blocks
};

int main() {
    int n, i;
    struct file f[20];  // Array of files to store information

    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &n);

    // Input the details for each file
    for (i = 0; i < n; i++) {
        printf("\nEnter the name of file %d: ", i + 1);
        scanf("%s", f[i].name);
        printf("Enter the starting block of file %s: ", f[i].name);
        scanf("%d", &f[i].sb);
        printf("Enter the number of blocks occupied by file %s: ", f[i].name);
        scanf("%d", &f[i].length);
    }

    // Display file allocation
    printf("\nFile\tStart\tLength\tBlocks\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].name, f[i].sb, f[i].length);
        for (int j = 0; j < f[i].length; j++) {
            printf("%d ", f[i].sb + j);  // Sequentially display allocated blocks
        }
        printf("\n");
    }

    return 0;
}
/*output
Enter the number of files: 3

Enter the name of file 1: file1
Enter the starting block of file file1: 0
Enter the number of blocks occupied by file file1: 5

Enter the name of file 2: file2
Enter the starting block of file file2: 6
Enter the number of blocks occupied by file file2: 3

Enter the name of file 3: file3
Enter the starting block of file file3: 10
Enter the number of blocks occupied by file file3: 4
File    Start   Length  Blocks
file1   0       5       0 1 2 3 4 
file2   6       3       6 7 8 
file3   10      4       10 11 12 13
*/
