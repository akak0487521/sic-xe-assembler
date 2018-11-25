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
    
    for (int i = 0; i < optab_size; i++) {
        if (strcmp(OPTAB[i].opcode, opcode) == 0) {
            *index = i;
            return true;
        }
    }
    
    return false;
}
