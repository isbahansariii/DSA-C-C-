// Infix to Postfix
// Stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack with a given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop the top element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';  // Return null character if the stack is empty
}

// Function to return the top element of the stack without popping
char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top];
    }
    return '\0';  // Return null character if the stack is empty
}

// Function to determine the precedence of operators
int precedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    if (stack == NULL) {
        printf("Stack creation failed\n");
        return;
    }

    int i, k;
    k = -1;  // Index for the output (postfix) string
    char postfix[strlen(infix) + 1];  // Initialize an array to store the postfix expression

    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[++k] = c;
        }
        // If the character is an open parenthesis, push it onto the stack
        else if (c == '(') {
            push(stack, c);
        }
        // If the character is a close parenthesis, pop operators from the stack and add them to the postfix expression until an open parenthesis is encountered
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression\n");
                free(stack->array);
                free(stack);
                return;
            } else {
                pop(stack);
            }
        }
        // If the character is an operator, pop operators from the stack and add them to the postfix expression if they have higher precedence
        else {
            while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack))) {
                postfix[++k] = pop(stack);
            }
            push(stack, c);
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(stack)) {
        postfix[++k] = pop(stack);
    }

    postfix[++k] = '\0';  // Null-terminate the postfix expression
    printf("Postfix expression: %s\n", postfix);
    free(stack->array);
    free(stack);
}

int main() {
    char infix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
