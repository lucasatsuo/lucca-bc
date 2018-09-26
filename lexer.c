/** @<lexer.c>:: **/

/** this file is responsible for lexic interpretation
 * e.g. it reads the file trying to classify the substrings into 
 * tokens that will be returned to the parser **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokens.h>
#include <lexer.h>
#include <keywords.h>

int lookahead;
char lexeme[MAXIDLEN + 1];

void skipspaces(FILE *tape){
    int head;
    while(isspace(head = getc(tape)));
    ungetc(head,tape);
}

int gettoken(FILE *tape){
    int token;
    skipspaces(tape);
    if( token = isID(tape) ){
      return token;
    }
    if( token = isNUM(tape) ){
        return token;
    }
    token = getc(tape);
    lexeme[0] = token;
    lexeme[1] = 0;
    return token;
}

int isID(FILE *tape){
    int i = 0, token = 0, keyword;
    /** [a-zA-Z] **/
    if( isalpha( lexeme[i] = getc(tape) ) ){
        i++;
        /** [a-zA-Z0-9]* **/
        while( isalnum( lexeme[i] = getc(tape) ) || lexeme[i] == '_' ) i++;
        ungetc(lexeme[i],tape);
        // finalizing the string lexeme
        // which contains the ID source
        lexeme[i] = 0;

        /* Checking if the ID found is a reserved word */
        keyword = iskeyword(lexeme);
        if(keyword){
            return keyword;
        }

        token = ID;
        return token;
    }
    /** not an ID **/
    ungetc(lexeme[i],tape);
    return token;
}

int isNUM(FILE* tape){
    int i = 0, i2;
    int token = 0;
    lexeme[i] = getc(tape);

    if( isdigit(lexeme[i]) ){
        token = UINT;
        if(lexeme[i] != 0){
            i++;
            while( isdigit(lexeme[i] = getc(tape)) ) i++;
        }
    }
    ungetc(lexeme[i], tape);
    lexeme[i] = 0;
    
    if((lexeme[i] = getc(tape)) == '.'){
        i++;
        if(token == UINT){
            token = FLTP;
            while(isdigit(lexeme[i] = getc(tape))) i++;
        }else{
            if(isdigit(lexeme[i] = getc(tape))){
                i++;
                token = FLTP;
                while(isdigit(lexeme[i] = getc(tape))) i++;
            }
        }
    }
    ungetc(lexeme[i],tape);
    lexeme[i] = 0;

    i2 = chk_Exp(tape,i);
    if(i != i2 && token != 0){
        i = i2;
        token = FLTP;
    }

    return token;
}

int chk_Exp(FILE *tape, int i0){
    int i = i0;
    /** [Ee] **/
    if( toupper(lexeme[i] = getc(tape)) == 'E'){
        i++;
        /** [/+/-]? **/
        if( (lexeme[i] = getc(tape)) == '+' || lexeme[i] == '-'){
            i++;
        }else{
            ungetc(lexeme[i],tape);
            lexeme[i] = 0;
        }

        /** [0-9]+ **/
        if( isdigit(lexeme[i] = getc(tape)) ){
            i++;
            while( isdigit(lexeme[i] = getc(tape)) ) i++;
            ungetc(lexeme[i],tape);
            lexeme[i] = 0;
            return i;
        }else{
            /** not an exp **/
            for(; i >= i0; i--){
                ungetc(lexeme[i],tape);
                lexeme[i] = 0;
            }
            return i0;
        }
    }

    /** not an exp **/
    ungetc(lexeme[i],tape);
    lexeme[i] = 0;
    return i0;

}

void clearLexeme(void){
    for(int j = 0; j < MAXIDLEN; j++){
        lexeme[j] = 0;
    }
}