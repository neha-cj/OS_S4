#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp, *fpOut; // File pointers for input and output files
    int i, j, stdaddr1;
    char line[50], name1[50], staddr[10];

    // Open the input file for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file for writing
    fpOut = fopen("output.txt", "w");
    if (fpOut == NULL) {
        perror("Error opening output file");
        fclose(fp);
        return 1;
    }

    // Read the header record
    fscanf(fp, "%s", line); // Read first line (header record)
    for (i = 2, j = 0; line[i] != '^'; i++, j++) {
        name1[j] = line[i]; // Store program name from header record
    }
    name1[j] = '\0'; // Null-terminate the string

    // Write program name to the output file
    fprintf(fpOut, "Program name: %s\n", name1);

    // Process each line in the file
    while (fscanf(fp, "%s", line) != EOF) {
        if (line[0] == 'T') {
            // Parse the starting address from the text record
            for (i = 2, j = 0; line[i] != '^'; i++, j++) {
                staddr[j] = line[i];
            }
            staddr[j] = '\0';
            stdaddr1 = strtol(staddr, NULL, 16); // Convert hex address to integer

            // Parse and write object code from the text record to output file
            i = 12; // Object code starts at index 12 in the line
            while (line[i] != '$') {
                if (line[i] != '^') {
                    // Write address and two-byte object code to the output file
                    fprintf(fpOut, "%06X\t%c%c\n", stdaddr1, line[i], line[i + 1]);
                    stdaddr1++; // Move to the next address
                    i += 2;     // Move to the next pair of hex characters
                } else {
                    i++; // Skip '^' separator
                }
            }
        } else if (line[0] == 'E') {
            break; // End of program
        }
    }

    // Close both files
    fclose(fp);
    fclose(fpOut);

    printf("Data written to output.txt successfully.\n");
    return 0;
}
/* 
input.txt
H^COPY^001000^0035
T^001000^0C^001003^001122$
T^002000^03^010B0A$
E^001000


output.txt
Program name: COPY
001000	00
001001	10
001002	03
001003	00
001004	11
001005	22
002000	01
002001	0B
002002	0A




*/
