#include <stdio.h> 
 
// A recursive binary search function 
int binarySearch(int arr[], int left, int right, int target) { 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
 
        // If the element is present at the middle 
        if (arr[mid] == target) 
            return mid; 
 
        // If the element is smaller than mid, then it can only be present in the left subarray 
        if (arr[mid] > target) 
            return binarySearch(arr, left, mid - 1, target); 
 
        // Else the element can only be present in the right subarray 
        return binarySearch(arr, mid + 1, right, target); 
    } 
 
    // If the element is not present in the array 
    return -1; 
} 
 
// Function to perform exponential search 
int exponentialSearch(int arr[], int n, int target) { 
    if (arr[0] == target) 
        return 0; 
 
    // Find range for binary search by repeated doubling 
    int i = 1; 
    while (i < n && arr[i] <= target) 
        i = i * 2; 
 
    // Call binary search for the found range 
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target); 
} 
 
int main() { 
    int arr[] = {2, 3, 4, 10, 40}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 10; 
    int result = exponentialSearch(arr, n, target); 
    if (result == -1) 
        printf("Element not found.\n"); 
    else 
        printf("Element found at index %d.\n", result); 
    return 0; 
}