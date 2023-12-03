// Stack using linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int data;
    struct stack *link;
};
struct stack *top = NULL;

void push(int data){
    struct stack *newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode->data = data;

    newnode->link = top;
    top = newnode;
}

void peek(){
    if(top == NULL){
        printf("Stack is empty.");
        return;
    }
    printf("\nTop element of the stack is: %d", top->data);
}

void pop(){
    struct stack *temp = top;
    if(top==NULL){
        printf("\nUnderflow Alert! Stack is empty.");
        return;
    }
    printf("\nPoping %d from stack.", top->data);
    top = top->link;
    free(temp);
}

void display(){
    struct stack *current = top;
    if(top == NULL){
        printf("Stack is empty.");
        return;
    }
    printf("\nDisplay:\t");
    while(current != NULL){
        printf("%d\t", current->data);
        current = current->link;
    }
}
void main(){
    push(4);
    push(5);
    push(20);

    display();
    pop();
    display();
    push(9);
    push(24);

    display();
    peek();
}