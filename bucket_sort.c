// Bucket Sort 
void bucketSort(int arr[], int n) { 
    // Assuming input elements are between 0 and 1 
    void insertionSortForBucket(int arr[], int n) { 
        int i, j; 
        for (i = 1; i < n; i++) { 
            int key = arr[i]; 
            j = i - 1; 
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 
 
    int i, j; 
    int bucket[n]; 
    for (i = 0; i < n; i++) 
        bucket[i] = 0; 
 
    for (i = 0; i < n; i++)

(bucket[(int)(n * arr[i])])++; 
 
    for (i = 0, j = 0; i < n; i++) 
        for (int k = bucket[i]; k > 0; k--) 
            arr[j++] = i / (float)n; 
 
    for (i = 0; i < n; i++) 
        insertionSortForBucket(bucket, n); 
} 