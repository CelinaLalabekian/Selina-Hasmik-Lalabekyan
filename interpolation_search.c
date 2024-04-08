#include <stdio.h> 
 
// Interpolation Search Function 
int interpolationSearch(int arr[], int n, int x) { 
    int low = 0, high = n - 1; 
 
    while (low <= high && x >= arr[low] && x <= arr[high]) { 
        if (low == high) { 
            if (arr[low] == x) 
                return low; 
            return -1; 
        } 
         
        // Calculating the position with interpolation formula 
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]); 
 
        if (arr[pos] == x) 
            return pos; 
        else if (arr[pos] < x) 
            low = pos + 1; 
        else 
            high = pos - 1; 
    } 
    return -1; 
} 
 
int main() { 
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 12; 
    int index = interpolationSearch(arr, n, x); 
 
    if (index != -1) 
        printf("Element %d found at index %d\n", x, index); 
    else 
        printf("Element %d not found\n", x); 
 
    return 0; 
}