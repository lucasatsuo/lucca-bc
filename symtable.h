#include <lexer.h>
#define MAXTABLESIZE 32

/** Definition for a cell 
 * in the symbol table. Each cell contains 
 * an id (string) and a value (float)
 **/
typedef struct cell{
    char id[MAXIDLEN];
    float val;
}cell;

/** FUNCTION: updatesym
 * INPUT: pointer to an array of cells, const char *, float
 * OUTPUT: int
 * DESCRIPTION: This function tries to insert a value in the symbol table,
 * if the table is full it returns -1, otherwise it returns 0
 **/
int updatesym(cell table[], const char* symbol, float value);

/** FUNCTION: retrievesym
 * INPUT: pointer to an array of cells, const char *
 * OUTPUT: float
 * DESCRIPTION: This function searches the symbol table
 * for a specific ID, if found it returns the float value,
 * otherwise it returns 0
 **/
float retrievesym(cell table[], const char* symbol);