/** @<parser.c> :: **/

#include <stdlib.h>
#include <stdio.h>
#include <tokens.h>
#include <lexer.h>
#include <string.h>
#include <stack.h>
#include <keywords.h>
#include <symtable.h>
#include <parser.h>

float acc;
extern Stack *head;
char symbol[MAXIDLEN];
extern cell table[];

void match (int expected){
    if(lookahead == expected){
        lookahead = gettoken(source);
    }else{
        fprintf(stderr,"token mismatch... exiting");
        exit(-2);
    }
}

/* mybc -> [expr] { [expr] cmdsep } cmdquit */
void mybc (void){
    //Acao semantica
    lookahead = gettoken(source);

mybc_start:

cmd_start:
    if (is_FIRST_expr()) {
        expr();
        printf("%lg\n",acc );
    }
    if (cmdsep()) goto cmd_start;
    if(!cmdquit()) goto mybc_start;
}

/* cmdsep -> \n | ; */
int cmdsep(){
    switch(lookahead){
        case '\n':
        case ';':
        match(lookahead);
        return 1;
    }
    return 0;

}

/* cmdquit -> quit | ... */
int cmdquit(){
    switch(lookahead){
        case QUIT:
        case EXIT:
        case BYE:
        case LOGOUT:
            match(lookahead);
        case EOF:
        return 1;
    }
    return 0;
}

int is_FIRST_expr(){
    switch(lookahead){
        case '+':
        case '-':
        case '(':
        case UINT:
        case FLTP:
        case ID:
        return 1;
    }
    return 0;
}

void expr(void)
{
    int isnegate = 0;
    int oplus = 0;
    int otimes = 0;

    /* checa pelo primeiro - (inversao de operador) */
    if(lookahead == '-'){
        isnegate = 1;
        match(lookahead);
    }else if(lookahead == '+'){
        match(lookahead);
    }

T_begin:

F_begin:

    //abstrai o diagrama de fact
    //coloca um resultado no acumulador
    fact();

    if(isnegate){
        acc = -acc;
        isnegate = 0;
    }

    switch(otimes){
        case '*':
        acc = pop(&head) * acc;
        otimes = 0;
        break;

        case '/':
        if (acc == 0){
            printf("Invalid operation\n");
            exit(-3);
        } else {
            acc = pop(&head) / acc;
            otimes = 0;
        }
    }

    if (lookahead == '*' || lookahead == '/') {
        otimes = lookahead;
        push(acc,&head);
        match(lookahead);
        goto F_begin;
    }

    switch(oplus){
        case '+':
        acc = pop(&head) + acc;
        oplus = 0;
        break;

        case '-':
        acc = pop(&head) - acc;
        oplus = 0;
    }

    if (lookahead == '+' || lookahead == '-') {
        oplus = lookahead;
        push(acc,&head);
        match(lookahead);
        goto T_begin;
    }
}

void fact(){
    switch (lookahead) {
        case ID:
            strcpy(symbol,lexeme);
            match(ID);
            if(lookahead == '='){
                match('=');
                expr();
                // acao semantica 7
                updatesym(table,symbol,acc);
            }else{
                acc = retrievesym(table,symbol);
            }
            break;
        case UINT:
        case FLTP:
            acc = atof(lexeme); // acao semantica 4
            clearLexeme();
            match(lookahead);
            break;
        default:
        match('('); expr(); match(')');
    }
}
