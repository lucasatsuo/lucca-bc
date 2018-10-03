#include <stdlib.h>
#include <stdio.h>
#include <stack.h>

Stack *head = NULL;

void push(float v, Stack** head){
	Stack *new = (Stack*)malloc(sizeof(Stack));
	new->value = v;
	new->next = *head;
	*head = new;
}

int isempty(Stack* head){
	if (head == NULL){
		return 1;
	}
	return 0;
}

float pop(Stack** head){
	Stack* old = *head;
	if(isempty(old)){
		printf("Head is null\n");
		exit(-1);
	}
	float val = old->value;
	*head = old->next;
	return val;
}
