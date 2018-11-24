#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_handler.h"

char **split_line(char *line)
{
    char **line_tokens = calloc(5, sizeof(char *));
    char *token;
    
    if (!line_tokens) {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(line, DELIMITER);
    for (int i = 0; i < TOKEN_NUM; i++) {
        if (token == NULL) break;
        line_tokens[i] = token;
        token = strtok(NULL, DELIMITER);
    }
    
    return line_tokens;
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

