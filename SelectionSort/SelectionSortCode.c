#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int n, i;
    clock_t start, end;
    srand(time(NULL));
    
    do {
        printf("ENTER THE NUMBER OF INPUTS (0 to exit): ");
        scanf("%d", &n);

        if (n == 0)
            break;

        int arr[n];
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        start = clock();
        selectionSort(arr, n);
        end = clock();

        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", time_taken);
    } while (1);
    
    return 0;
}
