#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER " \n\r\t"
#define LINE_SIZE 256
#define TOKEN_NUM 4

char **split_line(char *);

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[LINE_SIZE];
    char **line_tokens;
    
    int LOCCTR = 0;
    
    if (!argv[1]) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /******** Read file ********/
    if (!(fp = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /******** Read line test ********/
    while (fgets(line, LINE_SIZE, fp)) {
        line_tokens = split_line(line);
        
        for (int i = 0; i < TOKEN_NUM; i++) {
            if (line_tokens[i]) printf("%s\t\t", line_tokens[i]);
        }
        printf("\n");
        
        /****************************************************
         *  read first input line                           *
         *  if OPCODE == 'START' then                       *
         *      begin                                       *
         *          save #[OPERAND] as starting address     *
         *          initialize LOCCTR to starting address   *
         *          write line to intermediate file         *
         *          read next input line                    *
         *      end {if START}                              *
         *  else                                            *
         *      initialize LOCCTR to 0                      *
        *****************************************************/
    }
    
    free(line_tokens);
    
    fclose(fp);
    
    return 0;
}

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
