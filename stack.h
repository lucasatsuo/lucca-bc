/**
	Simple stack struct definition
	Contains a float value and a pointer to the next
	stack node
**/
typedef struct Stack{
	float value;
	struct Stack *next;
}Stack;

/** FUNCTION: push
 * INPUT: float, Stack**
 * OUTPUT: void
 * DESCRIPTION: pushes a float value to the top
 * of the stack given
 **/
void push(float v, Stack** head);

/** FUNCTION: isempty
 * INPUT: Stack*
 * OUTPUT: int
 * DESCRIPTION: if the given stack is empty returns 1
 * otherwise it returns 0
 **/
int isempty(Stack* head);

/** FUNCTION: pop
 * INPUT: Stack **
 * OUTPUT: float
 * DESCRIPTION: returns the float value located
 * on the top of the stack, removing it
 **/
float pop(Stack** head);
