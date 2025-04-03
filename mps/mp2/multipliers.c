#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long* calcProd(int arr[], int n, int m) {
    long long* results = (long long*)malloc(n * sizeof(long long));
    

    for (int i = 0; i < n; i++) {

        long long product = 1;
        int validElem = 0;
        

        for (int j = 0; j < n; j++) {

            if (abs(i - j) <= m) {
                continue;
            }
            
            product *= arr[j];
            validElem++;
        }
        


        results[i] = validElem > 0 ? product : 1;
    }
    
    return results;
}

int main() {
    int n, m;
    

    if (scanf("%d %d", &n, &m) != 2) {

        return 1;
    }
    

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {

        return 1;
    }
    

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {

            free(arr);
            return 1;
        }
    }
    

    long long* results = calcProd(arr, n, m);
    

    for (int i = 0; i < n; i++) {
        printf("%lld", results[i]);

        printf(" ");
    }
    printf("\n");
    

    free(arr);
    free(results);
    
    return 0;
}