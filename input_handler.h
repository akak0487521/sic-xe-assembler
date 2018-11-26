#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#define DELIMITER " \n\r\t"
#define LINE_SIZE 256
#define TOKEN_NUM 3

void split_line(char *, char **);
int get_count_tokens(char **);

#endif
