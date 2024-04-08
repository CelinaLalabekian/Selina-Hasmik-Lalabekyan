#include <stdio.h> 
 
// Function to perform linear search 
int linearSearch(int arr[], int n, int key) { 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == key) { 
            return i; // Return the index where the key is found 
        } 
    } 
    return -1; // Return -1 if key is not found 
} 
 
int main() { 
    int arr[] = {2, 5, 7, 9, 11, 13, 15}; 
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of array 
    int key = 11; 
 
    int index = linearSearch(arr, n, key); 
     
    if (index != -1) { 
        printf("Element found at index: %d\n", index); 
    } else { 
        printf("Element not found\n"); 
    } 
 
    return 0; 
}