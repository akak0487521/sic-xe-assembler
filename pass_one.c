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
            if (is_in_OPTAB(line_tokens[0], &index)) {
                strcpy(temp.opcode, line_tokens[0]);
            }
            break;
        case 2:
            // Label: X, Opcode: O, Operand: O
            if (is_in_OPTAB(line_tokens[0], &index) ||
                (strcmp(line_tokens[0], "WORD") == 0) ||
                (strcmp(line_tokens[0], "RESW") == 0) ||
                (strcmp(line_tokens[0], "BYTE") == 0) ||
                (strcmp(line_tokens[0], "RESB") == 0) ||
                (strcmp(line_tokens[0], "END") == 0))
            {
                strcpy(temp.opcode, line_tokens[0]);
                strcpy(temp.operand, line_tokens[1]);
            }
            // Label: O, Opcode: O, Operand: X
            else
            {
                strcpy(temp.label, line_tokens[0]);
                strcpy(temp.opcode, line_tokens[1]);
            }
            break;
        case 3:
            // Label: O, Opcode: O, Operand: O
            strcpy(temp.label, line_tokens[0]);
            strcpy(temp.opcode, line_tokens[1]);
            strcpy(temp.operand, line_tokens[2]);
            //Get index of OPTAB
            is_in_OPTAB(temp.opcode, &index);
        default:
            break;
    }
    
    if (index != -1) {
        *LOCCTR += OPTAB[index].format - '0';
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
