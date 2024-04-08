#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 100 
 
// Define the stack structure 
typedef struct { 
    int data[MAX_SIZE]; 
    int top; 
} Stack; 
 
// Function to initialize the stack 
void initializeStack(Stack *stack) { 
    stack->top = -1; 
} 
 
// Function to check if the stack is empty 
int isEmpty(Stack *stack) { 
    return stack->top == -1; 
} 
 
// Function to check if the stack is full 
int isFull(Stack *stack) { 
    return stack->top == MAX_SIZE - 1; 
} 
 
// Function to push an element onto the stack 
void push(Stack *stack, int value) { 
    if (isFull(stack)) { 
        printf("Stack overflow! Cannot push more elements.\n"); 
        return; 
    } 
    stack->data[++stack->top] = value; 
} 
 
// Function to display the elements of the stack 
void display(Stack *stack) { 
    if (isEmpty(stack)) { 
        printf("Stack is empty.\n"); 
        return; 
    } 
    printf("Stack elements: "); 
    for (int i = 0; i <= stack->top; ++i) { 
        printf("%d ", stack->data[i]); 
    } 
    printf("\n"); 
} 
 
int main() { 
    Stack stack; 
    initializeStack(&stack); 
 
    push(&stack, 10); 
    push(&stack, 20); 
    push(&stack, 30); 
 
    display(&stack); 
 
    return 0; 
}