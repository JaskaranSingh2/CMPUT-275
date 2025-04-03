#include <stdio.h>
#include <stdlib.h>

// Function to calculate the products
long long* calculate_products(int arr[], int n, int m) {
    long long* results = (long long*)malloc(n * sizeof(long long));
    
    // For each position in the array
    for (int i = 0; i < n; i++) {
        // Initialize product to 1
        long long product = 1;
        int valid_elements = 0;
        
        // Multiply all elements that are outside the exclusion range
        for (int j = 0; j < n; j++) {
            // Skip if j is within m spaces of i
            if (j >= i - m && j <= i + m) {
                continue;
            }
            
            // Multiply valid elements
            product *= arr[j];
            valid_elements++;
        }
        
        // If no valid elements to multiply, set product to 0
        results[i] = valid_elements > 0 ? product : 0;
    }
    
    return results;
}

int main() {
    int n, m;
    
    // Read n and m
    if (scanf("%d %d", &n, &m) != 2) {
        printf("Failed reading input\n");
        return 1;
    }
    
    // Allocate memory for array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Malloc failed\n");
        return 1;
    }
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Failed reading int\n");
            free(arr);
            return 1;
        }
    }
    
    // Calculate products
    long long* results = calculate_products(arr, n, m);
    
    // Print results
    for (int i = 0; i < n; i++) {
        printf("%lld", results[i]);
        // Add space after each element except the last one
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    free(results);
    
    return 0;
}