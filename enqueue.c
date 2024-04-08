#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 10 
 
typedef struct { 
    int items[MAX_SIZE]; 
    int front, rear; 
} CircularQueue; 
 
CircularQueue* createCircularQueue() { 
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue)); 
    queue->front = -1; 
    queue->rear = -1; 
    return queue; 
} 
 
int isFull(CircularQueue* queue) { 
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1); 
} 
 
int isEmpty(CircularQueue* queue) { 
    return queue->front == -1; 
} 
 
void enqueue(CircularQueue* queue, int value) { 
    if (isFull(queue)) { 
        printf("Queue is full. Enqueue operation failed.\n"); 
        return; 
    } 
 
    if (queue->front == -1) { 
        queue->front = 0; 
        queue->rear = 0; 
    } else if (queue->rear == MAX_SIZE - 1) { 
        queue->rear = 0; 
    } else { 
        queue->rear++; 
    } 
 
    queue->items