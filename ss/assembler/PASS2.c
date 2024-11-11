#include <stdio.h>
#include <string.h>

void main() {
    FILE *fp_ou, *fp_op, *fp_len, *fp_sy, *fp_obj;
    int loc, start_addr, len, reclen = 0;
    char label[20], opcode[20], operand[20];
    char mnemonic[10], code[10], symnam[10], symloc[10];
    char obj_code[30] = "", text_record[100] = "";
    int record_start_addr;

    // Open files
    fp_ou = fopen("output.txt", "r");
    fp_len = fopen("length.txt", "r");
    fp_op = fopen("optab.txt", "r");
    fp_sy = fopen("symtab.txt", "r");
    fp_obj = fopen("object_code.txt", "w");

    if (!fp_ou || !fp_len || !fp_op || !fp_sy || !fp_obj) {
        printf("Error opening files.\n");
        return;
    }

    // Read program length and start address
    fscanf(fp_len, "%d", &len);
    fscanf(fp_ou, "%s %s %s", label, opcode, operand);

    // Header Record
    if (strcmp(opcode, "START") == 0) {
        sscanf(operand, "%X", &start_addr);  // Start address in hex
        fprintf(fp_obj, "H^%s^%06X^%06X\n", label, start_addr, len);
    }

    // Initialize Text Record
    record_start_addr = start_addr;  // Track starting address for each record

    // Process each line of the intermediate file (output.txt)
    while (fscanf(fp_ou, "%d %s %s %s", &loc, label, opcode, operand) != EOF) {
        if (strcmp(opcode, "END") == 0) {
            break;
        }

        // Reset object code buffer
        strcpy(obj_code, "");

        // Check if opcode is in optab
        fseek(fp_op, 0, SEEK_SET);
        int opcode_found = 0;
        while (fscanf(fp_op, "%s %s", mnemonic, code) != EOF) {
            if (strcmp(opcode, mnemonic) == 0) {
                opcode_found = 1;
                fseek(fp_sy, 0, SEEK_SET);

                // Check if operand is in symtab
                int symbol_found = 0;
                while (fscanf(fp_sy, "%s %s", symnam, symloc) != EOF) {
                    if (strcmp(operand, symnam) == 0) {
                        sprintf(obj_code, "%s%s", code, symloc);
                        symbol_found = 1;
                        break;
                    }
                }
                
                // If operand not found, use "0000" as default address
                if (!symbol_found) {
                    sprintf(obj_code, "%s0000", code);
                }
                break;
            }
        }

        // Handle WORD and BYTE instructions if not found in optab
        if (!opcode_found) {
            if (strcmp(opcode, "WORD") == 0) {
                sprintf(obj_code, "%06X", atoi(operand));
            } else if (strcmp(opcode, "BYTE") == 0) {
                // Process BYTE C'Z' as ASCII hex
                if (operand[0] == 'C') {
                    for (int i = 2; i < strlen(operand) - 1; i++) {
                        sprintf(obj_code + strlen(obj_code), "%02X", operand[i]);
                    }
                }
            }
        }

        // Add object code to text record if the total length does not exceed 60 bytes
        if (strlen(text_record) + strlen(obj_code) <= 60) {
            strcat(text_record, obj_code);
            strcat(text_record, "^");
            reclen += strlen(obj_code) / 2;  // Update byte count for text record
        } else {
            // Write the current text record and reset for the next one
            fprintf(fp_obj, "T^%06X^%02X^%s\n", record_start_addr, reclen, text_record);
            strcpy(text_record, obj_code);
            strcat(text_record, "^");
            reclen = strlen(obj_code) / 2;
            record_start_addr = loc;
        }
    }

    // Finalize last Text Record
    if (strlen(text_record) > 0) {
        fprintf(fp_obj, "T^%06X^%02X^%s\n", record_start_addr, reclen, text_record);
    }

    // End Record
    fprintf(fp_obj, "E^%06X\n", start_addr);

    // Close all files
    fclose(fp_ou);
    fclose(fp_op);
    fclose(fp_sy);
    fclose(fp_len);
    fclose(fp_obj);
}
