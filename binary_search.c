#include <stdio.h> 
 
// Binary search function 
int binarySearch(int arr[], int l, int r, int x) { 
    while (l <= r) { 
        int mid = l + (r - l) / 2; 
 
        // Check if x is present at mid 
        if (arr[mid] == x) 
            return mid; 
 
        // If x greater, ignore left half 
        if (arr[mid] < x) 
            l = mid + 1; 
 
        // If x is smaller, ignore right half 
        else 
            r = mid - 1; 
    } 
 
    // If element is not present in array 
    return -1; 
} 
 
int main() { 
    int arr[] = {2, 3, 4, 10, 40}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 10; 
    int result = binarySearch(arr, 0, n - 1, x); 
    if (result == -1) 
        printf("Element is not present in array\n"); 
    else 
        printf("Element is present at index %d\n", result); 
    return 0; 
}