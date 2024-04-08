#include <stdio.h> 
#include <stdlib.h> 
 
// Structure to represent a binary max heap 
struct MaxHeap { 
    int *array;     // Pointer to array to store heap elements 
    int capacity;   // Maximum possible size of max heap 
    int size;       // Current number of elements in max heap 
}; 
 
// Function to create a new max heap 
struct MaxHeap* createMaxHeap(int capacity) { 
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap)); 
    maxHeap->capacity = capacity; 
    maxHeap->size = 0; 
    maxHeap->array = (int*) malloc(maxHeap->capacity * sizeof(int)); 
    return maxHeap; 
} 
 
// Function to swap two integers 
void swap(int* a, int* b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
// Function to maintain max heap property 
void maxHeapify(struct MaxHeap* maxHeap, int idx) { 
    int largest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
 
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest]) 
        largest = left; 
 
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest]) 
        largest = right; 
 
    if (largest != idx) { 
        swap(&maxHeap->array[idx], &maxHeap->array[largest]); 
        maxHeapify(maxHeap, largest); 
    } 
} 
 
// Function to insert a new key in max heap 
void insertKey(struct MaxHeap* maxHeap, int key) { 
    if (maxHeap->size == maxHeap->capacity) { 
        printf("Overflow: Could not insert key\n"); 
        return; 
    } 
 
    maxHeap->size++; 
    int i = maxHeap->size - 1; 
    maxHeap->array[i] = key; 
 
    // Fix the max heap property if it is violated 
    while (i != 0 && maxHeap->array[(i - 1) / 2] < maxHeap->array[i]) { 
        swap(&maxHeap->array[i], &maxHeap->array[(i - 1) / 2]); 
        i = (i - 1) / 2; 
    } 
} 
 
// Function to increase the value of a key at index idx to a new value new_val 
void increaseKey(struct MaxHeap* maxHeap, int idx, int new_val) { 
    if (idx >= maxHeap->size) { 
        printf("Index out of range\n"); 
        return; 
    } 
 
    maxHeap->array[idx] = new_val; 
    while (idx != 0 && maxHeap->array[(idx - 1) / 2] < maxHeap->array[idx]) { 
        swap(&maxHeap->array[idx], &maxHeap->array[(idx - 1) / 2]); 
        idx = (idx - 1) / 2; 
    } 
} 
 
// Function to extract the maximum key (root) from max heap 
int extractMax(struct MaxHeap* maxHeap) { 
    if (maxHeap->size <= 0) 
        return -1; 
 
    if (maxHeap->size == 1) { 
        maxHeap->size--; 
        return maxHeap->array[0]; 
    } 
 
    int root = maxHeap->array[0]; 
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1]; 
    maxHeap->size--; 
    maxHeapify(maxHeap, 0); 
 
    return root; 
} 
 
// Function to print the contents of the max heap 
void printMaxHeap(struct MaxHeap* maxHeap) { 
    printf("Max Heap: "); 
    for (int i = 0; i < maxHeap->size; ++i) 
        printf("%d ", maxHeap->array[i]); 
    printf("\n"); 
} 
 
// Driver program 
int main() { 
    struct MaxHeap* maxHeap = createMaxHeap(10); 
    insertKey(maxHeap, 3); 
    insertKey(maxHeap, 2); 
    insertKey(maxHeap, 15); 
    insertKey(maxHeap, 5); 
    insertKey(maxHeap, 4); 
    insertKey(maxHeap, 45); 
 
    printMaxHeap(maxHeap); 
 
    increaseKey(maxHeap, 4, 50); 
 
    printMaxHeap(maxHeap); 
 
    printf("Extracted max value: %d\n", extractMax(maxHeap)); 
 
    printMaxHeap(maxHeap); 
 
    free(maxHeap->array); 
    free(maxHeap); 
     
    return 0; 
}