#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void merge(int a[], int low, int mid, int high) {
    int h = low;
    int i = low;
    int j = mid + 1;
    int k;
    int b[100000]; // Assuming array size is 100

    while ((h <= mid) && (j <= high)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h = h + 1;
        } else {
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }

    if (h > mid) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i = i + 1;
        }
    } else {
        for (k = h; k <= mid; k++) {
            b[i] = a[k];
            i = i + 1;
        }
    }

    for (k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
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
        mergesort(arr,0,n-1);
        end = clock();

        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", time_taken);
    } while (1);
    
    return 0;
}