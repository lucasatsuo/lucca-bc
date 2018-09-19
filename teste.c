#include<stdio.h>
#include<stdlib.h>
#include<stack.h>

int main(){
    Stack* head = NULL;

    printf("%d\n",isempty(head));
    push(101.3,&head);
    push(102.0,&head);
    push(103.2,&head);
    push(104.1,&head);
    printf("%d\n",isempty(head));

    while(!isempty(head)){
        printf("%f\n",pop(&head));
    }
    printf("%f\n",pop(&head));
}
