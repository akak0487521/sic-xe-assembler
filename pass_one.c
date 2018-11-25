#include <stdlib.h>
#include <string.h>

#include "pass_one.h"

int init_starting_address(int count_tokens, char **line_tokens)
{
    int starting_address = 0;
    
    if (count_tokens == 3 && strcmp("START", line_tokens[1]) == 0) {
        // Save #[OPERAND] as starting address
        starting_address = strtol(line_tokens[2], NULL, 16);
    }
    
    return starting_address;
}
