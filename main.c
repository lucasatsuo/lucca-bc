/** @<main.c>:: **/

#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>
#include <parser.h>
#include <symtable.h>
#include <tokens.h>

FILE *source, *object;
extern int lookahead;
extern char lexeme[MAXIDLEN + 1];
extern float acc;
extern cell table[];

int main(){

//    source = fopen("teste.txt","r");
    source = stdin;
    object = stdout;

    updatesym(table,"asd",1.5);

    mybc();

    return 0;
}
