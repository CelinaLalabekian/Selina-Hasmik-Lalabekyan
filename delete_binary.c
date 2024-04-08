#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 100 
 
struct MaxHeap { 
    int *array; 
    int size; 
    int capacity; 
}; 
 
// Function to create a new Max Heap 
struct MaxHeap* createMaxHeap(int capacity) { 
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap)); 
    maxHeap->capacity = capacity; 
    maxHeap->size = 0; 
    maxHeap->array = (int*)malloc(capacity * sizeof(int)); 
    return maxHeap; 
} 
 
// Function to swap two elements of the heap 
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
// Function to get the index of the parent of a node 
int parent(int i) { 
    return (i - 1) / 2; 
} 
 
// Function to insert a new element into the Max Heap 
void insert(struct MaxHeap* maxHeap, int key) { 
    if (maxHeap->size == maxHeap->capacity) { 
        printf("Heap is full. Insertion failed.\n"); 
        return; 
    } 
 
    // Insert the new element at the end of the heap 
    maxHeap->size++; 
    int i = maxHeap->size - 1; 
    maxHeap->array[i] = key; 
 
    // Fix the Max Heap property 
    while (i != 0 && maxHeap->array[parent(i)] < maxHeap->array[i]) { 
        swap(&maxHeap->array[i], &maxHeap->array[parent(i)]); 
        i = parent(i); 
    } 
} 
 
// Function to heapify a subtree rooted with node i which is an index in maxHeap 
void maxHeapify(struct MaxHeap* maxHeap, int i) { 
    int largest = i; // Initialize largest as root 
    int left = 2 * i + 1; // left = 2*i + 1 
    int right = 2 * i + 2; // right = 2*i + 2 
 
    // If left child is larger than root 
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest]) 
        largest = left; 
 
    // If right child is larger than largest so far 
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest]) 
        largest = right; 
 
    // If largest is not root 
    if (largest != i) { 
        swap(&maxHeap->array[i], &maxHeap->array[largest]); 
        // Recursively heapify the affected sub-tree 
        maxHeapify(maxHeap, largest); 
    } 
} 
 
// Function to delete an element at position i from the Max Heap 
void deleteNode(struct MaxHeap* maxHeap, int i) { 
    if (i >= maxHeap->size) { 
        printf("Invalid index for deletion.\n"); 
        return; 
    } 
 
    // Replace the element to be deleted with the last element 
    maxHeap->array[i] = maxHeap->array[maxHeap->size - 1]; 
    maxHeap->size--; 
 
    // Heapify the root 
    maxHeapify(maxHeap, i); 
} 
 
// Function to print the elements of the Max Heap 
void printMaxHeap(struct MaxHeap* maxHeap) { 
    printf("Max Heap: "); 
    for (int i = 0; i < maxHeap->size; i++) 
        printf("%d ", maxHeap->array[i]); 
    printf("\n"); 
} 
 
int main() { 
    struct MaxHeap* maxHeap = createMaxHeap(MAX_SIZE); 
 
    // Insert elements into the Max Heap 
    insert(maxHeap, 10); 
    insert(maxHeap, 20); 
    insert(maxHeap, 15); 
    insert(maxHeap, 40); 
    insert(maxHeap, 50); 
    insert(maxHeap, 100); 
    insert(maxHeap, 25); 
 
    // Print the Max Heap 
    printMaxHeap(maxHeap); 
 
    // Delete an element from the Max Heap 
    deleteNode(maxHeap, 3); 
 
    // Print the Max Heap after deletion 
    printMaxHeap(maxHeap); 
 
    return 0; 
}