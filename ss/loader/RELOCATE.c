#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp1, *fpOut; // File pointers for input and output files
    int i, hexaddr, start_hexaddr;
    char line[50], addr[10];

    // Open input file for reading
    fp1 = fopen("input.txt", "r");
    if (fp1 == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open output file for writing
    fpOut = fopen("output.txt", "w");
    if (fpOut == NULL) {
        perror("Error opening output file");
        fclose(fp1);
        return 1;
    }

    // Get the starting address from the user
    printf("Enter the actual starting address: ");
    scanf("%x", &start_hexaddr);

    // Read each line from the input file
    while (fscanf(fp1, "%s", line) == 1) {
        if (line[0] == 'T') {
            // Extract the address portion from the T-record
            strncpy(addr, &line[1], 6);
            addr[6] = '\0';

            // Convert the extracted address to an integer
            sscanf(addr, "%x", &hexaddr);

            // Write relocated addresses and object code to output file
            i = 9; // Start after the address and length fields in T-record
            while (line[i] != '\0') {
                // Write to the output file instead of printing to console
                fprintf(fpOut, "%x \t %c%c\n", hexaddr + start_hexaddr, line[i], line[i + 1]);
                hexaddr += 1; // Move to the next address
                i += 2; // Move to the next byte in the T-record
            }
        }
    }

    // Close files
    fclose(fp1);
    fclose(fpOut);

    printf("Data written to output.txt successfully.\n");
    return 0;
}
/*//input.txt
HCOPY 000000000232
T0000001114203348303910203642033483039100203
T0020000C298300230000282030302015
E001000
output.txt
3000 	 14
3001 	 20
3002 	 33
3003 	 48
3004 	 30
3005 	 39
3006 	 10
3007 	 20
3008 	 36
3009 	 42
300a 	 03
300b 	 34
300c 	 83
300d 	 03
300e 	 91
300f 	 00
3010 	 20
3011 	 3

  */
