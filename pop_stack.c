#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 100 
 
// Structure definition for stack 
typedef struct { 
    int data[MAX_SIZE]; 
    int top; 
} Stack; 
 
// Function to initialize the stack 
void initializeStack(Stack *s) { 
    s->top = -1; 
} 
 
// Function to check if the stack is empty 
int isEmpty(Stack *s) { 
    return s->top == -1; 
} 
 
// Function to check if the stack is full 
int isFull(Stack *s) { 
    return s->top == MAX_SIZE - 1; 
} 
 
// Function to push an element onto the stack 
void push(Stack *s, int item) { 
    if (isFull(s)) { 
        printf("Stack Overflow\n"); 
        return; 
    } 
    s->data[++s->top] = item; 
} 
 
// Function to pop an element from the stack 
int pop(Stack *s) { 
    if (isEmpty(s)) { 
        printf("Stack Underflow\n"); 
        exit(EXIT_FAILURE); 
    } 
    return s->data[s->top--]; 
} 
 
// Function to retrieve the top element of the stack without popping it 
int top(Stack *s) { 
    if (isEmpty(s)) { 
        printf("Stack is empty\n"); 
        exit(EXIT_FAILURE); 
    } 
    return s->data[s->top]; 
} 
 
int main() { 
    Stack myStack; 
    initializeStack(&myStack); 
 
    push(&myStack, 10); 
    push(&myStack, 20); 
    push(&myStack, 30); 
 
    printf("Top element: %d\n", top(&myStack)); 
 
    printf("Popping elements: %d, %d\n", pop(&myStack), pop(&myStack)); 
 
    printf("Top element after popping: %d\n", top(&myStack)); 
 
    return 0; 
}