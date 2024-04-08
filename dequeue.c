#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 10 
 
typedef struct { 
    int items[MAX_SIZE]; 
    int front, rear; 
} CircularQueue; 
 
// Function to initialize the circular queue 
void initializeQueue(CircularQueue *queue) { 
    queue->front = -1; 
    queue->rear = -1; 
} 
 
// Function to check if the queue is full 
int isFull(CircularQueue *queue) { 
    return (queue->front == (queue->rear + 1) % MAX_SIZE); 
} 
 
// Function to check if the queue is empty 
int isEmpty(CircularQueue *queue) { 
    return (queue->front == -1 && queue->rear == -1); 
} 
 
// Function to add an element to the queue 
void enqueue(CircularQueue *queue, int value) { 
    if (isFull(queue)) { 
        printf("Queue is full\n"); 
        return; 
    } else if (isEmpty(queue)) { 
        queue->front = 0; 
        queue->rear = 0; 
    } else { 
        queue->rear = (queue->rear + 1) % MAX_SIZE; 
    } 
    queue->items[queue->rear] = value; 
} 
 
// Function to remove an element from the queue 
int dequeue(CircularQueue *queue) { 
    int item; 
    if (isEmpty(queue)) { 
        printf("Queue is empty\n"); 
        return -1; 
    } else if (queue->front == queue->rear) { 
        item = queue->items[queue->front]; 
        queue->front = -1; 
        queue->rear = -1; 
    } else { 
        item = queue->items[queue->front]; 
        queue->front = (queue->front + 1) % MAX_SIZE; 
    } 
    return item; 
} 
 
int main() { 
    CircularQueue queue; 
    initializeQueue(&queue); 
 
    // Enqueue some elements 
    enqueue(&queue, 10); 
    enqueue(&queue, 20); 
    enqueue(&queue, 30); 
 
    // Dequeue an element 
    printf("Dequeued element: %d\n", dequeue(&queue)); 
 
    // Enqueue more elements 
    enqueue(&queue, 40); 
    enqueue(&queue, 50); 
 
    // Dequeue remaining elements 
    while (!isEmpty(&queue)) { 
        printf("Dequeued element: %d\n", dequeue(&queue)); 
    } 
 
    return 0; 
}