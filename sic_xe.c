#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 256

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[LINE_SIZE];

    if (!argv[1]) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!(fp = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /******** Read line test ********/
    while (fgets(line, LINE_SIZE, fp)) {
        printf("%s", line);
    }

    fclose(fp);
    
    return 0;
}
