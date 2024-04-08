#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_HEAP_SIZE 100 
 
struct MaxHeap { 
    int *array; 
    int size; 
    int capacity; 
}; 
 
// Function to create a new heap 
struct MaxHeap* createHeap(int capacity) { 
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap)); 
    heap->capacity = capacity; 
    heap->size = 0; 
    heap->array = (int*)malloc(heap->capacity * sizeof(int)); 
    return heap; 
} 
 
// Function to swap two integers 
void swap(int* a, int* b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
// Function to heapify up 
void heapifyUp(struct MaxHeap* heap, int index) { 
    int parent = (index - 1) / 2; 
    while (index > 0 && heap->array[index] > heap->array[parent]) { 
        swap(&heap->array[index], &heap->array[parent]); 
        index = parent; 
        parent = (index - 1) / 2; 
    } 
} 
 
// Function to insert a new element into the heap 
void insert(struct MaxHeap* heap, int key) { 
    if (heap->size >= heap->capacity) { 
        printf("Heap is full. Cannot insert.\n"); 
        return; 
    } 
 
    heap->size++; 
    int index = heap->size - 1; 
    heap->array[index] = key; 
    heapifyUp(heap, index); 
} 
 
// Function to print the heap 
void printHeap(struct MaxHeap* heap) { 
    printf("Heap: "); 
    for (int i = 0; i < heap->size; i++) { 
        printf("%d ", heap->array[i]); 
    } 
    printf("\n"); 
} 
 
int main