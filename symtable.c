#include <string.h>
#include <symtable.h>

cell table[MAXTABLESIZE] = {{"",0}};

float retrievesym(cell table[], const char* symbol){
    for(int i = 0; i < MAXTABLESIZE; i++){
        if(!strcmp(table[i].id,symbol)){
            return table[i].val;
        }
    }
    return 0;
}

int updatesym(cell table[], const char* symbol, float value){
    for(int i = 0; i < MAXTABLESIZE; i++){
        if(!strcmp(table[i].id,"")){
            strcpy(table[i].id,symbol);
            table[i].val = value;
            return 0;
        }

        if(!strcmp(table[i].id,symbol)){
            table[i].val = value;
            return 0;
        }
    }
    return -1;
}
