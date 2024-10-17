#include <stdio.h>
#include <string.h>

void main() {
    FILE *fp_ou, *fp_op, *fp_len, *fp_sy, *fp_opc, *fp_samp, *fp_read;
    int i, j, len, reclen = 0, loc;
    char symnam[5], code[5], start[10], label[20], opcode[20], operand[20], symloc[10], mnemonic[10], a[20], b[20], count[20], s;

    fp_ou = fopen("output.txt", "r");
    fp_len = fopen("length.txt", "r");
    fp_op = fopen("optab.txt", "r");
    fp_sy = fopen("symtab.txt", "r");
    fp_opc = fopen("optab.txt", "r");
    fp_samp = fopen("samp.txt", "w");

    if (!fp_ou || !fp_len || !fp_op || !fp_sy || !fp_opc || !fp_samp) {
        printf("Error opening files.\n");
        return;
    }

    printf("\nPass 2 of a two pass assembler:\n\n");
    printf("Header rec:\n");

    fscanf(fp_ou, "%s %s %s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0) {
        strcpy(start, operand);
        fscanf(fp_len, "%d", &len);
    }
    printf("H^%s^00%s^0000%X\n", label, start, len);

    printf("Text rec:\n");
    printf("T^00%s^", start);
    reclen += 6;

    fscanf(fp_ou, "%d %s %s %s", &loc, label, opcode, operand);
    while (strcmp(opcode, "END") != 0) {
        fscanf(fp_op, "%s %s", mnemonic, code);
        while (!feof(fp_op)) {
            if (strcmp(opcode, mnemonic) == 0) {
                fscanf(fp_sy, "%s %s", symnam, symloc);
                while (!feof(fp_sy)) {
                    if (strcmp(operand, symnam) == 0) {
                        reclen += 6;
                        fprintf(fp_samp, "%s%s^", code, symloc);
                        break;
                    } else {
                        fscanf(fp_sy, "%s %s", symnam, symloc);
                    }
                }
                break;
            } else {
                fscanf(fp_op, "%s %s", mnemonic, code);
            }
        }

        if (strcmp(opcode, "WORD") == 0 || strcmp(opcode, "BYTE") == 0) {
            if (strcmp(opcode, "WORD") == 0) {
                fprintf(fp_samp, "00000%s^", operand);
                reclen += 6;
            } else {
                for (i = 0, j = 2; j < (strlen(operand) - 1); i++, j++) {
                    count[i] = operand[j];
                }
                count[i] = '\0';
                while (!feof(fp_opc)) {
                    fscanf(fp_opc, "%s %s", a, b);
                    if (strcmp(count, a) == 0) {
                        fprintf(fp_samp, "0000%s", b);
                        reclen += 6;
                    }
                }
            }
        }

        fscanf(fp_ou, "%d %s %s %s", &loc, label, opcode, operand);
        fseek(fp_op, 0, SEEK_SET);
        fseek(fp_sy, 0, SEEK_SET);
    }

    fclose(fp_samp);

    fp_read = fopen("samp.txt", "r");
    if (!fp_read) {
        printf("Error opening samp.txt.\n");
        return;
    }

    printf("%X^", reclen / 2);
    while ((s = fgetc(fp_read)) != EOF) {
        printf("%c", s);
    }

    printf("\nEnd rec:\n");
    printf("E^00%s\n", start);

    fclose(fp_ou);
    fclose(fp_op);
    fclose(fp_sy);
    fclose(fp_len);
    fclose(fp_read);
}





//optab.txt
START *
LDA   00
STA   0c
LDCH  50
STCH  54
Z     7a
END   *

length.txt
23

symtab.txt
ALPHA	2012
FIVE	2018
CHARZ	2021
C1	2022

output.txt
		COPY	START	2000
2000	**	LDA	FIVE	
2003	**	STA	ALPHA	
2006	**	LDCH	CHARZ	
2009	**	STCH	C1	
2012	ALPHA	RESW	2	
2018	FIVE	WORD	5	
2021	CHARZ	BYTE	C'Z'	
2022	C1	RESB	1	
2023	**	END	**
// output in samp.txt
002018^0c2012^502021^542022^000005^00007a
