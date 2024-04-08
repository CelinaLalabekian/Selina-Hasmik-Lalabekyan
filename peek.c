#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 5 
 
struct CircularQueue { 
    int items[MAX_SIZE]; 
    int front, rear; 
}; 
 
typedef struct CircularQueue CircularQueue; 
 
// Function to create an empty circular queue 
CircularQueue* createQueue() { 
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue)); 
    queue->front = -1; 
    queue->rear = -1; 
    return queue; 
} 
 
// Function to check if the circular queue is full 
int isFull(CircularQueue* queue) { 
    if ((queue->front == 0 && queue->rear == MAX_SIZE - 1) || 
        (queue->rear == (queue->front - 1) % (MAX_SIZE - 1))) { 
        return 1; 
    } 
    return 0; 
} 
 
// Function to check if the circular queue is empty 
int isEmpty(CircularQueue* queue) { 
    if (queue->front == -1) 
        return 1; 
    return 0; 
} 
 
// Function to add an element to the circular queue 
void enqueue(CircularQueue* queue, int value) { 
    if (isFull(queue)) { 
        printf("Queue is full\n"); 
        return; 
    } 
 
    if (isEmpty(queue)) { 
        queue->front = queue->rear = 0; 
    } else { 
        queue->rear = (queue->rear + 1) % MAX_SIZE; 
    } 
 
    queue->items[queue->rear] = value; 
    printf("%d enqueued to queue\n", value); 
} 
 
// Function to remove an element from the circular queue 
int dequeue(CircularQueue* queue) { 
    int item; 
    if (isEmpty(queue)) { 
        printf("Queue is empty\n"); 
        return -1; 
    } 
 
    item = queue->items[queue->front]; 
    if (queue->front == queue->rear) { 
        queue->front = queue->rear = -1; 
    } else { 
        queue->front = (queue->front + 1) % MAX_SIZE; 
    } 
    return item; 
} 
 
// Function to peek at the front element of the circular queue 
int peek(CircularQueue* queue) { 
    if (isEmpty(queue)) { 
        printf("Queue is empty\n"); 
        return -1; 
    } 
    return queue->items[queue->front]; 
} 
 
int main() { 
    CircularQueue* queue = createQueue(); 
 
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
 
    printf("Front element is %d\n", peek(queue)); 
 
    dequeue(queue); 
    dequeue(queue); 
 
    printf("Front element is %d\n", peek(queue)); 
 
    enqueue(queue, 50); 
    enqueue(queue, 60); 
 
    printf("Front element is %d\n", peek(queue)); 
 
    return 0; 
}