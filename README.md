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
    - [x] Read file
    - [x] Read line from file
    - [x] Split line
    - [x] Write line to intermediate file
    - [x] Check duplicate symbol
    - [x] Insert (LABEL, LOCCTR) into SYMTAB
    - [x] Search OPTAB for OPCODE
        - [x] O(n)
        - [ ] O(1)
    - [ ] ......
* Pass two
    - [ ] Read line from intermediate file
    - [ ] Write listing line
    - [ ] Write Header record to object program
        - [ ] Col 1: H
        - [ ] Col 2-7: Program name
        - [ ] Col 8-13: starting address
        - [ ] Col 14-19: length of object program in bytes
    - [ ] Write Text record to object program
        - [ ] Col 1: T
        - [ ] Col 2-7: starting address in this record
        - [ ] Col 8-9: length of object code in this record in bytes
        - [ ] Col 10-69: object code
    - [ ] Write End record to object program
        - [ ] Col 1: E
        - [ ] Col 2-7: address of first executable instruction
    - [ ] ......
