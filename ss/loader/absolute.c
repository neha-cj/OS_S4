#include<stdio.h>
#include<string.h>

char input[10], label[10], ch2;
int firsttext = 0, start, pretexaddr, len, length = 0, end, count = 0, k, texaddr, memaddr, col = 0, oldaddr;
FILE *fp1, *fp2;

void check();

int main() {
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(fp1, "%s", input);
    fprintf(fp2, "\t\tAbsolute Loader\t");
    fprintf(fp2, "\n..........................\n");
    fprintf(fp2, "Address(hex) \t\t\t Contents\n");
    fprintf(fp2, "\n........................\n");

    while (strcmp(input, "E") != 0) {
        if (strcmp(input, "H") == 0) {
            fscanf(fp1, "%s%x%x%s", label, &start, &end, input);
            memaddr = start;
        } else if (strcmp(input, "T") == 0) {
            len = length;
            pretexaddr = oldaddr;
            fscanf(fp1, "%x%x%s", &texaddr, &length, input);
            oldaddr = texaddr;

            if (firsttext == 0) {
                pretexaddr = memaddr;
                firsttext = 1;
            }

            for (k = 0; k < (texaddr - (pretexaddr + len)); k++) {
                memaddr++;
                fprintf(fp2, "xx");
                count++;
                if (count == 4) {
                    fprintf(fp2, " ");
                    col++;
                    if (col == 4) {
                        fprintf(fp2, "\n\n%x\t\t", memaddr);
                        col = 0;
                    }
                    count = 0;
                }
            }

            if (texaddr == start) {
                fprintf(fp2, "\n\n%x\t\t", texaddr);
                fprintf(fp2, "%c%c", input[0], input[1]);
                check();
                fprintf(fp2, "%c%c", input[2], input[3]);
                check();
                fprintf(fp2, "%c%c", input[4], input[5]);
                check();
                fscanf(fp1, "%s", input);
            } else {
                int bytenum = strlen(input);
                if (bytenum == 2) {
                    fprintf(fp2, "%c%c", input[0], input[1]);
                    check();
                    fscanf(fp1, "%s", input);
                } else {
                    fprintf(fp2, "%c%c", input[0], input[1]);
                    check();
                    fprintf(fp2, "%c%c", input[2], input[3]);
                    check();
                    fprintf(fp2, "%c%c", input[4], input[5]);
                    check();
                    fscanf(fp1, "%s", input);
                }
            }
        }
    }

    int m = 30;
    for (k = 0; k < (m - length); k++) {
        memaddr++;
        fprintf(fp2, "xx");
        count++;
        if (count == 4) {
            fprintf(fp2, " ");
            col++;
            if (col == 4) {
                fprintf(fp2, "\n\n%x\t\t", memaddr);
                col = 0;
            }
            count = 0;
        }
    }

    fprintf(fp2, "\n...............................\n");
    fclose(fp1);
    fclose(fp2);

    printf("\t Contents of output file\n\n");
    printf("\n..................\n");

    fp2 = fopen("output.txt", "r");
    ch2 = fgetc(fp2);
    while (ch2 != EOF) {
        printf("%c", ch2);
        ch2 = fgetc(fp2); // Fetch next character
    }
    fclose(fp2);

    return 0;
}

void check() {
    count++;
    memaddr++;
    texaddr++;
    if (count == 4) {
        fprintf(fp2, " ");
        col++;
        if (col == 4) {
            fprintf(fp2, "\n\n%x\t\t", texaddr);
            col = 0;
        }
        count = 0;
    }
}
