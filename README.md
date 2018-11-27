# sic-xe-assembler
------------------
A simple SIC/XE assembler written in C. (Not Finished)

## Compile
```
    make all
```

## Execute
```
    ./sic_xe filename
```

## TO DO LIST
* Pass one
    * Read file (Finished)
    * Read line from file (Finished)
    * Split line (Finished)
    * Write line to intermediate file (Finished)
    * Check duplicate symbol (Finished)
    * Insert (LABEL, LOCCTR) into SYMTAB (Finished)
    * Search OPTAB for OPCODE
        * O(n) (Finished)
        * O(1)
    * ......
* Pass two
    * Read line from intermediate file
    * Write listing line
    * Write Header record to object program
        * Col 1: H
        * Col 2-7: Program name
        * Col 8-13: starting address
        * Col 14-19: length of object program in bytes
    * Write Text record to object program
    * Write End record to object program
    * ......
