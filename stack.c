#include <stdlib.h>
#include <stdio.h>

typedef struct Stack{
	float value;
	struct Stack *next;
}Stack;

extern Stack *head;

void push(float v){
	Stack *new = (Stack*)malloc(sizeof(Stack));
	new->value = v;
	new->next = head;
	head = new;
}

int isempty(){
	if (head == NULL){
		return 1;
	}
	return 0;
}

float pop(void){
	if(isempty()){
		printf("Head is null\n");
		exit(-1);
	}
	float val = head->value;
	head = head->next;
	return val;
}
