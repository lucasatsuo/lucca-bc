typedef struct Stack{
	float value;
	struct Stack *next;
}Stack;

void push(float v, Stack** head);

int isempty(Stack* head);

float pop(Stack** head);
