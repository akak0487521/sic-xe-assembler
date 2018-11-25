#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_handler.h"
#include "sic_xe_data.h"
#include "pass_one.h"

int main(int argc, char **argv)
{
    FILE *input_file_ptr;
    char line[LINE_SIZE];
    char **line_tokens;
    int count_tokens;
    
    int starting_address = 0;
    int LOCCTR = 0;
    
    if (!argv[1]) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /******** Read file ********/
    if (!(input_file_ptr = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    /******** Read first input line ********/
    if (fgets(line, LINE_SIZE, input_file_ptr)) {
        line_tokens = split_line(line);
        count_tokens = get_count_tokens(line_tokens);
        
        starting_address = init_starting_address(count_tokens, line_tokens);
        
        // Initialize LOCCTR to starting address
        LOCCTR = starting_address;
        
        // Write line to intermediate file
        // ......
        
        free(line_tokens);
    }
    
    /******** Read input line ********/
    while (fgets(line, LINE_SIZE, input_file_ptr)) {
        line_tokens = split_line(line);
        count_tokens = get_count_tokens(line_tokens);
        
        /******** Output test ********/
        if (count_tokens) {
            printf("%-4d", count_tokens);
            for (int i = 0; i < count_tokens; i++) {
                printf("%-16s", line_tokens[i]);
                
            }
            printf("\n");
        }
        
        free(line_tokens);
    }
    
    fclose(input_file_ptr);
    
    return 0;
}
