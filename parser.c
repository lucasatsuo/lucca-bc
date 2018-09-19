/** @<parser.c> :: **/

#include <stdlib.h>
#include <stdio.h>
#include <tokens.h>
#include <lexer.h>
#include <string.h>
#include <stack.h>
#include <parser.h>

float acc;
Stack *head = NULL;

void match (int expected){
    if(lookahead == expected){
        lookahead = gettoken(source);
    }else{
        fprintf(stderr,"token mismatch... exiting");
        exit(-2);
    }
}

void expr(void)
{
    int flag = 0;

    /* checa pelo primeiro - (inversao de operador)*/
    if(lookahead == '-'){
        flag = 1;
        match(lookahead);
    }else if(lookahead == '+'){
        match(lookahead);
    }

T_begin:

F_begin:

    //abstrai o diagrama de fact
    //coloca um resultado no acumulador
    fact();

    switch(flag){
        //flag 1
        case 1:
            acc = -acc;
        break;
        //flag 2
        case '+':
            acc = acc + pop(&head);
        break;
        case '-':
            acc = pop(&head) - acc;
        break;
        //flag 3
        case '*':
            acc = acc * pop(&head);
        break;
        case '/':
            if (acc == 0){
                printf("Invalid operation\n");
                exit(-3);
            }
            acc = pop(&head) / acc;
        break;
        default:
        break;
    }

    flag = 0;

    if (lookahead == '*' || lookahead == '/') {
        flag = lookahead;
        push(acc,&head);
        match(lookahead);
        goto F_begin;
    }

    if (lookahead == '+' || lookahead == '-') {
        flag = lookahead;
        push(acc,&head);
        match(lookahead);
        goto T_begin;
    }
}

void fact(){
    switch (lookahead) {
    case ID:
        match(ID);
        if(lookahead == '='){
            match('=');
            expr();
        }
        break;
    case UINT:
    case FLTP:
        acc = atof(lexeme); //acao semantica 4
        clearLexeme();
        match(lookahead);
        break;
    default:
        match('('); expr(); match(')');
    }
}
