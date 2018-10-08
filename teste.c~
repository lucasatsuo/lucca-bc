#include<stdio.h>
#include<stdlib.h>
#include<symtable.h>

extern cell table[];

int main(){
    printf("%s %f\n",table[0].id,table[0].val);
    printf("%s %f\n",table[1].id,table[1].val);
    updatesym(table,"a",12.5);
    updatesym(table,"a",2.5);
    printf("%s %f\n",table[0].id,retrievesym(table,"a"));
    printf("%s %f\n",table[1].id,retrievesym(table,"b"));
}
