#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 100 
 
struct MaxHeap { 
    int *array; 
    int size; 
}; 
 
struct MaxHeap* createHeap() { 
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap)); 
    heap->array = (int*)malloc(MAX_SIZE * sizeof(int)); 
    heap->size = 0; 
    return heap; 
} 
 
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
void maxHeapify(struct MaxHeap* heap, int index) { 
    int largest = index; 
    int left = 2 * index + 1; 
    int right = 2 * index + 2; 
 
    if (left < heap->size && heap->array[left] > heap->array[largest]) 
        largest = left; 
 
    if (right < heap->size && heap->array[right] > heap->array[largest]) 
        largest = right; 
 
    if (largest != index) { 
        swap(&heap->array[index], &heap->array[largest]); 
        maxHeapify(heap, largest); 
    } 
} 
 
void insert(struct MaxHeap* heap, int value) { 
    if (heap->size >= MAX_SIZE) { 
        printf("Heap is full. Cannot insert more elements.\n"); 
        return; 
    } 
 
    int i = heap->size; 
    heap->array[i] = value; 
    heap->size++; 
 
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) { 
        swap(&heap->array[i], &heap->array[(i - 1) / 2]); 
        i = (i - 1) / 2; 
    } 
} 
 
int peek(struct MaxHeap* heap) { 
    if (heap->size == 0) { 
        printf("Heap is empty. Cannot peek.\n"); 
        return -1; // Return some invalid value indicating heap is empty 
    } 
 
    return heap->array[0]; 
} 
 
int main() { 
    struct MaxHeap* heap = createHeap(); 
 
    insert(heap, 10); 
    insert(heap, 20); 
    insert(heap, 15); 
    insert(heap, 30); 
    insert(heap, 25); 
 
    printf("Max element in heap: %d\n", peek(heap)); 
 
    return 0; 
}