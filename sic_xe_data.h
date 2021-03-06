#ifndef SIC_XE_DATA_H
#define SIC_XE_DATA_H

#define SYMTAB_SIZE 32
#define BLOCK_SIZE 16

typedef struct LineStruct {
    char label[BLOCK_SIZE];
    char opcode[BLOCK_SIZE];
    char operand[BLOCK_SIZE];
} LineStruct;

typedef struct SymbolTable {
    char label[BLOCK_SIZE];
    int LOCCTR;
} SymTab;

typedef struct OperatingCodeTable {
    char *opcode;
    char format;
    unsigned short int machine_code;
} OpTab;

static const OpTab OPTAB[] =
{
    /********************* SIC Instruction Set *********************/
    {"ADD", '3', 0x18},    {"AND", '3', 0x40},   {"COMP", '3', 0x28},
    {"DIV", '3', 0x24},    {"J", '3', 0x3C},     {"JEQ", '3', 0x30},
    {"JGT", '3', 0x34},    {"JLT", '3', 0x38},   {"JSUB", '3', 0x48},
    {"LDA", '3', 0x00},    {"LDCH", '3', 0x50},  {"LDL", '3', 0x08},
    {"LDX", '3', 0x04},    {"MUL", '3', 0x20},   {"OR", '3', 0x44},
    {"RD", '3', 0xD8},     {"RSUB", '3', 0x4F},  {"STA", '3', 0x0C},
    {"STCH", '3', 0x54},   {"STL", '3', 0x14},   {"STSW", '3', 0xE8},
    {"STX", '3', 0x10},    {"SUB", '3', 0x1C},   {"TD", '3', 0xE0},
    {"TIX", '3', 0x2C},    {"WD", '3', 0xDC},
    /****************** Floating-point Instruction ******************/
    {"ADDF", '3', 0x58},   {"COMPF", '3', 0x88}, {"DIVF", '3', 0x64},
    {"FIX", '1', 0xC4},    {"FLOAT", '1', 0xC0}, {"LDF", '3', 0x70},
    {"MULF", '3', 0x60},   {"NORM", '1', 0xC8},  {"STF", '3', 0x80},
    {"SUBF", '3', 0x5C},
    /********************** SIC/XE version only **********************/
    {"ADDR", '2', 0x90},   {"CLEAR", '2', 0xB4}, {"COMPR", '2', 0xA0},
    {"DIVR", '2', 0x9C},   {"HIO", '1', 0xF4},   {"LDB", '3', 0x68},
    {"LDS", '3', 0x6C},    {"LDT" , '3', 0x74},  {"LPS", '3', 0xD0},
    {"MULR", '2', 0x98},   {"RMO", '2', 0xAC},   {"SHIFTL", '2', 0xA4},
    {"SHIFTR", '2', 0xA8}, {"SIO", '1', 0xF0},   {"SSK", '3', 0xEC},
    {"STB", '3', 0x78},    {"STS", '3', 0x7C},   {"STT", '3', 0x84},
    {"SUBR", '2', 0x94},   {"SVC", '2', 0xB0},   {"TIO", '1', 0xF8},
    {"TIXR", '2', 0xB8},
};

#endif
