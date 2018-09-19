typedef struct Stack{
	float value;
	struct Stack *next;
}Stack;

void push(float v);

float pop();

int isempty();
