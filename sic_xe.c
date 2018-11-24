#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_handler.h"

int main(int argc, char **argv)
{
    FILE *fp;
    char line[LINE_SIZE];
    char **line_tokens;
    int count_tokens;
    
    //int LOCCTR = 0;
    
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
        count_tokens = get_count_tokens(line_tokens);
        
        if (count_tokens) printf("%-4d", count_tokens);
        for (int i = 0; i < count_tokens; i++) {
            printf("%-16s", line_tokens[i]);
        }
        if (count_tokens) printf("\n");
        
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
         ****************************************************/
    }
    
    free(line_tokens);
    
    fclose(fp);
    
    return 0;
}
