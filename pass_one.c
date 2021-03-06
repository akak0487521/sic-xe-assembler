#include <stdlib.h>
#include <string.h>

#include "pass_one.h"

bool init_starting_address(int count_tokens, char **line_tokens, int *starting_address)
{
    if (count_tokens == 3 && strcmp("START", line_tokens[1]) == 0) {
        // Save #[OPERAND] as starting address
        *starting_address = strtol(line_tokens[2], NULL, 16);
        return true;
    }
    
    *starting_address = 0;
    
    return false;
}

LineStruct get_line_struct(int count_tokens, char **line_tokens, int *LOCCTR)
{
    int index = -1;
    LineStruct temp = {"", "", ""};

    switch (count_tokens)
    {
        case 1:
            // Label: X, Opcode: O, Operand: X
            strcpy(temp.opcode, line_tokens[0]);
            break;
        case 2:
            // Label: O, Opcode: O, Operand: X
            if (is_in_OPTAB(line_tokens[1], &index))
            {
                strcpy(temp.label, line_tokens[0]);
                strcpy(temp.opcode, line_tokens[1]);
            }
            // Label: X, Opcode: O, Operand: O
            else
            {
                strcpy(temp.opcode, line_tokens[0]);
                strcpy(temp.operand, line_tokens[1]);
            }
            break;
        case 3:
            // Label: O, Opcode: O, Operand: O
            strcpy(temp.label, line_tokens[0]);
            strcpy(temp.opcode, line_tokens[1]);
            strcpy(temp.operand, line_tokens[2]);
            break;
        default:
            break;
    }
    
    if (index != -1 || is_in_OPTAB(temp.opcode, &index)) {
        *LOCCTR += OPTAB[index].format - '0';
    } else if (temp.opcode[0] == '+') {
        *LOCCTR += 4;
    } else if (strcmp(temp.opcode, "WORD") == 0) {
        *LOCCTR += 3;
    } else if (strcmp(temp.opcode, "RESW") == 0) {
        *LOCCTR += 3 * strtol(temp.operand, NULL, 10);
    } else if (strcmp(temp.opcode, "BYTE") == 0) {
        if (temp.operand[0] == 'C')
            *LOCCTR += strlen(temp.operand) - 3;
        else if (temp.operand[0] == 'X')
            *LOCCTR += (strlen(temp.operand) - 3) / 2;
    } else if (strcmp(temp.opcode, "RESB") == 0) {
        *LOCCTR += strtol(temp.operand, NULL, 10);
    }
    
    return temp;
}

void insert_SYMTAB(SymTab *SYMTAB, int *sym_num, char *label, int LOCCTR)
{
    for (int i = 0; i < *sym_num; i++) {
        if (strcmp(SYMTAB[i].label, label) == 0) {
            fprintf(stderr, "Duplicate symbol. (%s at SYMTAB[%d])\n", SYMTAB[i].label, i);
            exit(EXIT_FAILURE);
        }
    }
    if ( (*sym_num) + 1 < SYMTAB_SIZE ) {
        strcpy(SYMTAB[*sym_num].label, label);
        SYMTAB[*sym_num].LOCCTR = LOCCTR;
        *sym_num += 1;
    }
}

void write_intermediate_file(FILE *intermediate_file_ptr, LineStruct line_struct)
{
    fwrite(line_struct.label, sizeof(char), BLOCK_SIZE, intermediate_file_ptr);
    fwrite(line_struct.opcode, sizeof(char), BLOCK_SIZE, intermediate_file_ptr);
    fwrite(line_struct.operand, sizeof(char), BLOCK_SIZE, intermediate_file_ptr);
}

bool is_in_OPTAB(char *opcode, int *index)
{
    static int optab_size = sizeof(OPTAB) / sizeof(OpTab);
    
    if (opcode == NULL) return false;
    
    for (int i = *index + 1; i < optab_size; i++) {
        if (strcmp(OPTAB[i].opcode, opcode) == 0) {
            *index = i;
            return true;
        }
    }
    
    return false;
}
