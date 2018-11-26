#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_handler.h"
#include "sic_xe_data.h"
#include "pass_one.h"

int main(int argc, char **argv)
{
    FILE *input_file_ptr;
    FILE *intermediate_file_ptr;
    char line[LINE_SIZE];
    char **line_tokens;
    int count_tokens;
    
    LineStruct line_struct;
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
    
    /******** Write file ********/
    if (!(intermediate_file_ptr = fopen("intermediate.txt", "w"))) {
        fprintf(stderr, "%s can't be opened.\n", "intermediate.txt");
        exit(EXIT_FAILURE);
    }
    
    /******** Memory allocate ********/
    line_tokens = calloc(TOKEN_NUM + 1, sizeof(char *));
    if (!line_tokens) {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    
    /******** Read first input line ********/
    if (fgets(line, LINE_SIZE, input_file_ptr)) {
        split_line(line, line_tokens);
        count_tokens = get_count_tokens(line_tokens);
        
        // Return true if OPCODE == START
        if (init_starting_address(count_tokens, line_tokens, &starting_address)) {
            
            strcpy(line_struct.label, line_tokens[0]);
            strcpy(line_struct.opcode, line_tokens[1]);
            strcpy(line_struct.operand, line_tokens[2]);
            
            // Write line to intermediate file
            write_intermediate_file(intermediate_file_ptr, line_struct);
            
        } else {
            // Move to beginning of file
            fseek(input_file_ptr, 0L, SEEK_SET);
        }
        
        // Initialize LOCCTR to starting address
        LOCCTR = starting_address;
    }
    
    /******** Read input line ********/
    while (fgets(line, LINE_SIZE, input_file_ptr)) {
        
        split_line(line, line_tokens);
        count_tokens = get_count_tokens(line_tokens);
        
        if (count_tokens) {
            int temp_LOCCTR = LOCCTR;
            
            line_struct = get_line_struct(count_tokens, line_tokens, &LOCCTR);
            
            /******** Output test ********/
            if (strcmp(line_struct.opcode, "END"))
                printf("%-4d %04X   ", count_tokens, temp_LOCCTR);
            else
                printf("%-4d %-6s ", count_tokens, "");
            
            printf("%-12s", line_struct.label);
            printf("%-12s", line_struct.opcode);
            printf("%-12s", line_struct.operand);
            
            printf("\n");
            
            //if (line_struct.label) {
            //    SYMTAB = insert_SYMTAB(line_struct.label, temp_LOCCTR);
            //}
            
        }
        
        write_intermediate_file(intermediate_file_ptr, line_struct);
        
    }
    
    free(line_tokens);
    
    fclose(intermediate_file_ptr);
    fclose(input_file_ptr);
    
    return 0;
}
