#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_handler.h"

void split_line(char *line, char **line_tokens)
{
    int i;
    char *token;
    
    token = strtok(line, DELIMITER);
    for (i = 0; i < TOKEN_NUM; i++) {
        if (token == NULL) break;
        line_tokens[i] = token;
        token = strtok(NULL, DELIMITER);
    }
    line_tokens[i] = NULL;
}

int get_count_tokens(char **line_tokens)
{
    int count = TOKEN_NUM;
    
    for (int i = 0; i < TOKEN_NUM; i++) {
        if (!line_tokens[i] || line_tokens[i][0] == '.') {
            // Token is NULL or comment
            count = i;
            break;
        }
    }
    return count;
}

