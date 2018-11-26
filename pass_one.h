#ifndef PASS_ONE_H
#define PASS_ONE_H

#include <stdio.h>
#include <stdbool.h>
#include "sic_xe_data.h"

bool init_starting_address(int, char **, int *);

LineStruct get_line_struct(int, char **, int *);

void write_intermediate_file(FILE *, LineStruct);

bool is_in_OPTAB(char *, int *);

#endif
