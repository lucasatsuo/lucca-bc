/** @<main.c>:: **/

#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>
#include <parser.h>
#include <tokens.h>

FILE *source, *object;
extern int lookahead;
extern char lexeme[MAXIDLEN + 1];
extern float acc;

int main(){

    source = fopen("teste.txt","r");
    object = stdout;

    mybc();

    return 0;
}
