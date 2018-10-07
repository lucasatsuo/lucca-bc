#include <lexer.h>
#define MAXTABLESIZE 32

typedef struct cell{
    char id[MAXIDLEN];
    float val;
}cell;

int updatesym(cell table[], const char* symbol, float value);

float retrievesym(cell table[], const char* symbol);