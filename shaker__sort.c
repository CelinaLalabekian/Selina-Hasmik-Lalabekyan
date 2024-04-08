void shakerSort(int arr[], int n) {     int i, j, k; 
    for (i = 0; i < n / 2; ++i) {         bool swapped = false;
        // Forward pass (similar to Bubble Sort)        for (j = i; j < n - i - 1; ++j) { 
            if (arr[j] > arr[j + 1]) {                 swap(&arr[j], &arr[j + 1]); 
                swapped = true;            } 
        }         // Backward pass
        for (k = n - 2 - i; k > i; --k) {             if (arr[k] < arr[k - 1]) { 
                swap(&arr[k], &arr[k - 1]);                 swapped = true;
            }         } 
        // If no swapping occurred, the array is already sorted        if (!swapped) 
            break;    } 
}